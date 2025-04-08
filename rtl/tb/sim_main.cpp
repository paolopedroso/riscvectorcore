/*
 * Testbench C++ Script
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
 #include "Vtop.h"
 #include "Vtop___024root.h"
 
 vluint64_t main_time = 0;
 unsigned int total_cycles = 0;
 const unsigned int MAX_CYCLES = 200;  // Reduced max cycles to prevent excessive simulation time
 
 double sc_time_stamp() {
     return main_time;
 }
 
 // Helper function to print register values - COMPLETELY REWRITTEN
 void print_registers(Vtop* top, std::ofstream& reg_file) {
     std::vector<std::string> reg_names = {
         "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
         "s0/fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
         "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
         "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
     };
     
     // Print register values with correct formatting
     for (int i = 0; i < 32; i++) {
         // Direct access to register array
         uint32_t value = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
         
         // Write to file
         reg_file << "register x" << i << " = " << std::dec << value;
         if (i < reg_names.size()) {
             reg_file << " (" << reg_names[i] << ")";
         }
         reg_file << std::endl;
         
         // Print to console - careful not to use i for indexing in the printf format
         std::cout << "x" << std::setw(2) << std::setfill('0') << i 
                 << " (" << std::setw(5) << std::left << std::setfill(' ') 
                 << (i < reg_names.size() ? reg_names[i] : "----") << "): "
                 << "0x" << std::hex << std::setw(8) << std::setfill('0') << value 
                 << " (" << std::dec << value << ")" << std::endl;
     }
     
     // Simple format for verification
     reg_file << "\n# Simple format for verification\n";
     for (int i = 0; i < 32; i++) {
         uint32_t value = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
         reg_file << "x" << i << "=" << std::dec << value << std::endl;
     }
 }
 
 // Helper to dump pipeline state
 void dump_pipeline_state(Vtop* top, std::ofstream& debug_file) {
     debug_file << "================== Pipeline State ==================" << std::endl;
     debug_file << "PC: 0x" << std::hex << top->rootp->top__DOT__pc_out << std::endl;
     debug_file << "IF/ID PC: 0x" << top->rootp->top__DOT__if_id_pc << std::endl;
     debug_file << "IF/ID Instr: 0x" << top->rootp->top__DOT__if_id_instr << std::endl;
     
     debug_file << "ID/EX PC: 0x" << top->rootp->top__DOT__id_ex_pc << std::endl;
     debug_file << "ID/EX rs1_data: 0x" << top->rootp->top__DOT__id_ex_rs1_data << std::endl;
     debug_file << "ID/EX rs2_data: 0x" << top->rootp->top__DOT__id_ex_rs2_data << std::endl;
     debug_file << "ID/EX ALU op: " << std::dec << (int)top->rootp->top__DOT__id_ex_alu_op << std::endl;
     
     debug_file << "EX/MEM ALU result: 0x" << std::hex << top->rootp->top__DOT__ex_mem_alu_result << std::endl;
     debug_file << "EX/MEM rd_addr: " << std::dec << (int)top->rootp->top__DOT__ex_mem_rd_addr << std::endl;
     debug_file << "EX/MEM reg_write: " << (int)top->rootp->top__DOT__ex_mem_reg_write << std::endl;
     
     debug_file << "MEM/WB rd_addr: " << (int)top->rootp->top__DOT__mem_wb_rd_addr << std::endl;
     debug_file << "MEM/WB reg_write: " << (int)top->rootp->top__DOT__mem_wb_reg_write << std::endl;
     debug_file << "MEM/WB result: 0x" << std::hex << top->rootp->top__DOT__mem_wb_alu_result << std::endl;
     
     debug_file << "Control signals:" << std::endl;
     debug_file << "  stall_pipeline: " << std::dec << (int)top->rootp->top__DOT__stall_pipeline << std::endl;
     debug_file << "  take_branch: " << (int)top->rootp->top__DOT__take_branch << std::endl;
     debug_file << "  pc_src: " << (int)top->rootp->top__DOT__pc_src << std::endl;
     debug_file << "==================================================" << std::endl;
 }
 
 // Enhanced instruction decoder to better understand JAL and branches
 std::string decode_instruction(uint32_t instr) {
     uint32_t opcode = instr & 0x7F;
     uint32_t rd = (instr >> 7) & 0x1F;
     uint32_t rs1 = (instr >> 15) & 0x1F;
     uint32_t rs2 = (instr >> 20) & 0x1F;
     uint32_t funct3 = (instr >> 12) & 0x7;
     uint32_t funct7 = (instr >> 25) & 0x7F;
     
     std::string result = "Unknown instruction: " + std::to_string(instr);
     
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
         case 0x13: // I-type
             result = "I-type: ";
             if (funct3 == 0) result += "ADDI ";
             else if (funct3 == 1) result += "SLLI ";
             else if (funct3 == 2) result += "SLTI ";
             else if (funct3 == 3) result += "SLTIU ";
             else if (funct3 == 4) result += "XORI ";
             else if (funct3 == 5 && ((instr >> 26) & 0x3F) == 0) result += "SRLI ";
             else if (funct3 == 5 && ((instr >> 26) & 0x3F) == 0x10) result += "SRAI ";
             else if (funct3 == 6) result += "ORI ";
             else if (funct3 == 7) result += "ANDI ";
             result += "x" + std::to_string(rd) + ", x" + std::to_string(rs1) + ", " + std::to_string((int32_t)((instr & 0xFFF00000) >> 20));
             break;
         case 0x03: // Load
             result = "Load: ";
             if (funct3 == 0) result += "LB ";
             else if (funct3 == 1) result += "LH ";
             else if (funct3 == 2) result += "LW ";
             else if (funct3 == 4) result += "LBU ";
             else if (funct3 == 5) result += "LHU ";
             result += "x" + std::to_string(rd) + ", " + std::to_string((int32_t)((instr & 0xFFF00000) >> 20)) + "(x" + std::to_string(rs1) + ")";
             break;
         case 0x23: // Store
             {
                 int32_t imm = ((instr >> 25) << 5) | ((instr >> 7) & 0x1F);
                 result = "Store: ";
                 if (funct3 == 0) result += "SB ";
                 else if (funct3 == 1) result += "SH ";
                 else if (funct3 == 2) result += "SW ";
                 result += "x" + std::to_string(rs2) + ", " + std::to_string(imm) + "(x" + std::to_string(rs1) + ")";
             }
             break;
         case 0x6F: // JAL
             {
                 // J-type immediate calculation
                 int32_t imm = 0;
                 imm |= ((instr >> 31) & 0x1) << 20;       // imm[20]
                 imm |= ((instr >> 12) & 0xFF) << 12;      // imm[19:12]
                 imm |= ((instr >> 20) & 0x1) << 11;       // imm[11]
                 imm |= ((instr >> 21) & 0x3FF) << 1;      // imm[10:1]
                 // Sign extend
                 if ((imm >> 20) & 1) imm |= 0xFFE00000;
                 
                 result = "JAL: x" + std::to_string(rd) + ", " + std::to_string(imm) + " (offset)";
             }
             break;
         case 0x67: // JALR
             {
                 int32_t imm = (int32_t)((instr & 0xFFF00000) >> 20);
                 // Sign extend
                 if ((imm >> 11) & 1) imm |= 0xFFFFF000;
                 
                 result = "JALR: x" + std::to_string(rd) + ", x" + std::to_string(rs1) + ", " + std::to_string(imm);
             }
             break;
         case 0x63: // Branch
             {
                 int32_t imm = 0;
                 imm |= ((instr >> 31) & 0x1) << 12;       // imm[12]
                 imm |= ((instr >> 7) & 0x1) << 11;        // imm[11]
                 imm |= ((instr >> 25) & 0x3F) << 5;       // imm[10:5]
                 imm |= ((instr >> 8) & 0xF) << 1;         // imm[4:1]
                 // Sign extend
                 if ((imm >> 12) & 1) imm |= 0xFFFFE000;
                 
                 result = "Branch: ";
                 if (funct3 == 0) result += "BEQ ";
                 else if (funct3 == 1) result += "BNE ";
                 else if (funct3 == 4) result += "BLT ";
                 else if (funct3 == 5) result += "BGE ";
                 else if (funct3 == 6) result += "BLTU ";
                 else if (funct3 == 7) result += "BGEU ";
                 result += "x" + std::to_string(rs1) + ", x" + std::to_string(rs2) + ", " + std::to_string(imm);
             }
             break;
     }
     
     return result;
 }
 
 // Add this function to print register changes for analysis
 void print_register_changes(Vtop* top, uint32_t* prev_regs) {
     bool changes = false;
     std::cout << "Register changes: ";
     
     for (int i = 1; i < 32; i++) {  // Skip x0 which is always 0
         uint32_t current_value = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
         if (current_value != prev_regs[i]) {
             if (changes) std::cout << ", ";
             std::cout << "x" << i << ": 0x" << std::hex << prev_regs[i] 
                      << " -> 0x" << current_value << std::dec;
             prev_regs[i] = current_value;
             changes = true;
         }
     }
     
     if (!changes) {
         std::cout << "None";
     }
     std::cout << std::endl;
 }
 
 int main(int argc, char** argv) {
     // Create Verilator context
     VerilatedContext* contextp = new VerilatedContext;
     
     // Initialize Verilator
     contextp->commandArgs(argc, argv);
     
     // Create top-level model
     Vtop* top = new Vtop(contextp);
     
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
     uint32_t prev_regs[32] = {0};  // To track register changes
     std::vector<uint32_t> executed_instructions;
     
     // Output diagnostic information
     std::cout << "Starting simulation of RISC-V processor..." << std::endl;
     std::cout << "Verilator version: " << Verilated::productName() 
               << " " << Verilated::productVersion() << std::endl;
     
     // Initialize simulation inputs
     top->clk = 0;
     top->rst_n = 0;
     
     // Open debug log
     std::ofstream debug_log("debug_log.txt");
     std::ofstream instr_trace("instruction_trace.txt");
     
     std::cout << "Asserting reset..." << std::endl;
     
     // Hold reset for multiple cycles to ensure proper initialization
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
     std::cout << "Reset released at time " << main_time << std::endl;
     debug_log << "Reset released at time " << main_time << std::endl;
     
     // Check initial PC value
     top->eval();
     std::cout << "Initial PC value: 0x" << std::hex << top->rootp->top__DOT__pc_out << std::dec << std::endl;
     
     // Examine instruction memory contents - ADDED DEBUG
     std::cout << "Instruction memory contents:" << std::endl;
     for (int i = 0; i < 15; i++) {
         uint32_t instr = top->rootp->top__DOT__instr_mem_inst__DOT__imem[i];
         std::cout << "  imem[" << i << "] = 0x" << std::hex << instr << std::dec;
         if (i == 2 && instr == 0x002081b3) {
             std::cout << "  <- ADD x3, x1, x2";
         }
         std::cout << std::endl;
     }
     
     // Track previous PC to detect program completion
     uint32_t previous_pc = 0;
     uint32_t same_pc_count = 0;
     bool program_completed = false;
     
     // Print program instructions for reference
     std::cout << "Instruction memory initialized with test program" << std::endl;
     for (int i = 0; i < 15; i++) { // Print the first 15 instructions 
         if (top->rootp->top__DOT__instr_mem_inst__DOT__imem[i] != 0) {
             std::cout << "  imem[" << i << "] = 0x" << std::hex 
                       << top->rootp->top__DOT__instr_mem_inst__DOT__imem[i] << std::endl;
         }
     }
     std::cout << std::dec;
     
     // Debug flag to track ADD instruction
     bool add_instruction_passed = false;
     
     // Simulation loop
     while (!contextp->gotFinish() && total_cycles < MAX_CYCLES && !program_completed) {
         // Toggle clock
         top->clk = !top->clk;
         
         // Evaluate the design
         top->eval();
         
         // Dump trace - only every few cycles to reduce file size
         if (trace && (total_cycles % 5 == 0 || main_time < 100)) {
             tfp->dump(main_time);
         }
         
         // Special debug for ADD instruction
         if (top->clk && top->rst_n && top->rootp->top__DOT__if_id_instr == 0x002081b3) {
             std::cout << "FOUND ADD INSTRUCTION (x3 = x1 + x2)" << std::endl;
             add_instruction_passed = true;
         }
         
         // Track ADD instruction through pipeline
         if (add_instruction_passed && top->clk && top->rst_n) {
             if (top->rootp->top__DOT__id_ex_instr == 0x002081b3) {
                 std::cout << "ADD in ID/EX: rs1=x" << (int)top->rootp->top__DOT__id_ex_rs1_addr 
                           << " (0x" << std::hex << top->rootp->top__DOT__id_ex_rs1_data << ")"
                           << ", rs2=x" << (int)top->rootp->top__DOT__id_ex_rs2_addr
                           << " (0x" << top->rootp->top__DOT__id_ex_rs2_data << ")" << std::dec
                           << ", rd=x" << (int)top->rootp->top__DOT__id_ex_rd_addr << std::endl;
             }
             if (top->rootp->top__DOT__ex_mem_instr == 0x002081b3) {
                 std::cout << "ADD in EX/MEM: ALU result = 0x" << std::hex 
                           << top->rootp->top__DOT__ex_mem_alu_result << std::dec
                           << ", rd=x" << (int)top->rootp->top__DOT__ex_mem_rd_addr 
                           << ", reg_write=" << (int)top->rootp->top__DOT__ex_mem_reg_write << std::endl;
             }
             if (top->rootp->top__DOT__mem_wb_instr == 0x002081b3) {
                 std::cout << "ADD in MEM/WB: result = 0x" << std::hex 
                           << top->rootp->top__DOT__mem_wb_alu_result << std::dec
                           << ", rd=x" << (int)top->rootp->top__DOT__mem_wb_rd_addr 
                           << ", reg_write=" << (int)top->rootp->top__DOT__mem_wb_reg_write << std::endl;
             }
         }
         
         // Detailed cycle logging on positive clock edge
         if (top->clk && top->rst_n) {
             // Calculate actual cycle
             if (main_time % 2 == 1) {
                 // Format instruction for human readability
                 uint32_t instr = top->rootp->top__DOT__instr;
                 std::string decoded = decode_instruction(instr);
                 uint32_t current_pc = top->rootp->top__DOT__pc_out;
                 
                 // Log PC and instruction
                 debug_log << "Cycle " << total_cycles 
                         << " PC: 0x" << std::hex << current_pc 
                         << " Instruction: 0x" << instr
                         << std::dec << std::endl;
                 
                 // More detailed instruction trace
                 instr_trace << "Cycle " << std::setw(3) << total_cycles 
                         << " PC: 0x" << std::hex << std::setw(8) << std::setfill('0')
                         << current_pc 
                         << " Instr: 0x" << std::setw(8) << instr
                         << std::dec << std::setfill(' ') << " | " << decoded << std::endl;
                 
                 // Report on current cycle's instruction for console
                 if (total_cycles < 20) { // Only for early cycles to avoid spam
                     std::cout << "Cycle " << total_cycles << ": PC=0x" 
                              << std::hex << std::setw(8) << std::setfill('0') << current_pc
                              << std::dec << std::endl;
                 }
                 
                 // Track executed instructions
                 uint32_t current_instr = top->rootp->top__DOT__if_id_instr;
                 if (current_instr != 0) {
                     executed_instructions.push_back(current_instr);
                 }
                 
                 // Track register changes every cycle
                 print_register_changes(top, prev_regs);
                 
                 // Dump detailed pipeline state every 5 cycles
                 if (total_cycles % 5 == 0) {
                     dump_pipeline_state(top, debug_log);
                 }
                 
                 // Check for program completion - detect if PC is not changing
                 if (current_pc == previous_pc) {
                     same_pc_count++;
                     if (same_pc_count >= 10) {
                         std::cout << "Program appears to have completed (PC not changing for 10 cycles at 0x" 
                                  << std::hex << current_pc << std::dec << ")" << std::endl;
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
     
     // Check if simulation timed out
     if (total_cycles >= MAX_CYCLES) {
         std::cout << "\n*** SIMULATION TIMEOUT ***\n";
         std::cout << "Reached maximum cycles (" << MAX_CYCLES << "). Simulation may be stuck in a loop.\n";
         debug_log << "\n*** SIMULATION TIMEOUT ***\n";
         debug_log << "Reached maximum cycles (" << MAX_CYCLES << "). Simulation may be stuck in a loop.\n";
     }
     
     // Final state dump
     debug_log << "\n=== Final Pipeline State ===\n";
     dump_pipeline_state(top, debug_log);
     
     // Record register state at end of simulation
     std::cout << "\n=== Final Register Values ===\n";
     std::ofstream regDump("register_dump.txt");
     print_registers(top, regDump);
     regDump.close();
     
     // Print summary of executed instructions
     std::cout << "\n=== Summary of Executed Instructions ===\n";
     for (size_t i = 0; i < executed_instructions.size(); i++) {
         std::cout << i << ": 0x" << std::hex << executed_instructions[i] 
                  << " - " << decode_instruction(executed_instructions[i]) << std::dec << std::endl;
     }
     
     // Finalize
     top->final();
     
     // Clean up
     if (trace) {
         tfp->close();
         delete tfp;
     }
     delete top;
     delete contextp;
     
     std::cout << "Simulation completed at time: " << main_time << std::endl;
     std::cout << "Total cycles executed: " << total_cycles << std::endl;
     return 0;
 }
 