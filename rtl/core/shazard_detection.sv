/*
 * Hazard Detection Unit
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module shazard_detection #(
    parameter int DATA_WIDTH = 32
) (
    // Instruction being decoded
    input logic [4:0] id_rs1_addr,
    input logic [4:0] id_rs2_addr,
    input logic id_uses_rs1,
    input logic id_uses_rs2,
    
    // Instruction in execute stage
    input logic ex_mem_read,
    input logic [4:0] ex_rd_addr,
    
    output logic stall_pipeline
);
    // Detect load-use hazard
    always_comb begin
        stall_pipeline = 1'b0;
        
        // Load-use hazard: When a load is followed immediately by an instruction
        // that uses the loaded value
        if (ex_mem_read && ex_rd_addr != 5'b0 &&
            ((id_uses_rs1 && (id_rs1_addr == ex_rd_addr)) ||
             (id_uses_rs2 && (id_rs2_addr == ex_rd_addr)))) begin
            stall_pipeline = 1'b1;
        end
    end
endmodule
