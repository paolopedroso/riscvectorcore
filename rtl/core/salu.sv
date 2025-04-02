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
    input logic [3:0] alu_op_in, // funct3

    output logic [DATA_WIDTH-1:0] alu_res_o,
    output logic zero_flag_o,
    output logic negative_flag_o,
    output logic overflow_flag_o
);

// Internal signals
logic [DATA_WIDTH-1:0] add_result;
logic [DATA_WIDTH-1:0] sub_result;
logic [DATA_WIDTH:0]   add_overflow_check; // Extra bit for overflow detection
logic [DATA_WIDTH:0]   sub_overflow_check; // Extra bit for overflow detection

// ALU operations as defined in the decoder
localparam logic [3:0] ADD   = 4'b0000;
localparam logic [3:0] SUB   = 4'b0001;
localparam logic [3:0] SLL   = 4'b0010;
localparam logic [3:0] SLT   = 4'b0011;
localparam logic [3:0] SLTU  = 4'b0100;
localparam logic [3:0] XOR   = 4'b0101;
localparam logic [3:0] SRL   = 4'b0110;
localparam logic [3:0] SRA   = 4'b0111;
localparam logic [3:0] OR    = 4'b1000;
localparam logic [3:0] AND   = 4'b1001;
localparam logic [3:0] BEQ   = 4'b1010;
localparam logic [3:0] BNE   = 4'b1011;
localparam logic [3:0] BLT   = 4'b1100;
localparam logic [3:0] BGE   = 4'b1101;
localparam logic [3:0] BLTU  = 4'b1110;
localparam logic [3:0] BGEU  = 4'b1111;

// Pre-compute common operations
assign add_result = rs1_data_i + rs2_data_i;
assign sub_result = rs1_data_i - rs2_data_i;

// Overflow detection signals
assign add_overflow_check = {rs1_data_i[DATA_WIDTH-1], rs1_data_i} +
                          {rs2_data_i[DATA_WIDTH-1], rs2_data_i};
assign sub_overflow_check = {rs1_data_i[DATA_WIDTH-1], rs1_data_i} -
                          {rs2_data_i[DATA_WIDTH-1], rs2_data_i};

// Result selection based on alu_op
always_comb begin
    alu_res_o = '0;
    zero_flag_o = 1'b0;
    negative_flag_o = 1'b0;
    overflow_flag_o = 1'b0;

    case (alu_op_in)
        ADD: begin
            alu_res_o = add_result;
            overflow_flag_o = (rs1_data_i[DATA_WIDTH-1] == rs2_data_i[DATA_WIDTH-1]) &&
                             (add_result[DATA_WIDTH-1] != rs1_data_i[DATA_WIDTH-1]);
        end

        SUB: begin
            alu_res_o = sub_result;
            overflow_flag_o = (rs1_data_i[DATA_WIDTH-1] != rs2_data_i[DATA_WIDTH-1]) &&
                             (sub_result[DATA_WIDTH-1] != rs1_data_i[DATA_WIDTH-1]);
        end

        SLL: begin
            alu_res_o = rs1_data_i << rs2_data_i[4:0]; // Shift amount limited to 5 bits
        end

        SLT: begin
            // Signed comparison
            if (rs1_data_i[DATA_WIDTH-1] != rs2_data_i[DATA_WIDTH-1])
                alu_res_o = rs1_data_i[DATA_WIDTH-1] ? 1 : 0;
            else
                alu_res_o = (rs1_data_i < rs2_data_i) ? 1 : 0;
        end

        SLTU: begin
            // Unsigned comparison
            alu_res_o = (rs1_data_i < rs2_data_i) ? 1 : 0;
        end

        XOR: begin
            alu_res_o = rs1_data_i ^ rs2_data_i;
        end

        SRL: begin
            alu_res_o = rs1_data_i >> rs2_data_i[4:0]; // Shift amount limited to 5 bits
        end

        SRA: begin
            // fix
            alu_res_o = $signed(rs1_data_i) >>> rs2_data_i[4:0];
        end

        OR: begin
            alu_res_o = rs1_data_i | rs2_data_i;
        end

        AND: begin
            alu_res_o = rs1_data_i & rs2_data_i;
        end

        // Branch conditions
        BEQ: begin
            alu_res_o = sub_result;
        end

        BNE: begin
            alu_res_o = sub_result;
        end

        BLT, BGE: begin
            // Signed comparison similar to SLT
            if (rs1_data_i[DATA_WIDTH-1] != rs2_data_i[DATA_WIDTH-1])
                alu_res_o = rs1_data_i[DATA_WIDTH-1] ? 1 : 0;
            else
                alu_res_o = (rs1_data_i < rs2_data_i) ? 1 : 0;
        end

        BLTU, BGEU: begin
            // Unsigned comparison similar to SLTU
            alu_res_o = (rs1_data_i < rs2_data_i) ? 1 : 0;
        end

        default: begin
            alu_res_o = '0;
        end
    endcase

    // Set flags based on result
    zero_flag_o = (alu_res_o == 0);
    negative_flag_o = alu_res_o[DATA_WIDTH-1];
end

endmodule
