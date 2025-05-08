/*
 *
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

/*

Vector DATA_WIDTH 32 bit encoding

31        25 24    20 19    15 14    12 11        7 6         0
+----------+--------+--------+--------+-----------+-----------+
| funct7   | vs2    | vs1    | funct3 | vd        | opcode    |
+----------+--------+--------+--------+-----------+-----------+
  7 bits     5 bits   5 bits   3 bits   5 bits      7 bits

*/

module sdecode #(
   parameter int DATA_WIDTH = 32
) (
   input  logic                   clk,
   input  logic                   rst_n,
   input  logic [DATA_WIDTH-1:0]  instr_in,
   input  logic                   instr_valid,

   output logic [4:0]             rs1_addr_o,
   output logic [4:0]             rs2_addr_o,
   output logic [4:0]             rd_addr_o,
   output logic                   reg_write_en_o,

   output logic [DATA_WIDTH-1:0]  imm_value_o,
   output logic                   imm_valid_o,

   output logic [3:0]             alu_op_o,
   output logic                   mem_read_o,
   output logic                   mem_write_o,
   output logic [1:0]             mem_size_o,
   output logic                   branch_o,
   output logic                   jump_o,
   output logic [1:0]             result_src_o,

   output logic                   uses_rs1_o,
   output logic                   uses_rs2_o
);

wire [6:0] opcode = instr_in[6:0];
wire [4:0] rd = instr_in[11:7];
wire [2:0] funct3 = instr_in[14:12];
wire [4:0] regs1 = instr_in[19:15];
wire [4:0] regs2 = instr_in[24:20];
wire [6:0] funct7 = instr_in[31:25];

logic is_r_type, is_i_type, is_s_type, is_b_type, is_u_type, is_j_type;

always_comb begin
    is_r_type = 1'b0;
    is_i_type = 1'b0;
    is_s_type = 1'b0;
    is_b_type = 1'b0;
    is_u_type = 1'b0;
    is_j_type = 1'b0;

    case (opcode)
        7'b0110011: is_r_type = 1'b1;
        7'b0010011: is_i_type = 1'b1;
        7'b0000011: is_i_type = 1'b1;
        7'b1100111: is_i_type = 1'b1;
        7'b0100011: is_s_type = 1'b1;
        7'b1100011: is_b_type = 1'b1;
        7'b0110111: is_u_type = 1'b1;
        7'b0010111: is_u_type = 1'b1;
        7'b1101111: is_j_type = 1'b1;
        default: begin
            is_r_type = 1'b0;
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

always_comb begin
    reg_write_en_o = 1'b0;
    mem_read_o = 1'b0;
    mem_write_o = 1'b0;
    mem_size_o = 2'b10;
    branch_o = 1'b0;
    jump_o = 1'b0;
    alu_op_o = 4'b0000;
    result_src_o = 2'b00;
    uses_rs1_o = 1'b0;
    uses_rs2_o = 1'b0;

    if (instr_valid) begin
        case (opcode)
            7'b0110011: begin
                `ifdef SIMULATION
                 if (instr_valid && opcode == 7'b0110011 && funct3 == 3'b000 && !funct7[5]) begin
                     $display("ADD INSTRUCTION DETECTED: rs1=x%0d, rs2=x%0d, rd=x%0d", 
                             regs1, regs2, rd);
                     $display("Control signals: reg_write=%b, imm_valid=%b, alu_op=0x%h", 
                             reg_write_en_o, imm_valid_o, alu_op_o);
                end
                 `endif
                reg_write_en_o = 1'b1;
                uses_rs1_o = 1'b1;
                uses_rs2_o = 1'b1;

                unique case (funct3)
                    3'b000: alu_op_o = (funct7[5]) ? 4'b0001 : 4'b0000;
                    3'b001: alu_op_o = 4'b0010;
                    3'b010: alu_op_o = 4'b0011;
                    3'b011: alu_op_o = 4'b0100;
                    3'b100: alu_op_o = 4'b0101;
                    3'b101: alu_op_o = (funct7[5]) ? 4'b0111 : 4'b0110;
                    3'b110: alu_op_o = 4'b1000;
                    3'b111: alu_op_o = 4'b1001;
                    default: alu_op_o = 4'b0000;
                endcase
            end

            7'b0010011: begin
                reg_write_en_o = 1'b1;
                uses_rs1_o = 1'b1;

                unique case (funct3)
                    3'b000: alu_op_o = 4'b0000;
                    3'b001: alu_op_o = 4'b0010;
                    3'b010: alu_op_o = 4'b0011;
                    3'b011: alu_op_o = 4'b0100;
                    3'b100: alu_op_o = 4'b0101;
                    3'b101: alu_op_o = (funct7[5]) ? 4'b0111 : 4'b0110;
                    3'b110: alu_op_o = 4'b1000;
                    3'b111: alu_op_o = 4'b1001;
                    default: alu_op_o = 4'b0000;
                endcase
            end

            7'b0000011: begin
                reg_write_en_o = 1'b1;
                mem_read_o = 1'b1;
                uses_rs1_o = 1'b1;
                result_src_o = 2'b01;

                case (funct3)
                    3'b000: mem_size_o = 2'b00;
                    3'b001: mem_size_o = 2'b01;
                    3'b010: mem_size_o = 2'b10;
                    3'b100: mem_size_o = 2'b00;
                    3'b101: mem_size_o = 2'b01;
                    default: mem_size_o = 2'b10;
                endcase
            end

            7'b0100011: begin
                mem_write_o = 1'b1;
                uses_rs1_o = 1'b1;
                uses_rs2_o = 1'b1;

                case (funct3)
                    3'b000: mem_size_o = 2'b00;
                    3'b001: mem_size_o = 2'b01;
                    3'b010: mem_size_o = 2'b10;
                    default: mem_size_o = 2'b10;
                endcase
            end

            7'b1100011: begin
                branch_o = 1'b1;
                uses_rs1_o = 1'b1;
                uses_rs2_o = 1'b1;

                case (funct3)
                    3'b000: alu_op_o = 4'b1010;
                    3'b001: alu_op_o = 4'b1011;
                    3'b100: alu_op_o = 4'b1100;
                    3'b101: alu_op_o = 4'b1101;
                    3'b110: alu_op_o = 4'b1110;
                    3'b111: alu_op_o = 4'b1111;
                    default: alu_op_o = 4'b0000;
                endcase
            end

            7'b0110111: begin
                reg_write_en_o = 1'b1;
                alu_op_o = 4'b0000;
            end

            7'b0010111: begin
                reg_write_en_o = 1'b1;
                alu_op_o = 4'b0000;
            end

            7'b1101111: begin  // JAL
                reg_write_en_o = 1'b1;
                jump_o = 1'b1;
                result_src_o = 2'b10;  // Select PC+4 for rd write
                `ifdef SIMULATION
                    $display("DECODE: JAL instruction detected, rd=x%0d, imm=0x%h", rd, j_imm);
                `endif
            end

            7'b1100111: begin
                reg_write_en_o = 1'b1;
                jump_o = 1'b1;
                uses_rs1_o = 1'b1;
                result_src_o = 2'b10;
            end

            default: begin
            end
        endcase
    end
        // Read register addresses directly from the instruction
    rs1_addr_o = instr_in[19:15];  // Extract rs1 (bits 19:15)
    rs2_addr_o = instr_in[24:20];  // Extract rs2 (bits 24:20)
    rd_addr_o = instr_in[11:7];    // Extract rd (bits 11:7)
    
    // Add debug to verify correct extraction
    `ifdef SIMULATION
        if (instr_valid) begin
            // Debug for ADD instruction specifically
            if (instr_in == 32'h002081b3) begin  // ADD x3, x1, x2
                $display("DECODE DEBUG: ADD instruction detected");
                $display("  rs1=x%0d (bits 19:15 = 0x%h)", rs1_addr_o, instr_in[19:15]);
                $display("  rs2=x%0d (bits 24:20 = 0x%h)", rs2_addr_o, instr_in[24:20]);
                $display("  rd=x%0d (bits 11:7 = 0x%h)", rd_addr_o, instr_in[11:7]);
                
                // Verify bit fields explicitly
                if (rs1_addr_o != 5'd1 || rs2_addr_o != 5'd2 || rd_addr_o != 5'd3) begin
                    $display("ERROR: ADD instruction incorrectly decoded!");
                    $display("Expected: rs1=x1, rs2=x2, rd=x3");
                    $display("Actual: rs1=x%0d, rs2=x%0d, rd=x%0d", rs1_addr_o, rs2_addr_o, rd_addr_o);
                    $display("Instruction: 0x%h", instr_in);
                    $display("Bits 19:15 = 0b%5b", instr_in[19:15]);
                    $display("Bits 24:20 = 0b%5b", instr_in[24:20]);
                    $display("Bits 11:7 = 0b%5b", instr_in[11:7]);
                end
            end
        end
    `endif
end

// always_ff @(posedge clk) begin
//     if (!rst_n) begin
//         rs1_addr_o <= 5'b0;
//         rs2_addr_o <= 5'b0;
//         rd_addr_o <= 5'b0;
//     end else begin
//         rs1_addr_o <= regs1;
//         rs2_addr_o <= regs2;
//         rd_addr_o <= rd;
//     end
// end

endmodule
