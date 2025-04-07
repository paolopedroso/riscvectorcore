/*
 * Scalar Register File
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module sregfile #(
    parameter int DATA_WIDTH = 32,
    parameter int REG_COUNT = 32
) (
    input logic clk,
    input logic rst_n,

    input logic [4:0] rs1_addr_i,
    output logic [DATA_WIDTH-1:0] rs1_data_o,

    input logic [4:0] rs2_addr_i,
    output logic [DATA_WIDTH-1:0] rs2_data_o,

    input logic [4:0] rd_addr_i,
    input logic [DATA_WIDTH-1:0] rd_data_i,
    input logic reg_write_en_i
);

// Register file
logic [DATA_WIDTH-1:0] register [REG_COUNT-1:0];

// Read logic
always_comb begin
    // Register x0 is hardwired to 0
    if (rs1_addr_i == 5'b0) begin
        rs1_data_o = 32'b0;
    end else begin
        rs1_data_o = register[rs1_addr_i];
        `ifdef SIMULATION
            $display("REGFILE: Read rs1=x%0d, value=0x%h", rs1_addr_i, register[rs1_addr_i]);
        `endif
    end
    
    if (rs2_addr_i == 5'b0) begin
        rs2_data_o = 32'b0;
    end else begin
        rs2_data_o = register[rs2_addr_i];
        `ifdef SIMULATION
            $display("REGFILE: Read rs2=x%0d, value=0x%h", rs2_addr_i, register[rs2_addr_i]);
        `endif
    end
end

// Write logic
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        // Initialize all registers to 0
        for (int i = 0; i < REG_COUNT; i++) begin
            register[i] <= 32'b0;
        end
    end
    else if (reg_write_en_i && rd_addr_i != 5'b0) begin
        // Write to register if not x0
        register[rd_addr_i] <= rd_data_i;
        `ifdef SIMULATION
            $display("REGFILE: Write rd=x%0d, value=0x%h", rd_addr_i, rd_data_i);
        `endif
    end
end

endmodule
