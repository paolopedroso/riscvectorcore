/*
 * Program Counter
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module program_counter #(
    parameter int DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst_n,
    input logic pc_write,        // Added for pipeline stall control
    input logic branch_en,
    input logic jmp_en,
    input logic [DATA_WIDTH-1:0] imm,
    input logic [DATA_WIDTH-1:0] pc_i,

    output logic [DATA_WIDTH-1:0] pc_out
);

logic [DATA_WIDTH-1:0] pc_d;

always_comb begin
    pc_d = pc_i + 32'd4;
    if (jmp_en) begin
        pc_d = pc_i + imm;
    end else if (branch_en) begin
        pc_d = pc_i + imm;
    end
end

always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        pc_out <= 32'b0;
    end else if (pc_write) begin  // Only update PC when not stalled
        pc_out <= pc_d;
    end
    // When pc_write is 0, PC holds its value (stall)
end

endmodule
