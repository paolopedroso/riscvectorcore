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
    // Generated from $ASM_FILE on $(date)
    // First reset all memory locations to zero
    for (int i = 0; i < MEM_SIZE; i++) begin
        imem[i] = 32'h0;
    end

    imem[0] = 32'h00100093;  // Address 0x0
    imem[1] = 32'h00200113;  // Address 0x4
    imem[2] = 32'h00400193;  // Address 0x8
    imem[3] = 32'h00800213;  // Address 0xc
    imem[4] = 32'h002081b3;  // Address 0x10
    imem[5] = 32'h40308233;  // Address 0x14
    imem[6] = 32'h0020f2b3;  // Address 0x18
    imem[7] = 32'h0020e333;  // Address 0x1c
    imem[8] = 32'h0020c3b3;  // Address 0x20
    imem[9] = 32'h00109413;  // Address 0x24
    imem[10] = 32'h0020d493;  // Address 0x28
    imem[11] = 32'h4020d513;  // Address 0x2c
    imem[12] = 32'h00302023;  // Address 0x30
    imem[13] = 32'h00402223;  // Address 0x34
    imem[14] = 32'h00002583;  // Address 0x38
    imem[15] = 32'h00058593;  // Address 0x3c
    imem[16] = 32'h00402603;  // Address 0x40
    imem[17] = 32'h00c58633;  // Address 0x44
    imem[18] = 32'h00c02423;  // Address 0x48
    imem[19] = 32'h00802683;  // Address 0x4c
    imem[20] = 32'h00d106b3;  // Address 0x50
    imem[21] = 32'h00d02623;  // Address 0x54
    imem[22] = 32'h0fd00713;  // Address 0x58
    imem[23] = 32'h00e02823;  // Address 0x5c
    imem[24] = 32'h01000783;  // Address 0x60
    imem[25] = 32'h01004803;  // Address 0x64
    imem[26] = 32'haaaab837;  // Address 0x68
    imem[27] = 32'h01002a23;  // Address 0x6c
    imem[28] = 32'h01401883;  // Address 0x70
    imem[29] = 32'h01405903;  // Address 0x74
    imem[30] = 32'h00300993;  // Address 0x78
    imem[31] = 32'h00500a13;  // Address 0x7c
    imem[32] = 32'h01498c63;  // Address 0x80
    imem[33] = 32'h01400a93;  // Address 0x84
    imem[34] = 32'h01499463;  // Address 0x88
    imem[35] = 32'hfff00b13;  // Address 0x8c
    imem[36] = 32'h00a00b13;  // Address 0x90
    imem[37] = 32'h01002b83;  // Address 0x94
    imem[38] = 32'h015a0c13;  // Address 0x98
    imem[39] = 32'h018c0c93;  // Address 0x9c
    imem[40] = 32'h019c8d13;  // Address 0xa0
    imem[41] = 32'h01ad0d93;  // Address 0xa4
    imem[42] = 32'h01b02e23;  // Address 0xa8
    imem[43] = 32'h01c02e83;  // Address 0xac
    imem[44] = 32'h01d00e13;  // Address 0xb0
    imem[45] = 32'h01c02f23;  // Address 0xb4
    imem[46] = 32'h01c00f13;  // Address 0xb8
    imem[47] = 32'h01e00f93;  // Address 0xbc
    imem[48] = 32'h01ef0f33;  // Address 0xc0
    imem[49] = 32'h018000ef;  // Address 0xc4
    imem[50] = 32'h00000013;  // Address 0xc8
    imem[51] = 32'h00000013;  // Address 0xcc
    imem[52] = 32'h00000013;  // Address 0xd0
    imem[53] = 32'h00000013;  // Address 0xd4
    imem[54] = 32'h00000013;  // Address 0xd8
    imem[55] = 32'h00008067;  // Address 0xdc
    imem[56] = 32'h12345837;  // Address 0xe0
    imem[57] = 32'h00100073;  // Address 0xe4
end

endmodule
