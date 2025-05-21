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

    output logic [DATA_WIDTH-1:0] pc_out,

    // jalr special case
    input logic jalr_en,
    input logic [DATA_WIDTH-1:0] rs1_data
);

logic [DATA_WIDTH-1:0] next_pc;

always_comb begin
    // Default: normal increment
    next_pc = pc_out + 32'd4;

    if (jalr_en) begin
        // JALR: rs1 + imm
        next_pc = rs1_data + imm;
        next_pc[0] = 1'b0;  // Ensure alignment
        
        `ifdef SIMULATION
            $display("PC: JALR from 0x%h to 0x%h (rs1_data=0x%h, imm=0x%h)", 
                     pc_i, next_pc, rs1_data, imm);
        `endif
    end 
    else if (jmp_en) begin
        // JAL: pc + imm (JAL is PC-relative)
        next_pc = pc_i + imm;
        
        `ifdef SIMULATION
            $display("PC: JAL from 0x%h to 0x%h (imm=0x%h)", 
                     pc_i, next_pc, imm);
        `endif
    end
    else if (branch_en) begin
        // Branch: pc + imm
        next_pc = pc_i + imm;
        
        `ifdef SIMULATION
            $display("PC: Branch from 0x%h to 0x%h (imm=0x%h)", 
                     pc_i, next_pc, imm);
        `endif
    end
    else if (pc_i != pc_out) begin
        // Pipeline flush
        next_pc = pc_i;
        
        `ifdef SIMULATION
            $display("PC: Forced update from 0x%h to 0x%h", pc_out, next_pc);
        `endif
    end
    
    // Bounds checking
    if ((next_pc > MAX_PC) || (next_pc[1:0] != 2'b00)) begin
        `ifdef SIMULATION
            $display("WARNING: PC invalid (0x%h). Program continuing but PC limited.", next_pc);
        `endif
        next_pc = pc_out;
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
