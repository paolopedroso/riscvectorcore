/*
 * Small Vector RISC-V Core
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 *
 */

module top #(
    parameter int DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst_n
);

// Internal signals
logic [DATA_WIDTH-1:0] pc_out;
logic [DATA_WIDTH-1:0] instr;
logic                  instr_valid;

// Decoder outputs
logic [4:0]             rs1_addr;
logic [4:0]             rs2_addr;
logic [4:0]             rd_addr;
logic                   reg_write_en;
logic [DATA_WIDTH-1:0]  imm_value;
logic                   imm_valid;
logic [3:0]             alu_op;
logic                   mem_read;
logic                   mem_write;
logic [1:0]             mem_size;
logic                   branch;
logic                   jump;
logic [1:0]             result_src;
logic                   uses_rs1;
logic                   uses_rs2;

// Register file signals
logic [DATA_WIDTH-1:0]  rs1_data;
logic [DATA_WIDTH-1:0]  rs2_data;
logic [DATA_WIDTH-1:0]  rd_data;

// ALU signals
logic [DATA_WIDTH-1:0]  alu_result;
logic                   zero_flag;
logic                   negative_flag;
logic                   overflow_flag;

// Memory signals
logic [DATA_WIDTH-1:0]  mem_rdata;

// Instruction fetch from memory
assign instr_valid = 1'b1; // For simplicity

program_counter pc_inst (
    .clk(clk),
    .rst_n(rst_n),
    .instr(instr),
    .branch_en(branch && zero_flag),
    .jmp_en(jump),
    .imm(imm_value),
    .pc_in(pc_out),

    .pc_out(pc_out)
);

sdecode sdecode_inst (
    .clk(clk),
    .rst_n(rst_n),
    .instr_in(instr),
    .instr_valid(instr_valid),

    .rs1_addr_o(rs1_addr),
    .rs2_addr_o(rs2_addr),
    .rd_addr_o(rd_addr),
    .reg_write_en(reg_write_en),

    .imm_value_o(imm_value),
    .imm_valid_o(imm_valid),

    .alu_op_o(alu_op), // funct3
    .mem_read_o(mem_read),
    .mem_write_o(mem_write),
    .mem_size_o(mem_size),
    .branch_o(branch),
    .jump_o(jump),
    .result_src_o(result_src),

    .uses_rs1_o(uses_rs1),
    .uses_rs2_o(uses_rs2)
);

sregfile sregfile_inst (
    .clk(clk),
    .rst_n(rst_n),

    // Linking Decode Stage
    .rs1_addr_i(rs1_addr),
    .rs1_data_o(rs1_data),

    .rs2_addr_i(rs2_addr),
    .rs2_data_o(rs2_data),

    // write back inputs
    .rd_addr_i(rd_addr),
    .rd_data_i(rd_data),
    .reg_write_en_i(reg_write_en)
);

// Write-back mux
always_comb begin
    case (result_src)
        2'b00: rd_data = alu_result;      // ALU result
        2'b01: rd_data = mem_rdata;       // Memory load
        2'b10: rd_data = pc_out + 4;      // PC+4 for jumps
        default: rd_data = alu_result;
    endcase
end

salu salu_inst (
    .clk(clk),
    .rst_n(rst_n),

    .rs1_data_in(rs1_data),
    .rs2_data_in(imm_valid ? imm_value : rs2_data),  // Mux for immediate
    .alu_op_in(alu_op),

    .result_out(alu_result),
    .zero_flag_o(zero_flag),
    .negative_flag_o(negative_flag),
    .overflow_flag_o(overflow_flag)
);



endmodule
