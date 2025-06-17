/*
 * Vector Register File Testbench
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module tb_vregfile;

    parameter int DATA_WIDTH = 32;
    parameter int VREGS = 32;
    parameter int ELEMENTS = 8;
    parameter int VLEN = DATA_WIDTH * ELEMENTS;
    
    logic clk, rst_n;
    logic [4:0] rs1_addr_i;
    logic [4:0] rs2_addr_i;
    logic [VLEN-1:0] rs1_data_o; 
    logic [VLEN-1:0] rs2_data_o;
    logic [4:0] vrd_addr_i;
    logic vregw_en_i;
    logic [VLEN-1:0] vrd_data_i;

    vregfile #(
        .DATA_WIDTH(DATA_WIDTH),
        .VREGS(VREGS),
        .ELEMENTS(ELEMENTS),
        .VLEN(VLEN)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .rs1_addr_i(rs1_addr_i),
        .rs2_addr_i(rs2_addr_i),
        .rs1_data_o(rs1_data_o),
        .rs2_data_o(rs2_data_o),
        .vrd_addr_i(vrd_addr_i),
        .vregw_en_i(vregw_en_i),
        .vrd_data_i(vrd_data_i)
    );

    always #5 clk <= ~clk;

    task write_register(input [4:0] addr, input [VLEN-1:0] data, input [VLEN-1:0] expected_data);
        @(posedge clk);
        vrd_addr_i = addr;
        vrd_data_i = data;
        vregw_en_i = 1'b1;
        @(posedge clk);
        vregw_en_i = 1'b0;
        
        @(posedge clk);
        rs1_addr_i = addr;
        #1;
        
        if (addr == 0) begin
            // Register 0 should always read as 0
            if (rs1_data_o != 0) begin
                $error("ERROR: Register 0 read 0x%h, expected 0x0", rs1_data_o);
            end else begin
                $display("SUCCESS: Register 0 correctly reads as 0 (write ignored)");
            end
        end else begin
            if (rs1_data_o != expected_data) begin
                $error("ERROR: Register %0d read 0x%h, expected 0x%h", addr, rs1_data_o, expected_data);
            end else begin
                $display("SUCCESS: Written and verified 0x%h to register %0d", data, addr);
            end
        end
    endtask

    task read_registers(input [4:0] rs1_addr, input [4:0] rs2_addr);
        @(posedge clk);
        rs1_addr_i = rs1_addr;
        rs2_addr_i = rs2_addr;
        #1;
        $display("Read from reg[%0d]: 0x%h", rs1_addr, rs1_data_o);
        $display("Read from reg[%0d]: 0x%h", rs2_addr, rs2_data_o);
    endtask

    initial begin
        clk = 0;
        rst_n = 0;
        rs1_addr_i = 0;
        rs2_addr_i = 0;
        vrd_addr_i = 0;
        vregw_en_i = 0;
        vrd_data_i = 0;
        
        $display("\nStarting Vector Regfile Testbench...\n");
        
        #20;
        rst_n = 1;
        $display("Reset released\n");
        
        // Test writing to register 0 (should be ignored)
        $display("\n=== Testing Register 0 (should ignore writes) ===\n");
        write_register(5'd0, 
            256'hDEADBEEF_CAFEBABE_12345678_87654321_AAAABBBB_CCCCDDDD_EEEEFFFF_11112222,
            256'h0);  // Expected: 0 (write should be ignored)

        $finish;
    end

endmodule