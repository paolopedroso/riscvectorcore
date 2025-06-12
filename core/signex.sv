/*
 * Sign Extension
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module signex #(
    parameter int DATA_WIDTH = 32
)(
    input logic [6:0] opcode_in,
    input logic [DATA_WIDTH-1:0] instr_in,

    output logic imm_valid_o,
    output logic [DATA_WIDTH-1:0] imm_value_o
);

logic is_i_type, is_s_type, is_b_type, is_u_type, is_j_type;

always_comb begin
    is_i_type = 1'b0;
    is_s_type = 1'b0;
    is_b_type = 1'b0;
    is_u_type = 1'b0;
    is_j_type = 1'b0;

    case (opcode_in)
        7'b0010011: is_i_type = 1'b1;
        7'b0000011: is_i_type = 1'b1;
        7'b1100111: is_i_type = 1'b1;
        7'b0100011: is_s_type = 1'b1;
        7'b1100011: is_b_type = 1'b1;
        7'b0110111: is_u_type = 1'b1;
        7'b0010111: is_u_type = 1'b1;
        7'b1101111: is_j_type = 1'b1;
        default: begin
            is_i_type = 1'b0;
            is_s_type = 1'b0;
            is_b_type = 1'b0;
            is_u_type = 1'b0;
            is_j_type = 1'b0;
        end
    endcase
end

logic [DATA_WIDTH-1:0] i_imm, s_imm, b_imm, u_imm, j_imm;

assign i_imm = {{20{instr_in[31]}}, instr_in[31:20]};

assign s_imm = {{20{instr_in[31]}}, 
               instr_in[31:25], 
               instr_in[11:7]};

assign b_imm = {{19{instr_in[31]}}, 
                instr_in[31], 
                instr_in[7], 
                instr_in[30:25], 
                instr_in[11:8], 
                1'b0};

assign u_imm = {instr_in[31:12], 12'b0};

assign j_imm = {{12{instr_in[31]}}, 
               instr_in[19:12], 
               instr_in[20], 
               instr_in[30:21], 
               1'b0};

always_comb begin
    if (is_i_type)
        imm_value_o = i_imm;
    else if (is_s_type)
        imm_value_o = s_imm;
    else if (is_b_type)
        imm_value_o = b_imm;
    else if (is_u_type)
        imm_value_o = u_imm;
    else if (is_j_type)
        imm_value_o = j_imm;
    else
        imm_value_o = 32'b0;

    imm_valid_o = is_i_type | is_s_type | is_b_type | is_u_type | is_j_type;
end

endmodule
