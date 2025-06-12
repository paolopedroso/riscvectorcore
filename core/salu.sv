/*
 * Enhanced Scalar ALU with Detailed Debug
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 *
 */

module salu #(
    parameter int DATA_WIDTH = 32
) (
    input logic [DATA_WIDTH-1:0] rs1_data_i,
    input logic [DATA_WIDTH-1:0] rs2_data_i,
    input logic [3:0] alu_op_in,

    output logic [DATA_WIDTH-1:0] alu_res_o,
    output logic zero_flag_o,
    output logic negative_flag_o,
    output logic overflow_flag_o
);

// ALU operation codes
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

// ALU combinational logic with enhanced debug
always_comb begin
    // Default values
    alu_res_o = '0;
    zero_flag_o = 1'b0;
    negative_flag_o = 1'b0;
    overflow_flag_o = 1'b0;

    case (alu_op_in)
        ADD: begin
            alu_res_o = rs1_data_i + rs2_data_i;
            overflow_flag_o = (rs1_data_i[DATA_WIDTH-1] == rs2_data_i[DATA_WIDTH-1]) &&
                              (alu_res_o[DATA_WIDTH-1] != rs1_data_i[DATA_WIDTH-1]);
        end

        SUB: begin
            alu_res_o = rs1_data_i - rs2_data_i;
            overflow_flag_o = (rs1_data_i[DATA_WIDTH-1] != rs2_data_i[DATA_WIDTH-1]) &&
                              (alu_res_o[DATA_WIDTH-1] != rs1_data_i[DATA_WIDTH-1]);
        end

        SLL: begin
            alu_res_o = rs1_data_i << rs2_data_i[4:0];
        end

        SLT: begin
            alu_res_o = ($signed(rs1_data_i) < $signed(rs2_data_i)) ? 32'd1 : 32'd0;
        end

        SLTU: begin
            alu_res_o = (rs1_data_i < rs2_data_i) ? 32'd1 : 32'd0;
        end

        XOR: begin
            alu_res_o = rs1_data_i ^ rs2_data_i;
        end

        SRL: begin
            alu_res_o = rs1_data_i >> rs2_data_i[4:0];
        end

        SRA: begin
            alu_res_o = $signed(rs1_data_i) >>> rs2_data_i[4:0];
        end

        OR: begin
            alu_res_o = rs1_data_i | rs2_data_i;
        end

        AND: begin
            alu_res_o = rs1_data_i & rs2_data_i;
        end

        BEQ: begin
            alu_res_o = rs1_data_i - rs2_data_i;
            zero_flag_o = (rs1_data_i == rs2_data_i);
        end

        BNE: begin
            alu_res_o = rs1_data_i - rs2_data_i;
            zero_flag_o = (rs1_data_i != rs2_data_i);
        end

        BLT: begin
            alu_res_o = ($signed(rs1_data_i) < $signed(rs2_data_i)) ? 32'd1 : 32'd0;
            zero_flag_o = ($signed(rs1_data_i) < $signed(rs2_data_i));
        end

        BGE: begin
            alu_res_o = ($signed(rs1_data_i) >= $signed(rs2_data_i)) ? 32'd1 : 32'd0;
            zero_flag_o = ($signed(rs1_data_i) >= $signed(rs2_data_i));
        end

        BLTU: begin
            alu_res_o = (rs1_data_i < rs2_data_i) ? 32'd1 : 32'd0;
            zero_flag_o = (rs1_data_i < rs2_data_i);
        end

        BGEU: begin
            alu_res_o = (rs1_data_i >= rs2_data_i) ? 32'd1 : 32'd0;
            zero_flag_o = (rs1_data_i >= rs2_data_i);
        end

        default: begin
            alu_res_o = '0;

            // Debug Unknown Instruction
            // `ifdef SIMULATION
            //     $display("ALU: Unknown operation code: %b", alu_op_in);
            // `endif
        
        end
    endcase

    // Calculate common flags for non-branch operations
    negative_flag_o = alu_res_o[DATA_WIDTH-1];
    
    // Only update zero_flag for non-branch operations
    if (!(alu_op_in inside {BEQ, BNE, BLT, BGE, BLTU, BGEU})) begin
        zero_flag_o = (alu_res_o == 0);
    end
    
    // Show output values
    // `ifdef SIMULATION
    //     $display("ALU OUTPUT: alu_res_o = 0x%h (bytes: %h %h %h %h)", 
    //             alu_res_o,
    //             alu_res_o[7:0], alu_res_o[15:8], 
    //             alu_res_o[23:16], alu_res_o[31:24]);
    //     $display("ALU FLAGS: zero=%b, negative=%b, overflow=%b", 
    //             zero_flag_o, negative_flag_o, overflow_flag_o);
    // `endif

end

endmodule
