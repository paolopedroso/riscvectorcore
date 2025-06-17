/*
 * Testbench
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

`timescale 1ns/1ps

module tb_top;
  // Clock and reset signals
  logic clk;
  logic rst_n;
  
  // Instantiate the DUT (Design Under Test)
  top dut (
    .clk(clk),
    .rst_n(rst_n)
  );
  
  // Clock generation
  initial begin
    clk = 0;
    forever #5 clk = ~clk; // 10ns period (100MHz)
  end
  
  // For VCD dump
  initial begin
    $dumpfile("tb_top.vcd");
    $dumpvars(0, tb_top);
  end
  
  // Test sequence
  initial begin
    // Initialize and apply reset
    rst_n = 0;
    repeat(5) @(posedge clk);
    rst_n = 1;
    
    // Run simulation for multiple cycles to execute the test program
    repeat(100) @(posedge clk);
    
    // End simulation
    $display("Simulation completed successfully!");
    $finish;
  end
  
  // Monitor registers for debug
  always @(posedge clk) begin
    if (rst_n) begin
      $display("Time: %0t, PC: %h, Instruction: %h", 
               $time, dut.pc_out, dut.instr);
      
      // Print register file updates when a write occurs
      if (dut.mem_wb_reg_write && dut.mem_wb_rd_addr != 0) begin
        $display("  Register x%0d updated with value: %h", 
                 dut.mem_wb_rd_addr, dut.rd_data);
      end
    end
  end
endmodule
