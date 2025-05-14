/*
 * Program Counter
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module program_counter #(
    parameter int DATA_WIDTH = 32,
    parameter int MAX_PC = 32'h00000100  // Limit PC to reasonable program space
) (
    input logic clk,
    input logic rst_n,
    input logic pc_write,        // Added for pipeline stall control
    input logic branch_en,
    input logic jmp_en,
    input logic [DATA_WIDTH-1:0] imm,
    input logic [DATA_WIDTH-1:0] pc_i,

    output logic [DATA_WIDTH-1:0] pc_out
);

logic [DATA_WIDTH-1:0] next_pc;

// Next PC logic
always_comb begin
    if (branch_en || jmp_en) begin
        // For branches and jumps, add immediate to current PC
        next_pc = pc_i + imm;
        
        `ifdef SIMULATION
            $display("PC: Branch/Jump from 0x%h to 0x%h (imm=0x%h, jmp=%b, branch=%b)", 
                     pc_i, next_pc, imm, jmp_en, branch_en);
        `endif
    end
    else if (pc_i != pc_out) begin
        // This is for flushing the pipeline - use the provided PC
        next_pc = pc_i;
        
        `ifdef SIMULATION
            $display("PC: Forced update from 0x%h to 0x%h", pc_out, next_pc);
        `endif
    end
    else begin
        // Normal PC increment by 4 (word-aligned)
        next_pc = pc_out + 32'd4;
        
        `ifdef SIMULATION
            $display("PC: Normal increment from 0x%h to 0x%h", pc_out, next_pc);
        `endif
    end
    
    // Add bounds checking to prevent runaway execution
    if ((next_pc > MAX_PC) || (next_pc[1:0] != 2'b00)) begin
        `ifdef SIMULATION
            $display("WARNING: PC invalid (0x%h). Program continuing but PC limited.", next_pc);
            // Don't finish here - let EBREAK or other checks handle termination
        `endif
        
        // Instead of halting, keep PC within valid range
        next_pc = pc_out;  // Hold the PC value
    end
end

// Sequential PC update
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        pc_out <= 32'b0;
    end 
    else if (pc_write) begin  // Only update PC when not stalled
        pc_out <= next_pc;
    end
    // When pc_write is 0, PC holds its value (stall)
end

endmodule
