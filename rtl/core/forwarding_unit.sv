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
    
    output logic [1:0] forward_a,
    output logic [1:0] forward_b
);

always_comb begin
    // Default: no forwarding
    forward_a = 2'b00;
    forward_b = 2'b00;
    
    // Forward from MEM stage
    if (mem_reg_write && (mem_rd_addr != 0) && (mem_rd_addr == ex_rs1_addr))
        forward_a = 2'b10;
        
    if (mem_reg_write && (mem_rd_addr != 0) && (mem_rd_addr == ex_rs2_addr))
        forward_b = 2'b10;
        
    // Forward from WB stage
    if (wb_reg_write && (wb_rd_addr != 0) && 
        !(mem_reg_write && (mem_rd_addr == ex_rs1_addr)) && 
        (wb_rd_addr == ex_rs1_addr))
        forward_a = 2'b01;
        
    if (wb_reg_write && (wb_rd_addr != 0) && 
        !(mem_reg_write && (mem_rd_addr == ex_rs2_addr)) && 
        (wb_rd_addr == ex_rs2_addr))
        forward_b = 2'b01;
end

endmodule
