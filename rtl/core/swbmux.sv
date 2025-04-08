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
        2'b00: begin
            rd_data_o = alu_result;      // ALU result
            `ifdef SIMULATION
                $display("WBMUX: Selected ALU result: 0x%h", alu_result);
            `endif
        end
        2'b01: begin
            rd_data_o = mem_rdata;       // Memory load
            `ifdef SIMULATION
                $display("WBMUX: Selected Memory data: 0x%h", mem_rdata);
            `endif
        end
        2'b10: begin
            rd_data_o = pc_i + 4;      // PC+4 for jumps
            `ifdef SIMULATION
                $display("WBMUX: Selected PC+4: 0x%h", pc_i + 4);
            `endif
        end
        default: begin
            rd_data_o = alu_result;
            `ifdef SIMULATION
                $display("WBMUX: Default - Selected ALU result: 0x%h", alu_result);
            `endif
        end
    endcase
end

endmodule
