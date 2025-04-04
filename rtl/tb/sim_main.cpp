/*
 * Testbench
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include <memory>
#include "Vtop.h"
#include "Vtop___024root.h"  // Include the root file for internal signal access

// Simulation time
vluint64_t main_time = 0;

// Called by $time in Verilog
double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    // Create an instance of our top module
    auto top = std::make_unique<Vtop>();
    
    // Initialize trace if requested
    std::unique_ptr<VerilatedVcdC> tfp;
    const bool trace = true;
    if (trace) {
        Verilated::traceEverOn(true);
        tfp = std::make_unique<VerilatedVcdC>();
        top->trace(tfp.get(), 99);  // Trace 99 levels of hierarchy
        tfp->open("tb_top.vcd");
    }
    
    // Initialize simulation inputs
    top->clk = 0;
    top->rst_n = 0;  // Active low reset
    
    // Run simulation for 2000 time units
    while (main_time < 2000 && !Verilated::gotFinish()) {
        // Toggle clock
        top->clk = !top->clk;
        
        // Release reset after 50 time units
        if (main_time == 50) {
            top->rst_n = 1;
        }
        
        // Evaluate the design (calculate combinational logic)
        top->eval();
        
        // Dump trace data if tracing
        if (trace) {
            tfp->dump(main_time);
        }
        
        // Output debug info - access signals through rootp
        if (top->clk && top->rst_n) {
            std::cout << "Time: " << main_time;
            
            // Use Verilator command to print state without directly accessing internal signals
            Verilated::runFlushCallbacks();
        }
        
        // Increment simulation time
        main_time++;
    }
    
    // Clean up and exit
    if (trace) {
        tfp->close();
    }
    
    std::cout << "Simulation completed at time: " << main_time << std::endl;
    return 0;
}
