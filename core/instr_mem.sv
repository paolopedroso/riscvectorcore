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
    // Memory array
    logic [DATA_WIDTH-1:0] imem [MEM_SIZE-1:0];
    
    // Read logic - enhanced with safety checks
    always_comb begin
        // Use memory index appropriate for word addressing
        // addr_i is in bytes, divide by 4 to get word address
        int mem_index;
        
        // First convert to unsigned to avoid negative indices
        // Then divide by 4 (shift right by 2) to get word address
        // Then mask to just the needed bits based on memory size
        mem_index = int'(($unsigned(addr_i) >> 2) & (MEM_SIZE - 1));
        
        // Debug output
        `ifdef SIMULATION
            $display("IMEM: Reading from address 0x%h, mem_index=%0d, instruction=0x%h", 
                     addr_i, mem_index, imem[mem_index]);
            if (addr_i > 32'h00000100) begin
                $display("WARNING: PC is outside expected program range! addr=0x%h", addr_i);
            end
        `endif
        
        // Return instruction at calculated index with bounds check
        if (mem_index < MEM_SIZE && mem_index >= 0) begin
            instr_o = imem[mem_index];
        end else begin
            instr_o = 32'h00000013;  // Return a NOP for out-of-bounds
            `ifdef SIMULATION
                $display("ERROR: Memory access out of bounds! index=%0d", mem_index);
            `endif
        end
    end

// Just ONE initialization block to avoid conflicts
initial begin
    for (int i = 0; i < MEM_SIZE; i++) begin
        imem[i] = 32'h0;
    end

    //========== Basic ALU and Immediate Operations ==========
    // Basic register setup
    imem[0] = 32'h00100093;  // addi x1, x0, 1    # x1 = 1
    imem[1] = 32'h00200113;  // addi x2, x0, 2    # x2 = 2
    imem[2] = 32'h00400193;  // addi x3, x0, 4    # x3 = 4
    imem[3] = 32'h00800213;  // addi x4, x0, 8    # x4 = 8
    
    // Test arithmetic operations
    imem[4] = 32'h002081b3;  // add  x3, x1, x2   # x3 = 1 + 2 = 3 (tests forwarding)
    imem[5] = 32'h40308233;  // sub  x4, x1, x3   # x4 = 1 - 3 = -2 (tests forwarding)
    
    // Test logical operations
    imem[6] = 32'h0020f2b3;  // and  x5, x1, x2   # x5 = 1 & 2 = 0
    imem[7] = 32'h0020e333;  // or   x6, x1, x2   # x6 = 1 | 2 = 3
    imem[8] = 32'h0020c3b3;  // xor  x7, x1, x2   # x7 = 1 ^ 2 = 3
    
    // Test shifts
    imem[9]  = 32'h00109413;  // slli x8, x1, 1    # x8 = 1 << 1 = 2
    imem[10] = 32'h0020d493;  // srli x9, x1, 2    # x9 = 1 >> 2 = 0
    imem[11] = 32'h4020d513;  // srai x10, x1, 2   # x10 = 1 >> 2 = 0 (arithmetic)
    
    //========== Memory Operations with Data Hazards ==========
    // Store operations - test immediate forwarding
    imem[12] = 32'h00302023;  // sw   x3, 0(x0)    # mem[0] = 3
    imem[13] = 32'h00402223;  // sw   x4, 4(x0)    # mem[4] = -2
    
    // Load operations - test load-use hazard
    imem[14] = 32'h00002583;  // lw   x11, 0(x0)   # x11 = mem[0] = 3
    imem[15] = 32'h00b00593;  // addi x11, x11, 0  # NOP-like to test load-use hazard
    
    // Load-Add forwarding test
    imem[16] = 32'h00402603;  // lw   x12, 4(x0)   # x12 = mem[4] = -2
    imem[17] = 32'h00c58633;  // add  x12, x11, x12 # x12 = 3 + (-2) = 1
    
    // Complex store/load sequence with back-to-back dependencies
    imem[18] = 32'h00c02423;  // sw   x12, 8(x0)   # mem[8] = 1
    imem[19] = 32'h00802683;  // lw   x13, 8(x0)   # x13 = mem[8] = 1
    imem[20] = 32'h00d106b3;  // add  x13, x2, x13 # x13 = 2 + 1 = 3
    imem[21] = 32'h00d02623;  // sw   x13, 12(x0)  # mem[12] = 3
    
    //========== Different Memory Access Sizes ==========
    // Byte operations
    imem[22] = 32'h0fd00713;  // addi x14, x0, 253 # x14 = 253 (0xFD)
    imem[23] = 32'h00e02823;  // sw   x14, 16(x0)  # mem[16] = 253
    imem[24] = 32'h01000783;  // lb   x15, 16(x0)  # x15 = mem[16](byte) = -3 (sign extended)
    imem[25] = 32'h01004803;  // lbu  x16, 16(x0)  # x16 = mem[16](byte) = 253 (zero extended)
    
    // Halfword operations
    imem[26] = 32'haaaab837;  // lui  x16, 0xaaaab # Upper 20 bits to make big value
    imem[27] = 32'h01002a23;  // sw   x16, 20(x0)  # mem[20] = big value
    imem[28] = 32'h01401883;  // lh   x17, 20(x0)  # x17 = mem[20](halfword) = sign extended
    imem[29] = 32'h01405903;  // lhu  x18, 20(x0)  # x18 = mem[20](halfword) = zero extended
    
    //========== Test Branches ==========
    // Branch test setup
    imem[30] = 32'h00300993;  // addi x19, x0, 3   # x19 = 3
    imem[31] = 32'h00500a13;  // addi x20, x0, 5   # x20 = 5
    
    // Test branch equal (not taken)
    imem[32] = 32'h01498a63;  // beq  x19, x20, 20 # Skip if x19 == x20 (should not branch)
    
    // Continue with normal execution
    imem[33] = 32'h01400a93;  // addi x21, x0, 20  # x21 = 20 (only executed if branch not taken)
    
    // Test branch not equal (taken)
    imem[34] = 32'h01499463;  // bne  x19, x20, 8  # Branch if x19 != x20 (should branch)
    imem[35] = 32'hfff00b13;  // addi x22, x0, -1  # x22 = -1 (should be skipped)
    
    // Branch target
    imem[36] = 32'h00a00b13;  // addi x22, x0, 10  # x22 = 10 (only executed if branch taken)
    
    // Test load after branch
    imem[37] = 32'h01002b83;  // lw   x23, 16(x0)  # x23 = mem[16] = 253
    
    //========== Test Complex Forwarding Cases ==========
    // Multiple consecutive data hazards
    imem[38] = 32'h015a0c13;  // addi x24, x20, 21 # x24 = 5 + 21 = 26
    imem[39] = 32'h018c0c93;  // addi x25, x24, 24 # x25 = 26 + 24 = 50
    imem[40] = 32'h019c8d13;  // addi x26, x25, 25 # x26 = 50 + 25 = 75
    imem[41] = 32'h01ad0d93;  // addi x27, x26, 26 # x27 = 75 + 26 = 101
    
    // Store-load-store sequence
    imem[42] = 32'h01b02e23;  // sw   x27, 28(x0)  # mem[28] = 101
    imem[43] = 32'h01c02e83;  // lw   x29, 28(x0)  # x29 = mem[28] = 101
    imem[44] = 32'h01d00e13;  // addi x28, x0, 29  # x28 = 29
    imem[45] = 32'h01c02f23;  // sw   x28, 30(x0)  # mem[30] = 29
    
    // Read from register being written
    imem[46] = 32'h01c00f13;  // addi x30, x0, 28  # x30 = 28
    imem[47] = 32'h01e00f93;  // addi x31, x0, 30  # x31 = 30
    imem[48] = 32'h01ef0f33;  // add  x30, x30, x30 # x30 = 28 + 28 = 56
    
    //========== Final test and terminate ==========
    // Test jump and link
    imem[49] = 32'h018000ef;  // jal  x1, 24       # Jump to inst[55], x1 = PC+4 = 53
    
    // Instructions that should be skipped
    imem[50] = 32'h00000013;  // addi x0, x0, 0    # NOP (should be skipped)
    imem[51] = 32'h00000013;  // addi x0, x0, 0    # NOP (should be skipped)
    imem[52] = 32'h00000013;  // addi x0, x0, 0    # NOP (should be skipped)
    imem[53] = 32'h00000013;  // addi x0, x0, 0    # NOP (should be skipped)
    imem[54] = 32'h00000013;  // addi x0, x0, 0    # NOP (should be skipped)
    
    // Jump target (instruction 55)
    imem[55] = 32'h00008067;  // jalr x0, 0(x1)    # Return to inst[50], don't update x1
    
    // Final test - should be executed after return
    imem[56] = 32'h12345837;  // lui  x16, 0x12345 # Final register update test
    
    // Terminate with EBREAK
    imem[57] = 32'h00100073;  // EBREAK            # End simulation
end

endmodule
