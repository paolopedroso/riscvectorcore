/*
 * Data Memory
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 *
 */

module datamem #(
    parameter int DATA_WIDTH = 32,
    parameter int MEM_SIZE = 1024  // 1K words of memory
) (
    input logic clk,
    input logic rst_n,
    
    // Control inputs from sdecoder
    input logic mem_read_i,            // Read enable
    input logic mem_write_i,           // Write enable
    input logic [1:0] mem_size_i,      // Size of access: 00=byte, 01=halfword, 10=word
    input logic mem_unsigned_i,        // LUI case

    // Address and data
    input logic [DATA_WIDTH-1:0] addr_i,    // Memory address
    input logic [DATA_WIDTH-1:0] wdata_i,   // Data to write
    output logic [DATA_WIDTH-1:0] rdata_o,  // Data read from memory

    // Debugging signals
    input logic [DATA_WIDTH-1:0] curr_instr,
    input logic [DATA_WIDTH-1:0] curr_pc
);

// Internal signals
// Mem array - byte addressable memory
logic [7:0] memory [MEM_SIZE-1:0];

// Debug memory status
// `ifdef SIMULATION
//     function void print_mem_status(input [31:0] addr);
//         $display("DMEM: MEMORY STATUS: Memory[%0d:%0d] = %02x %02x %02x %02x",
//                 addr+3, addr,
//                 memory[addr], memory[addr+1], 
//                 memory[addr+2], memory[addr+3]);
//     endfunction
// `endif

// Read logic with endianness correction and unsigned support
always_comb begin
    rdata_o = 32'b0;  // Default value
    
    if (mem_read_i) begin

        // `ifdef SIMULATION
        //     $display("DMEM: LOAD INSTRUCTION DETECTED");
        //     $display("DMEM: MEMORY DEBUG: Reading from address 0x%h", addr_i);
        //     $display("DMEM: INSTRUCTION: 0x%h", curr_instr);
        //     $display("DMEM: PC: 0x%h", curr_pc);
        //     $display("DMEM: Unsigned load: %b", mem_unsigned_i);
        // `endif
    
        // Add bounds checking
        if (addr_i >= MEM_SIZE - 3) begin  // -3 to account for word access
            `ifdef SIMULATION
                $display("DMEM: WARNING: Memory read out of bounds: addr=0x%h", addr_i);
            `endif
            rdata_o = 32'hDEADBEEF;  // Error pattern
        end else begin
            case (mem_size_i)
                2'b00: begin // Byte (8-bit)
                    if (mem_unsigned_i) begin
                        // Zero-extend for unsigned byte
                        rdata_o = {24'b0, memory[addr_i]};
                    end else begin
                        // Sign-extend for signed byte
                        rdata_o = {{24{memory[addr_i][7]}}, memory[addr_i]};
                    end
                    
                    // `ifdef SIMULATION
                    //     $display("DMEM: MEMORY READ BYTE: addr=0x%h, data=%02x, unsigned=%b", 
                    //             addr_i, memory[addr_i], mem_unsigned_i);
                    // `endif
                end
                
                2'b01: begin // Half word (16-bit)
                    if (mem_unsigned_i) begin
                        // Zero-extend for unsigned halfword
                        rdata_o = {16'b0, memory[addr_i+1], memory[addr_i]};
                    end else begin
                        // Sign-extend for signed halfword
                        rdata_o = {{16{memory[addr_i+1][7]}}, memory[addr_i+1], memory[addr_i]};
                    end
                    
                    // `ifdef SIMULATION
                    //     $display("DMEM: MEMORY READ HALFWORD: addr=0x%h, data=%04x, unsigned=%b", 
                    //             addr_i, {memory[addr_i+1], memory[addr_i]}, mem_unsigned_i);
                    // `endif
                end
                
                2'b10, 2'b11: begin // Word (32-bit)
                    // No sign extension needed for word loads
                    rdata_o = {memory[addr_i+3], memory[addr_i+2], 
                              memory[addr_i+1], memory[addr_i]};
                    
                    // `ifdef SIMULATION
                    //     $display("DMEM: MEMORY READ WORD: addr=0x%h, data=0x%08x", addr_i, 
                    //             {memory[addr_i+3], memory[addr_i+2], 
                    //             memory[addr_i+1], memory[addr_i]});
                                
                    //     $display("DMEM:   Final register value: 0x%08x", rdata_o);
                    //     print_mem_status(addr_i);
                    // `endif
                end
            endcase
        end
    end
end

// Store Instruction Detection
// Write logic block with bounds checking
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        for (int i = 0; i < MEM_SIZE; i++) begin
            memory[i] = 8'h00;
        end
    end
    else if (mem_write_i) begin

        // `ifdef SIMULATION
        //     $display("DMEM: SAVE INSTRUCTION DETECTED");
        //     $display("DMEM: INSTRUCTION: 0x%h", curr_instr);
        //     $display("DMEM: MEMORY DEBUG: Writing to address 0x%h, data=0x%h, size=%0d", 
        //              addr_i, wdata_i, mem_size_i);
        // `endif

        // Add bounds checking
        if (addr_i >= MEM_SIZE - 3) begin  // -3 to account for word access

            // `ifdef SIMULATION
            //     $display("DMEM: WARNING: Memory write out of bounds: addr=0x%h", addr_i);
            // `endif

        end else begin
            case (mem_size_i)
                2'b00: begin // Byte
                    memory[addr_i] <= wdata_i[7:0];
        
                    // `ifdef SIMULATION
                    //     $display("DMEM: MEMORY WRITE BYTE: addr=0x%h, data=%02x", addr_i, wdata_i[7:0]);
                    // `endif

                end
                
                2'b01: begin // Half word with correct byte order (little-endian)
                    memory[addr_i]   <= wdata_i[7:0];   // LSB first
                    memory[addr_i+1] <= wdata_i[15:8];  // MSB second

                    // `ifdef SIMULATION
                    //     $display("DMEM: MEMORY WRITE HALFWORD: addr=0x%h, data=%04x", addr_i, wdata_i[15:0]);
                    // `endif

                end
                
                2'b10, 2'b11: begin // Word with correct byte order (little-endian)
                    memory[addr_i]   <= wdata_i[7:0];    // LSB first
                    memory[addr_i+1] <= wdata_i[15:8];   // ...
                    memory[addr_i+2] <= wdata_i[23:16];  // ...
                    memory[addr_i+3] <= wdata_i[31:24];  // MSB last
                    
                    // Add extra debug
                    // `ifdef SIMULATION
                    //     $display("DMEM: MEMORY WRITE WORD: addr=0x%h, data=0x%08x", addr_i, wdata_i);
                    //     $display("DMEM:   Writing bytes: %02x %02x %02x %02x", 
                    //             wdata_i[7:0], wdata_i[15:8], wdata_i[23:16], wdata_i[31:24]);
                                
                    //     // Add a more visible debug message
                    //     $display("DMEM: ** MEMORY STORE: WORD 0x%h written to address 0x%h **", wdata_i, addr_i);
                    // `endif

                end
            endcase
        end
    end
end


// Ensure data writes
// `ifdef SIMULATION
// // Memory debugging with Verilator compatibility
// // Registers to track memory writes for verification
// logic verify_write;
// logic [DATA_WIDTH-1:0] verify_addr;
// logic [DATA_WIDTH-1:0] verify_data;

// // Set the verification flags on write
// always @(posedge clk) begin
//     if (rst_n) begin
//         if (mem_write_i && mem_size_i == 2'b10 && addr_i < MEM_SIZE - 3) begin
//             verify_write <= 1'b1;
//             verify_addr <= addr_i;
//             verify_data <= wdata_i;
//         end else begin
//             verify_write <= 1'b0;
//         end
//     end else begin
//         verify_write <= 1'b0;
//     end
// end

// // Verify on the next cycle after the write
// always @(posedge clk) begin
//     if (rst_n && verify_write) begin
//         #1;
//         // Verify memory contents after write (now on next cycle)
//         $display("DMEM: MEMORY CONTENTS after write at addr=0x%h:", verify_addr);
//         $display("DMEM:   Memory[%0d:%0d] = %02x %02x %02x %02x",
//                 verify_addr+3, verify_addr,
//                 memory[verify_addr], memory[verify_addr+1], 
//                 memory[verify_addr+2], memory[verify_addr+3]);
                
//         // Directly use concatenation in display without temporary variable
//         $display("DMEM:   Reconstructed word: 0x%08x", 
//                 {memory[verify_addr+3], memory[verify_addr+2], 
//                  memory[verify_addr+1], memory[verify_addr]});
        
//         // Check if the stored word matches the expected value
//         if ({memory[verify_addr+3], memory[verify_addr+2], 
//              memory[verify_addr+1], memory[verify_addr]} != verify_data) begin
//             $display("DMEM:   ERROR: Stored word 0x%08x doesn't match input 0x%08x", 
//                     {memory[verify_addr+3], memory[verify_addr+2], 
//                      memory[verify_addr+1], memory[verify_addr]}, 
//                     verify_data);
//         end
//     end
// end
// `endif

endmodule
