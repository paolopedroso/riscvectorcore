/*
 * Program Counter
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module program_counter #(
    parameter int DATA_WIDTH = 32
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
            $display("PC: Branch/Jump from 0x%h to 0x%h", pc_i, next_pc);
        `endif
    end
    else if (!pc_write) begin
        // When stalled, maintain current PC
        next_pc = pc_out;
        
        `ifdef SIMULATION
            $display("PC: Stalled at 0x%h", pc_out);
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
end

// Sequential PC update - CRITICAL FIX: Ensure PC resets to exactly 0
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        pc_out <= 32'h00000000;  // Force PC to start at absolute 0
        `ifdef SIMULATION
            $display("PC: Reset to 0x00000000");
        `endif
    end 
    else begin
        pc_out <= next_pc;
    end
end

endmodule
