/*
 *
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

/*

Vector DATA_WIDTH 32 bit encoding

31        25 24    20 19    15 14    12 11        7 6         0
+----------+--------+--------+--------+-----------+-----------+
| funct7   | vs2    | vs1    | funct3 | vd        | opcode    |
+----------+--------+--------+--------+-----------+-----------+
  7 bits     5 bits   5 bits   3 bits   5 bits      7 bits

*/

module instr_parser #(
   parameter int DATA_WIDTH = 32
) (
   input clk,
   input rst_n,
   input [DATA_WIDTH-1:0] instr_in,

   output [4:0] r1data_o,
   output [4:0] r2data_o,
   output [6:0] opcode_o
);

// Parsing
wire [4:0] regs1;
wire [4:0] regs2;
wire [6:0] opcode_d;
assign instr_in[19:15] = regs1;
assign instr_in[24:20] = regs1;

always_ff @(posedge clk) begin
    if (rst_n) begin
        r1data_o <= 5'b0;
        r2data_o <= 5'b0;
        opcode_o <= 7'b0;
    end else begin
        r1data_o <= regs1;
        r2data_o <= regs2;
        opcode_o <= opcode_d;
    end
end


endmodule
