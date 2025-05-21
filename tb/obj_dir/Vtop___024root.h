// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        CData/*0:0*/ top__DOT__stall_pipeline;
        CData/*0:0*/ top__DOT__take_branch;
        CData/*0:0*/ top__DOT__pc_src;
        CData/*4:0*/ top__DOT__rs1_addr;
        CData/*4:0*/ top__DOT__rs2_addr;
        CData/*4:0*/ top__DOT__rd_addr;
        CData/*0:0*/ top__DOT__reg_write_en;
        CData/*0:0*/ top__DOT__imm_valid;
        CData/*3:0*/ top__DOT__alu_op;
        CData/*0:0*/ top__DOT__mem_read;
        CData/*0:0*/ top__DOT__mem_write;
        CData/*1:0*/ top__DOT__mem_size;
        CData/*0:0*/ top__DOT__branch;
        CData/*0:0*/ top__DOT__jump;
        CData/*1:0*/ top__DOT__result_src;
        CData/*0:0*/ top__DOT__uses_rs1;
        CData/*0:0*/ top__DOT__uses_rs2;
        CData/*0:0*/ top__DOT__detected_infinite_loop;
        CData/*1:0*/ top__DOT__forward_a;
        CData/*1:0*/ top__DOT__forward_b;
        CData/*4:0*/ top__DOT__id_ex_rs1_addr;
        CData/*4:0*/ top__DOT__id_ex_rs2_addr;
        CData/*4:0*/ top__DOT__id_ex_rd_addr;
        CData/*0:0*/ top__DOT__id_ex_reg_write;
        CData/*0:0*/ top__DOT__id_ex_mem_read;
        CData/*0:0*/ top__DOT__id_ex_mem_write;
        CData/*1:0*/ top__DOT__id_ex_mem_size;
        CData/*0:0*/ top__DOT__id_ex_branch;
        CData/*0:0*/ top__DOT__id_ex_jump;
        CData/*1:0*/ top__DOT__id_ex_result_src;
        CData/*3:0*/ top__DOT__id_ex_alu_op;
        CData/*0:0*/ top__DOT__id_ex_imm_valid;
        CData/*4:0*/ top__DOT__ex_mem_rd_addr;
        CData/*0:0*/ top__DOT__ex_mem_reg_write;
        CData/*0:0*/ top__DOT__ex_mem_mem_read;
        CData/*0:0*/ top__DOT__ex_mem_mem_write;
        CData/*1:0*/ top__DOT__ex_mem_mem_size;
        CData/*1:0*/ top__DOT__ex_mem_result_src;
        CData/*0:0*/ top__DOT__ex_mem_zero_flag;
        CData/*0:0*/ top__DOT__ex_mem_branch;
        CData/*0:0*/ top__DOT__ex_mem_jump;
        CData/*4:0*/ top__DOT__mem_wb_rd_addr;
        CData/*0:0*/ top__DOT__mem_wb_reg_write;
        CData/*1:0*/ top__DOT__mem_wb_result_src;
        CData/*0:0*/ top__DOT__jalr;
        CData/*0:0*/ top__DOT__id_ex_jalr;
        CData/*0:0*/ top__DOT__ex_mem_jalr;
        CData/*4:0*/ top__DOT__unnamedblk3__DOT__local_rs2_addr;
        CData/*0:0*/ top__DOT__sdecode_inst__DOT__is_r_type;
        CData/*0:0*/ top__DOT__sdecode_inst__DOT__is_i_type;
        CData/*0:0*/ top__DOT__sdecode_inst__DOT__is_s_type;
        CData/*0:0*/ top__DOT__sdecode_inst__DOT__is_b_type;
        CData/*0:0*/ top__DOT__sdecode_inst__DOT__is_u_type;
        CData/*0:0*/ top__DOT__sdecode_inst__DOT__is_j_type;
        CData/*0:0*/ top__DOT__salu_inst__DOT__zero_flag_d;
        CData/*0:0*/ top__DOT__salu_inst__DOT__negative_flag_d;
        CData/*0:0*/ top__DOT__salu_inst__DOT__overflow_flag_d;
        CData/*0:0*/ top__DOT__sdatamem_inst__DOT__verify_write;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactDidInit;
    };
    struct {
        CData/*0:0*/ __VactContinue;
        SData/*9:0*/ top__DOT__same_pc_counter;
        IData/*31:0*/ top__DOT__cycle_count;
        IData/*31:0*/ top__DOT__pc_out;
        IData/*31:0*/ top__DOT__instr;
        IData/*31:0*/ top__DOT__imm_value;
        IData/*31:0*/ top__DOT__last_pc;
        IData/*31:0*/ top__DOT__rs1_data;
        IData/*31:0*/ top__DOT__rs2_data;
        IData/*31:0*/ top__DOT__rd_data;
        IData/*31:0*/ top__DOT__alu_input_a;
        IData/*31:0*/ top__DOT__alu_input_b;
        IData/*31:0*/ top__DOT__alu_rs2_input;
        IData/*31:0*/ top__DOT__mem_rdata;
        IData/*31:0*/ top__DOT__if_id_pc;
        IData/*31:0*/ top__DOT__if_id_instr;
        IData/*31:0*/ top__DOT__id_ex_pc;
        IData/*31:0*/ top__DOT__id_ex_rs1_data;
        IData/*31:0*/ top__DOT__id_ex_rs2_data;
        IData/*31:0*/ top__DOT__id_ex_imm;
        IData/*31:0*/ top__DOT__id_ex_instr;
        IData/*31:0*/ top__DOT__ex_mem_pc;
        IData/*31:0*/ top__DOT__ex_mem_alu_result;
        IData/*31:0*/ top__DOT__ex_mem_rs2_data;
        IData/*31:0*/ top__DOT__ex_mem_imm;
        IData/*31:0*/ top__DOT__ex_mem_instr;
        IData/*31:0*/ top__DOT__mem_wb_alu_result;
        IData/*31:0*/ top__DOT__mem_wb_mem_data;
        IData/*31:0*/ top__DOT__mem_wb_pc;
        IData/*31:0*/ top__DOT__mem_wb_instr;
        IData/*31:0*/ top__DOT__forwarded_rs1_value;
        IData/*31:0*/ top__DOT__forwarded_rs2_value;
        IData/*31:0*/ top__DOT____Vcellinp__pc_inst__pc_i;
        IData/*31:0*/ top__DOT__instruction_count;
        IData/*31:0*/ top__DOT__address_0_contents;
        IData/*31:0*/ top__DOT__unnamedblk1__DOT__fd;
        IData/*31:0*/ top__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ top__DOT__pc_inst__DOT__next_pc;
        IData/*31:0*/ top__DOT__instr_mem_inst__DOT__unnamedblk1__DOT__mem_index;
        IData/*31:0*/ top__DOT__instr_mem_inst__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ top__DOT__sdecode_inst__DOT__j_imm;
        IData/*31:0*/ top__DOT__sregfile_inst__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ top__DOT__salu_inst__DOT__alu_res_d;
        IData/*31:0*/ top__DOT__sdatamem_inst__DOT__verify_addr;
        IData/*31:0*/ top__DOT__sdatamem_inst__DOT__verify_data;
        IData/*31:0*/ top__DOT__sdatamem_inst__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ __Vtask_top__DOT__sdatamem_inst__DOT__print_mem_status__8__addr;
        IData/*31:0*/ __Vdly__top__DOT__cycle_count;
        IData/*31:0*/ __Vdly__top__DOT__instruction_count;
        IData/*31:0*/ __Vtrigprevexpr___TOP__top__DOT__salu_inst__DOT__alu_res_d__0;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ top__DOT__sregfile_inst__DOT__cycle_count;
        VlUnpacked<IData/*31:0*/, 1024> top__DOT__instr_mem_inst__DOT__imem;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__sregfile_inst__DOT__register;
        VlUnpacked<CData/*7:0*/, 1024> top__DOT__sdatamem_inst__DOT__memory;
        VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hef71830d__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
