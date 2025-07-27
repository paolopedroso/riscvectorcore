/*
 * Vector ALU TB
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 *
 */

module tb_valu;

    localparam DATA_WIDTH = 32;
    localparam ELEMENTS = 8;
    logic [3:0]            valu_op_in;
    logic [DATA_WIDTH-1:0] vrs2_data_in [ELEMENTS];
    logic [DATA_WIDTH-1:0] vrs1_data_in [ELEMENTS];
    logic [DATA_WIDTH-1:0] valu_res_o [ELEMENTS];

    valu dut (
        .valu_op_in(valu_op_in),
        .vrs1_data_in(vrs1_data_in),
        .vrs2_data_in(vrs2_data_in),
        .valu_res_o(valu_res_o)

    );

    initial begin

    valu_op_in = 0;
    vrs1_data_in = '{default: 32'd0};
    vrs2_data_in = '{default: 32'd0};

    #10;

    valu_op_in = 4'b0000;
    vrs1_data_in = '{32'd1,32'd2,32'd3,32'd4,32'd5,32'd6,32'd7,32'd8};
    vrs2_data_in = '{32'd1,32'd2,32'd3,32'd4,32'd5,32'd6,32'd7,32'd8};

    #10;
        for (int i = 0; i < ELEMENTS; i++) begin
            $display("Element %d: %d + %d = %d", i, vrs1_data_in[i], vrs2_data_in[i], valu_res_o[i]);
        end

    $finish;
    
    end

endmodule
