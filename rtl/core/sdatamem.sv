/*
 * Data Memory
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

// These functions cause syntax errors in Verilator - simpler to remove them and use inline conversions
// Instead of using functions, we'll implement the conversions directly where needed

`ifdef SIMULATION
    // Declare temp variables at module level for debug displays
    logic [31:0] debug_corrected;
    logic [31:0] debug_stored_word;
`endif

// Debug output (simplified to avoid duplicates)
`ifdef SIMULATION
    always @(posedge clk) begin
        if (mem_write_i) begin
            if (addr_i >= MEM_SIZE - 3) begin
                $display("ERROR: MEMORY WRITE OUT OF BOUNDS: Address=0x%h", addr_i);
            end else begin
                $display("MEMORY WRITE: Address=0x%h, Size=%0d, Data=0x%h",
                        addr_i, mem_size_i, wdata_i);
                $display("  Byte order (original): %02x %02x %02x %02x", 
                        wdata_i[7:0], wdata_i[15:8], wdata_i[23:16], wdata_i[31:24]);
                        
                debug_corrected = {wdata_i[7:0], wdata_i[15:8], wdata_i[23:16], wdata_i[31:24]};
                $display("  Byte order (corrected): %02x %02x %02x %02x", 
                        debug_corrected[7:0], debug_corrected[15:8], 
                        debug_corrected[23:16], debug_corrected[31:24]);
            end
        end
    end
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
                    logic [7:0] byte_data;
                    byte_data = memory[addr_i];
                    rdata_o = {{24{byte_data[7]}}, byte_data};
                    
                    `ifdef SIMULATION
                        $display("MEMORY READ BYTE: addr=0x%h, data=%02x", addr_i, byte_data);
                    `endif
                end
                
                2'b01: begin // Half word (16-bit)
                    // Properly sign-extend the halfword with correct byte order (little-endian)
                    logic [15:0] half_data;
                    half_data = {memory[addr_i+1], memory[addr_i]};
                    rdata_o = {{16{half_data[15]}}, half_data};
                    
                    `ifdef SIMULATION
                        $display("MEMORY READ HALFWORD: addr=0x%h, data=%04x", addr_i, half_data);
                    `endif
                end
                
                2'b10, 2'b11: begin // Word (32-bit)
                    // Correct byte ordering for little-endian RISC-V
                    rdata_o = {memory[addr_i+3], memory[addr_i+2], 
                              memory[addr_i+1], memory[addr_i]};
                    
                    `ifdef SIMULATION
                        $display("MEMORY READ WORD: addr=0x%h, data=%08x", addr_i, 
                                {memory[addr_i+3], memory[addr_i+2], 
                                memory[addr_i+1], memory[addr_i]});
                        $display("  Byte order (raw): %02x %02x %02x %02x", 
                                memory[addr_i], memory[addr_i+1], 
                                memory[addr_i+2], memory[addr_i+3]);
                        $display("  Byte order (returned): %02x %02x %02x %02x", 
                                rdata_o[7:0], rdata_o[15:8], rdata_o[23:16], rdata_o[31:24]);
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
                    `endif
                end
                
                2'b01: begin // Half word with correct byte order (little-endian)
                    memory[addr_i]   <= wdata_i[7:0];   // LSB first
                    memory[addr_i+1] <= wdata_i[15:8];  // MSB second
                    `ifdef SIMULATION
                        $display("MEMORY WRITE HALFWORD: addr=0x%h, data=%04x", addr_i, wdata_i[15:0]);
                    `endif
                end
                
                2'b10, 2'b11: begin // Word with correct byte order (little-endian)
                    memory[addr_i]   <= wdata_i[7:0];    // LSB first
                    memory[addr_i+1] <= wdata_i[15:8];   // ...
                    memory[addr_i+2] <= wdata_i[23:16];  // ...
                    memory[addr_i+3] <= wdata_i[31:24];  // MSB last
                    `ifdef SIMULATION
                        $display("MEMORY WRITE WORD: addr=0x%h, data=%08x", addr_i, wdata_i);
                        $display("  Writing bytes: %02x %02x %02x %02x", 
                                wdata_i[7:0], wdata_i[15:8], wdata_i[23:16], wdata_i[31:24]);
                    `endif
                end
            endcase
        end
    end
end

// Verification mechanism to check memory contents after each write
`ifdef SIMULATION
// Memory writes with byte-level verification
always @(posedge clk) begin
    if (mem_write_i && mem_size_i == 2'b10 && addr_i < MEM_SIZE - 3) begin
        // Verify memory contents after write
        $display("  Memory after write: mem[%0d:%0d] = %02x %02x %02x %02x",
                addr_i+3, addr_i,
                memory[addr_i], memory[addr_i+1], 
                memory[addr_i+2], memory[addr_i+3]);
                
        // Reconstruct the word to verify correctness
        debug_stored_word = {memory[addr_i+3], memory[addr_i+2], 
                             memory[addr_i+1], memory[addr_i]};
        $display("  Reconstructed word: 0x%08x", debug_stored_word);
        
        // Check if the stored word matches the expected value
        if (debug_stored_word != wdata_i) begin
            $display("  ENDIANNESS WARNING: Stored word 0x%08x doesn't match input 0x%08x", 
                    debug_stored_word, wdata_i);
            
            // Show corrected version
            debug_corrected = {debug_stored_word[7:0], debug_stored_word[15:8], 
                              debug_stored_word[23:16], debug_stored_word[31:24]};
            $display("  Endian-corrected: 0x%08x", debug_corrected);
        end
    end
end
`endif

endmodule
