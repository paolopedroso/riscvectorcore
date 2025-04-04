/*
 * Write-back Mux
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module swbmux #(
    parameter int DATA_WIDTH = 32
) (
    input logic [1:0] result_src_i,
    input logic [DATA_WIDTH-1:0] alu_result,
    input logic [DATA_WIDTH-1:0] mem_rdata,
    input logic [DATA_WIDTH-1:0] pc_i,
    output logic [DATA_WIDTH-1:0] rd_data_o
);

always_comb begin
    case (result_src_i)
        2'b00: rd_data_o = alu_result;      // ALU result
        2'b01: rd_data_o = mem_rdata;       // Memory load
        2'b10: rd_data_o = pc_i + 4;      // PC+4 for jumps
        default: rd_data_o = alu_result;
    endcase
end

endmodule
