/*
 * Vector Register File
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module vregfile #(
    parameter int DATA_WIDTH = 32,
    parameter int VREGS = 32,
    parameter int ELEMENTS = 8,
    parameter int VLEN = DATA_WIDTH * ELEMENTS
)(
    input logic clk, rst_n,
    input logic [4:0] rs1_addr_i,
    input logic [4:0] rs2_addr_i,

    output logic [VLEN-1:0] rs1_data_o, 
    output logic [VLEN-1:0] rs2_data_o,

    input logic [4:0] vrd_addr_i,
    input logic vregw_en_i,
    input logic [VLEN-1:0] vrd_data_i

);

// 8196 bit memory
// 1024 bit VLEN
logic [DATA_WIDTH-1:0] vregs [VREGS][ELEMENTS];

always_ff @(posedge clk) begin
    if (!rst_n) begin
        for (int i=0; i < VREGS; i++) begin
            for (int j=0; j<ELEMENTS; j++) begin
                vregs[i][j] <= '0;
            end
        end
    end

    if (vregw_en_i && (vrd_addr_i != 0)) begin
        // Optimize
        // for (int i=0; i<ELEMENTS/4; i+=4) begin
        //     vregs[vrd_addr_i][i  ] <= vrd_data_i[((i  )*DATA_WIDTH) +: DATA_WIDTH];
        //     vregs[vrd_addr_i][i+1] <= vrd_data_i[((i+1)*DATA_WIDTH) +: DATA_WIDTH];
        //     vregs[vrd_addr_i][i+2] <= vrd_data_i[((i+2)*DATA_WIDTH) +: DATA_WIDTH];
        //     vregs[vrd_addr_i][i+3] <= vrd_data_i[((i+3)*DATA_WIDTH) +: DATA_WIDTH];
        // end

        for (int i=0; i<ELEMENTS; i++) begin
            vregs[vrd_addr_i][i] <= vrd_data_i[((i)*DATA_WIDTH) +: DATA_WIDTH];
        end
    end
end

always_comb begin
    if (rs1_addr_i != 0) begin
        for (int i=0; i<ELEMENTS; i++) begin
            rs1_data_o[(i*DATA_WIDTH) +: DATA_WIDTH] = vregs[rs1_addr_i][i];
        end
    end else begin
        rs1_data_o = 0;
    end

    if (rs2_addr_i != 0) begin
        for (int i=0; i<ELEMENTS; i++) begin
            rs2_data_o[(i*DATA_WIDTH) +: DATA_WIDTH] = vregs[rs2_addr_i][i];
        end
    end else begin
        rs2_data_o = 0;
    end
end

endmodule
