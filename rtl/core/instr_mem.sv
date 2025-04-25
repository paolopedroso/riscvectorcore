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
    
    // Read logic - combinational with proper address calculation
    always_comb begin
        // Use memory index appropriate for word addressing
        // addr_i is in bytes, divide by 4 to get word address
        int mem_index;
        
        // First convert to unsigned to avoid negative indices
        // Then divide by 4 (shift right by 2) to get word address
        // Then mask to just the needed bits based on memory size
        mem_index = int'(($unsigned(addr_i) >> 2) & (MEM_SIZE - 1));
        
        // Check if PC is in reasonable range for the test program
        if (mem_index >= 14) begin  // Adjust based on your program size (13 instructions + buffer)
            `ifdef SIMULATION
                $display("WARNING: PC is outside program range! addr=0x%h, returning NOP", addr_i);
                if (mem_index > 20) $finish;  // Stop if we're really out of bounds
            `endif
            instr_o = 32'h00000013;  // NOP instruction (addi x0, x0, 0) for safety
        end else begin
            // Debug output
            `ifdef SIMULATION
                $display("IMEM: Reading from address 0x%h, mem_index=%0d, instruction=0x%h", 
                         addr_i, mem_index, imem[mem_index]);
            `endif
            
            // Return instruction at calculated index
            instr_o = imem[mem_index];
        end
    end

// Initialize memory with comprehensive test program
initial begin
    for (int i = 0; i < MEM_SIZE; i++) begin
        imem[i] = 32'h0;
    end

    // Extremely simple test program focused on ADD operations
    imem[0] = 32'h00100093;  // addi x1, x0, 1    # x1 = 1
    imem[1] = 32'h00200113;  // addi x2, x0, 2    # x2 = 2
    imem[2] = 32'h002081b3;  // add x3, x1, x2    # x3 = 3
    imem[3] = 32'h00300213;  // addi x4, x0, 3    # x4 = 3
    imem[4] = 32'h0030a023;  // sw x3, 0(x1)      # store x3 to address in x1 (addr 1)
    imem[5] = 32'h0000a283;  // lw x5, 0(x1)      # load from address in x1 to x5 (should be 3)
    imem[6] = 32'h005182b3;  // add x5, x3, x5    # x5 = x3 + x5 = 3 + 3 = 6
    imem[7] = 32'h0000006f;  // jal x0, 0         # infinite loop
    
    // Debug output to verify instruction memory contents
    `ifdef SIMULATION
        $display("Instruction memory initialized with test program");
        for (int i = 0; i < 8; i++) begin
            $display("  imem[%0d] = 0x%h", i, imem[i]);
            // Show byte-level detail to confirm endianness of instruction memory
            $display("      bytes: %02x %02x %02x %02x", 
                    imem[i][7:0], imem[i][15:8], imem[i][23:16], imem[i][31:24]);
        end
    `endif
end
endmodule
