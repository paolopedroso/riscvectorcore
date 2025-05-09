/*
 * Forwarding Unit for RISC-V Processor - Fixed Version
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module forwarding_unit #(
    parameter int DATA_WIDTH = 32
) (
    // Register addresses from decode stage
    input logic [4:0] ex_rs1_addr,
    input logic [4:0] ex_rs2_addr,
    
    input logic mem_reg_write,
    input logic [4:0] mem_rd_addr,
    input logic wb_reg_write,
    input logic [4:0] wb_rd_addr,
    
    // Debug instruction tracking (optional)
    input logic [31:0] ex_instr,
    input logic [31:0] mem_instr,
    input logic [31:0] wb_instr,
    
    output logic [1:0] forward_a,
    output logic [1:0] forward_b
);

// Improved store instruction detection - checks opcode directly
wire is_store = (ex_instr[6:0] == 7'b0100011);

// Debug signals to help track execution
logic is_executing_store;
logic rs2_being_forwarded;

always_comb begin
    // Default: no forwarding
    forward_a = 2'b00;
    forward_b = 2'b00;
    
    // Debug signals initialization
    is_executing_store = is_store;
    rs2_being_forwarded = 1'b0;
    
    // RS1 forwarding logic with detailed debugging
    if (ex_rs1_addr != 5'b0) begin  // Don't forward for register x0
        // Check MEM stage forwarding (higher priority)
        if (mem_reg_write && (mem_rd_addr == ex_rs1_addr)) begin
            forward_a = 2'b10;
            `ifdef SIMULATION
                $display("FORWARDING: RS1 x%0d from MEM stage (x%0d), mem_reg_write=%b", 
                         ex_rs1_addr, mem_rd_addr, mem_reg_write);
                $display("FORWARDING: MEM instr=0x%h, EX instr=0x%h", mem_instr, ex_instr);
            `endif
        end
        // Check WB stage forwarding if MEM stage doesn't match
        else if (wb_reg_write && (wb_rd_addr == ex_rs1_addr)) begin
            forward_a = 2'b01;
            `ifdef SIMULATION
                $display("FORWARDING: RS1 x%0d from WB stage (x%0d), wb_reg_write=%b", 
                         ex_rs1_addr, wb_rd_addr, wb_reg_write);
                $display("FORWARDING: WB instr=0x%h, EX instr=0x%h", wb_instr, ex_instr);
            `endif
        end
    end
    
    // RS2 forwarding logic - IMPROVED LOGIC FOR STORES
    
    if (ex_rs2_addr != 5'b0) begin  // Don't forward for register x0
        // Enhanced debug for store instructions
        if (is_store) begin
            `ifdef SIMULATION
                $display("STORE INSTRUCTION DETECTED IN FORWARDING UNIT: ex_instr=0x%h", ex_instr);
                $display("  Store using rs2=x%0d", ex_rs2_addr);
            `endif
        end
        
        // Special forwarding for store instructions - more aggressive checking
        // Fix the forwarding detection for store instructions
        if (is_store) begin
            // Check WB stage forwarding more aggressively
            if (wb_rd_addr == ex_rs2_addr && wb_reg_write) begin
                forward_b = 2'b01;  // Forward from WB stage
                `ifdef SIMULATION
                    $display("STORE FORWARDING ACTIVE: Using x%0d from WB stage (FIXED)", ex_rs2_addr);
                    $display("  WB instr=0x%h, WB.rd_addr=%0d", wb_instr, wb_rd_addr);
                `endif
            end
            // Check MEM stage forwarding
            else if (mem_rd_addr == ex_rs2_addr && mem_reg_write) begin
                forward_b = 2'b10;  // Forward from MEM stage
                `ifdef SIMULATION
                    $display("STORE FORWARDING ACTIVE: Using x%0d from MEM stage", ex_rs2_addr);
                    $display("  MEM instr=0x%h, MEM.rd_addr=%0d", mem_instr, mem_rd_addr);
                `endif
            end
        end
        // Standard forwarding for regular instructions
        else begin
            // Check MEM stage forwarding (higher priority)
            if (mem_reg_write && (mem_rd_addr == ex_rs2_addr)) begin
                forward_b = 2'b10;
                `ifdef SIMULATION
                    $display("FORWARDING: RS2 x%0d from MEM stage (x%0d), mem_reg_write=%b", 
                             ex_rs2_addr, mem_rd_addr, mem_reg_write);
                    $display("FORWARDING: MEM instr=0x%h, EX instr=0x%h", mem_instr, ex_instr);
                `endif
            end
            // Check WB stage forwarding if MEM stage doesn't match
            else if (wb_reg_write && (wb_rd_addr == ex_rs2_addr)) begin
                forward_b = 2'b01;
                `ifdef SIMULATION
                    $display("FORWARDING: RS2 x%0d from WB stage (x%0d), wb_reg_write=%b", 
                             ex_rs2_addr, wb_rd_addr, wb_reg_write);
                    $display("FORWARDING: WB instr=0x%h, EX instr=0x%h", wb_instr, ex_instr);
                `endif
            end
        end
    end
end

endmodule
