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

// Debug output
`ifdef SIMULATION
    always @(posedge clk) begin
        if (mem_write_i) begin
            if (addr_i >= MEM_SIZE - 3) begin
                $display("ERROR: MEMORY WRITE OUT OF BOUNDS: Address=0x%h", addr_i);
            end else begin
                $display("MEMORY WRITE: Address=0x%h, Size=%0d, Data=0x%h",
                        addr_i, mem_size_i, wdata_i);
            end
        end
        if (mem_read_i) begin
            if (addr_i >= MEM_SIZE - 3) begin
                $display("ERROR: MEMORY READ OUT OF BOUNDS: Address=0x%h", addr_i);
            end else begin
                $display("MEMORY READ: Address=0x%h, Size=%0d",
                        addr_i, mem_size_i);
            end
        end
    end
`endif

// Read logic block - fixed sign extension with bounds checking
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
                end
                
                2'b01: begin // Half word (16-bit)
                    // Properly sign-extend the halfword
                    logic [15:0] half_data;
                    half_data = {memory[addr_i+1], memory[addr_i]};
                    rdata_o = {{16{half_data[15]}}, half_data};
                end
                
                2'b10, 2'b11: begin // Word (32-bit)
                    rdata_o = {memory[addr_i+3], memory[addr_i+2], 
                              memory[addr_i+1], memory[addr_i]};
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
                        $display("MEMORY: Writing byte 0x%h to address 0x%h", wdata_i[7:0], addr_i);
                    `endif
                end
                
                2'b01: begin // Half word
                    memory[addr_i]   <= wdata_i[7:0];
                    memory[addr_i+1] <= wdata_i[15:8];
                    `ifdef SIMULATION
                        $display("MEMORY: Writing halfword 0x%h to address 0x%h", wdata_i[15:0], addr_i);
                    `endif
                end
                
                2'b10, 2'b11: begin // Word
                    memory[addr_i]   <= wdata_i[7:0];
                    memory[addr_i+1] <= wdata_i[15:8];
                    memory[addr_i+2] <= wdata_i[23:16];
                    memory[addr_i+3] <= wdata_i[31:24];
                    `ifdef SIMULATION
                        $display("MEMORY: Writing word 0x%h to address 0x%h", wdata_i, addr_i);
                    `endif
                end
            endcase
        end
    end
end

endmodule
