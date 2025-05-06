/*
 * Data Memory - Fixed version
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 *
 */

module sdatamem #(
    parameter int DATA_WIDTH = 32,
    parameter int MEM_SIZE = 1024  // 1K words of memory
) (
    input logic clk,
    input logic rst_n,
    
    // Control inputs from sdecoder
    input logic mem_read_i,            // Read enable
    input logic mem_write_i,           // Write enable
    input logic [1:0] mem_size_i,      // Size of access: 00=byte, 01=halfword, 10=word
    
    // Address and data
    input logic [DATA_WIDTH-1:0] addr_i,    // Memory address
    input logic [DATA_WIDTH-1:0] wdata_i,   // Data to write
    output logic [DATA_WIDTH-1:0] rdata_o   // Data read from memory
);

// Internal signals
// Mem array - byte addressable memory
logic [7:0] memory [MEM_SIZE-1:0];

// Debug memory status
`ifdef SIMULATION
    function void print_mem_status(input [31:0] addr);
        $display("MEMORY STATUS: Memory[%0d:%0d] = %02x %02x %02x %02x",
                addr+3, addr,
                memory[addr], memory[addr+1], 
                memory[addr+2], memory[addr+3]);
    endfunction
`endif

// Read logic with endianness correction
always_comb begin
    rdata_o = 32'b0;  // Default value
    
    if (mem_read_i) begin
        // Add bounds checking
        if (addr_i >= MEM_SIZE - 3) begin  // -3 to account for word access
            `ifdef SIMULATION
                $display("WARNING: Memory read out of bounds: addr=0x%h", addr_i);
            `endif
            rdata_o = 32'hDEADBEEF;  // Error pattern
        end else begin
            case (mem_size_i)
                2'b00: begin // Byte (8-bit)
                    // Properly sign-extend the byte
                    rdata_o = {{24{memory[addr_i][7]}}, memory[addr_i]};
                    
                    `ifdef SIMULATION
                        $display("MEMORY READ BYTE: addr=0x%h, data=%02x", addr_i, memory[addr_i]);
                    `endif
                end
                
                2'b01: begin // Half word (16-bit)
                    // Properly sign-extend the halfword with correct byte order (little-endian)
                    rdata_o = {{16{memory[addr_i+1][7]}}, memory[addr_i+1], memory[addr_i]};
                    
                    `ifdef SIMULATION
                        $display("MEMORY READ HALFWORD: addr=0x%h, data=%04x", addr_i, {memory[addr_i+1], memory[addr_i]});
                    `endif
                end
                
                2'b10, 2'b11: begin // Word (32-bit)
                    // Correct byte ordering for little-endian RISC-V
                    rdata_o = {memory[addr_i+3], memory[addr_i+2], 
                              memory[addr_i+1], memory[addr_i]};
                    
                    `ifdef SIMULATION
                        // Basic read information
                        $display("MEMORY READ WORD: addr=0x%h, data=0x%08x", addr_i, 
                                {memory[addr_i+3], memory[addr_i+2], 
                                memory[addr_i+1], memory[addr_i]});
                                
                        // Detailed little-endian memory layout explanation
                        $display("  Memory layout (RISC-V little-endian):");
                        $display("    addr+0 (0x%h): 0x%02x (LSB, bits 7-0)", 
                                addr_i, memory[addr_i]);
                        $display("    addr+1 (0x%h): 0x%02x (bits 15-8)", 
                                addr_i+1, memory[addr_i+1]);
                        $display("    addr+2 (0x%h): 0x%02x (bits 23-16)", 
                                addr_i+2, memory[addr_i+2]);
                        $display("    addr+3 (0x%h): 0x%02x (MSB, bits 31-24)", 
                                addr_i+3, memory[addr_i+3]);
                                
                        // Show final register value
                        $display("  Final register value: 0x%08x", rdata_o);
                        print_mem_status(addr_i);
                    `endif
                end
            endcase
        end
    end
end

// Write logic block with bounds checking
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        for (int i = 0; i < MEM_SIZE; i++) begin
            memory[i] <= 8'h00;
        end
    end
    else if (mem_write_i) begin
        // Add bounds checking
        if (addr_i >= MEM_SIZE - 3) begin  // -3 to account for word access
            `ifdef SIMULATION
                $display("WARNING: Memory write out of bounds: addr=0x%h", addr_i);
            `endif
            // Don't write anything
        end else begin
            case (mem_size_i)
                2'b00: begin // Byte
                    memory[addr_i] <= wdata_i[7:0];
                    `ifdef SIMULATION
                        $display("MEMORY WRITE BYTE: addr=0x%h, data=%02x", addr_i, wdata_i[7:0]);
                        print_mem_status(addr_i);
                    `endif
                end
                
                2'b01: begin // Half word with correct byte order (little-endian)
                    memory[addr_i]   <= wdata_i[7:0];   // LSB first
                    memory[addr_i+1] <= wdata_i[15:8];  // MSB second
                    `ifdef SIMULATION
                        $display("MEMORY WRITE HALFWORD: addr=0x%h, data=%04x", addr_i, wdata_i[15:0]);
                        print_mem_status(addr_i);
                    `endif
                end
                
                2'b10, 2'b11: begin // Word with correct byte order (little-endian)
                    memory[addr_i]   <= wdata_i[7:0];    // LSB first
                    memory[addr_i+1] <= wdata_i[15:8];   // ...
                    memory[addr_i+2] <= wdata_i[23:16];  // ...
                    memory[addr_i+3] <= wdata_i[31:24];  // MSB last
                    `ifdef SIMULATION
                        $display("MEMORY WRITE WORD: addr=0x%h, data=0x%08x", addr_i, wdata_i);
                        $display("  Writing bytes: %02x %02x %02x %02x", 
                                wdata_i[7:0], wdata_i[15:8], wdata_i[23:16], wdata_i[31:24]);
                        print_mem_status(addr_i);
                    `endif
                end
            endcase
        end
    end
end

// Verification mechanism to check memory contents after each write
`ifdef SIMULATION
// Memory debugging
always @(posedge clk) begin
    if (mem_write_i && mem_size_i == 2'b10 && addr_i < MEM_SIZE - 3) begin
        
        // Verify memory contents after write
        $display("MEMORY CONTENTS after write at addr=0x%h:", addr_i);
        $display("  Memory[%0d:%0d] = %02x %02x %02x %02x",
                addr_i+3, addr_i,
                memory[addr_i], memory[addr_i+1], 
                memory[addr_i+2], memory[addr_i+3]);
                
        // Reconstruct the word to verify correctness
        $display("  Reconstructed word: 0x%08x", 
                {memory[addr_i+3], memory[addr_i+2], 
                 memory[addr_i+1], memory[addr_i]});
        
        // Check if the stored word matches the expected value
        if ({memory[addr_i+3], memory[addr_i+2], memory[addr_i+1], memory[addr_i]} != wdata_i) begin
            $display("  ERROR: Stored word 0x%08x doesn't match input 0x%08x", 
                    {memory[addr_i+3], memory[addr_i+2], memory[addr_i+1], memory[addr_i]}, 
                    wdata_i);
        end
    end
end
`endif

endmodule
