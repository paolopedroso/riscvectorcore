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

   // Register file interface
   output logic [4:0]             rs1_addr_o,
   output logic [4:0]             rs2_addr_o,
   output logic [4:0]             rd_addr_o,
   output logic                   reg_write_en_o,

   // Immediate value generation
   output logic [DATA_WIDTH-1:0]  imm_value_o,
   output logic                   imm_valid_o,

   // Control signals
   output logic [3:0]             alu_op_o,
   output logic                   mem_read_o,
   output logic                   mem_write_o,
   output logic [1:0]             mem_size_o,
   output logic                   branch_o,
   output logic                   jump_o,
   output logic [1:0]             result_src_o,

   // Forwarding interface
   output logic                   uses_rs1_o,
   output logic                   uses_rs2_o
);

// Parsing
wire [6:0] opcode_d = instr_in[6:0];
wire [2:0] rd = instr_in[11:7];
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

    // Define Instruction Format
    case (opcode)
        7'b0110011: is_r_type = 1'b1; // R-type (register)
        7'b0010011: is_i_type = 1'b1; // I-type (immediate)
        7'b0000011: is_i_type = 1'b1; // I-type (load)
        7'b1100111: is_i_type = 1'b1; // I-type (JALR)
        7'b0100011: is_s_type = 1'b1; // S-type (store)
        7'b1100011: is_b_type = 1'b1; // B-type (branch)
        7'b0110111: is_u_type = 1'b1; // U-type (LUI)
        7'b0010111: is_u_type = 1'b1; // U-type (AUIPC)
        7'b1101111: is_j_type = 1'b1; // J-type (JAL)
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

// Immediate Generation
logic [DATA_WIDTH-1:0] i_imm, s_imm, b_imm, u_imm, j_imm;

// I-type immediate
assign i_imm = {{20{instr_in[31]}},
                    instr_in[31:20]};

// S-type immediate
assign s_imm = {{20{instr_in[31]}},
                    instr_in[31:25],
                    instr_in[11:7]};

// B-type immediate
assign b_imm = {{19{instr_in[31]}},
                    instr_in[31],
                    instr_in[7],
                    instr_in[30:25],
                    instr_in[11:8],
                    1'b0};

// U-type immediate
assign u_imm = {instr_in[31:12],
                12'b0};

// J-type immediate
assign j_imm = {{11{instr_in[31]}},
                instr_in[31],
                instr_in[19:12],
                instr_in[20],
                instr_in[30:21],
                1'b0};

// Select appropriate immediate based on instruction type
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

// Control Signal Generation
always_comb begin
    reg_write_en_o = 1'b0;
    mem_read_o = 1'b0;
    mem_write_o = 1'b0;
    mem_size_o = 2'b10;
    branch_o = 1'b0;
    jump_o = 1'b0;
    alu_op_o = 4'b0000; // Default: ADD
    result_src_o = 2'b00; // ALU result
    uses_rs1_o = 1'b0;
    uses_rs2_o = 1'b0;

    if (instr_valid) begin
         case (opcode)
            7'b0110011: begin // R-type
               reg_write_en_o = 1'b1;
               uses_rs1_o = 1'b1;
               uses_rs2_o = 1'b1;

               // ALU operation determined by funct3 and funct7
               unique case (funct3)
                  3'b000: alu_op_o = (funct7[5]) ? 4'b0001 : 4'b0000; // SUB : ADD
                  3'b001: alu_op_o = 4'b0010; // SLL
                  3'b010: alu_op_o = 4'b0011; // SLT
                  3'b011: alu_op_o = 4'b0100; // SLTU
                  3'b100: alu_op_o = 4'b0101; // XOR
                  3'b101: alu_op_o = (funct7[5]) ? 4'b0111 : 4'b0110; // SRA : SRL
                  3'b110: alu_op_o = 4'b1000; // OR
                  3'b111: alu_op_o = 4'b1001; // AND
               endcase
            end

            7'b0010011: begin // I-type ALU
               reg_write_en_o = 1'b1;
               uses_rs1_o = 1'b1;

               case (funct3)
                  3'b000: alu_op_o = 4'b0000; // ADDI
                  3'b001: alu_op_o = 4'b0010; // SLLI
                  3'b010: alu_op_o = 4'b0011; // SLTI
                  3'b011: alu_op_o = 4'b0100; // SLTUI
                  3'b100: alu_op_o = 4'b0101; // XORI
                  3'b101: alu_op_o = (funct7[5]) ? 4'b0111 : 4'b0110; // SRAI : SRLI
                  3'b110: alu_op_o = 4'b1000; // ORI
                  3'b111: alu_op_o = 4'b1001; // ANDI
               endcase
            end

            7'b0000011: begin // Load instructions
               reg_write_en_o = 1'b1;
               mem_read_o = 1'b1;
               uses_rs1_o = 1'b1;
               result_src_o = 2'b01; // Memory result

               // Memory size
               case (funct3)
                  3'b000: mem_size_o = 2'b00; // LB
                  3'b001: mem_size_o = 2'b01; // LH
                  3'b010: mem_size_o = 2'b10; // LW
                  3'b100: mem_size_o = 2'b00; // LBU
                  3'b101: mem_size_o = 2'b01; // LHU
                  default: mem_size_o = 2'b10;
               endcase
            end

            7'b0100011: begin // Store instructions
               mem_write_o = 1'b1;
               uses_rs1_o = 1'b1;
               uses_rs2_o = 1'b1;

               // Memory size
               case (funct3)
                  3'b000: mem_size_o = 2'b00; // SB
                  3'b001: mem_size_o = 2'b01; // SH
                  3'b010: mem_size_o = 2'b10; // SW
                  default: mem_size_o = 2'b10;
               endcase
            end

            7'b1100011: begin // Branch instructions
               branch_o = 1'b1;
               uses_rs1_o = 1'b1;
               uses_rs2_o = 1'b1;

               // Branch condition type
               case (funct3)
                  3'b000: alu_op_o = 4'b1010; // BEQ
                  3'b001: alu_op_o = 4'b1011; // BNE
                  3'b100: alu_op_o = 4'b1100; // BLT
                  3'b101: alu_op_o = 4'b1101; // BGE
                  3'b110: alu_op_o = 4'b1110; // BLTU
                  3'b111: alu_op_o = 4'b1111; // BGEU
                  default: alu_op_o = 4'b0000;
               endcase
            end

            7'b0110111: begin // LUI
               reg_write_en_o = 1'b1;
               alu_op_o = 4'b0000; // Pass through immediate
            end

            7'b0010111: begin // AUIPC
               reg_write_en_o = 1'b1;
               alu_op_o = 4'b0000; // ADD PC + immediate
            end

            7'b1101111: begin // JAL
               reg_write_en_o = 1'b1;
               jump_o = 1'b1;
               result_src_o = 2'b10; // PC+4
            end

            7'b1100111: begin // JALR
               reg_write_en_o = 1'b1;
               jump_o = 1'b1;
               uses_rs1_o = 1'b1;
               result_src_o = 2'b10; // PC+4
            end

            default: begin
               // Invalid instruction - all signals at default values
            end
         endcase
      end
   end

always_ff @(posedge clk) begin
    if (rst_n) begin
        r1data_o <= 5'b0;
        r2data_o <= 5'b0;
        opcode_o <= 7'b0;
        rd_addr_o <= 5'b0;
    end else begin
        r1data_o <= regs1;
        r2data_o <= regs2;
        opcode_o <= opcode_d;
        rd_addr_o <= rd;
    end
end


endmodule
