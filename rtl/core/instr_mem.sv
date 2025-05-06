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
            if (addr_i > 32'h00001000) begin
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

// Initialize memory with a small test program
initial begin
    for (int i = 0; i < MEM_SIZE; i++) begin
        imem[i] = 32'h0;
    end

    // Simple test program - RISC-V instructions
    imem[0] = 32'h00100093;  // addi x1, x0, 1    # x1 = 1
    imem[1] = 32'h00200113;  // addi x2, x0, 2    # x2 = 2
    imem[2] = 32'h002081b3;  // add x3, x1, x2    # x3 = 3
    imem[3] = 32'h00219213;  // slli x4, x3, 2    # x4 = 12
    imem[4] = 32'h00a27293;  // andi x5, x4, 10   # x5 = 8
    imem[5] = 32'h00302023;  // sw x3, 0(x0)      # store x3 to address 0
    imem[6] = 32'h00002303;  // lw x6, 0(x0)      # load from address 0 to x6 (should be 3)
    imem[7] = 32'h00431393;  // slli x7, x6, 4    # x7 = x6 << 4 = 3 << 4 = 48
    imem[8] = 32'h00100413;  // addi x8, x0, 1    # x8 = 1
    imem[9] = 32'h02a00493;  // addi x9, x0, 42   # x9 = 42
    imem[10] = 32'h00300533;  // add x10, x0, x3   # x10 = 3
    imem[11] = 32'h00200593;  // addi x11, x0, 2   # x11 = 2
    imem[12] = 32'h00400613;  // addi x12, x0, 4   # x12 = 4
    imem[13] = 32'h0000006f;  // jal x0, 0        # Infinite loop to current PC (safer than branch)
    
    `ifdef SIMULATION
        $display("Instruction memory initialized with test program");
        for (int i = 0; i < 14; i++) begin
            $display("  imem[%0d] = 0x%h", i, imem[i]);
        end
    `endif
end
endmodule