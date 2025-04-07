/*
 * Forwarding Unit
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
                $display("Forwarding: RS1 x%0d from MEM stage (x%0d)", ex_rs1_addr, mem_rd_addr);
            `endif
        end
        // Check WB stage forwarding if MEM stage doesn't match
        else if (wb_reg_write && (wb_rd_addr == ex_rs1_addr)) begin
            forward_a = 2'b01;
            `ifdef SIMULATION
                $display("Forwarding: RS1 x%0d from WB stage (x%0d)", ex_rs1_addr, wb_rd_addr);
            `endif
        end
    end
    
    // RS2 forwarding logic
    if (ex_rs2_addr != 5'b0) begin  // Don't forward for register x0
        // Check MEM stage forwarding (higher priority)
        if (mem_reg_write && (mem_rd_addr == ex_rs2_addr)) begin
            forward_b = 2'b10;
            `ifdef SIMULATION
                $display("Forwarding: RS2 x%0d from MEM stage (x%0d)", ex_rs2_addr, mem_rd_addr);
            `endif
        end
        // Check WB stage forwarding if MEM stage doesn't match
        else if (wb_reg_write && (wb_rd_addr == ex_rs2_addr)) begin
            forward_b = 2'b01;
            `ifdef SIMULATION
                $display("Forwarding: RS2 x%0d from WB stage (x%0d)", ex_rs2_addr, wb_rd_addr);
            `endif
        end
    end
end

endmodule
