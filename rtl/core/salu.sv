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

// Internal signals
logic [DATA_WIDTH-1:0] alu_res_d;
logic zero_flag_d, negative_flag_d, overflow_flag_d;

// ALU combinational logic
always_comb begin
    // Default values
    alu_res_d = '0;
    zero_flag_d = 1'b0;
    negative_flag_d = 1'b0;
    overflow_flag_d = 1'b0;

    case (alu_op_in)
        ADD: begin
            alu_res_d = rs1_data_i + rs2_data_i;
            overflow_flag_d = (rs1_data_i[DATA_WIDTH-1] == rs2_data_i[DATA_WIDTH-1]) &&
                              (alu_res_d[DATA_WIDTH-1] != rs1_data_i[DATA_WIDTH-1]);
            `ifdef SIMULATION
                $display("ALU ADD: 0x%h + 0x%h = 0x%h", rs1_data_i, rs2_data_i, alu_res_d);
            `endif
        end

        SUB: begin
            alu_res_d = rs1_data_i - rs2_data_i;
            overflow_flag_d = (rs1_data_i[DATA_WIDTH-1] != rs2_data_i[DATA_WIDTH-1]) &&
                              (alu_res_d[DATA_WIDTH-1] != rs1_data_i[DATA_WIDTH-1]);
            `ifdef SIMULATION
                $display("ALU SUB: 0x%h - 0x%h = 0x%h", rs1_data_i, rs2_data_i, alu_res_d);
            `endif
        end

        SLL: begin
            alu_res_d = rs1_data_i << rs2_data_i[4:0];
            `ifdef SIMULATION
                $display("ALU SLL: 0x%h << 0x%h = 0x%h", rs1_data_i, rs2_data_i[4:0], alu_res_d);
            `endif
        end

        SLT: begin
            alu_res_d = ($signed(rs1_data_i) < $signed(rs2_data_i)) ? 32'd1 : 32'd0;
            `ifdef SIMULATION
                $display("ALU SLT: 0x%h < 0x%h = %d", rs1_data_i, rs2_data_i, alu_res_d);
            `endif
        end

        SLTU: begin
            alu_res_d = (rs1_data_i < rs2_data_i) ? 32'd1 : 32'd0;
            `ifdef SIMULATION
                $display("ALU SLTU: 0x%h < 0x%h = %d", rs1_data_i, rs2_data_i, alu_res_d);
            `endif
        end

        XOR: begin
            alu_res_d = rs1_data_i ^ rs2_data_i;
            `ifdef SIMULATION
                $display("ALU XOR: 0x%h ^ 0x%h = 0x%h", rs1_data_i, rs2_data_i, alu_res_d);
            `endif
        end

        SRL: begin
            alu_res_d = rs1_data_i >> rs2_data_i[4:0];
            `ifdef SIMULATION
                $display("ALU SRL: 0x%h >> 0x%h = 0x%h", rs1_data_i, rs2_data_i[4:0], alu_res_d);
            `endif
        end

        SRA: begin
            alu_res_d = $signed(rs1_data_i) >>> rs2_data_i[4:0];
            `ifdef SIMULATION
                $display("ALU SRA: 0x%h >>> 0x%h = 0x%h", rs1_data_i, rs2_data_i[4:0], alu_res_d);
            `endif
        end

        OR: begin
            alu_res_d = rs1_data_i | rs2_data_i;
            `ifdef SIMULATION
                $display("ALU OR: 0x%h | 0x%h = 0x%h", rs1_data_i, rs2_data_i, alu_res_d);
            `endif
        end

        AND: begin
            alu_res_d = rs1_data_i & rs2_data_i;
            `ifdef SIMULATION
                $display("ALU AND: 0x%h & 0x%h = 0x%h", rs1_data_i, rs2_data_i, alu_res_d);
            `endif
        end

        BEQ: begin
            alu_res_d = rs1_data_i - rs2_data_i;
            zero_flag_d = (rs1_data_i == rs2_data_i);
            `ifdef SIMULATION
                $display("ALU BEQ: 0x%h == 0x%h = %d", rs1_data_i, rs2_data_i, zero_flag_d);
            `endif
        end

        BNE: begin
            alu_res_d = rs1_data_i - rs2_data_i;
            zero_flag_d = (rs1_data_i != rs2_data_i);
            `ifdef SIMULATION
                $display("ALU BNE: 0x%h != 0x%h = %d", rs1_data_i, rs2_data_i, zero_flag_d);
            `endif
        end

        BLT: begin
            alu_res_d = ($signed(rs1_data_i) < $signed(rs2_data_i)) ? 32'd1 : 32'd0;
            zero_flag_d = ($signed(rs1_data_i) < $signed(rs2_data_i));
            `ifdef SIMULATION
                $display("ALU BLT: 0x%h < 0x%h = %d", rs1_data_i, rs2_data_i, zero_flag_d);
            `endif
        end

        BGE: begin
            alu_res_d = ($signed(rs1_data_i) >= $signed(rs2_data_i)) ? 32'd1 : 32'd0;
            zero_flag_d = ($signed(rs1_data_i) >= $signed(rs2_data_i));
            `ifdef SIMULATION
                $display("ALU BGE: 0x%h >= 0x%h = %d", rs1_data_i, rs2_data_i, zero_flag_d);
            `endif
        end

        BLTU: begin
            alu_res_d = (rs1_data_i < rs2_data_i) ? 32'd1 : 32'd0;
            zero_flag_d = (rs1_data_i < rs2_data_i);
            `ifdef SIMULATION
                $display("ALU BLTU: 0x%h < 0x%h = %d", rs1_data_i, rs2_data_i, zero_flag_d);
            `endif
        end

        BGEU: begin
            alu_res_d = (rs1_data_i >= rs2_data_i) ? 32'd1 : 32'd0;
            zero_flag_d = (rs1_data_i >= rs2_data_i);
            `ifdef SIMULATION
                $display("ALU BGEU: 0x%h >= 0x%h = %d", rs1_data_i, rs2_data_i, zero_flag_d);
            `endif
        end

        default: begin
            alu_res_d = '0;
            `ifdef SIMULATION
                $display("ALU: Unknown operation code: %b", alu_op_in);
            `endif
        end
    endcase

    // Calculate common flags for non-branch operations
    negative_flag_d = alu_res_d[DATA_WIDTH-1];
    
    // Only update zero_flag for non-branch operations
    if (!(alu_op_in inside {BEQ, BNE, BLT, BGE, BLTU, BGEU})) begin
        zero_flag_d = (alu_res_d == 0);
    end
end

// Register outputs
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        alu_res_o <= '0;
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
