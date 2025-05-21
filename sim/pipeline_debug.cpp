/*
 * RISC-V Pipeline State Debugger
 *
 * This utility tracks and displays the complete pipeline state at each clock cycle,
 * with special focus on forwarding logic and data hazards. It's designed to help
 * debug forwarding issues by showing exactly how data flows through the pipeline.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cstdint>

class PipelineDebugger {
private:
    // File for debug output
    std::ofstream debug_file;
    
    // Cycle counter
    uint64_t cycle_count;
    
    // Previous register values for change detection
    uint32_t prev_regs[32];
    
    // Current register values
    uint32_t current_regs[32];
    
    // Store previous forwarding signals
    uint32_t prev_forward_a;
    uint32_t prev_forward_b;
    
    // Instruction mapping for better debug output
    std::map<uint32_t, std::string> instr_desc;
    
    // Helper function to decode instruction
    std::string decode_instruction(uint32_t instr) {
        // Basic instruction decoder - can be expanded
        uint8_t opcode = instr & 0x7F;
        uint8_t rd = (instr >> 7) & 0x1F;
        uint8_t rs1 = (instr >> 15) & 0x1F;
        uint8_t rs2 = (instr >> 20) & 0x1F;
        uint8_t funct3 = (instr >> 12) & 0x7;
        uint8_t funct7 = (instr >> 25) & 0x7F;
        
        std::stringstream ss;
        
        switch(opcode) {
            case 0x33: // R-type
                if (funct3 == 0 && funct7 == 0)
                    ss << "ADD x" << (int)rd << ", x" << (int)rs1 << ", x" << (int)rs2;
                else if (funct3 == 0 && funct7 == 0x20)
                    ss << "SUB x" << (int)rd << ", x" << (int)rs1 << ", x" << (int)rs2;
                else
                    ss << "R-TYPE x" << (int)rd << ", x" << (int)rs1 << ", x" << (int)rs2;
                break;
                
            case 0x13: // I-type ALU
                if (funct3 == 0)
                    ss << "ADDI x" << (int)rd << ", x" << (int)rs1 << ", " << (int)(instr >> 20);
                else if (funct3 == 1)
                    ss << "SLLI x" << (int)rd << ", x" << (int)rs1 << ", " << (int)(rs2);
                else
                    ss << "I-TYPE x" << (int)rd << ", x" << (int)rs1;
                break;
                
            case 0x03: // Load
                ss << "LOAD x" << (int)rd << ", " << (int)(instr >> 20) << "(x" << (int)rs1 << ")";
                break;
                
            case 0x23: // Store
                {
                    int32_t imm = ((instr >> 25) << 5) | ((instr >> 7) & 0x1F);
                    // Sign extend
                    if (imm & 0x800) imm |= 0xFFFFF000;
                    ss << "STORE x" << (int)rs2 << ", " << imm << "(x" << (int)rs1 << ")";
                }
                break;
                
            case 0x63: // Branch
                ss << "BRANCH";
                break;
                
            case 0x6F: // JAL
                ss << "JAL x" << (int)rd;
                break;
                
            case 0x67: // JALR
                ss << "JALR x" << (int)rd << ", x" << (int)rs1;
                break;
                
            case 0x73: // System
                if (instr == 0x00100073)
                    ss << "EBREAK";
                else
                    ss << "SYSTEM";
                break;
                
            default:
                if (instr == 0)
                    ss << "NOP (0x00000000)";
                else
                    ss << "UNKNOWN (0x" << std::hex << instr << ")";
        }
        
        return ss.str();
    }
    
public:
    PipelineDebugger() : cycle_count(0), prev_forward_a(0), prev_forward_b(0) {
        // Initialize register arrays
        for (int i = 0; i < 32; i++) {
            prev_regs[i] = 0;
            current_regs[i] = 0;
        }
        
        // Open debug file
        debug_file.open("pipeline_trace.log");
        if (!debug_file.is_open()) {
            std::cerr << "Failed to open pipeline_trace.log for writing!" << std::endl;
        }
        
        // Print header
        debug_file << "=======================================" << std::endl;
        debug_file << "RISC-V Pipeline State Debugger" << std::endl;
        debug_file << "=======================================" << std::endl;
        debug_file << std::endl;
    }
    
    ~PipelineDebugger() {
        if (debug_file.is_open()) {
            debug_file.close();
        }
    }
    
    // Update this function with pointers to your top module's signals
    void update_state(
        // Top module pointer
        Vtop* top,
        
        // Pipeline control signals
        bool stall_pipeline,
        bool pc_write,
        bool branch_taken,
        
        // Forwarding signals
        uint32_t forward_a,
        uint32_t forward_b,
        
        // Instruction decode signals
        uint32_t if_id_instr,
        uint32_t id_ex_instr,
        uint32_t ex_mem_instr,
        uint32_t mem_wb_instr,
        
        // Register addresses
        uint32_t rs1_addr,
        uint32_t rs2_addr,
        uint32_t id_ex_rs1_addr,
        uint32_t id_ex_rs2_addr,
        uint32_t id_ex_rd_addr,
        uint32_t ex_mem_rd_addr,
        uint32_t mem_wb_rd_addr,
        
        // Data values
        uint32_t rs1_data,
        uint32_t rs2_data,
        uint32_t id_ex_rs1_data,
        uint32_t id_ex_rs2_data,
        uint32_t alu_result,
        uint32_t ex_mem_alu_result,
        uint32_t mem_rdata,
        uint32_t wb_data,
        
        // Control signals
        bool reg_write_en,
        bool id_ex_reg_write,
        bool ex_mem_reg_write,
        bool mem_wb_reg_write,
        bool id_ex_mem_write,
        bool ex_mem_mem_write,
        
        // Store specific signals
        uint32_t ex_mem_rs2_data
    ) {
        cycle_count++;
        
        // Update register values (assuming we can access them directly)
        for (int i = 0; i < 32; i++) {
            // Access register file from the top module - adjust this based on your actual path
            current_regs[i] = top->rootp->top__DOT__sregfile_inst__DOT__register[i];
        }
        
        // Start a new section for this cycle
        debug_file << "\n=============== CYCLE " << cycle_count << " ===============\n";
        
        // PC and instruction information
        debug_file << "PC = 0x" << std::hex << std::setw(8) << std::setfill('0') 
                  << top->rootp->top__DOT__pc_out << "\n";
                  
        // Print pipeline state
        debug_file << "\nPIPELINE STATE:\n";
        debug_file << "  IF/ID: " << decode_instruction(if_id_instr) << " (0x" << std::hex << if_id_instr << ")\n";
        debug_file << "  ID/EX: " << decode_instruction(id_ex_instr) << " (0x" << std::hex << id_ex_instr << ")\n";
        debug_file << "  EX/MEM: " << decode_instruction(ex_mem_instr) << " (0x" << std::hex << ex_mem_instr << ")\n";
        debug_file << "  MEM/WB: " << decode_instruction(mem_wb_instr) << " (0x" << std::hex << mem_wb_instr << ")\n";
        
        // Control signals
        debug_file << "\nCONTROL SIGNALS:\n";
        debug_file << "  Stall = " << stall_pipeline << ", PC Write = " << pc_write 
                  << ", Branch Taken = " << branch_taken << "\n";
        debug_file << "  ID/EX Reg Write = " << id_ex_reg_write 
                  << ", EX/MEM Reg Write = " << ex_mem_reg_write 
                  << ", MEM/WB Reg Write = " << mem_wb_reg_write << "\n";
        debug_file << "  ID/EX Mem Write = " << id_ex_mem_write 
                  << ", EX/MEM Mem Write = " << ex_mem_mem_write << "\n";
        
        // Forwarding information - highlight changes
        debug_file << "\nFORWARDING SIGNALS:\n";
        
        // Forward A
        if (forward_a != prev_forward_a) {
            debug_file << "  >> FORWARD_A changed to " << forward_a << " <<\n";
        } else {
            debug_file << "  FORWARD_A = " << forward_a << "\n";
        }
        
        // Forward B
        if (forward_b != prev_forward_b) {
            debug_file << "  >> FORWARD_B changed to " << forward_b << " <<\n";
        } else {
            debug_file << "  FORWARD_B = " << forward_b << "\n";
        }
        
        // Register addresses across pipeline
        debug_file << "\nREGISTER ADDRESSES:\n";
        debug_file << "  Decode: rs1 = x" << rs1_addr << ", rs2 = x" << rs2_addr << "\n";
        debug_file << "  ID/EX: rs1 = x" << id_ex_rs1_addr << ", rs2 = x" << id_ex_rs2_addr 
                  << ", rd = x" << id_ex_rd_addr << "\n";
        debug_file << "  EX/MEM: rd = x" << ex_mem_rd_addr << "\n";
        debug_file << "  MEM/WB: rd = x" << mem_wb_rd_addr << "\n";
        
        // Data values across pipeline
        debug_file << "\nDATA VALUES:\n";
        debug_file << "  Decode: rs1_data = 0x" << std::hex << rs1_data 
                  << ", rs2_data = 0x" << rs2_data << "\n";
        debug_file << "  ID/EX: rs1_data = 0x" << id_ex_rs1_data 
                  << ", rs2_data = 0x" << id_ex_rs2_data << "\n";
        debug_file << "  EX/MEM: alu_result = 0x" << ex_mem_alu_result 
                  << ", rs2_data = 0x" << ex_mem_rs2_data << "\n";
        debug_file << "  MEM/WB: wb_data = 0x" << wb_data << "\n";
        
        // Register changes
        debug_file << "\nREGISTER CHANGES:\n";
        for (int i = 1; i < 32; i++) {  // Skip x0 (always 0)
            if (current_regs[i] != prev_regs[i]) {
                debug_file << "  x" << i << ": 0x" << std::hex << prev_regs[i] 
                          << " -> 0x" << current_regs[i] << "\n";
            }
        }
        
        // Special store detection
        if (id_ex_mem_write || ex_mem_mem_write) {
            debug_file << "\n!!! STORE INSTRUCTION DETECTED !!!\n";
            
            if (id_ex_mem_write) {
                debug_file << "  In ID/EX stage: rs2 = x" << id_ex_rs2_addr 
                          << ", data = 0x" << std::hex << id_ex_rs2_data 
                          << ", forward_b = " << forward_b << "\n";
                          
                // Special focus on register 3 (the problematic one)
                if (id_ex_rs2_addr == 3) {
                    debug_file << "  !!! STORE USING x3 !!! Current value = 0x" 
                              << std::hex << current_regs[3] << "\n";
                              
                    // Show what would be selected by the forwarding mux
                    debug_file << "  If forward_b = 0: Would use 0x" << std::hex << id_ex_rs2_data << "\n";
                    debug_file << "  If forward_b = 1: Would use 0x" << std::hex << wb_data << "\n";
                    debug_file << "  If forward_b = 2: Would use 0x" << std::hex << ex_mem_alu_result << "\n";
                }
            }
            
            if (ex_mem_mem_write) {
                debug_file << "  In EX/MEM stage: rs2 = x" << id_ex_rs2_addr 
                          << ", data actually being stored = 0x" << std::hex << ex_mem_rs2_data << "\n";
            }
        }
        
        // Update previous values for next cycle
        for (int i = 0; i < 32; i++) {
            prev_regs[i] = current_regs[i];
        }
        prev_forward_a = forward_a;
        prev_forward_b = forward_b;
    }
};