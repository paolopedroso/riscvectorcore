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
 
 vluint64_t main_time = 0;
 unsigned int total_cycles = 0;
 const unsigned int MAX_CYCLES = 300;  // Increased for comprehensive test

 // Function to swap bytes for endianness correction
 uint32_t swap_endianness(uint32_t value) {
     return ((value & 0xFF) << 24) |
            ((value & 0xFF00) << 8) |
            ((value & 0xFF0000) >> 8) |
            ((value & 0xFF000000) >> 24);
 }
 
 double sc_time_stamp() {
     return main_time;
 }
 
 // Enhanced helper function to print register values with endianness correction
 void print_registers(Vtop* top, std::ofstream& reg_file) {
     std::vector<std::string> reg_names = {
         "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
         "s0/fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
         "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
         "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
     };
     
     // Print register values with correct formatting
     for (int i = 0; i < 32; i++) {
         // Direct access to register array with endianness correction
         uint32_t raw_value = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
         
         // Apply endianness correction
         uint32_t value = swap_endianness(raw_value);
         
         // Write to file (corrected endianness)
         reg_file << "register x" << i << " = " << std::dec << value;
         if (i < reg_names.size()) {
             reg_file << " (" << reg_names[i] << ")";
         }
         reg_file << std::endl;
         
         // Print to console in hex and decimal (corrected endianness)
         std::cout << "x" << std::dec << std::setw(2) << std::setfill('0') << i 
                 << " (" << std::setw(5) << std::left << std::setfill(' ') 
                 << (i < reg_names.size() ? reg_names[i] : "----") << "): "
                 << "0x" << std::hex << std::setw(8) << std::setfill('0') << value 
                 << " (" << std::dec << value << ")" << std::endl;
                 
         // Print bytes to confirm endianness (corrected order)
         std::cout << "   RAW: 0x" << std::hex << raw_value 
                 << " (bytes: " 
                 << std::setw(2) << std::setfill('0') << (raw_value & 0xFF) << " "
                 << std::setw(2) << std::setfill('0') << ((raw_value >> 8) & 0xFF) << " "
                 << std::setw(2) << std::setfill('0') << ((raw_value >> 16) & 0xFF) << " "
                 << std::setw(2) << std::setfill('0') << ((raw_value >> 24) & 0xFF) << ")" << std::endl;
         
         std::cout << "   CORRECTED: 0x" << std::hex << value 
                 << " (bytes: " 
                 << std::setw(2) << std::setfill('0') << (value & 0xFF) << " "
                 << std::setw(2) << std::setfill('0') << ((value >> 8) & 0xFF) << " "
                 << std::setw(2) << std::setfill('0') << ((value >> 16) & 0xFF) << " "
                 << std::setw(2) << std::setfill('0') << ((value >> 24) & 0xFF) << ")" << std::endl;
     }
     
     // Simple format for verification with corrected endianness
     reg_file << "\n# Simple format for verification\n";
     for (int i = 0; i < 32; i++) {
         uint32_t value = swap_endianness(top->rootp->top__DOT__sregfile_inst__DOT__register[i]);
         reg_file << "x" << i << "=" << std::dec << value << std::endl;
     }
 }
 
 // Helper to dump memory contents with endianness correction
 void dump_memory_contents(Vtop* top, std::ofstream& mem_file) {
     mem_file << "# Memory Dump (First 64 bytes)" << std::endl;
     for (int i = 0; i < 64; i++) {
         uint8_t value = top->rootp->top__DOT__sdatamem_inst__DOT__memory[i];
         mem_file << "mem[" << std::dec << i << "] = 0x" 
                  << std::hex << std::setw(2) << std::setfill('0') 
                  << static_cast<int>(value) << std::endl;
     }
 }
 
 // Enhanced helper to dump pipeline state with endianness correction
 void dump_pipeline_state(Vtop* top, std::ofstream& debug_file) {
     debug_file << "================== Pipeline State ==================" << std::endl;
     debug_file << "PC: 0x" << std::hex << top->rootp->top__DOT__pc_out << std::endl;
     debug_file << "IF/ID PC: 0x" << top->rootp->top__DOT__if_id_pc << std::endl;
     debug_file << "IF/ID Instr: 0x" << top->rootp->top__DOT__if_id_instr << std::endl;
     
     debug_file << "ID/EX PC: 0x" << top->rootp->top__DOT__id_ex_pc << std::endl;
     debug_file << "ID/EX rs1_data: 0x" << std::hex << swap_endianness(top->rootp->top__DOT__id_ex_rs1_data) << std::endl;
     debug_file << "ID/EX rs2_data: 0x" << std::hex << swap_endianness(top->rootp->top__DOT__id_ex_rs2_data) << std::endl;
     debug_file << "ID/EX ALU op: " << std::dec << (int)top->rootp->top__DOT__id_ex_alu_op << std::endl;
     
     debug_file << "EX/MEM ALU result: 0x" << std::hex << swap_endianness(top->rootp->top__DOT__ex_mem_alu_result) << std::endl;
     debug_file << "EX/MEM rd_addr: " << std::dec << (int)top->rootp->top__DOT__ex_mem_rd_addr << std::endl;
     debug_file << "EX/MEM reg_write: " << (int)top->rootp->top__DOT__ex_mem_reg_write << std::endl;
     
     debug_file << "MEM/WB rd_addr: " << std::dec << (int)top->rootp->top__DOT__mem_wb_rd_addr << std::endl;
     debug_file << "MEM/WB reg_write: " << (int)top->rootp->top__DOT__mem_wb_reg_write << std::endl;
     debug_file << "MEM/WB result: 0x" << std::hex << swap_endianness(top->rootp->top__DOT__mem_wb_alu_result) << std::endl;
     
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
             
             // Calculate and print signed immediate
             imm = (int32_t)((instr & 0xFFF00000) >> 20);
             if (imm & 0x800) imm |= 0xFFFFF000; // Sign extension
             
             result += "x" + std::to_string(rd) + ", x" + std::to_string(rs1) + ", " + std::to_string(imm) + 
                      " (0x" + std::to_string(imm & 0xFFF) + ")";
             break;
             
         case 0x03: // Load
             result = "Load: ";
             if (funct3 == 0) result += "LB ";
             else if (funct3 == 1) result += "LH ";
             else if (funct3 == 2) result += "LW ";
             else if (funct3 == 4) result += "LBU ";
             else if (funct3 == 5) result += "LHU ";
             
             // Calculate and print signed immediate
             imm = (int32_t)((instr & 0xFFF00000) >> 20);
             if (imm & 0x800) imm |= 0xFFFFF000; // Sign extension
             
             result += "x" + std::to_string(rd) + ", " + std::to_string(imm) + "(x" + std::to_string(rs1) + ")";
             break;
             
         case 0x23: // Store
             result = "Store: ";
             imm1 = (instr >> 25) & 0x7F;
             imm2 = (instr >> 7) & 0x1F;
             imm = (imm1 << 5) | imm2;
             if (imm & 0x800) imm |= 0xFFFFF000; // Sign extension
             
             if (funct3 == 0) result += "SB ";
             else if (funct3 == 1) result += "SH ";
             else if (funct3 == 2) result += "SW ";
             
             result += "x" + std::to_string(rs2) + ", " + std::to_string(imm) + "(x" + std::to_string(rs1) + ")";
             break;
             
         case 0x63: // Branch
             result = "Branch: ";
             
             // Complex immediate calculation for B-type
             imm12 = (instr >> 31) & 0x1;
             imm11 = (instr >> 7) & 0x1;
             imm10_5 = (instr >> 25) & 0x3F;
             imm4_1 = (instr >> 8) & 0xF;
             imm = (imm12 << 12) | (imm11 << 11) | (imm10_5 << 5) | (imm4_1 << 1);
             if (imm & 0x1000) imm |= 0xFFFFE000; // Sign extension
             
             if (funct3 == 0) result += "BEQ ";
             else if (funct3 == 1) result += "BNE ";
             else if (funct3 == 4) result += "BLT ";
             else if (funct3 == 5) result += "BGE ";
             else if (funct3 == 6) result += "BLTU ";
             else if (funct3 == 7) result += "BGEU ";
             
             result += "x" + std::to_string(rs1) + ", x" + std::to_string(rs2) + 
                      ", PC+" + std::to_string(imm) + " (0x" + std::to_string(imm & 0x1FFF) + ")";
             break;
             
         case 0x6F: // JAL
             result = "JAL: ";
             
             // Complex immediate calculation for J-type
             imm20 = (instr >> 31) & 0x1;
             imm19_12 = (instr >> 12) & 0xFF;
             imm11 = (instr >> 20) & 0x1;
             imm10_1 = (instr >> 21) & 0x3FF;
             
             imm = (imm20 << 20) | (imm19_12 << 12) | (imm11 << 11) | (imm10_1 << 1);
             if (imm & 0x100000) imm |= 0xFFF00000; // Sign extension
             
             result += "x" + std::to_string(rd) + ", PC+" + std::to_string(imm) + 
                      " (0x" + std::to_string(imm & 0x1FFFFF) + ")";
             break;
             
         case 0x67: // JALR
             result = "JALR: ";
             
             // Calculate and print signed immediate
             imm = (int32_t)((instr & 0xFFF00000) >> 20);
             if (imm & 0x800) imm |= 0xFFFFF000; // Sign extension
             
             result += "x" + std::to_string(rd) + ", x" + std::to_string(rs1) + "+" + 
                      std::to_string(imm) + " (0x" + std::to_string(imm & 0xFFF) + ")";
             break;
             
         case 0x73: // System
             if ((instr & 0xFFFFFFFF) == 0x00100073)
                 result = "EBREAK";
             else
                 result = "SYSTEM";
             break;
     }
     
     return result;
 }
 
 // Track register changes for debugging with endianness correction
 void print_register_changes(Vtop* top, uint32_t* prev_regs) {
     bool changes = false;
     std::cout << "Register changes: ";
     
     for (int i = 0; i < 32; i++) {  // Include all registers for clarity
         uint32_t raw_value = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
         uint32_t current_value = swap_endianness(raw_value);
         
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
 
 // Simple test with identifiable values to verify endianness
 void run_endianness_test(Vtop* top) {
     std::cout << "\n======= ENDIANNESS TEST =======\n";
     
     // Test with specific values to help identify endianness issues
     // We'll manually inject values to verify raw vs. corrected display
     
     // Test values with distinctive byte patterns
     uint32_t test_value1 = 0x01020304;  // Little-endian: bytes 04, 03, 02, 01
     uint32_t test_value2 = 0x05060708;  // Little-endian: bytes 08, 07, 06, 05
     
     std::cout << "Test value 1: 0x" << std::hex << test_value1 << std::endl;
     std::cout << "  Bytes: "
              << std::setw(2) << std::setfill('0') << (test_value1 & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((test_value1 >> 8) & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((test_value1 >> 16) & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((test_value1 >> 24) & 0xFF) << std::endl;
              
     std::cout << "  Swapped: 0x" << std::hex << swap_endianness(test_value1) << std::endl;
     std::cout << "  Swapped bytes: "
              << std::setw(2) << std::setfill('0') << (swap_endianness(test_value1) & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((swap_endianness(test_value1) >> 8) & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((swap_endianness(test_value1) >> 16) & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((swap_endianness(test_value1) >> 24) & 0xFF) << std::endl;
     
     std::cout << "\nTest value 2: 0x" << std::hex << test_value2 << std::endl;
     std::cout << "  Bytes: "
              << std::setw(2) << std::setfill('0') << (test_value2 & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((test_value2 >> 8) & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((test_value2 >> 16) & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((test_value2 >> 24) & 0xFF) << std::endl;
              
     std::cout << "  Swapped: 0x" << std::hex << swap_endianness(test_value2) << std::endl;
     std::cout << "  Swapped bytes: "
              << std::setw(2) << std::setfill('0') << (swap_endianness(test_value2) & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((swap_endianness(test_value2) >> 8) & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((swap_endianness(test_value2) >> 16) & 0xFF) << " "
              << std::setw(2) << std::setfill('0') << ((swap_endianness(test_value2) >> 24) & 0xFF) << std::endl;
     
     // Verify result of addition with endianness correction
     uint32_t expected_sum = 0x06080A0C;  // 0x01020304 + 0x05060708
     std::cout << "\nExpected sum: 0x" << std::hex << expected_sum << std::endl;
     std::cout << "Swapped expected sum: 0x" << std::hex << swap_endianness(expected_sum) << std::endl;
     
     std::cout << "======= END ENDIANNESS TEST =======\n\n";
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
     
     // For register change tracking (with endianness correction)
     uint32_t prev_regs[32] = {0};  // To track register changes
     std::vector<uint32_t> executed_instructions;
     
     // Output diagnostic information
     std::cout << "Starting simulation of RISC-V processor..." << std::endl;
     std::cout << "Verilator version: " << Verilated::productName() 
               << " " << Verilated::productVersion() << std::endl;
     
     // Initialize simulation inputs
     top->clk = 0;
     top->rst_n = 0;
     
     // Open debug logs
     std::ofstream debug_log("debug_log.txt");
     std::ofstream instr_trace("instruction_trace.txt");
     std::ofstream mem_dump("memory_dump.txt");
     
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
     
     // Run endianness test
     run_endianness_test(top);
     
     // Examine instruction memory contents - ENHANCED DEBUG
     std::cout << "Instruction memory contents:" << std::endl;
     for (int i = 0; i < 14; i++) {  // Show the first 14 instructions
         uint32_t instr = top->rootp->top__DOT__instr_mem_inst__DOT__imem[i];
         if (instr != 0) {
             // Check if the instruction needs endianness correction
             bool needs_swap = ((instr & 0xFF) == 0) && ((instr & 0xFF000000) != 0);
             uint32_t display_instr = needs_swap ? swap_endianness(instr) : instr;
             
             std::cout << "  imem[" << std::hex << i << "] = 0x" << std::setw(8) << std::setfill('0') << display_instr;
             if (i == 2) std::cout << "  <- ADD x3, x1, x2";  // Highlight the ADD instruction
             std::cout << std::dec << std::endl;
             
             // Show both versions to help diagnose endianness issues
             if (needs_swap) {
                 std::cout << "    Original bytes: "
                          << std::hex << std::setw(2) << std::setfill('0') << (instr & 0xFF) << " "
                          << std::setw(2) << std::setfill('0') << ((instr >> 8) & 0xFF) << " "
                          << std::setw(2) << std::setfill('0') << ((instr >> 16) & 0xFF) << " "
                          << std::setw(2) << std::setfill('0') << ((instr >> 24) & 0xFF) << std::endl;
                 std::cout << "    Swapped bytes:  "
                          << std::hex << std::setw(2) << std::setfill('0') << (display_instr & 0xFF) << " "
                          << std::setw(2) << std::setfill('0') << ((display_instr >> 8) & 0xFF) << " "
                          << std::setw(2) << std::setfill('0') << ((display_instr >> 16) & 0xFF) << " "
                          << std::setw(2) << std::setfill('0') << ((display_instr >> 24) & 0xFF) << std::endl;
             }
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
         
         // Evaluate the design
         top->eval();
         
         // Dump trace
         if (trace) {
             tfp->dump(main_time);
         }
         
         // Execute ALU and other logic on clock edge
         if (top->clk && top->rst_n) {
             // Track execution on positive clock edge
             if (main_time % 2 == 1) {
                 // Format instruction for human readability
                 uint32_t raw_instr = top->rootp->top__DOT__instr;
                 bool needs_swap = ((raw_instr & 0xFF) == 0) && ((raw_instr & 0xFF000000) != 0);
                 uint32_t instr = needs_swap ? swap_endianness(raw_instr) : raw_instr;
                 
                 std::string decoded = decode_instruction(instr);
                 uint32_t current_pc = top->rootp->top__DOT__pc_out;
                 
                 // Debugging output to verify instruction endianness
                 std::cout << "Instruction at PC 0x" << std::hex << current_pc << ":" << std::endl;
                 std::cout << "  Raw:     0x" << std::setw(8) << std::setfill('0') << raw_instr << std::endl;
                 if (needs_swap) {
                     std::cout << "  Swapped: 0x" << std::setw(8) << std::setfill('0') << instr << std::endl;
                 }
                 std::cout << "  Decoded: " << decoded << std::endl;
                 
                 // Track executed instructions
                 uint32_t current_instr = top->rootp->top__DOT__if_id_instr;
                 if (current_instr != 0) {
                     uint32_t corrected_instr = ((current_instr & 0xFF) == 0) ? 
                                               swap_endianness(current_instr) : current_instr;
                     executed_instructions.push_back(corrected_instr);
                 }
                 
                 // Track register changes every cycle with endianness correction
                 print_register_changes(top, prev_regs);
                 
                 // Check for EBREAK instruction
                 if (instr == 0x00100073) { // EBREAK opcode
                     std::cout << "EBREAK instruction detected at PC=0x" << std::hex << current_pc 
                               << " - Ending simulation" << std::dec << std::endl;
                     ebreak_detected = true;
                 }
                 
                 // Monitor specific instructions
                 if (instr == 0x002081b3) { // ADD x3, x1, x2
                     std::cout << "FOUND ADD INSTRUCTION (x3 = x1 + x2)" << std::endl;
                     
                     // Debug output for registers and ALU inputs/outputs
                     uint32_t rs1_val = swap_endianness(top->rootp->top__DOT__rs1_data);
                     uint32_t rs2_val = swap_endianness(top->rootp->top__DOT__rs2_data);
                     std::cout << "REGISTER VALUES: x1=" << std::hex << rs1_val << ", x2=" << rs2_val << std::endl;
                     
                     // Debug ALU operation
                     uint32_t alu_in1 = swap_endianness(top->rootp->top__DOT__alu_input_a);
                     uint32_t alu_in2 = swap_endianness(top->rootp->top__DOT__alu_input_b);
                     uint32_t alu_out = swap_endianness(top->rootp->top__DOT__alu_result);
                     std::cout << "ALU INPUTS: " << std::hex << alu_in1 << " + " << alu_in2 
                              << " = " << alu_out << std::dec << std::endl;
                 }
                 
                 // Dump detailed pipeline state occasionally
                 if (total_cycles % 10 == 0) {
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
     std::cout << "Simulation completed at time: " << main_time << std::endl;
     std::cout << "Total cycles executed: " << total_cycles << std::endl;
     
     // Print actual register values showing both raw and corrected values
     std::cout << "\n=== Register Endianness Comparison ===\n";
     for (int i = 1; i <= 12; i++) {  // Print only registers x1-x12 for brevity
         uint32_t raw_val = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
         uint32_t corrected_val = swap_endianness(raw_val);
         
         std::cout << "x" << i << ": RAW=0x" << std::hex << std::setw(8) << std::setfill('0') << raw_val
                  << "  CORRECTED=0x" << std::setw(8) << std::setfill('0') << corrected_val
                  << std::dec << std::endl;
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
     
     return 0;
 }