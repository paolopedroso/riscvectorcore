/*
 * Control Unit
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module control #(
   parameter int DATA_WIDTH = 32
) (
   input  logic [DATA_WIDTH-1:0]  instr_in,
   input  logic                   instr_valid,
   input  logic [6:0]             opcode_in,
   input  logic [2:0]             funct3_in,
   input  logic [6:0]             funct7_in,

   output logic                   reg_write_en_o,
   output logic [3:0]             alu_op_o,
   output logic                   mem_read_o,
   output logic                   mem_write_o,
   output logic [1:0]             mem_size_o,
   output logic                   mem_unsigned_o,
   output logic                   branch_o,
   output logic                   jump_o,
   output logic [1:0]             result_src_o,
   output logic                   uses_rs1_o,
   output logic                   uses_rs2_o,
   output logic                   jalr_o
);

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
    jalr_o = 1'b0;

    // LUI case
    mem_unsigned_o = 1'b0;

    if (instr_valid) begin
        case (opcode_in)
            7'b0110011: begin
                reg_write_en_o = 1'b1;
                uses_rs1_o = 1'b1;
                uses_rs2_o = 1'b1;

                unique case (funct3_in)
                    3'b000: alu_op_o = (funct7_in[5]) ? 4'b0001 : 4'b0000; // ADD/SUB
                    3'b001: alu_op_o = 4'b0010; // SLL
                    3'b010: alu_op_o = 4'b0011; // SLT
                    3'b011: alu_op_o = 4'b0100; // SLTU
                    3'b100: alu_op_o = 4'b0101; // XOR
                    3'b101: alu_op_o = (funct7_in[5]) ? 4'b0111 : 4'b0110; // SRL/SRA
                    3'b110: alu_op_o = 4'b1000; // OR
                    3'b111: alu_op_o = 4'b1001; // AND
                    default: alu_op_o = 4'b0000; // Default case
                endcase
            end

            7'b0010011: begin
                reg_write_en_o = 1'b1;
                uses_rs1_o = 1'b1;

                unique case (funct3_in)
                    3'b000: alu_op_o = 4'b0000; // ADDI
                    3'b001: alu_op_o = 4'b0010; // SLLI
                    3'b010: alu_op_o = 4'b0011; // SLTI
                    3'b011: alu_op_o = 4'b0100; // SLTIU
                    3'b100: alu_op_o = 4'b0101; // XORI
                    3'b101: alu_op_o = (funct7_in[5]) ? 4'b0111 : 4'b0110; // SRLI/SRAI
                    3'b110: alu_op_o = 4'b1000; // ORI
                    3'b111: alu_op_o = 4'b1001; // ANDI
                    default: alu_op_o = 4'b0000; // Default case
                endcase
            end

            7'b0000011: begin  // Load instructions
                reg_write_en_o = 1'b1;
                mem_read_o = 1'b1;
                uses_rs1_o = 1'b1;
                result_src_o = 2'b01;

                case (funct3_in)
                    3'b000: begin
                        mem_size_o = 2'b00; // LB
                        mem_unsigned_o = 1'b0; // signed
                    end
                    3'b001: begin
                        mem_size_o = 2'b01; // LH
                        mem_unsigned_o = 1'b0; // signed
                    end
                    3'b010: begin
                        mem_size_o = 2'b10; // LW
                        mem_unsigned_o = 1'b0; // signed (doesn't matter for word)
                    end
                    3'b100: begin
                        mem_size_o = 2'b00; // LBU
                        mem_unsigned_o = 1'b1; // unsigned
                    end
                    3'b101: begin
                        mem_size_o = 2'b01; // LHU
                        mem_unsigned_o = 1'b1; // unsigned
                    end
                    default: begin
                        mem_size_o = 2'b10; // LW
                        mem_unsigned_o = 1'b0;
                    end
                endcase
            end

            7'b0100011: begin
                mem_write_o = 1'b1;
                uses_rs1_o = 1'b1;
                uses_rs2_o = 1'b1;

                case (funct3_in)
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

                case (funct3_in)
                    3'b000: alu_op_o = 4'b1010;
                    3'b001: alu_op_o = 4'b1011;
                    3'b100: alu_op_o = 4'b1100;
                    3'b101: alu_op_o = 4'b1101;
                    3'b110: alu_op_o = 4'b1110;
                    3'b111: alu_op_o = 4'b1111;
                    default: alu_op_o = 4'b0000;
                endcase
            end

            7'b0110111: begin // LUI
                reg_write_en_o = 1'b1;
                alu_op_o = 4'b0000;
            end

            7'b0010111: begin // AUIPC
                reg_write_en_o = 1'b1;
                alu_op_o = 4'b0000;
            end

            7'b1101111: begin  // JAL
                reg_write_en_o = 1'b1;
                jump_o = 1'b1;
                result_src_o = 2'b10;  // Select PC+4 for rd write
            end

            7'b1100111: begin
                reg_write_en_o = 1'b1;
                jump_o = 1'b1;
                uses_rs1_o = 1'b1;
                result_src_o = 2'b10;

                // jalr flag
                jalr_o = 1'b1;
            end

            default: begin
            end
        endcase
    end
end

endmodule
