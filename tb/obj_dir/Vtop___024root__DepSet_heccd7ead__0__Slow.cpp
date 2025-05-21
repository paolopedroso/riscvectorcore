// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->top__DOT__cycle_count = 0U;
    vlSelf->top__DOT__instruction_count = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk2__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk2__DOT__i)) {
        vlSelf->top__DOT__instr_mem_inst__DOT__imem[(0x3ffU 
                                                     & vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk2__DOT__i)] = 0U;
        vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk2__DOT__i 
            = ((IData)(1U) + vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk2__DOT__i);
    }
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0U] = 0x100093U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[1U] = 0x200113U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[2U] = 0x400193U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[3U] = 0x800213U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[4U] = 0x2081b3U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[5U] = 0x40308233U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[6U] = 0x20f2b3U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[7U] = 0x20e333U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[8U] = 0x20c3b3U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[9U] = 0x109413U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0xaU] = 0x20d493U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0xbU] = 0x4020d513U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0xcU] = 0x302023U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0xdU] = 0x402223U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0xeU] = 0x2583U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0xfU] = 0xb00593U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x10U] = 0x402603U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x11U] = 0xc58633U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x12U] = 0xc02423U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x13U] = 0x802683U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x14U] = 0xd106b3U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x15U] = 0xd02623U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x16U] = 0xfd00713U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x17U] = 0xe02823U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x18U] = 0x1000783U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x19U] = 0x1004803U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x1aU] = 0xaaaab837U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x1bU] = 0x1002a23U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x1cU] = 0x1401883U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x1dU] = 0x1405903U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x1eU] = 0x300993U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x1fU] = 0x500a13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x20U] = 0x1498a63U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x21U] = 0x1400a93U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x22U] = 0x1499463U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x23U] = 0xfff00b13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x24U] = 0xa00b13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x25U] = 0x1002b83U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x26U] = 0x15a0c13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x27U] = 0x18c0c93U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x28U] = 0x19c8d13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x29U] = 0x1ad0d93U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x2aU] = 0x1b02e23U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x2bU] = 0x1c02e83U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x2cU] = 0x1d00e13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x2dU] = 0x1c02f23U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x2eU] = 0x1c00f13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x2fU] = 0x1e00f93U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x30U] = 0x1ef0f33U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x31U] = 0x18000efU;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x32U] = 0x13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x33U] = 0x13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x34U] = 0x13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x35U] = 0x13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x36U] = 0x13U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x37U] = 0x8067U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x38U] = 0x12345837U;
    vlSelf->top__DOT__instr_mem_inst__DOT__imem[0x39U] = 0x100073U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../core/../core/top.sv", 9, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h5e3dfec6_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h392e18e9_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_ha96ed2bf_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_he4685dc5_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h72611ab3_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hf1f34e79_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->top__DOT__rs1_addr = (0x1fU & (vlSelf->top__DOT__if_id_instr 
                                           >> 0xfU));
    vlSelf->top__DOT__rs2_addr = (0x1fU & (vlSelf->top__DOT__if_id_instr 
                                           >> 0x14U));
    vlSelf->top__DOT__rd_addr = (0x1fU & (vlSelf->top__DOT__if_id_instr 
                                          >> 7U));
    vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk1__DOT__mem_index 
        = (0x3ffU & VL_SHIFTR_III(32,32,32, vlSelf->top__DOT__pc_out, 2U));
    VL_WRITEF("IMEM: Reading from address 0x%x, mem_index=%0d, instruction=0x%x\n",
              32,vlSelf->top__DOT__pc_out,32,vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk1__DOT__mem_index,
              32,vlSelf->top__DOT__instr_mem_inst__DOT__imem
              [(0x3ffU & vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk1__DOT__mem_index)]);
    if (VL_UNLIKELY((0x100U < vlSelf->top__DOT__pc_out))) {
        VL_WRITEF("WARNING: PC is outside expected program range! addr=0x%x\n",
                  32,vlSelf->top__DOT__pc_out);
    }
    if (VL_LIKELY((VL_GTS_III(32, 0x400U, vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk1__DOT__mem_index) 
                   & VL_LTES_III(32, 0U, vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk1__DOT__mem_index)))) {
        vlSelf->top__DOT__instr = vlSelf->top__DOT__instr_mem_inst__DOT__imem
            [(0x3ffU & vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk1__DOT__mem_index)];
    } else {
        VL_WRITEF("ERROR: Memory access out of bounds! index=%0d\n",
                  32,vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk1__DOT__mem_index);
        vlSelf->top__DOT__instr = 0x13U;
    }
    vlSelf->top__DOT__mem_rdata = 0U;
    if (VL_UNLIKELY(vlSelf->top__DOT__ex_mem_mem_read)) {
        VL_WRITEF("DMEM: LOAD INSTRUCTION DETECTED\nDMEM: MEMORY DEBUG: Reading from address 0x%x\nDMEM: INSTRUCTION: 0x%x\nDMEM: PC: 0x%x\n",
                  32,vlSelf->top__DOT__ex_mem_alu_result,
                  32,vlSelf->top__DOT__ex_mem_instr,
                  32,vlSelf->top__DOT__ex_mem_pc);
        if (VL_UNLIKELY((0x3fdU <= vlSelf->top__DOT__ex_mem_alu_result))) {
            VL_WRITEF("DMEM: WARNING: Memory read out of bounds: addr=0x%x\n",
                      32,vlSelf->top__DOT__ex_mem_alu_result);
            vlSelf->top__DOT__mem_rdata = 0xdeadbeefU;
        } else if (VL_UNLIKELY((2U & (IData)(vlSelf->top__DOT__ex_mem_mem_size)))) {
            vlSelf->top__DOT__mem_rdata = ((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                            [(0x3ffU 
                                              & ((IData)(3U) 
                                                 + vlSelf->top__DOT__ex_mem_alu_result))] 
                                            << 0x18U) 
                                           | ((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                               [(0x3ffU 
                                                 & ((IData)(2U) 
                                                    + vlSelf->top__DOT__ex_mem_alu_result))] 
                                               << 0x10U) 
                                              | ((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                                  [
                                                  (0x3ffU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->top__DOT__ex_mem_alu_result))] 
                                                  << 8U) 
                                                 | vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                                 [(0x3ffU 
                                                   & vlSelf->top__DOT__ex_mem_alu_result)])));
            VL_WRITEF("DMEM: MEMORY READ WORD: addr=0x%x, data=0x%08x\nDMEM:   Final register value: 0x%08x\n",
                      32,vlSelf->top__DOT__ex_mem_alu_result,
                      32,((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                           [(0x3ffU & ((IData)(3U) 
                                       + vlSelf->top__DOT__ex_mem_alu_result))] 
                           << 0x18U) | ((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                         [(0x3ffU & 
                                           ((IData)(2U) 
                                            + vlSelf->top__DOT__ex_mem_alu_result))] 
                                         << 0x10U) 
                                        | ((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                            [(0x3ffU 
                                              & ((IData)(1U) 
                                                 + vlSelf->top__DOT__ex_mem_alu_result))] 
                                            << 8U) 
                                           | vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                           [(0x3ffU 
                                             & vlSelf->top__DOT__ex_mem_alu_result)]))),
                      32,vlSelf->top__DOT__mem_rdata);
            vlSelf->__Vtask_top__DOT__sdatamem_inst__DOT__print_mem_status__8__addr 
                = vlSelf->top__DOT__ex_mem_alu_result;
            VL_WRITEF("DMEM: MEMORY STATUS: Memory[%0#:%0#] = %02x %02x %02x %02x\n",
                      32,((IData)(3U) + vlSelf->__Vtask_top__DOT__sdatamem_inst__DOT__print_mem_status__8__addr),
                      32,vlSelf->__Vtask_top__DOT__sdatamem_inst__DOT__print_mem_status__8__addr,
                      8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                      [(0x3ffU & vlSelf->__Vtask_top__DOT__sdatamem_inst__DOT__print_mem_status__8__addr)],
                      8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                      [(0x3ffU & ((IData)(1U) + vlSelf->__Vtask_top__DOT__sdatamem_inst__DOT__print_mem_status__8__addr))],
                      8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                      [(0x3ffU & ((IData)(2U) + vlSelf->__Vtask_top__DOT__sdatamem_inst__DOT__print_mem_status__8__addr))],
                      8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                      [(0x3ffU & ((IData)(3U) + vlSelf->__Vtask_top__DOT__sdatamem_inst__DOT__print_mem_status__8__addr))]);
        } else if ((1U & (IData)(vlSelf->top__DOT__ex_mem_mem_size))) {
            VL_WRITEF("DMEM: MEMORY READ HALFWORD: addr=0x%x, data=%04x\n",
                      32,vlSelf->top__DOT__ex_mem_alu_result,
                      16,((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                           [(0x3ffU & ((IData)(1U) 
                                       + vlSelf->top__DOT__ex_mem_alu_result))] 
                           << 8U) | vlSelf->top__DOT__sdatamem_inst__DOT__memory
                          [(0x3ffU & vlSelf->top__DOT__ex_mem_alu_result)]));
            vlSelf->top__DOT__mem_rdata = (((- (IData)(
                                                       (1U 
                                                        & (vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                                           [
                                                           (0x3ffU 
                                                            & ((IData)(1U) 
                                                               + vlSelf->top__DOT__ex_mem_alu_result))] 
                                                           >> 7U)))) 
                                            << 0x10U) 
                                           | ((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                               [(0x3ffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->top__DOT__ex_mem_alu_result))] 
                                               << 8U) 
                                              | vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                              [(0x3ffU 
                                                & vlSelf->top__DOT__ex_mem_alu_result)]));
        } else {
            VL_WRITEF("DMEM: MEMORY READ BYTE: addr=0x%x, data=%02x\n",
                      32,vlSelf->top__DOT__ex_mem_alu_result,
                      8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                      [(0x3ffU & vlSelf->top__DOT__ex_mem_alu_result)]);
            vlSelf->top__DOT__mem_rdata = (((- (IData)(
                                                       (1U 
                                                        & (vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                                           [
                                                           (0x3ffU 
                                                            & vlSelf->top__DOT__ex_mem_alu_result)] 
                                                           >> 7U)))) 
                                            << 8U) 
                                           | vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                           [(0x3ffU 
                                             & vlSelf->top__DOT__ex_mem_alu_result)]);
        }
    }
    vlSelf->top__DOT__take_branch = ((IData)(vlSelf->top__DOT__ex_mem_branch) 
                                     & (IData)(vlSelf->top__DOT__ex_mem_zero_flag));
    vlSelf->top__DOT__sdecode_inst__DOT__j_imm = ((
                                                   (- (IData)(
                                                              (vlSelf->top__DOT__if_id_instr 
                                                               >> 0x1fU))) 
                                                   << 0x14U) 
                                                  | ((0xff000U 
                                                      & vlSelf->top__DOT__if_id_instr) 
                                                     | ((0x800U 
                                                         & (vlSelf->top__DOT__if_id_instr 
                                                            >> 9U)) 
                                                        | (0x7feU 
                                                           & (vlSelf->top__DOT__if_id_instr 
                                                              >> 0x14U)))));
    if (VL_UNLIKELY((0U == (IData)(vlSelf->top__DOT__mem_wb_result_src)))) {
        vlSelf->top__DOT__rd_data = vlSelf->top__DOT__mem_wb_alu_result;
        VL_WRITEF("WBMUX: Selected ALU result: 0x%x\n",
                  32,vlSelf->top__DOT__mem_wb_alu_result);
    } else if (VL_UNLIKELY((1U == (IData)(vlSelf->top__DOT__mem_wb_result_src)))) {
        VL_WRITEF("WBMUX: Selected Memory data: 0x%x\n",
                  32,vlSelf->top__DOT__mem_wb_mem_data);
        vlSelf->top__DOT__rd_data = vlSelf->top__DOT__mem_wb_mem_data;
    } else if ((2U == (IData)(vlSelf->top__DOT__mem_wb_result_src))) {
        VL_WRITEF("WBMUX: Selected PC+4: 0x%x\n",32,
                  ((IData)(4U) + vlSelf->top__DOT__mem_wb_pc));
        vlSelf->top__DOT__rd_data = ((IData)(4U) + vlSelf->top__DOT__mem_wb_pc);
    } else {
        VL_WRITEF("WBMUX: Default - Selected ALU result: 0x%x\n",
                  32,vlSelf->top__DOT__mem_wb_alu_result);
        vlSelf->top__DOT__rd_data = vlSelf->top__DOT__mem_wb_alu_result;
    }
    __Vtableidx1 = (0x7fU & vlSelf->top__DOT__if_id_instr);
    vlSelf->top__DOT__sdecode_inst__DOT__is_r_type 
        = Vtop__ConstPool__TABLE_h5e3dfec6_0[__Vtableidx1];
    vlSelf->top__DOT__sdecode_inst__DOT__is_i_type 
        = Vtop__ConstPool__TABLE_h392e18e9_0[__Vtableidx1];
    vlSelf->top__DOT__sdecode_inst__DOT__is_s_type 
        = Vtop__ConstPool__TABLE_ha96ed2bf_0[__Vtableidx1];
    vlSelf->top__DOT__sdecode_inst__DOT__is_b_type 
        = Vtop__ConstPool__TABLE_he4685dc5_0[__Vtableidx1];
    vlSelf->top__DOT__sdecode_inst__DOT__is_u_type 
        = Vtop__ConstPool__TABLE_h72611ab3_0[__Vtableidx1];
    vlSelf->top__DOT__sdecode_inst__DOT__is_j_type 
        = Vtop__ConstPool__TABLE_hf1f34e79_0[__Vtableidx1];
    vlSelf->top__DOT__forward_a = 0U;
    vlSelf->top__DOT__forward_b = 0U;
    if ((0U != (IData)(vlSelf->top__DOT__id_ex_rs1_addr))) {
        if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__ex_mem_reg_write) 
                         & ((IData)(vlSelf->top__DOT__ex_mem_rd_addr) 
                            == (IData)(vlSelf->top__DOT__id_ex_rs1_addr))))) {
            vlSelf->top__DOT__forward_a = 2U;
            VL_WRITEF("FWD: Forwarding rs1 from MEM stage: x%0#\n",
                      5,vlSelf->top__DOT__ex_mem_rd_addr);
        } else if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__mem_wb_reg_write) 
                                & ((IData)(vlSelf->top__DOT__mem_wb_rd_addr) 
                                   == (IData)(vlSelf->top__DOT__id_ex_rs1_addr))))) {
            VL_WRITEF("FWD: Forwarding rs1 from WB stage: x%0#\n",
                      5,vlSelf->top__DOT__mem_wb_rd_addr);
            vlSelf->top__DOT__forward_a = 1U;
        }
    }
    if ((0U != (IData)(vlSelf->top__DOT__id_ex_rs2_addr))) {
        if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__ex_mem_reg_write) 
                         & ((IData)(vlSelf->top__DOT__ex_mem_rd_addr) 
                            == (IData)(vlSelf->top__DOT__id_ex_rs2_addr))))) {
            VL_WRITEF("FWD: Forwarding rs2 from MEM stage: x%0#\n",
                      5,vlSelf->top__DOT__ex_mem_rd_addr);
            vlSelf->top__DOT__forward_b = 2U;
        } else if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__mem_wb_reg_write) 
                                & ((IData)(vlSelf->top__DOT__mem_wb_rd_addr) 
                                   == (IData)(vlSelf->top__DOT__id_ex_rs2_addr))))) {
            VL_WRITEF("FWD: Forwarding rs2 from WB stage: x%0#\n",
                      5,vlSelf->top__DOT__mem_wb_rd_addr);
            vlSelf->top__DOT__forward_b = 1U;
        }
    }
    vlSelf->top__DOT__pc_src = ((IData)(vlSelf->top__DOT__take_branch) 
                                | (IData)(vlSelf->top__DOT__ex_mem_jump));
    vlSelf->top__DOT__reg_write_en = 0U;
    vlSelf->top__DOT__mem_read = 0U;
    vlSelf->top__DOT__mem_write = 0U;
    vlSelf->top__DOT__mem_size = 2U;
    vlSelf->top__DOT__branch = 0U;
    vlSelf->top__DOT__jump = 0U;
    vlSelf->top__DOT__alu_op = 0U;
    vlSelf->top__DOT__result_src = 0U;
    vlSelf->top__DOT__uses_rs1 = 0U;
    vlSelf->top__DOT__uses_rs2 = 0U;
    vlSelf->top__DOT__jalr = 0U;
    if ((0x40U & vlSelf->top__DOT__if_id_instr)) {
        if ((0x20U & vlSelf->top__DOT__if_id_instr)) {
            if ((1U & (~ (vlSelf->top__DOT__if_id_instr 
                          >> 4U)))) {
                if ((8U & vlSelf->top__DOT__if_id_instr)) {
                    if ((4U & vlSelf->top__DOT__if_id_instr)) {
                        if ((2U & vlSelf->top__DOT__if_id_instr)) {
                            if (VL_UNLIKELY((1U & vlSelf->top__DOT__if_id_instr))) {
                                vlSelf->top__DOT__reg_write_en = 1U;
                                vlSelf->top__DOT__jump = 1U;
                                vlSelf->top__DOT__result_src = 2U;
                                VL_WRITEF("DECODE: JAL instruction detected, rd=x%0#, imm=0x%x\n",
                                          5,(0x1fU 
                                             & (vlSelf->top__DOT__if_id_instr 
                                                >> 7U)),
                                          32,vlSelf->top__DOT__sdecode_inst__DOT__j_imm);
                            }
                        }
                    }
                } else if ((4U & vlSelf->top__DOT__if_id_instr)) {
                    if ((2U & vlSelf->top__DOT__if_id_instr)) {
                        if ((1U & vlSelf->top__DOT__if_id_instr)) {
                            vlSelf->top__DOT__reg_write_en = 1U;
                            vlSelf->top__DOT__jump = 1U;
                            vlSelf->top__DOT__uses_rs1 = 1U;
                            vlSelf->top__DOT__result_src = 2U;
                            vlSelf->top__DOT__jalr = 1U;
                        }
                    }
                } else if ((2U & vlSelf->top__DOT__if_id_instr)) {
                    if ((1U & vlSelf->top__DOT__if_id_instr)) {
                        vlSelf->top__DOT__branch = 1U;
                        vlSelf->top__DOT__uses_rs1 = 1U;
                        vlSelf->top__DOT__uses_rs2 = 1U;
                        vlSelf->top__DOT__alu_op = 
                            ((0x4000U & vlSelf->top__DOT__if_id_instr)
                              ? ((0x2000U & vlSelf->top__DOT__if_id_instr)
                                  ? ((0x1000U & vlSelf->top__DOT__if_id_instr)
                                      ? 0xfU : 0xeU)
                                  : ((0x1000U & vlSelf->top__DOT__if_id_instr)
                                      ? 0xdU : 0xcU))
                              : ((0x2000U & vlSelf->top__DOT__if_id_instr)
                                  ? 0U : ((0x1000U 
                                           & vlSelf->top__DOT__if_id_instr)
                                           ? 0xbU : 0xaU)));
                    }
                }
            }
        }
    } else if ((0x20U & vlSelf->top__DOT__if_id_instr)) {
        if ((0x10U & vlSelf->top__DOT__if_id_instr)) {
            if ((1U & (~ (vlSelf->top__DOT__if_id_instr 
                          >> 3U)))) {
                if ((4U & vlSelf->top__DOT__if_id_instr)) {
                    if ((2U & vlSelf->top__DOT__if_id_instr)) {
                        if ((1U & vlSelf->top__DOT__if_id_instr)) {
                            vlSelf->top__DOT__reg_write_en = 1U;
                            vlSelf->top__DOT__alu_op = 0U;
                        }
                    }
                } else if ((2U & vlSelf->top__DOT__if_id_instr)) {
                    if ((1U & vlSelf->top__DOT__if_id_instr)) {
                        vlSelf->top__DOT__reg_write_en = 1U;
                        vlSelf->top__DOT__uses_rs1 = 1U;
                        vlSelf->top__DOT__uses_rs2 = 1U;
                        vlSelf->top__DOT__alu_op = 
                            ((0x4000U & vlSelf->top__DOT__if_id_instr)
                              ? ((0x2000U & vlSelf->top__DOT__if_id_instr)
                                  ? ((0x1000U & vlSelf->top__DOT__if_id_instr)
                                      ? 9U : 8U) : 
                                 ((0x1000U & vlSelf->top__DOT__if_id_instr)
                                   ? ((0x40000000U 
                                       & vlSelf->top__DOT__if_id_instr)
                                       ? 7U : 6U) : 5U))
                              : ((0x2000U & vlSelf->top__DOT__if_id_instr)
                                  ? ((0x1000U & vlSelf->top__DOT__if_id_instr)
                                      ? 4U : 3U) : 
                                 ((0x1000U & vlSelf->top__DOT__if_id_instr)
                                   ? 2U : ((0x40000000U 
                                            & vlSelf->top__DOT__if_id_instr)
                                            ? 1U : 0U))));
                    }
                }
            }
        } else if ((1U & (~ (vlSelf->top__DOT__if_id_instr 
                             >> 3U)))) {
            if ((1U & (~ (vlSelf->top__DOT__if_id_instr 
                          >> 2U)))) {
                if ((2U & vlSelf->top__DOT__if_id_instr)) {
                    if ((1U & vlSelf->top__DOT__if_id_instr)) {
                        vlSelf->top__DOT__mem_write = 1U;
                        vlSelf->top__DOT__uses_rs1 = 1U;
                        vlSelf->top__DOT__uses_rs2 = 1U;
                        vlSelf->top__DOT__mem_size 
                            = ((0U == (7U & (vlSelf->top__DOT__if_id_instr 
                                             >> 0xcU)))
                                ? 0U : ((1U == (7U 
                                                & (vlSelf->top__DOT__if_id_instr 
                                                   >> 0xcU)))
                                         ? 1U : 2U));
                    }
                }
            }
        }
    } else if ((0x10U & vlSelf->top__DOT__if_id_instr)) {
        if ((1U & (~ (vlSelf->top__DOT__if_id_instr 
                      >> 3U)))) {
            if ((4U & vlSelf->top__DOT__if_id_instr)) {
                if ((2U & vlSelf->top__DOT__if_id_instr)) {
                    if ((1U & vlSelf->top__DOT__if_id_instr)) {
                        vlSelf->top__DOT__reg_write_en = 1U;
                        vlSelf->top__DOT__alu_op = 0U;
                    }
                }
            } else if ((2U & vlSelf->top__DOT__if_id_instr)) {
                if ((1U & vlSelf->top__DOT__if_id_instr)) {
                    vlSelf->top__DOT__reg_write_en = 1U;
                    vlSelf->top__DOT__uses_rs1 = 1U;
                    vlSelf->top__DOT__alu_op = ((0x4000U 
                                                 & vlSelf->top__DOT__if_id_instr)
                                                 ? 
                                                ((0x2000U 
                                                  & vlSelf->top__DOT__if_id_instr)
                                                  ? 
                                                 ((0x1000U 
                                                   & vlSelf->top__DOT__if_id_instr)
                                                   ? 9U
                                                   : 8U)
                                                  : 
                                                 ((0x1000U 
                                                   & vlSelf->top__DOT__if_id_instr)
                                                   ? 
                                                  ((0x40000000U 
                                                    & vlSelf->top__DOT__if_id_instr)
                                                    ? 7U
                                                    : 6U)
                                                   : 5U))
                                                 : 
                                                ((0x2000U 
                                                  & vlSelf->top__DOT__if_id_instr)
                                                  ? 
                                                 ((0x1000U 
                                                   & vlSelf->top__DOT__if_id_instr)
                                                   ? 4U
                                                   : 3U)
                                                  : 
                                                 ((0x1000U 
                                                   & vlSelf->top__DOT__if_id_instr)
                                                   ? 2U
                                                   : 0U)));
                }
            }
        }
    } else if ((1U & (~ (vlSelf->top__DOT__if_id_instr 
                         >> 3U)))) {
        if ((1U & (~ (vlSelf->top__DOT__if_id_instr 
                      >> 2U)))) {
            if ((2U & vlSelf->top__DOT__if_id_instr)) {
                if ((1U & vlSelf->top__DOT__if_id_instr)) {
                    vlSelf->top__DOT__reg_write_en = 1U;
                    vlSelf->top__DOT__mem_read = 1U;
                    vlSelf->top__DOT__uses_rs1 = 1U;
                    vlSelf->top__DOT__result_src = 1U;
                    vlSelf->top__DOT__mem_size = ((0x4000U 
                                                   & vlSelf->top__DOT__if_id_instr)
                                                   ? 
                                                  ((0x2000U 
                                                    & vlSelf->top__DOT__if_id_instr)
                                                    ? 2U
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->top__DOT__if_id_instr)
                                                     ? 1U
                                                     : 0U))
                                                   : 
                                                  ((0x2000U 
                                                    & vlSelf->top__DOT__if_id_instr)
                                                    ? 2U
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->top__DOT__if_id_instr)
                                                     ? 1U
                                                     : 0U)));
                }
            }
        }
    }
    vlSelf->top__DOT__rs1_data = ((0U == (0x1fU & (vlSelf->top__DOT__if_id_instr 
                                                   >> 0xfU)))
                                   ? 0U : vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [(0x1fU & (vlSelf->top__DOT__if_id_instr 
                                             >> 0xfU))]);
    vlSelf->top__DOT__rs2_data = ((0U == (0x1fU & (vlSelf->top__DOT__if_id_instr 
                                                   >> 0x14U)))
                                   ? 0U : vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [(0x1fU & (vlSelf->top__DOT__if_id_instr 
                                             >> 0x14U))]);
    if (((IData)(vlSelf->top__DOT__mem_wb_reg_write) 
         & (0U != (IData)(vlSelf->top__DOT__mem_wb_rd_addr)))) {
        if (((0x1fU & (vlSelf->top__DOT__if_id_instr 
                       >> 0xfU)) == (IData)(vlSelf->top__DOT__mem_wb_rd_addr))) {
            vlSelf->top__DOT__rs1_data = vlSelf->top__DOT__rd_data;
        }
        if (((0x1fU & (vlSelf->top__DOT__if_id_instr 
                       >> 0x14U)) == (IData)(vlSelf->top__DOT__mem_wb_rd_addr))) {
            vlSelf->top__DOT__rs2_data = vlSelf->top__DOT__rd_data;
        }
    }
    vlSelf->top__DOT__imm_valid = (((((IData)(vlSelf->top__DOT__sdecode_inst__DOT__is_i_type) 
                                      | (IData)(vlSelf->top__DOT__sdecode_inst__DOT__is_s_type)) 
                                     | (IData)(vlSelf->top__DOT__sdecode_inst__DOT__is_b_type)) 
                                    | (IData)(vlSelf->top__DOT__sdecode_inst__DOT__is_u_type)) 
                                   | (IData)(vlSelf->top__DOT__sdecode_inst__DOT__is_j_type));
    vlSelf->top__DOT__imm_value = ((IData)(vlSelf->top__DOT__sdecode_inst__DOT__is_i_type)
                                    ? (((- (IData)(
                                                   (vlSelf->top__DOT__if_id_instr 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       (vlSelf->top__DOT__if_id_instr 
                                        >> 0x14U)) : 
                                   ((IData)(vlSelf->top__DOT__sdecode_inst__DOT__is_s_type)
                                     ? (((- (IData)(
                                                    (vlSelf->top__DOT__if_id_instr 
                                                     >> 0x1fU))) 
                                         << 0xcU) | 
                                        ((0xfe0U & 
                                          (vlSelf->top__DOT__if_id_instr 
                                           >> 0x14U)) 
                                         | (0x1fU & 
                                            (vlSelf->top__DOT__if_id_instr 
                                             >> 7U))))
                                     : ((IData)(vlSelf->top__DOT__sdecode_inst__DOT__is_b_type)
                                         ? (((- (IData)(
                                                        (vlSelf->top__DOT__if_id_instr 
                                                         >> 0x1fU))) 
                                             << 0xdU) 
                                            | ((0x1000U 
                                                & (vlSelf->top__DOT__if_id_instr 
                                                   >> 0x13U)) 
                                               | ((0x800U 
                                                   & (vlSelf->top__DOT__if_id_instr 
                                                      << 4U)) 
                                                  | ((0x7e0U 
                                                      & (vlSelf->top__DOT__if_id_instr 
                                                         >> 0x14U)) 
                                                     | (0x1eU 
                                                        & (vlSelf->top__DOT__if_id_instr 
                                                           >> 7U))))))
                                         : ((IData)(vlSelf->top__DOT__sdecode_inst__DOT__is_u_type)
                                             ? (0xfffff000U 
                                                & vlSelf->top__DOT__if_id_instr)
                                             : ((IData)(vlSelf->top__DOT__sdecode_inst__DOT__is_j_type)
                                                 ? vlSelf->top__DOT__sdecode_inst__DOT__j_imm
                                                 : 0U)))));
    vlSelf->top__DOT__forwarded_rs1_value = ((0U == (IData)(vlSelf->top__DOT__forward_a))
                                              ? vlSelf->top__DOT__id_ex_rs1_data
                                              : ((1U 
                                                  == (IData)(vlSelf->top__DOT__forward_a))
                                                  ? vlSelf->top__DOT__rd_data
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->top__DOT__forward_a))
                                                   ? vlSelf->top__DOT__ex_mem_alu_result
                                                   : vlSelf->top__DOT__id_ex_rs1_data)));
    vlSelf->top__DOT__forwarded_rs2_value = ((0U == (IData)(vlSelf->top__DOT__forward_b))
                                              ? vlSelf->top__DOT__id_ex_rs2_data
                                              : ((1U 
                                                  == (IData)(vlSelf->top__DOT__forward_b))
                                                  ? vlSelf->top__DOT__rd_data
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->top__DOT__forward_b))
                                                   ? vlSelf->top__DOT__ex_mem_alu_result
                                                   : vlSelf->top__DOT__id_ex_rs2_data)));
    vlSelf->top__DOT__alu_input_a = vlSelf->top__DOT__forwarded_rs1_value;
    vlSelf->top__DOT__alu_input_b = ((IData)(vlSelf->top__DOT__id_ex_imm_valid)
                                      ? vlSelf->top__DOT__id_ex_imm
                                      : vlSelf->top__DOT__forwarded_rs2_value);
    if (VL_UNLIKELY((0U != (IData)(vlSelf->top__DOT__forward_a)))) {
        VL_WRITEF("TOP: Using forwarded RS1: forward_a=%b, value=0x%x\n",
                  2,vlSelf->top__DOT__forward_a,32,
                  vlSelf->top__DOT__forwarded_rs1_value);
    }
    if (VL_UNLIKELY((0U != (IData)(vlSelf->top__DOT__forward_b)))) {
        VL_WRITEF("TOP: Using forwarded RS2: forward_b=%b, value=0x%x\n",
                  2,vlSelf->top__DOT__forward_b,32,
                  vlSelf->top__DOT__forwarded_rs2_value);
    }
    vlSelf->top__DOT____Vcellinp__pc_inst__pc_i = ((IData)(vlSelf->top__DOT__pc_src)
                                                    ? vlSelf->top__DOT__ex_mem_pc
                                                    : vlSelf->top__DOT__pc_out);
    vlSelf->top__DOT__stall_pipeline = 0U;
    if (VL_UNLIKELY((((IData)(vlSelf->top__DOT__id_ex_mem_read) 
                      & (0U != (IData)(vlSelf->top__DOT__id_ex_rd_addr))) 
                     & (((IData)(vlSelf->top__DOT__uses_rs1) 
                         & ((0x1fU & (vlSelf->top__DOT__if_id_instr 
                                      >> 0xfU)) == (IData)(vlSelf->top__DOT__id_ex_rd_addr))) 
                        | ((IData)(vlSelf->top__DOT__uses_rs2) 
                           & ((0x1fU & (vlSelf->top__DOT__if_id_instr 
                                        >> 0x14U)) 
                              == (IData)(vlSelf->top__DOT__id_ex_rd_addr))))))) {
        VL_WRITEF("HAZARD DETECTED: Load-use hazard. Stalling pipeline.\n");
        vlSelf->top__DOT__stall_pipeline = 1U;
        VL_WRITEF("  Load to register x%0#, followed by use in rs1=%0# or rs2=%0#\n",
                  5,vlSelf->top__DOT__id_ex_rd_addr,
                  5,(0x1fU & (vlSelf->top__DOT__if_id_instr 
                              >> 0xfU)),5,(0x1fU & 
                                           (vlSelf->top__DOT__if_id_instr 
                                            >> 0x14U)));
    }
    vlSelf->top__DOT__salu_inst__DOT__alu_res_d = 0U;
    vlSelf->top__DOT__salu_inst__DOT__zero_flag_d = 0U;
    vlSelf->top__DOT__salu_inst__DOT__overflow_flag_d = 0U;
    VL_WRITEF("ALU INPUT: rs1_data_i = 0x%x (bytes: %x %x %x %x)\nALU INPUT: rs2_data_i = 0x%x (bytes: %x %x %x %x)\nALU INPUT: alu_op_in = %b\n",
              32,vlSelf->top__DOT__alu_input_a,8,(0xffU 
                                                  & vlSelf->top__DOT__alu_input_a),
              8,(0xffU & (vlSelf->top__DOT__alu_input_a 
                          >> 8U)),8,(0xffU & (vlSelf->top__DOT__alu_input_a 
                                              >> 0x10U)),
              8,(vlSelf->top__DOT__alu_input_a >> 0x18U),
              32,vlSelf->top__DOT__alu_input_b,8,(0xffU 
                                                  & vlSelf->top__DOT__alu_input_b),
              8,(0xffU & (vlSelf->top__DOT__alu_input_b 
                          >> 8U)),8,(0xffU & (vlSelf->top__DOT__alu_input_b 
                                              >> 0x10U)),
              8,(vlSelf->top__DOT__alu_input_b >> 0x18U),
              4,(IData)(vlSelf->top__DOT__id_ex_alu_op));
    if ((8U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
        if ((4U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
            if ((2U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
                if ((1U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
                    if ((vlSelf->top__DOT__alu_input_a 
                         >= vlSelf->top__DOT__alu_input_b)) {
                        vlSelf->top__DOT__salu_inst__DOT__zero_flag_d = 1U;
                        vlSelf->top__DOT__salu_inst__DOT__alu_res_d = 1U;
                    } else {
                        vlSelf->top__DOT__salu_inst__DOT__zero_flag_d = 0U;
                        vlSelf->top__DOT__salu_inst__DOT__alu_res_d = 0U;
                    }
                    VL_WRITEF("ALU BGEU: 0x%x >= 0x%x = %1#\n",
                              32,vlSelf->top__DOT__alu_input_a,
                              32,vlSelf->top__DOT__alu_input_b,
                              1,(IData)(vlSelf->top__DOT__salu_inst__DOT__zero_flag_d));
                } else {
                    if ((vlSelf->top__DOT__alu_input_a 
                         < vlSelf->top__DOT__alu_input_b)) {
                        vlSelf->top__DOT__salu_inst__DOT__zero_flag_d = 1U;
                        vlSelf->top__DOT__salu_inst__DOT__alu_res_d = 1U;
                    } else {
                        vlSelf->top__DOT__salu_inst__DOT__zero_flag_d = 0U;
                        vlSelf->top__DOT__salu_inst__DOT__alu_res_d = 0U;
                    }
                    VL_WRITEF("ALU BLTU: 0x%x < 0x%x = %1#\n",
                              32,vlSelf->top__DOT__alu_input_a,
                              32,vlSelf->top__DOT__alu_input_b,
                              1,(IData)(vlSelf->top__DOT__salu_inst__DOT__zero_flag_d));
                }
            } else if ((1U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
                if (VL_GTES_III(32, vlSelf->top__DOT__alu_input_a, vlSelf->top__DOT__alu_input_b)) {
                    vlSelf->top__DOT__salu_inst__DOT__zero_flag_d = 1U;
                    vlSelf->top__DOT__salu_inst__DOT__alu_res_d = 1U;
                } else {
                    vlSelf->top__DOT__salu_inst__DOT__zero_flag_d = 0U;
                    vlSelf->top__DOT__salu_inst__DOT__alu_res_d = 0U;
                }
                VL_WRITEF("ALU BGE: 0x%x >= 0x%x = %1#\n",
                          32,vlSelf->top__DOT__alu_input_a,
                          32,vlSelf->top__DOT__alu_input_b,
                          1,(IData)(vlSelf->top__DOT__salu_inst__DOT__zero_flag_d));
            } else {
                if (VL_LTS_III(32, vlSelf->top__DOT__alu_input_a, vlSelf->top__DOT__alu_input_b)) {
                    vlSelf->top__DOT__salu_inst__DOT__zero_flag_d = 1U;
                    vlSelf->top__DOT__salu_inst__DOT__alu_res_d = 1U;
                } else {
                    vlSelf->top__DOT__salu_inst__DOT__zero_flag_d = 0U;
                    vlSelf->top__DOT__salu_inst__DOT__alu_res_d = 0U;
                }
                VL_WRITEF("ALU BLT: 0x%x < 0x%x = %1#\n",
                          32,vlSelf->top__DOT__alu_input_a,
                          32,vlSelf->top__DOT__alu_input_b,
                          1,(IData)(vlSelf->top__DOT__salu_inst__DOT__zero_flag_d));
            }
        } else if ((2U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
            if ((1U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
                vlSelf->top__DOT__salu_inst__DOT__zero_flag_d 
                    = (vlSelf->top__DOT__alu_input_a 
                       != vlSelf->top__DOT__alu_input_b);
                vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                    = (vlSelf->top__DOT__alu_input_a 
                       - vlSelf->top__DOT__alu_input_b);
                VL_WRITEF("ALU BNE: 0x%x != 0x%x = %1#\n",
                          32,vlSelf->top__DOT__alu_input_a,
                          32,vlSelf->top__DOT__alu_input_b,
                          1,(IData)(vlSelf->top__DOT__salu_inst__DOT__zero_flag_d));
            } else {
                vlSelf->top__DOT__salu_inst__DOT__zero_flag_d 
                    = (vlSelf->top__DOT__alu_input_a 
                       == vlSelf->top__DOT__alu_input_b);
                vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                    = (vlSelf->top__DOT__alu_input_a 
                       - vlSelf->top__DOT__alu_input_b);
                VL_WRITEF("ALU BEQ: 0x%x == 0x%x = %1#\n",
                          32,vlSelf->top__DOT__alu_input_a,
                          32,vlSelf->top__DOT__alu_input_b,
                          1,(IData)(vlSelf->top__DOT__salu_inst__DOT__zero_flag_d));
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
            vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                = (vlSelf->top__DOT__alu_input_a & vlSelf->top__DOT__alu_input_b);
            VL_WRITEF("ALU AND: 0x%x & 0x%x = 0x%x\n",
                      32,vlSelf->top__DOT__alu_input_a,
                      32,vlSelf->top__DOT__alu_input_b,
                      32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d);
        } else {
            vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                = (vlSelf->top__DOT__alu_input_a | vlSelf->top__DOT__alu_input_b);
            VL_WRITEF("ALU OR: 0x%x | 0x%x = 0x%x\n",
                      32,vlSelf->top__DOT__alu_input_a,
                      32,vlSelf->top__DOT__alu_input_b,
                      32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d);
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
        if ((2U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
            if ((1U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
                vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                    = VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__alu_input_a, 
                                     (0x1fU & vlSelf->top__DOT__alu_input_b));
                VL_WRITEF("ALU SRA: 0x%x >>> 0x%x = 0x%x\n",
                          32,vlSelf->top__DOT__alu_input_a,
                          5,(0x1fU & vlSelf->top__DOT__alu_input_b),
                          32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d);
            } else {
                vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                    = (vlSelf->top__DOT__alu_input_a 
                       >> (0x1fU & vlSelf->top__DOT__alu_input_b));
                VL_WRITEF("ALU SRL: 0x%x >> 0x%x = 0x%x\n",
                          32,vlSelf->top__DOT__alu_input_a,
                          5,(0x1fU & vlSelf->top__DOT__alu_input_b),
                          32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d);
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
            vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                = (vlSelf->top__DOT__alu_input_a ^ vlSelf->top__DOT__alu_input_b);
            VL_WRITEF("ALU XOR: 0x%x ^ 0x%x = 0x%x\n",
                      32,vlSelf->top__DOT__alu_input_a,
                      32,vlSelf->top__DOT__alu_input_b,
                      32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d);
        } else {
            vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                = ((vlSelf->top__DOT__alu_input_a < vlSelf->top__DOT__alu_input_b)
                    ? 1U : 0U);
            VL_WRITEF("ALU SLTU: 0x%x < 0x%x = %10# (unsigned)\n",
                      32,vlSelf->top__DOT__alu_input_a,
                      32,vlSelf->top__DOT__alu_input_b,
                      32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d);
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
        if ((1U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
            vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                = (VL_LTS_III(32, vlSelf->top__DOT__alu_input_a, vlSelf->top__DOT__alu_input_b)
                    ? 1U : 0U);
            VL_WRITEF("ALU SLT: 0x%x < 0x%x = %10# (signed: %0d < %0d)\n",
                      32,vlSelf->top__DOT__alu_input_a,
                      32,vlSelf->top__DOT__alu_input_b,
                      32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d,
                      32,vlSelf->top__DOT__alu_input_a,
                      32,vlSelf->top__DOT__alu_input_b);
        } else {
            vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                = (vlSelf->top__DOT__alu_input_a << 
                   (0x1fU & vlSelf->top__DOT__alu_input_b));
            VL_WRITEF("ALU SLL: 0x%x << 0x%x = 0x%x\n",
                      32,vlSelf->top__DOT__alu_input_a,
                      5,(0x1fU & vlSelf->top__DOT__alu_input_b),
                      32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d);
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__id_ex_alu_op))) {
        vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
            = (vlSelf->top__DOT__alu_input_a - vlSelf->top__DOT__alu_input_b);
        vlSelf->top__DOT__salu_inst__DOT__overflow_flag_d 
            = (((vlSelf->top__DOT__alu_input_a >> 0x1fU) 
                != (vlSelf->top__DOT__alu_input_b >> 0x1fU)) 
               & ((vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                   >> 0x1fU) != (vlSelf->top__DOT__alu_input_a 
                                 >> 0x1fU)));
        VL_WRITEF("ALU SUB: 0x%x - 0x%x = 0x%x (decimal: %0d - %0d = %0d)\n",
                  32,vlSelf->top__DOT__alu_input_a,
                  32,vlSelf->top__DOT__alu_input_b,
                  32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d,
                  32,vlSelf->top__DOT__alu_input_a,
                  32,vlSelf->top__DOT__alu_input_b,
                  32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d);
    } else {
        vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
            = (vlSelf->top__DOT__alu_input_a + vlSelf->top__DOT__alu_input_b);
        vlSelf->top__DOT__salu_inst__DOT__overflow_flag_d 
            = (((vlSelf->top__DOT__alu_input_a >> 0x1fU) 
                == (vlSelf->top__DOT__alu_input_b >> 0x1fU)) 
               & ((vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                   >> 0x1fU) != (vlSelf->top__DOT__alu_input_a 
                                 >> 0x1fU)));
        VL_WRITEF("ALU ADD: 0x%x + 0x%x = 0x%x (decimal: %0d + %0d = %0d)\nALU ADD RESULT BYTES: %x %x %x %x\n",
                  32,vlSelf->top__DOT__alu_input_a,
                  32,vlSelf->top__DOT__alu_input_b,
                  32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d,
                  32,vlSelf->top__DOT__alu_input_a,
                  32,vlSelf->top__DOT__alu_input_b,
                  32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d,
                  8,(0xffU & vlSelf->top__DOT__salu_inst__DOT__alu_res_d),
                  8,(0xffU & (vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                              >> 8U)),8,(0xffU & (vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                                                  >> 0x10U)),
                  8,(vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                     >> 0x18U));
    }
    vlSelf->top__DOT__salu_inst__DOT__negative_flag_d 
        = (vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
           >> 0x1fU);
    if ((1U & (~ ((((((0xaU == (IData)(vlSelf->top__DOT__id_ex_alu_op)) 
                      | (0xbU == (IData)(vlSelf->top__DOT__id_ex_alu_op))) 
                     | (0xcU == (IData)(vlSelf->top__DOT__id_ex_alu_op))) 
                    | (0xdU == (IData)(vlSelf->top__DOT__id_ex_alu_op))) 
                   | (0xeU == (IData)(vlSelf->top__DOT__id_ex_alu_op))) 
                  | (0xfU == (IData)(vlSelf->top__DOT__id_ex_alu_op)))))) {
        vlSelf->top__DOT__salu_inst__DOT__zero_flag_d 
            = (0U == vlSelf->top__DOT__salu_inst__DOT__alu_res_d);
    }
    VL_WRITEF("ALU OUTPUT: alu_res_d = 0x%x (bytes: %x %x %x %x)\nALU FLAGS: zero=%b, negative=%b, overflow=%b\n",
              32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d,
              8,(0xffU & vlSelf->top__DOT__salu_inst__DOT__alu_res_d),
              8,(0xffU & (vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                          >> 8U)),8,(0xffU & (vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                                              >> 0x10U)),
              8,(vlSelf->top__DOT__salu_inst__DOT__alu_res_d 
                 >> 0x18U),1,(IData)(vlSelf->top__DOT__salu_inst__DOT__zero_flag_d),
              1,vlSelf->top__DOT__salu_inst__DOT__negative_flag_d,
              1,(IData)(vlSelf->top__DOT__salu_inst__DOT__overflow_flag_d));
    vlSelf->top__DOT__pc_inst__DOT__next_pc = ((IData)(4U) 
                                               + vlSelf->top__DOT__pc_out);
    if (VL_UNLIKELY(vlSelf->top__DOT__ex_mem_jalr)) {
        vlSelf->top__DOT__pc_inst__DOT__next_pc = (vlSelf->top__DOT__alu_input_a 
                                                   + vlSelf->top__DOT__ex_mem_imm);
        vlSelf->top__DOT__pc_inst__DOT__next_pc = (0xfffffffeU 
                                                   & vlSelf->top__DOT__pc_inst__DOT__next_pc);
        VL_WRITEF("PC: JALR from 0x%x to 0x%x (rs1_data=0x%x, imm=0x%x)\n",
                  32,vlSelf->top__DOT____Vcellinp__pc_inst__pc_i,
                  32,vlSelf->top__DOT__pc_inst__DOT__next_pc,
                  32,vlSelf->top__DOT__alu_input_a,
                  32,vlSelf->top__DOT__ex_mem_imm);
    } else if (VL_UNLIKELY(vlSelf->top__DOT__ex_mem_jump)) {
        vlSelf->top__DOT__pc_inst__DOT__next_pc = (vlSelf->top__DOT____Vcellinp__pc_inst__pc_i 
                                                   + vlSelf->top__DOT__ex_mem_imm);
        VL_WRITEF("PC: JAL from 0x%x to 0x%x (imm=0x%x)\n",
                  32,vlSelf->top__DOT____Vcellinp__pc_inst__pc_i,
                  32,vlSelf->top__DOT__pc_inst__DOT__next_pc,
                  32,vlSelf->top__DOT__ex_mem_imm);
    } else if (VL_UNLIKELY(vlSelf->top__DOT__take_branch)) {
        vlSelf->top__DOT__pc_inst__DOT__next_pc = (vlSelf->top__DOT____Vcellinp__pc_inst__pc_i 
                                                   + vlSelf->top__DOT__ex_mem_imm);
        VL_WRITEF("PC: Branch from 0x%x to 0x%x (imm=0x%x)\n",
                  32,vlSelf->top__DOT____Vcellinp__pc_inst__pc_i,
                  32,vlSelf->top__DOT__pc_inst__DOT__next_pc,
                  32,vlSelf->top__DOT__ex_mem_imm);
    } else if (VL_UNLIKELY((vlSelf->top__DOT____Vcellinp__pc_inst__pc_i 
                            != vlSelf->top__DOT__pc_out))) {
        vlSelf->top__DOT__pc_inst__DOT__next_pc = vlSelf->top__DOT____Vcellinp__pc_inst__pc_i;
        VL_WRITEF("PC: Forced update from 0x%x to 0x%x\n",
                  32,vlSelf->top__DOT__pc_out,32,vlSelf->top__DOT__pc_inst__DOT__next_pc);
    }
    if (VL_UNLIKELY(((0x100U < vlSelf->top__DOT__pc_inst__DOT__next_pc) 
                     | (0U != (3U & vlSelf->top__DOT__pc_inst__DOT__next_pc))))) {
        VL_WRITEF("WARNING: PC invalid (0x%x). Program continuing but PC limited.\n",
                  32,vlSelf->top__DOT__pc_inst__DOT__next_pc);
        vlSelf->top__DOT__pc_inst__DOT__next_pc = vlSelf->top__DOT__pc_out;
    }
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([changed] top.salu_inst.alu_res_d)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([changed] top.salu_inst.alu_res_d)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cycle_count = 0;
    vlSelf->top__DOT__pc_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__stall_pipeline = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__take_branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__pc_src = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__rs1_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__rs2_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__rd_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__reg_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__imm_value = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__imm_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__alu_op = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__mem_read = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_size = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__jump = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__result_src = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__uses_rs1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__uses_rs2 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__last_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__same_pc_counter = VL_RAND_RESET_I(10);
    vlSelf->top__DOT__detected_infinite_loop = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__rs1_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rs2_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rd_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_input_a = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_input_b = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_rs2_input = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__forward_a = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__forward_b = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__mem_rdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__if_id_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__if_id_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__id_ex_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__id_ex_rs1_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__id_ex_rs2_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__id_ex_imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__id_ex_rs1_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__id_ex_rs2_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__id_ex_rd_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__id_ex_reg_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__id_ex_mem_read = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__id_ex_mem_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__id_ex_mem_size = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__id_ex_branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__id_ex_jump = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__id_ex_result_src = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__id_ex_alu_op = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__id_ex_imm_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__id_ex_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_mem_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_mem_alu_result = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_mem_rs2_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_mem_imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ex_mem_rd_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__ex_mem_reg_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_mem_mem_read = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_mem_mem_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_mem_mem_size = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ex_mem_result_src = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ex_mem_zero_flag = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_mem_branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_mem_jump = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_mem_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_wb_alu_result = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_wb_mem_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_wb_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_wb_rd_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__mem_wb_reg_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_wb_result_src = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__mem_wb_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__forwarded_rs1_value = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__forwarded_rs2_value = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__id_ex_jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ex_mem_jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____Vcellinp__pc_inst__pc_i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__instruction_count = 0;
    vlSelf->top__DOT__address_0_contents = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__unnamedblk1__DOT__fd = 0;
    vlSelf->top__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->top__DOT__unnamedblk3__DOT__local_rs2_addr = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__pc_inst__DOT__next_pc = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->top__DOT__instr_mem_inst__DOT__imem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk1__DOT__mem_index = 0;
    vlSelf->top__DOT__instr_mem_inst__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->top__DOT__sdecode_inst__DOT__is_r_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sdecode_inst__DOT__is_i_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sdecode_inst__DOT__is_s_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sdecode_inst__DOT__is_b_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sdecode_inst__DOT__is_u_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sdecode_inst__DOT__is_j_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sdecode_inst__DOT__j_imm = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__sregfile_inst__DOT__register[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__sregfile_inst__DOT__cycle_count = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__sregfile_inst__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->top__DOT__salu_inst__DOT__alu_res_d = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__salu_inst__DOT__zero_flag_d = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__salu_inst__DOT__negative_flag_d = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__salu_inst__DOT__overflow_flag_d = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->top__DOT__sdatamem_inst__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__sdatamem_inst__DOT__verify_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sdatamem_inst__DOT__verify_addr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__sdatamem_inst__DOT__verify_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__sdatamem_inst__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->__Vtask_top__DOT__sdatamem_inst__DOT__print_mem_status__8__addr = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__top__DOT__cycle_count = 0;
    vlSelf->__Vdly__top__DOT__instruction_count = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__salu_inst__DOT__alu_res_d__0 = VL_RAND_RESET_I(32);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
