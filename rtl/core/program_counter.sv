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
    input logic [DATA_WIDTH-1:0] instr,
    input logic branch_en,
    input logic jmp_en,
    input logic [DATA_WIDTH-1:0] imm,
    input logic [DATA_WIDTH-1:0] pc_in,

    output logic [DATA_WIDTH-1:0] pc_out
);

    logic [DATA_WIDTH-1:0] pc_d;

    always_comb begin
        pc_d = pc_in + 32'd4;
        if (jmp_en) begin
            pc_d = pc_in + imm;
        end else if (branch_en) begin
            pc_d = pc_in + imm;
        end
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc_out <= 32'b0;
        end else begin
            pc_out <= pc_d;
        end
    end

endmodule
