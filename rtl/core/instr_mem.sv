/*
 * Instruction Memory
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module instr_mem #(
    parameter int DATA_WIDTH = 32,
    parameter int MEM_SIZE = 1024
) (
    input logic clk,
    input logic rst_n,
    input logic [DATA_WIDTH-1:0] addr_i,
    output logic [DATA_WIDTH-1:0] instr_o
);
logic [DATA_WIDTH-1:0] imem [MEM_SIZE-1:0];

always_comb begin
    instr_o = imem[addr_i[DATA_WIDTH-1:2]];
end

initial begin
    for (int i = 0; i < MEM_SIZE; i++) begin
        imem[i] = 32'h0;
    end
    
    // Basic ALU operations
    imem[0] = 32'h00000013;  // addi x0, x0, 0  (NOP)
    imem[1] = 32'h00100093;  // addi x1, x0, 1  (x1 = 1)
    imem[2] = 32'h00200113;  // addi x2, x0, 2  (x2 = 2)
    imem[3] = 32'h002081b3;  // add x3, x1, x2  (x3 = 3)
    imem[4] = 32'h4020d213;  // srai x4, x1, 2  (x4 = 0)
    imem[5] = 32'h0020f293;  // andi x5, x1, 2  (x5 = 0)
    imem[6] = 32'h0020e313;  // ori x6, x1, 2   (x6 = 3)
    imem[7] = 32'h0020c393;  // xori x7, x1, 2  (x7 = 3)
    imem[8] = 32'h00239413;  // slli x8, x7, 2  (x8 = 12)
    imem[9] = 32'h0041a493;  // slti x9, x3, 4  (x9 = 1)
    
    // Data hazard testing
    imem[10] = 32'h00100513;  // addi x10, x0, 1   (x10 = 1)
    imem[11] = 32'h00150513;  // addi x10, x10, 1  (RAW hazard, x10 = 2)
    imem[12] = 32'h00150513;  // addi x10, x10, 1  (RAW hazard, x10 = 3)
    imem[13] = 32'h00058593;  // addi x11, x11, 0  (Read-after-read, x11 = 0)
    
    // Load-use hazard testing
    imem[14] = 32'h00a02623;  // sw x10, 12(x0)    (Store x10=3 to address 12)
    imem[15] = 32'h00c02603;  // lw x12, 12(x0)    (Load from address 12 into x12)
    imem[16] = 32'h00160613;  // addi x12, x12, 1  (Load-use hazard, x12 = 4)
    imem[17] = 32'h00000013;  // nop
    
    // Branch testing
    imem[18] = 32'h00100693;  // addi x13, x0, 1   (x13 = 1)
    imem[19] = 32'h00168693;  // addi x13, x13, 1  (x13 = 2)
    imem[20] = 32'h00c68863;  // beq x13, x12, 16  (Branch to +16 if x13==x12, not taken)
    imem[21] = 32'h00170713;  // addi x14, x14, 1  (x14 = 1)
    imem[22] = 32'h00068713;  // addi x14, x13, 0  (x14 = 2)
    imem[23] = 32'hfe0696e3;  // bne x13, x0, -20  (Branch to -20 if x13!=0, taken)
    
    // Jump testing
    imem[24] = 32'h00c0006f;  // jal x0, 12        (Jump to PC+12, link to x0)
    imem[25] = 32'h00000013;  // nop (should be skipped)
    imem[26] = 32'h00000013;  // nop (should be skipped)
    imem[27] = 32'h00000013;  // nop (should be skipped)
    imem[28] = 32'h00100793;  // addi x15, x0, 1   (x15 = 1)
    imem[29] = 32'h000780e7;  // jalr x1, 0(x15)   (Jump to x15, link to x1)
    
    // Memory access testing
    imem[30] = 32'h00100813;  // addi x16, x0, 1   (x16 = 1)
    imem[31] = 32'h01002023;  // sw x16, 0(x0)     (Store word)
    imem[32] = 32'h00800893;  // addi x17, x0, 8   (x17 = 8)
    imem[33] = 32'h01101023;  // sh x17, 0(x0)     (Store halfword)
    imem[34] = 32'h00001903;  // lh x18, 0(x0)     (Load halfword, x18 = 8)
    imem[35] = 32'h00004903;  // lbu x18, 0(x0)    (Load byte unsigned, x18 = 8)
    imem[36] = 32'h00100993;  // addi x19, x0, 1   (x19 = 1)
    imem[37] = 32'h00e00a13;  // addi x20, x0, 14  (x20 = 14)
    imem[38] = 32'h01402023;  // sw x20, 0(x0)     (Store word)
    imem[39] = 32'h00004a83;  // lbu x21, 0(x0)    (Load byte unsigned, x21 = 14)
    
    // Forwarding unit testing
    imem[40] = 32'h00100b13;  // addi x22, x0, 1   (x22 = 1)
    imem[41] = 32'h002b0b13;  // addi x22, x22, 2  (MEM to EX forward, x22 = 3)
    imem[42] = 32'h000b8b93;  // addi x23, x23, 0  (No forward needed)
    imem[43] = 32'h002b8b93;  // addi x23, x23, 2  (x23 = 2)
    imem[44] = 32'h016b0c33;  // add x24, x22, x22 (MEM to EX forward, x24 = 6)
    imem[45] = 32'h017c0c33;  // add x24, x24, x23 (WB to EX forward, x24 = 8)
    
    // Edge cases
    imem[46] = 32'h80000cb7;  // lui x25, 0x80000  (x25 = 0x80000000)
    imem[47] = 32'hffffd37;   // lui x26, 0xFFFFF  (x26 = 0xFFFFF000)
    imem[48] = 32'h001d0d33;  // add x26, x26, x1  (x26 = 0xFFFFF001)
    imem[49] = 32'h01ac8db3;  // add x27, x25, x26 (Overflow test, x27 = 0x7FFFF001)
    imem[50] = 32'h003b9e33;  // sll x28, x23, x3  (Variable shift, x28 = 16)
end
endmodule