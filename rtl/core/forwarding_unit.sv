/*
 * Enhanced Forwarding Unit with Debug
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

// Combinational logic for forwarding
always_comb begin
    // Default: no forwarding
    forward_a = 2'b00;
    forward_b = 2'b00;
    
    // RS1 forwarding logic
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
        else begin
            `ifdef SIMULATION
                $display("FORWARDING: No forward for RS1 x%0d", ex_rs1_addr);
            `endif
        end
    end
    
    // RS2 forwarding logic
    if (ex_rs2_addr != 5'b0) begin  // Don't forward for register x0
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
        else begin
            `ifdef SIMULATION
                $display("FORWARDING: No forward for RS2 x%0d", ex_rs2_addr);
            `endif
        end
    end
    
    // Enhanced debug for ALU ADD instruction
    `ifdef SIMULATION
        if (ex_instr == 32'h002081b3) begin // add x3, x1, x2
            $display("ADD INSTRUCTION DEBUG ==============================");
            $display("  forward_a=%b, forward_b=%b", forward_a, forward_b);
            $display("  ex_rs1_addr=%d, ex_rs2_addr=%d", ex_rs1_addr, ex_rs2_addr);
            $display("  mem_rd_addr=%d, wb_rd_addr=%d", mem_rd_addr, wb_rd_addr);
            $display("  mem_reg_write=%b, wb_reg_write=%b", mem_reg_write, wb_reg_write);
            $display("  rs1 should be x1, rs2 should be x2");
            $display("====================================================");
        end
    `endif
end

endmodule
