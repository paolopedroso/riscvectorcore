/*
 * Scalar ALU TB
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 *
 */

module tb_salu;

    localparam DATA_WIDTH = 32;
    logic [3:0]            alu_op_in;
    logic [DATA_WIDTH-1:0] rs1_data_i;
    logic [DATA_WIDTH-1:0] rs2_data_i;
    logic [DATA_WIDTH-1:0] alu_res_o;
    logic                  zero_flag_o;
    logic                  negative_flag_o;
    logic                  overflow_flag_o;

    salu dut (
        .alu_op_in(alu_op_in),
        .rs1_data_i(rs1_data_i),
        .rs2_data_i(rs2_data_i),
        .alu_res_o(alu_res_o),
        .zero_flag_o(zero_flag_o),
        .negative_flag_o(negative_flag_o),
        .overflow_flag_o(overflow_flag_o)
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

    task automatic get_arithmetic(
        input  logic [3:0] arithmetic,
        output string      arithmetic_str_out
    );
    case (arithmetic)
        ADD: arithmetic_str_out = "+";
        SUB: arithmetic_str_out = "-";
        SLL: arithmetic_str_out = "<<";
        SLT: arithmetic_str_out = "<";
        SLTU: arithmetic_str_out = "<u";
        XOR: arithmetic_str_out = "^";
        SRL: arithmetic_str_out = ">>";
        SRA: arithmetic_str_out = ">>>";
        OR: arithmetic_str_out = "|";
        AND: arithmetic_str_out = "&";
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
        input  logic [DATA_WIDTH-1:0]     rs1_data,
        input  logic [DATA_WIDTH-1:0]     rs2_data
    );
    string arith_str;

    alu_op_in = arithmetic;
    rs1_data_i = rs1_data;
    rs2_data_i = rs2_data;
    get_arithmetic(arithmetic, arith_str);

    #10;
    $display("Arithmetic: %s", arith_str);
    $display("%0d %s %0d = %0d (flags: Z=%b N=%b V=%b)",
            rs1_data, arith_str, rs2_data, alu_res_o, 
            zero_flag_o, negative_flag_o, overflow_flag_o);
    $display("");
    endtask

    initial begin

    alu_op_in = 4'b0000;
    rs1_data_i = 32'd0;
    rs2_data_i = 32'd0;

    #10;

    arithmetic_helper(ADD, 32'd5, 32'd3);
    arithmetic_helper(SUB, 32'd5, 32'd3);
    arithmetic_helper(SLL, 32'd5, 32'd2);
    arithmetic_helper(SLT, 32'd5, 32'd3);
    arithmetic_helper(SLTU, 32'd5, 32'd3);
    arithmetic_helper(XOR, 32'd5, 32'd3);
    arithmetic_helper(SRL, 32'd20, 32'd2);
    arithmetic_helper(SRA, 32'hfffffff0, 32'd2);
    arithmetic_helper(OR, 32'd5, 32'd3);
    arithmetic_helper(AND, 32'd5, 32'd3);
    arithmetic_helper(BEQ, 32'd5, 32'd5);
    arithmetic_helper(BNE, 32'd5, 32'd3);
    arithmetic_helper(BLT, 32'd3, 32'd5);
    arithmetic_helper(BGE, 32'd5, 32'd3);
    arithmetic_helper(BLTU, 32'd3, 32'd5);
    arithmetic_helper(BGEU, 32'd5, 32'd3);

    $finish;
    
    end

endmodule