/*
 * Control Unit with Vector Extension Support
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

   // Scalar control outputs
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
   output logic                   jalr_o,

   // Vector control outputs
   output logic                   is_vector_op_o,
   output logic                   vreg_write_en_o,
   output logic [3:0]             valu_op_o,
   output logic                   vmem_read_o,
   output logic                   vmem_write_o,
   output logic                   uses_vrs1_o,
   output logic                   uses_vrs2_o,
   output logic [1:0]             vector_width_o,
   output logic                   vector_mask_en_o
);

localparam logic [6:0] 
    // Vector
    OP_V       = 7'b1010111,  
    OP_VL      = 7'b0000111,  
    OP_VS      = 7'b0100111,
    
    // Scalar
    OP_REG     = 7'b0110011,
    OP_IMM     = 7'b0010011,
    OP_LOAD    = 7'b0000011,  
    OP_STORE   = 7'b0100011,  
    OP_BRANCH  = 7'b1100011,  
    OP_LUI     = 7'b0110111,
    OP_AUIPC   = 7'b0010111,
    OP_JAL     = 7'b1101111,
    OP_JALR    = 7'b1100111; 

localparam logic [3:0]
    S_ADD = 4'b0000;

always_comb begin
    // Default scalar control signals
    reg_write_en_o = 1'b0;
    mem_read_o = 1'b0;
    mem_write_o = 1'b0;
    mem_size_o = 2'b10;
    branch_o = 1'b0;
    jump_o = 1'b0;
    alu_op_o = S_ADD;
    result_src_o = 2'b00;
    uses_rs1_o = 1'b0;
    uses_rs2_o = 1'b0;
    jalr_o = 1'b0;
    mem_unsigned_o = 1'b0;

    // Default vector control signals
    is_vector_op_o = 1'b0;
    vreg_write_en_o = 1'b0;
    valu_op_o = S_ADD;
    vmem_read_o = 1'b0;
    vmem_write_o = 1'b0;
    uses_vrs1_o = 1'b0;
    uses_vrs2_o = 1'b0;
    vector_width_o = 2'b10;  // Default 32-bit
    vector_mask_en_o = 1'b0;

    if (instr_valid) begin
        case (opcode_in)
            // Scalar operations (existing logic)
            OP_REG: begin // R-type
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
                    default: alu_op_o = 4'b0000; 
                endcase
            end

            OP_IMM: begin // I-type
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
                    default: alu_op_o = 4'b0000;
                endcase
            end

            OP_LOAD: begin  // Load instructions
                reg_write_en_o = 1'b1;
                mem_read_o = 1'b1;
                uses_rs1_o = 1'b1;
                result_src_o = 2'b01;

                case (funct3_in)
                    3'b000: begin
                        mem_size_o = 2'b00; // LB
                        mem_unsigned_o = 1'b0;
                    end
                    3'b001: begin
                        mem_size_o = 2'b01; // LH
                        mem_unsigned_o = 1'b0;
                    end
                    3'b010: begin
                        mem_size_o = 2'b10; // LW
                        mem_unsigned_o = 1'b0;
                    end
                    3'b100: begin
                        mem_size_o = 2'b00; // LBU
                        mem_unsigned_o = 1'b1;
                    end
                    3'b101: begin
                        mem_size_o = 2'b01; // LHU
                        mem_unsigned_o = 1'b1;
                    end
                    default: begin
                        mem_size_o = 2'b10;
                        mem_unsigned_o = 1'b0;
                    end
                endcase
            end

            OP_STORE: begin // Store instructions
                mem_write_o = 1'b1;
                uses_rs1_o = 1'b1;
                uses_rs2_o = 1'b1;

                case (funct3_in)
                    3'b000: mem_size_o = 2'b00; // SB
                    3'b001: mem_size_o = 2'b01; // SH
                    3'b010: mem_size_o = 2'b10; // SW
                    default: mem_size_o = 2'b10;
                endcase
            end

            OP_BRANCH: begin // Branch instructions
                branch_o = 1'b1;
                uses_rs1_o = 1'b1;
                uses_rs2_o = 1'b1;

                case (funct3_in)
                    3'b000: alu_op_o = 4'b1010; // BEQ
                    3'b001: alu_op_o = 4'b1011; // BNE
                    3'b100: alu_op_o = 4'b1100; // BLT
                    3'b101: alu_op_o = 4'b1101; // BGE
                    3'b110: alu_op_o = 4'b1110; // BLTU
                    3'b111: alu_op_o = 4'b1111; // BGEU
                    default: alu_op_o = 4'b0000;
                endcase
            end

            OP_LUI: begin // LUI
                reg_write_en_o = 1'b1;
                alu_op_o = 4'b0000;
            end

            OP_AUIPC: begin // AUIPC
                reg_write_en_o = 1'b1;
                alu_op_o = 4'b0000;
            end

            OP_JAL: begin  // JAL
                reg_write_en_o = 1'b1;
                jump_o = 1'b1;
                result_src_o = 2'b10;
            end

            OP_JALR: begin // JALR
                reg_write_en_o = 1'b1;
                jump_o = 1'b1;
                uses_rs1_o = 1'b1;
                result_src_o = 2'b10;
                jalr_o = 1'b1;
            end

            // Vector operations
            OP_V: begin // Vector arithmetic operations
                is_vector_op_o = 1'b1;
                vreg_write_en_o = 1'b1;
                uses_vrs1_o = 1'b1;
                uses_vrs2_o = 1'b1;

                // Decode vector width from instruction
                case (instr_in[14:12]) // funct3 for vector width
                    3'b000: vector_width_o = 2'b00; // 8-bit
                    3'b001: vector_width_o = 2'b01; // 16-bit
                    3'b010: vector_width_o = 2'b10; // 32-bit
                    3'b011: vector_width_o = 2'b11; // 64-bit
                    default: vector_width_o = 2'b10;
                endcase

                // Decode vector ALU operation from funct6
                case (instr_in[31:26]) // funct6
                    6'b000000: valu_op_o = 4'b0000; // VADD
                    6'b000010: valu_op_o = 4'b0001; // VSUB
                    6'b100101: valu_op_o = 4'b0010; // VSLL
                    6'b011000: valu_op_o = 4'b0011; // VSLT
                    6'b011001: valu_op_o = 4'b0100; // VSLTU
                    6'b001001: valu_op_o = 4'b0101; // VXOR
                    6'b101000: valu_op_o = 4'b0110; // VSRL
                    6'b101001: valu_op_o = 4'b0111; // VSRA
                    6'b001010: valu_op_o = 4'b1000; // VOR
                    6'b001001: valu_op_o = 4'b1001; // VAND
                    default: valu_op_o = 4'b0000;
                endcase

                // Check for mask enable
                vector_mask_en_o = instr_in[25]; // vm bit
            end

            OP_VL: begin // Vector load
                is_vector_op_o = 1'b1;
                vmem_read_o = 1'b1;
                vreg_write_en_o = 1'b1;
                uses_rs1_o = 1'b1; // Base address

                // Decode element width
                case (instr_in[14:12])
                    3'b000: vector_width_o = 2'b00; // 8-bit
                    3'b101: vector_width_o = 2'b01; // 16-bit
                    3'b110: vector_width_o = 2'b10; // 32-bit
                    3'b111: vector_width_o = 2'b11; // 64-bit
                    default: vector_width_o = 2'b10;
                endcase
            end

            OP_VS: begin // Vector store
                is_vector_op_o = 1'b1;
                vmem_write_o = 1'b1;
                uses_rs1_o = 1'b1; // Base address
                uses_vrs2_o = 1'b1; // Data to store

                // Decode element width
                case (instr_in[14:12])
                    3'b000: vector_width_o = 2'b00; // 8-bit
                    3'b101: vector_width_o = 2'b01; // 16-bit
                    3'b110: vector_width_o = 2'b10; // 32-bit
                    3'b111: vector_width_o = 2'b11; // 64-bit
                    default: vector_width_o = 2'b10;
                endcase
            end

            default: begin
                // Unknown instruction - all outputs remain at default values
            end
        endcase
    end
end

endmodule