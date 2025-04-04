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

    input logic [DATA_WIDTH-1:0] rs1_data_i,
    input logic [DATA_WIDTH-1:0] rs2_data_i,
    input logic [3:0] alu_op_in,

    output logic [DATA_WIDTH-1:0] alu_res_o,
    output logic zero_flag_o,
    output logic negative_flag_o,
    output logic overflow_flag_o
);

localparam logic [3:0] 
    ADD   = 4'b0000,
    SUB   = 4'b0001,
    SLL   = 4'b0010,
    SLT   = 4'b0011,
    SLTU  = 4'b0100,
    XOR   = 4'b0101,
    SRL   = 4'b0110,
    SRA   = 4'b0111,
    OR    = 4'b1000,
    AND   = 4'b1001,
    BEQ   = 4'b1010,
    BNE   = 4'b1011,
    BLT   = 4'b1100,
    BGE   = 4'b1101,
    BLTU  = 4'b1110,
    BGEU  = 4'b1111;

logic [DATA_WIDTH-1:0] add_result;
logic [DATA_WIDTH-1:0] sub_result;
logic [DATA_WIDTH:0] add_overflow_check;
logic [DATA_WIDTH:0] sub_overflow_check;

logic [DATA_WIDTH-1:0] alu_res_d;
logic zero_flag_d;
logic negative_flag_d;
logic overflow_flag_d;

assign add_result = rs1_data_i + rs2_data_i;
assign sub_result = rs1_data_i - rs2_data_i;

assign add_overflow_check = {1'b0, rs1_data_i} + {1'b0, rs2_data_i};
assign sub_overflow_check = {1'b0, rs1_data_i} - {1'b0, rs2_data_i};

always_comb begin
    alu_res_d = '0;
    zero_flag_d = 1'b0;
    negative_flag_d = 1'b0;
    overflow_flag_d = 1'b0;

    case (alu_op_in)
        ADD: begin
            alu_res_d = add_result;
            overflow_flag_d = (rs1_data_i[DATA_WIDTH-1] == rs2_data_i[DATA_WIDTH-1]) &&
                             (add_result[DATA_WIDTH-1] != rs1_data_i[DATA_WIDTH-1]);
        end

        SUB: begin
            alu_res_d = sub_result;
            overflow_flag_d = (rs1_data_i[DATA_WIDTH-1] != rs2_data_i[DATA_WIDTH-1]) &&
                             (sub_result[DATA_WIDTH-1] != rs1_data_i[DATA_WIDTH-1]);
        end

        SLL: begin
            alu_res_d = rs1_data_i << rs2_data_i[4:0];
        end

        SLT: begin
            if (rs1_data_i[DATA_WIDTH-1] != rs2_data_i[DATA_WIDTH-1])
                alu_res_d = rs1_data_i[DATA_WIDTH-1] ? 32'd1 : 32'd0;
            else
                alu_res_d = (rs1_data_i < rs2_data_i) ? 32'd1 : 32'd0;
        end

        SLTU: begin
            alu_res_d = (rs1_data_i < rs2_data_i) ? 32'd1 : 32'd0;
        end

        XOR: begin
            alu_res_d = rs1_data_i ^ rs2_data_i;
        end

        SRL: begin
            alu_res_d = rs1_data_i >> rs2_data_i[4:0];
        end

        SRA: begin
            alu_res_d = $signed(rs1_data_i) >>> rs2_data_i[4:0];
        end

        OR: begin
            alu_res_d = rs1_data_i | rs2_data_i;
        end

        AND: begin
            alu_res_d = rs1_data_i & rs2_data_i;
        end

        BEQ: begin
            alu_res_d = sub_result;
            zero_flag_d = (sub_result == 0);
        end

        BNE: begin
            alu_res_d = sub_result;
            zero_flag_d = (sub_result != 0);
        end

        BLT, BGE: begin
            if (rs1_data_i[DATA_WIDTH-1] != rs2_data_i[DATA_WIDTH-1])
                alu_res_d = rs1_data_i[DATA_WIDTH-1] ? 32'd1 : 32'd0;
            else
                alu_res_d = (rs1_data_i < rs2_data_i) ? 32'd1 : 32'd0;
        end

        BLTU, BGEU: begin
            alu_res_d = (rs1_data_i < rs2_data_i) ? 32'd1 : 32'd0;
        end

        default: begin
            alu_res_d = '0;
        end
    endcase

    zero_flag_d = (alu_res_d == 0);
    negative_flag_d = alu_res_d[DATA_WIDTH-1];
end

always_ff @(posedge clk) begin
    if (!rst_n) begin
        alu_res_o <= 32'b0;
        zero_flag_o <= 1'b0;
        negative_flag_o <= 1'b0;
        overflow_flag_o <= 1'b0;
    end else begin
        alu_res_o <= alu_res_d;
        zero_flag_o <= zero_flag_d;
        negative_flag_o <= negative_flag_d;
        overflow_flag_o <= overflow_flag_d;
    end
end

endmodule
