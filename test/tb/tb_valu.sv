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

    task automatic get_arithmetic(
        input  logic [3:0] arithmetic,
        output string      arithmetic_str_out
    );
    case (arithmetic)
        VADD: arithmetic_str_out = "+";
        VSUB: arithmetic_str_out = "-";
        VSLL: arithmetic_str_out = "<<";
        VSLT: arithmetic_str_out = "<";
        VSLTU: arithmetic_str_out = "<u";
        VXOR: arithmetic_str_out = "^";
        VSRL: arithmetic_str_out = ">>";
        VSRA: arithmetic_str_out = ">>>";
        VOR: arithmetic_str_out = "|";
        VAND: arithmetic_str_out = "&";
        BEQ: arithmetic_str_out = "==";
        BNE: arithmetic_str_out = "!=";
        BLT: arithmetic_str_out = "<";
        BGE: arithmetic_str_out = ">=";
        BLTU: arithmetic_str_out = "<u";
        BGEU: arithmetic_str_out = ">=u";
        default: arithmetic_str_out = "?";
    endcase
    endtask

    task automatic arithmetic_helper(
        input  logic [3:0]                arithmetic,
        input  logic [DATA_WIDTH-1:0]     rs1_data_in [ELEMENTS],
        input  logic [DATA_WIDTH-1:0]     rs2_data_in [ELEMENTS],
    );
    string arith_str;
    valu_op_in = arithmetic;
    get_arithmetic(arithmetic, arith_str);

    #10;
    $display("Arithmetic: %s", arith_str);
    for (int i = 0; i < ELEMENTS; i++) begin
        $display("Element %0d: %0d %s %0d = %0d",
                i, rs1_data_in[i], arith_str, rs2_data_in[i], valu_res_o[i]);
    end
    $display("");
    endtask

    initial begin

    // valu_op_in = 0;
    vrs1_data_in = '{default: 32'd0};
    vrs2_data_in = '{default: 32'd0};

    #10;

    // valu_op_in = 4'b0000;
    vrs1_data_in = '{32'd1,32'd2,32'd3,32'd4,32'd5,32'd6,32'd7,32'd8};
    vrs2_data_in = '{32'd1,32'd2,32'd3,32'd4,32'd5,32'd6,32'd7,32'd8};

    arithmetic_helper(VADD, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(VSUB, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(VSLL, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(VSLT, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(VSLTU, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(VXOR, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(VSRL, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(VSRA, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(VOR, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(VAND, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(BEQ, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(BNE, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(BLT, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(BGE, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(BLTU, vrs1_data_in, vrs2_data_in);
    arithmetic_helper(BGEU, vrs1_data_in, vrs2_data_in);

    $finish;
    
    end

endmodule
