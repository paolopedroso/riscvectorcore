/*
 * Scalar ALU
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 *
 */

module salu #(
    parameter int DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst_n,

    input logic [31:0] rs1_data_i,
    input logic [31:0] rs2_data_i,
    input logic [3:0] alu_op_in, // funct3

    output logic [31:0] alu_res_o
);

// Internal signals
logic [DATA_WIDTH-1:0] add_result;
logic [DATA_WIDTH-1:0] sub_result;
logic [DATA_WIDTH:0]   add_overflow_check; // Extra bit for overflow detection
logic [DATA_WIDTH:0]   sub_overflow_check; // Extra bit for overflow detection

// ALU operations as defined in the decoder
localparam logic ALU_ADD   = 4'b0000;
localparam logic ALU_SUB   = 4'b0001;
localparam logic ALU_SLL   = 4'b0010;
localparam logic ALU_SLT   = 4'b0011;
localparam logic ALU_SLTU  = 4'b0100;
localparam logic ALU_XOR   = 4'b0101;
localparam logic ALU_SRL   = 4'b0110;
localparam logic ALU_SRA   = 4'b0111;
localparam logic ALU_OR    = 4'b1000;
localparam logic ALU_AND   = 4'b1001;
localparam logic ALU_BEQ   = 4'b1010;
localparam logic ALU_BNE   = 4'b1011;
localparam logic ALU_BLT   = 4'b1100;
localparam logic ALU_BGE   = 4'b1101;
localparam logic ALU_BLTU  = 4'b1110;
localparam logic ALU_BGEU  = 4'b1111;



endmodule
