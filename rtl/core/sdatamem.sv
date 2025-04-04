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
// Mem array
logic [7:0] memory [MEM_SIZE-1:0];

// Read logic block
always_comb begin
    rdata_o = 32'b0;  // Default value
    if (mem_read_i) begin
        case (mem_size_i)
            2'b00: rdata_o = {{24{memory[addr_i][7]}}, // Byte
                memory[addr_i]};
            2'b01: rdata_o = {{16{memory[addr_i+1][7]}}, memory[addr_i+1], // Half word
                memory[addr_i]};
            2'b10, 2'b11: rdata_o = {memory[addr_i+3], memory[addr_i+2], // Word (Default from sdecoder)
                memory[addr_i+1], memory[addr_i]};
        endcase
    end
end

always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        for (int i = 0; i < MEM_SIZE; i++) begin
            memory[i] <= 8'h00;
        end
    end
    else if (mem_write_i) begin
        case (mem_size_i)
            2'b00: begin // Byte
                memory[addr_i] <= wdata_i[7:0];
            end
            
            2'b01: begin // Half word
                memory[addr_i]   <= wdata_i[7:0];
                memory[addr_i+1] <= wdata_i[15:8];
            end
            
            2'b10, 2'b11: begin // Word
                memory[addr_i]   <= wdata_i[7:0];
                memory[addr_i+1] <= wdata_i[15:8];
                memory[addr_i+2] <= wdata_i[23:16];
                memory[addr_i+3] <= wdata_i[31:24];
            end
        endcase
    end
end

endmodule
