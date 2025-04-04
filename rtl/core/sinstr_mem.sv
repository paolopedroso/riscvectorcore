/*
 * Instruction Memory
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module sinstr_mem #(
    parameter int DATA_WIDTH = 32,
    parameter int MEM_SIZE = 1024
) (
    input logic clk,
    input logic rst_n,
    input logic [DATA_WIDTH-1:0] addr_i,
    output logic [DATA_WIDTH-1:0] instr_o
);

// Memory array
logic [DATA_WIDTH-1:0] imem [MEM_SIZE-1:0];

// Read logic - combinational
always_comb begin
    instr_o = imem[addr_i[DATA_WIDTH-1:2]]; // Word-aligned access
end

// For Verilator, initialize memory using file I/O
initial begin
    for (int i = 0; i < MEM_SIZE; i++) begin
        imem[i] = 32'h0;
    end
    // Example test program
    imem[0] = 32'h00000013; // NOP (addi x0, x0, 0)
    imem[1] = 32'h00100093; // addi x1, x0, 1
    imem[2] = 32'h00200113; // addi x2, x0, 2
    imem[3] = 32'h002081b3; // add x3, x1, x2  (x3 = 3)
    imem[4] = 32'h00312233; // slt x4, x2, x3  (x4 = 1)
    imem[5] = 32'h0041a2b3; // slt x5, x3, x4  (x5 = 0)
    imem[6] = 32'h00000013; // NOP
    imem[7] = 32'h00000013; // NOP
end
    
endmodule
