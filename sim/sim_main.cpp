/*
 * Enhanced Testbench C++ Script for RISC-V Processor
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

 #include <verilated.h>
 #include <verilated_vcd_c.h>
 #include <iostream>
 #include <iomanip>
 #include <fstream>
 #include <memory>
 #include <string>
 #include <vector>
 #include <map>
 #include "Vtop.h"
 #include "Vtop___024root.h"

 // Pipeline Debugger
 #include "pipeline_debug.cpp"  // Include the pipeline debugger header
 
 vluint64_t main_time = 0;
 unsigned int total_cycles = 0;
 const unsigned int MAX_CYCLES = 300;  // Increased for comprehensive test
 const std::vector<std::string> reg_names = {
     "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
     "s0/fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
     "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
     "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
 };
 
 // Function to display bytes in little-endian ordering (RISC-V native format)
 void print_bytes_little_endian(uint32_t value) {
     printf("%02x %02x %02x %02x", 
            (value & 0xFF), 
            ((value >> 8) & 0xFF), 
            ((value >> 16) & 0xFF),
            ((value >> 24) & 0xFF));
 }
 
 double sc_time_stamp() {
     return main_time;
 }
 
 // Enhanced helper function to print register values in RISC-V little-endian format
 void print_registers(Vtop* top, std::ofstream& reg_file) {
     // Print register values with correct formatting
     for (int i = 0; i < 32; i++) {
         // Direct access to register array
         uint32_t value = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
         
         // Write to file in the format expected by analyze_vcd.py
         reg_file << "x" << i << "=" << std::dec << value << std::endl;
         
         // Also write human-readable format
         reg_file << "register x" << i << " = " << std::dec << value;
         if (i < reg_names.size()) {
             reg_file << " (" << reg_names[i] << ")";
         }
         reg_file << std::endl;
         
         // Display to console with printf for consistent formatting
         printf("x%d (%5s): 0x%08x (%d)\n", 
                i, i < reg_names.size() ? reg_names[i].c_str() : "----", 
                value, value);
         
         // Print bytes to show little-endian ordering
         printf("   Bytes (little-endian): ");
         print_bytes_little_endian(value);
         printf("\n");
     }
 }
 
 // Helper to dump memory contents
 void dump_memory_contents(Vtop* top, std::ofstream& mem_file) {
     mem_file << "# Memory Dump (First 64 bytes)" << std::endl;
     for (int i = 0; i < 64; i++) {
         uint8_t value = top->rootp->top__DOT__datamem_inst__DOT__memory[i];
         mem_file << "mem[" << std::dec << i << "] = 0x" 
                  << std::hex << std::setw(2) << std::setfill('0') 
                  << static_cast<int>(value) << std::endl;
     }
 }
 
 // Enhanced helper to dump pipeline state
 void dump_pipeline_state(Vtop* top, std::ofstream& debug_file) {
     debug_file << "================== Pipeline State ==================" << std::endl;
     debug_file << "PC: 0x" << std::hex << top->rootp->top__DOT__pc_out << std::endl;
     debug_file << "IF/ID PC: 0x" << top->rootp->top__DOT__if_id_pc << std::endl;
     debug_file << "IF/ID Instr: 0x" << top->rootp->top__DOT__if_id_instr << std::endl;
     
     debug_file << "ID/EX PC: 0x" << top->rootp->top__DOT__id_ex_pc << std::endl;
     debug_file << "ID/EX rs1_data: 0x" << std::hex << top->rootp->top__DOT__id_ex_rs1_data << std::endl;
     debug_file << "ID/EX rs2_data: 0x" << std::hex << top->rootp->top__DOT__id_ex_rs2_data << std::endl;
     debug_file << "ID/EX ALU op: " << std::dec << (int)top->rootp->top__DOT__id_ex_alu_op << std::endl;
     
     debug_file << "EX/MEM ALU result: 0x" << std::hex << top->rootp->top__DOT__ex_mem_alu_result << std::endl;
     debug_file << "EX/MEM rd_addr: " << std::dec << (int)top->rootp->top__DOT__ex_mem_rd_addr << std::endl;
     debug_file << "EX/MEM reg_write: " << (int)top->rootp->top__DOT__ex_mem_reg_write << std::endl;
     
     debug_file << "MEM/WB rd_addr: " << std::dec << (int)top->rootp->top__DOT__mem_wb_rd_addr << std::endl;
     debug_file << "MEM/WB reg_write: " << (int)top->rootp->top__DOT__mem_wb_reg_write << std::endl;
     debug_file << "MEM/WB result: 0x" << std::hex << top->rootp->top__DOT__mem_wb_alu_result << std::endl;
     
     debug_file << "Control signals:" << std::endl;
     debug_file << "  stall_pipeline: " << std::dec << (int)top->rootp->top__DOT__stall_pipeline << std::endl;
     debug_file << "  take_branch: " << (int)top->rootp->top__DOT__take_branch << std::endl;
     debug_file << "  pc_src: " << (int)top->rootp->top__DOT__pc_src << std::endl;
     debug_file << "==================================================" << std::endl;
 }
 
 // Enhanced instruction decoder with more details
 std::string decode_instruction(uint32_t instr) {
     uint32_t opcode = instr & 0x7F;
     uint32_t rd = (instr >> 7) & 0x1F;
     uint32_t rs1 = (instr >> 15) & 0x1F;
     uint32_t rs2 = (instr >> 20) & 0x1F;
     uint32_t funct3 = (instr >> 12) & 0x7;
     uint32_t funct7 = (instr >> 25) & 0x7F;
     
     std::string result = "Unknown instruction: 0x" + std::to_string(instr);
     
     // Define imm variables outside the switch statement to avoid scope issues
     int32_t imm = 0;
     uint32_t imm1 = 0;
     uint32_t imm2 = 0;
     uint32_t imm12 = 0;
     uint32_t imm11 = 0;
     uint32_t imm10_5 = 0;
     uint32_t imm4_1 = 0;
     uint32_t imm20 = 0;
     uint32_t imm19_12 = 0;
     uint32_t imm10_1 = 0;
     
     switch (opcode) {
         case 0x33: // R-type
             result = "R-type: ";
             if (funct3 == 0 && funct7 == 0) result += "ADD ";
             else if (funct3 == 0 && funct7 == 0x20) result += "SUB ";
             else if (funct3 == 1) result += "SLL ";
             else if (funct3 == 2) result += "SLT ";
             else if (funct3 == 3) result += "SLTU ";
             else if (funct3 == 4) result += "XOR ";
             else if (funct3 == 5 && funct7 == 0) result += "SRL ";
             else if (funct3 == 5 && funct7 == 0x20) result += "SRA ";
             else if (funct3 == 6) result += "OR ";
             else if (funct3 == 7) result += "AND ";
             result += "x" + std::to_string(rd) + ", x" + std::to_string(rs1) + ", x" + std::to_string(rs2);
             break;
             
         case 0x03: // I-type Load
             result = "I-type Load: ";
             if (funct3 == 0) result += "LB ";
             else if (funct3 == 1) result += "LH ";
             else if (funct3 == 2) result += "LW ";
             else if (funct3 == 4) result += "LBU ";
             else if (funct3 == 5) result += "LHU ";
             
             imm = ((int32_t)(instr & 0xFFF00000)) >> 20;
             result += "x" + std::to_string(rd) + ", " + 
                      std::to_string(imm) + "(x" + std::to_string(rs1) + ")";
             break;
             
         case 0x13: // I-type ALU
             result = "I-type ALU: ";
             if (funct3 == 0) result += "ADDI ";
             else if (funct3 == 1) result += "SLLI ";
             else if (funct3 == 2) result += "SLTI ";
             else if (funct3 == 3) result += "SLTIU ";
             else if (funct3 == 4) result += "XORI ";
             else if (funct3 == 5) {
                 if (funct7 & 0x20) result += "SRAI ";
                 else result += "SRLI ";
             }
             else if (funct3 == 6) result += "ORI ";
             else if (funct3 == 7) result += "ANDI ";
             
             imm = ((int32_t)(instr & 0xFFF00000)) >> 20;
             result += "x" + std::to_string(rd) + ", x" + std::to_string(rs1) + 
                      ", " + std::to_string(imm);
             break;
             
         case 0x23: // S-type
             result = "S-type: ";
             if (funct3 == 0) result += "SB ";
             else if (funct3 == 1) result += "SH ";
             else if (funct3 == 2) result += "SW ";
             
             imm11 = (instr >> 7) & 0x1F;  // imm[4:0]
             imm12 = (instr >> 25) & 0x7F; // imm[11:5]
             imm = (imm12 << 5) | imm11;
             if (imm12 & 0x40) imm |= 0xFFFFF800; // Sign extend
             
             result += "x" + std::to_string(rs2) + ", " + 
                      std::to_string(imm) + "(x" + std::to_string(rs1) + ")";
             break;
             
         case 0x63: // B-type
             result = "B-type: ";
             if (funct3 == 0) result += "BEQ ";
             else if (funct3 == 1) result += "BNE ";
             else if (funct3 == 4) result += "BLT ";
             else if (funct3 == 5) result += "BGE ";
             else if (funct3 == 6) result += "BLTU ";
             else if (funct3 == 7) result += "BGEU ";
             
             // Decode immediate for B-type
             imm11 = (instr >> 7) & 0x1;      // imm[11]
             imm4_1 = (instr >> 8) & 0xF;     // imm[4:1]
             imm10_5 = (instr >> 25) & 0x3F;  // imm[10:5]
             imm12 = (instr >> 31) & 0x1;     // imm[12]
             
             imm = (imm12 << 12) | (imm11 << 11) | (imm10_5 << 5) | (imm4_1 << 1);
             if (imm12) imm |= 0xFFFFE000; // Sign extend
             
             result += "x" + std::to_string(rs1) + ", x" + std::to_string(rs2) + 
                      ", " + std::to_string(imm);
             break;
             
         case 0x37: // U-type (LUI)
             result = "U-type: LUI ";
             imm = instr & 0xFFFFF000;
             result += "x" + std::to_string(rd) + ", 0x" + 
                      std::to_string(imm >> 12);
             break;
             
         case 0x17: // U-type (AUIPC)
             result = "U-type: AUIPC ";
             imm = instr & 0xFFFFF000;
             result += "x" + std::to_string(rd) + ", 0x" + 
                      std::to_string(imm >> 12);
             break;
             
         case 0x6F: // J-type (JAL)
             result = "J-type: JAL ";
             
             // Decode immediate for JAL
             imm20 = (instr >> 31) & 0x1;     // imm[20]
             imm10_1 = (instr >> 21) & 0x3FF; // imm[10:1]
             imm11 = (instr >> 20) & 0x1;     // imm[11]
             imm19_12 = (instr >> 12) & 0xFF; // imm[19:12]
             
             imm = (imm20 << 20) | (imm19_12 << 12) | (imm11 << 11) | (imm10_1 << 1);
             if (imm20) imm |= 0xFFE00000; // Sign extend
             
             result += "x" + std::to_string(rd) + ", " + std::to_string(imm);
             break;
             
         case 0x67: // I-type (JALR)
             result = "I-type: JALR ";
             imm = ((int32_t)(instr & 0xFFF00000)) >> 20;
             result += "x" + std::to_string(rd) + ", " + 
                      std::to_string(imm) + "(x" + std::to_string(rs1) + ")";
             break;
             
         case 0x73: // System
             if ((instr & 0xFFFFFFFF) == 0x00100073)
                 result = "EBREAK";
             else if ((instr & 0xFFFFFFFF) == 0x00000073)
                 result = "ECALL";
             else
                 result = "SYSTEM";
             break;
     }
     
     return result;
 }
 
 // Track register changes for debugging
 void print_register_changes(Vtop* top, uint32_t* prev_regs) {
     bool changes = false;
     printf("Register changes: ");
     
     for (int i = 0; i < 32; i++) {
         uint32_t current_value = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
         
         if (current_value != prev_regs[i]) {
             if (changes) printf(", ");
             printf("x%d: 0x%x -> 0x%x", i, prev_regs[i], current_value);
             prev_regs[i] = current_value;
             changes = true;
         }
     }
     
     if (!changes) {
         printf("None");
     }
     printf("\n");
 }
 
 int main(int argc, char** argv) {
     // Initialize variables and setup
     VerilatedContext* contextp = new VerilatedContext;
     contextp->commandArgs(argc, argv);
     Vtop* top = new Vtop(contextp);
     PipelineDebugger pipeline_debug;

     
     // Trace setup
     VerilatedVcdC* tfp = nullptr;
     const bool trace = true;
     if (trace) {
         Verilated::traceEverOn(true);
         tfp = new VerilatedVcdC;
         top->trace(tfp, 99);
         tfp->open("tb_top.vcd");
     }
     
     // For register change tracking
     uint32_t prev_regs[32] = {0};
     std::vector<uint32_t> executed_instructions;
     
     // Output diagnostic information
     printf("Starting simulation of RISC-V processor...\n");
     printf("Verilator version: %s %s\n", 
            Verilated::productName(), 
            Verilated::productVersion());
     
     // Initialize simulation inputs
     top->clk = 0;
     top->rst_n = 0;
     
     // Open debug logs
     std::ofstream debug_log("debug_log.txt");
     std::ofstream instr_trace("instruction_trace.txt");
     std::ofstream mem_dump("memory_dump.txt");
     
     printf("Asserting reset...\n");
     
     // Reset sequence
     for (int i = 0; i < 10; i++) {
         top->clk = !top->clk;
         top->eval();
         if (trace) {
             tfp->dump(main_time);
         }
         main_time++;
     }
     
     // Release reset
     top->rst_n = 1;
     printf("Reset released at time %lu\n", main_time);
     debug_log << "Reset released at time " << main_time << std::endl;
     
     // Check initial PC value
     top->eval();
     printf("Initial PC value: 0x%08x\n", top->rootp->top__DOT__pc_out);
     
     // Run endianness test
     // run_endianness_test(top);
     
     // Examine instruction memory contents
     printf("Instruction memory contents:\n");
     for (int i = 0; i < 14; i++) {
         uint32_t instr = top->rootp->top__DOT__instr_mem_inst__DOT__imem[i];
         if (instr != 0) {
             printf("  imem[%x] = 0x%08x", i, instr);
             if (i == 2) printf("  <- ADD x3, x1, x2");
             printf("\n");
             
             // Show bytes in little-endian order
             printf("    Bytes (little-endian): ");
             print_bytes_little_endian(instr);
             printf("\n");
         }
     }
     
     // Track previous PC to detect program completion
     uint32_t previous_pc = 0;
     uint32_t same_pc_count = 0;
     bool program_completed = false;
     
     // Check for EBREAK to end simulation
     bool ebreak_detected = false;
     
     // Simulation loop
     while (!contextp->gotFinish() && total_cycles < MAX_CYCLES && !program_completed && !ebreak_detected) {
         // Toggle clock
         top->clk = !top->clk;
         top->eval();
         
         // Dump trace
         if (trace) {
             tfp->dump(main_time);
         }
         
         // Execute ALU and other logic on clock edge
         if (top->clk && top->rst_n) {
             // Track execution on positive clock edge
                 pipeline_debug.update_state(
                    top,                              // Top module pointer
                    top->rootp->top__DOT__stall_pipeline,  // Stall signal
                    false,        // PC write signal
                    top->rootp->top__DOT__take_branch,     // Branch taken
                    
                    top->rootp->top__DOT__forward_a,       // Forward A
                    top->rootp->top__DOT__forward_b,       // Forward B
                    
                    top->rootp->top__DOT__if_id_instr,     // IF/ID instruction
                    top->rootp->top__DOT__id_ex_instr,     // ID/EX instruction
                    top->rootp->top__DOT__ex_mem_instr,    // EX/MEM instruction
                    top->rootp->top__DOT__mem_wb_instr,    // MEM/WB instruction
                    
                    top->rootp->top__DOT__rs1_addr,        // Decode rs1
                    top->rootp->top__DOT__rs2_addr,        // Decode rs2
                    top->rootp->top__DOT__id_ex_rs1_addr,  // ID/EX rs1
                    top->rootp->top__DOT__id_ex_rs2_addr,  // ID/EX rs2
                    top->rootp->top__DOT__id_ex_rd_addr,   // ID/EX rd
                    top->rootp->top__DOT__ex_mem_rd_addr,  // EX/MEM rd
                    top->rootp->top__DOT__mem_wb_rd_addr,  // MEM/WB rd
                    
                    top->rootp->top__DOT__rs1_data,        // rs1 data
                    top->rootp->top__DOT__rs2_data,        // rs2 data
                    top->rootp->top__DOT__id_ex_rs1_data,  // ID/EX rs1 data
                    top->rootp->top__DOT__id_ex_rs2_data,  // ID/EX rs2 data 
                    top->rootp->top__DOT__id_ex_alu_op,  // Using id_ex_alu_op instead of alu_result
                    top->rootp->top__DOT__ex_mem_alu_result, // EX/MEM ALU result
                    top->rootp->top__DOT__mem_rdata,       // Memory read data
                    top->rootp->top__DOT__rd_data,         // Writeback data
                    
                    top->rootp->top__DOT__reg_write_en,    // Decode reg write
                    top->rootp->top__DOT__id_ex_reg_write, // ID/EX reg write
                    top->rootp->top__DOT__ex_mem_reg_write, // EX/MEM reg write
                    top->rootp->top__DOT__mem_wb_reg_write, // MEM/WB reg write
                    top->rootp->top__DOT__id_ex_mem_write, // ID/EX mem write
                    top->rootp->top__DOT__ex_mem_mem_write, // EX/MEM mem write
                    
                    top->rootp->top__DOT__ex_mem_rs2_data  // Store data
                );

             if (main_time % 2 == 1) {
                 // Get current instruction - no endianness swapping needed
                 uint32_t instr = top->rootp->top__DOT__instr;
                 
                 std::string decoded = decode_instruction(instr);
                 uint32_t current_pc = top->rootp->top__DOT__pc_out;
                 
                 // Debugging output
                 printf("Instruction at PC 0x%08x:\n", current_pc);
                 printf("  Instr: 0x%08x\n", instr);
                 printf("  Bytes (little-endian): ");
                 print_bytes_little_endian(instr);
                 printf("\n");
                 printf("  Decoded: %s\n", decoded.c_str());
                 
                 // Track executed instructions
                 uint32_t current_instr = top->rootp->top__DOT__if_id_instr;
                 if (current_instr != 0) {
                     executed_instructions.push_back(current_instr);
                 }
                 
                 // Track register changes every cycle
                 print_register_changes(top, prev_regs);
                 
                 // Check for EBREAK/ECALL instructions
                 if (instr == 0x00100073 || instr == 0x00000073) { 
                     const char* instr_name = (instr == 0x00100073) ? "EBREAK" : "ECALL";
                     printf("\n==== %s INSTRUCTION DETECTED at PC=0x%08x ====\n", instr_name, current_pc);
                     printf("Terminating simulation normally\n");
                     ebreak_detected = true;
                     
                     // Dump final register state before exiting
                     printf("\n=== Final Register Values on %s ===\n", instr_name);
                     std::ofstream regDump("register_dump.txt");
                     
                     if (regDump.is_open()) {
                         // Write both formats - human readable for debugging and simple format for verification
                         for (int i = 0; i < 32; i++) {
                             uint32_t value = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
                             
                             // Format for analyze_vcd.py
                             regDump << "x" << i << "=" << std::dec << value << std::endl;
                             
                             // Also write the detailed format for human debugging
                             regDump << "register x" << i << " = " << std::dec << value;
                             if (i < reg_names.size()) {
                                 regDump << " (" << reg_names[i] << ")";
                             }
                             regDump << std::endl;
                         }
                         regDump.close();
                         printf("Register dump created: register_dump.txt\n");
                     } else {
                         printf("Error: Could not create register dump file\n");
                     }
                     
                     // Dump memory contents
                     std::ofstream memDump("memory_dump.txt");
                     dump_memory_contents(top, memDump);
                     memDump.close();
                     
                     // Print one final register summary to console
                     printf("\n=== Register Values Summary (RISC-V Little-Endian) ===\n");
                     for (int i = 0; i <= 31; i++) {
                         uint32_t value = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
                         
                         printf("x%d (%5s): 0x%08x (decimal: %d)\n", 
                                i, i < reg_names.size() ? reg_names[i].c_str() : "----", 
                                value, value);
                         
                         printf("   Bytes (little-endian): ");
                         print_bytes_little_endian(value);
                         printf("\n");
                     }
                     
                     // Exit simulation
                     program_completed = true;
                 }
                
                 
                 // Dump detailed pipeline state occasionally
                 if (total_cycles % 10 == 0) {
                     dump_pipeline_state(top, debug_log);
                 }
                 
                 // Check for program completion - detect if PC is not changing
                 if (current_pc == previous_pc) {
                     same_pc_count++;
                     if (same_pc_count >= 10) {
                         printf("Program appears to have completed (PC not changing for 10 cycles at 0x%08x)\n", 
                                current_pc);
                         program_completed = true;
                     }
                 } else {
                     same_pc_count = 0;
                 }
                 previous_pc = current_pc;
                 
                 total_cycles++;
             }
         }
         
         // Increment simulation time
         main_time++;
     }
     
     // Final state dump
     debug_log << "\n=== Final Pipeline State ===\n";
     dump_pipeline_state(top, debug_log);
     
     // Record register state at end of simulation if not already done
     if (!ebreak_detected) {
         printf("\n=== Final Register Values (RISC-V Little-Endian) ===\n");
         std::ofstream regDump("register_dump.txt");
         print_registers(top, regDump);  // This function is correctly implemented
         regDump.close();
 
         // Print summary of executed instructions
         printf("\n=== Summary of Executed Instructions ===\n");
         printf("Simulation completed at time: %lu\n", main_time);
         printf("Total cycles executed: %u\n", total_cycles);
 
         // Optional simplified summary with proper formatting - CORRECTLY DISPLAYED
         printf("\n=== Register Values Summary (RISC-V Little-Endian) ===\n");
         for (int i = 0; i <= 31; i++) {  // Print only registers x1-x12 for brevity
             // Direct access without endianness correction
             uint32_t value = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
             
             // Display using printf for consistent formatting across platforms
             printf("x%d (%5s): 0x%08x (decimal: %d)\n", 
                    i, i < reg_names.size() ? reg_names[i].c_str() : "----", 
                    value, value);
             
             // Print bytes in correct little-endian order
             printf("   Bytes (little-endian): ");
             print_bytes_little_endian(value);
             printf("\n");
         }
     }
 
     top->final();
     
     // Clean up
     if (trace) {
         tfp->close();
         delete tfp;
     }
     delete top;
     delete contextp;
     
     printf("Simulation completed. Register dump generated.\n");
     printf("Debug information has been saved to simulation_output.log\n");
     
     return 0;
 }
 