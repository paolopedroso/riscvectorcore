/*
 * Vector ALU
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 *
 */

module valu #(
    parameter int DATA_WIDTH = 32,
    parameter int ELEMENTS = 8
) (
    input logic [3:0] valu_op_in,
    input logic [DATA_WIDTH-1:0] vrs2_data_in [ELEMENTS],
    input logic [DATA_WIDTH-1:0] vrs1_data_in [ELEMENTS],
    output logic [DATA_WIDTH-1:0] valu_res_o [ELEMENTS]
);

localparam logic [3:0] 
        VADD   = 4'b0000,
        VSUB   = 4'b0001,
        VSLL   = 4'b0010,
        VSLT   = 4'b0011,
        VSLTU  = 4'b0100,
        VXOR   = 4'b0101,
        VSRL   = 4'b0110,
        VSRA   = 4'b0111,
        VOR    = 4'b1000,
        VAND   = 4'b1001,
        BEQ    = 4'b1010,
        BNE    = 4'b1011,
        BLT    = 4'b1100,
        BGE    = 4'b1101,
        BLTU   = 4'b1110,
        BGEU   = 4'b1111;

always_comb begin
    case(valu_op_in)
        VADD: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = vrs1_data_in[i] + vrs2_data_in[i];
            end
        end
        VSUB: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = vrs1_data_in[i] - vrs2_data_in[i];
            end
        end
        VSLL: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = vrs1_data_in[i] << vrs2_data_in[i][4:0];
            end
        end
        VSLT: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = ($signed(vrs1_data_in[i]) < $signed(vrs2_data_in[i])) ? 32'd1 : 32'd0;
            end
        end
        VSLTU: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = (vrs1_data_in[i] < vrs2_data_in[i]) ? 32'd1 : 32'd0;
            end
        end
        VXOR: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = vrs1_data_in[i] ^ vrs2_data_in[i];
            end
        end
        VSRL: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = vrs1_data_in[i] >> vrs2_data_in[i][4:0];
            end
        end
        VSRA: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = $signed(vrs1_data_in[i]) >>> vrs2_data_in[i][4:0];
            end
        end
        VOR: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = vrs1_data_in[i] | vrs2_data_in[i];
            end
        end
        VAND: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = vrs1_data_in[i] & vrs2_data_in[i];
            end
        end
        BEQ: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = (vrs1_data_in[i] == vrs2_data_in[i]) ? 32'd1 : 32'd0;
            end
        end
        BNE: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = (vrs1_data_in[i] != vrs2_data_in[i]) ? 32'd1 : 32'd0;
            end
        end
        BLT: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = ($signed(vrs1_data_in[i]) < $signed(vrs2_data_in[i])) ? 32'd1 : 32'd0;
            end
        end
        BGE: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = ($signed(vrs1_data_in[i]) >= $signed(vrs2_data_in[i])) ? 32'd1 : 32'd0;
            end
        end
        BLTU: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = (vrs1_data_in[i] < vrs2_data_in[i]) ? 32'd1 : 32'd0;
            end
        end
        BGEU: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = (vrs1_data_in[i] >= vrs2_data_in[i]) ? 32'd1 : 32'd0;
            end
        end
        default: begin
            for (int i=0; i<ELEMENTS; i++) begin
                valu_res_o[i] = '0;
            end
        end
    endcase
end

endmodule
