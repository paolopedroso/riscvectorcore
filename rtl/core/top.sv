    /*
     * Small Vector Floating Point RISC-V Core
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

program_counter (
    .clk(clk),
    .rst_n(rst_n),
    .instr(instr),
    .branch_en(branch_en),
    .jmp_en(jmp_en),
    .imm(imm),
    .pc_in(pc_in),

    .pc_out(pc_out)
);

sdecode (
    .clk(clk),
    .rst_n(rst_n),
    .instr_in(instr_in),
    .instr_valid(instr_valid),

    .rs1_addr_o(rs1_addr_o),
    .rs2_addr_o(rs2_addr_o),
    .rd_addr_o(rd_addr_o),
    .reg_write_en_o(reg_write_en_o),

    .imm_value_o(imm_value_o),
    .imm_valid_o(imm_valid_o),

    .alu_op_o(alu_op_o),
    .mem_read_o(mem_read_o),
    .mem_write_o(mem_write_o),
    .mem_size_o(mem_size_o),
    .branch_o(branch_o),
    .jump_o(jump_o),
    .result_src_o(result_src_o),

    .uses_rs1_o(uses_rs1_o),
    .uses_rs2_o(uses_rs2_o)
);


endmodule
