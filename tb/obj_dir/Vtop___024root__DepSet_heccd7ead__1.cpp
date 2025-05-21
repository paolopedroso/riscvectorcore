// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Init
    std::string __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name;
    std::string __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
    CData/*4:0*/ __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx;
    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0;
    // Body
    if (vlSelf->rst_n) {
        if (VL_UNLIKELY(vlSelf->top__DOT__ex_mem_mem_write)) {
            VL_WRITEF("TOP: \nEXECUTING MEMORY STORE: addr=0x%x, data=0x%x\n",
                      32,vlSelf->top__DOT__ex_mem_alu_result,
                      32,vlSelf->top__DOT__ex_mem_rs2_data);
            if (VL_UNLIKELY((0x23U == (0x7fU & vlSelf->top__DOT__ex_mem_instr)))) {
                vlSelf->top__DOT__unnamedblk3__DOT__local_rs2_addr 
                    = (0x1fU & (vlSelf->top__DOT__ex_mem_instr 
                                >> 0x14U));
                VL_WRITEF("TOP:   STORE INSTRUCTION: Using rs2=x%0# (value=0x%x)\n",
                          5,vlSelf->top__DOT__unnamedblk3__DOT__local_rs2_addr,
                          32,vlSelf->top__DOT__ex_mem_rs2_data);
            }
            if (VL_UNLIKELY((0U == vlSelf->top__DOT__ex_mem_alu_result))) {
                VL_WRITEF("TOP:   CRITICAL STORE TO ADDRESS 0: val=0x%x\n",
                          32,vlSelf->top__DOT__ex_mem_rs2_data);
            }
        }
        if (VL_UNLIKELY(vlSelf->top__DOT__ex_mem_mem_read)) {
            VL_WRITEF("TOP: \nEXECUTING MEMORY LOAD: addr=0x%x\n",
                      32,vlSelf->top__DOT__ex_mem_alu_result);
            if (VL_UNLIKELY((0U == vlSelf->top__DOT__ex_mem_alu_result))) {
                VL_WRITEF("TOP:   CRITICAL LOAD FROM ADDRESS 0\nTOP:   Memory contents: %02x %02x %02x %02x\n",
                          8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                          [0U],8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                          [1U],8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                          [2U],8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                          [3U]);
            }
        }
    }
    if (vlSelf->rst_n) {
        if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__ex_mem_mem_write) 
                         & (0U == vlSelf->top__DOT__ex_mem_alu_result)))) {
            VL_WRITEF("TOP: VERIFICATION: About to store 0x%x to address 0\n",
                      32,vlSelf->top__DOT__ex_mem_rs2_data);
        }
        vlSelf->top__DOT__address_0_contents = ((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                                 [3U] 
                                                 << 0x18U) 
                                                | ((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                                    [2U] 
                                                    << 0x10U) 
                                                   | ((vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                                       [1U] 
                                                       << 8U) 
                                                      | vlSelf->top__DOT__sdatamem_inst__DOT__memory
                                                      [0U])));
        if (VL_UNLIKELY(((1U == (IData)(vlSelf->top__DOT__mem_wb_result_src)) 
                         & (0U == vlSelf->top__DOT__mem_wb_alu_result)))) {
            VL_WRITEF("TOP: VERIFICATION: Loaded 0x%x from address 0\n",
                      32,vlSelf->top__DOT__mem_wb_mem_data);
            if ((3U == vlSelf->top__DOT__mem_wb_mem_data)) {
                VL_WRITEF("TOP: VERIFICATION PASSED: Successfully loaded correct value (3) from address 0\n");
            } else {
                VL_WRITEF("TOP: VERIFICATION FAILED: Expected to load 3, got 0x%x\n",
                          32,vlSelf->top__DOT__mem_wb_mem_data);
            }
        }
    }
    if ((1U & (~ (IData)(vlSelf->rst_n)))) {
        vlSelf->__Vdly__top__DOT__cycle_count = ((IData)(1U) 
                                                 + vlSelf->top__DOT__cycle_count);
        if (VL_UNLIKELY(VL_LTES_III(32, 0x7d0U, vlSelf->top__DOT__cycle_count))) {
            VL_WRITEF("TOP: WARNING: Maximum cycle count (2000) reached. Terminating simulation.\n");
            VL_WRITEF("REGFILE: ========== Register File Dump (Cycle %0#) ==========\n",
                      64,vlSelf->top__DOT__sregfile_inst__DOT__cycle_count);
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel97;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel97;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel97;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel97;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel97;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel97;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel97;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel97;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel97;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel97;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel97;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel97;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel97;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel97;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel97;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel97;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel97;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel97;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel97;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel97;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel97;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel97;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel97;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel97;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel97;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel97;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel97;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel97;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel97;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel97;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel97;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel97;
                }
                __Vlabel97: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x0 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                              [0U]),8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0U] >> 0x10U)),8,
                      (vlSelf->top__DOT__sregfile_inst__DOT__register
                       [0U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 1U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel98;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel98;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel98;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel98;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel98;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel98;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel98;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel98;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel98;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel98;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel98;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel98;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel98;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel98;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel98;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel98;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel98;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel98;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel98;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel98;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel98;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel98;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel98;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel98;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel98;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel98;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel98;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel98;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel98;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel98;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel98;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel98;
                }
                __Vlabel98: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x1 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [1U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                              [1U]),8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [1U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [1U] >> 0x10U)),8,
                      (vlSelf->top__DOT__sregfile_inst__DOT__register
                       [1U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 2U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel99;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel99;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel99;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel99;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel99;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel99;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel99;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel99;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel99;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel99;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel99;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel99;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel99;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel99;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel99;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel99;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel99;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel99;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel99;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel99;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel99;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel99;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel99;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel99;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel99;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel99;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel99;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel99;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel99;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel99;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel99;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel99;
                }
                __Vlabel99: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x2 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [2U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                              [2U]),8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [2U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [2U] >> 0x10U)),8,
                      (vlSelf->top__DOT__sregfile_inst__DOT__register
                       [2U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 3U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel100;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel100;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel100;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel100;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel100;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel100;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel100;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel100;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel100;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel100;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel100;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel100;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel100;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel100;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel100;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel100;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel100;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel100;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel100;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel100;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel100;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel100;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel100;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel100;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel100;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel100;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel100;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel100;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel100;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel100;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel100;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel100;
                }
                __Vlabel100: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x3 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [3U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                              [3U]),8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [3U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [3U] >> 0x10U)),8,
                      (vlSelf->top__DOT__sregfile_inst__DOT__register
                       [3U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 4U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel101;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel101;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel101;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel101;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel101;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel101;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel101;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel101;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel101;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel101;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel101;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel101;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel101;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel101;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel101;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel101;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel101;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel101;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel101;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel101;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel101;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel101;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel101;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel101;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel101;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel101;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel101;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel101;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel101;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel101;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel101;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel101;
                }
                __Vlabel101: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x4 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [4U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                              [4U]),8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [4U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [4U] >> 0x10U)),8,
                      (vlSelf->top__DOT__sregfile_inst__DOT__register
                       [4U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 5U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel102;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel102;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel102;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel102;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel102;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel102;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel102;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel102;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel102;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel102;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel102;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel102;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel102;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel102;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel102;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel102;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel102;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel102;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel102;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel102;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel102;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel102;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel102;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel102;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel102;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel102;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel102;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel102;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel102;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel102;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel102;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel102;
                }
                __Vlabel102: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x5 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [5U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                              [5U]),8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [5U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [5U] >> 0x10U)),8,
                      (vlSelf->top__DOT__sregfile_inst__DOT__register
                       [5U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 6U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel103;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel103;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel103;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel103;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel103;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel103;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel103;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel103;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel103;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel103;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel103;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel103;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel103;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel103;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel103;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel103;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel103;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel103;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel103;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel103;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel103;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel103;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel103;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel103;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel103;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel103;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel103;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel103;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel103;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel103;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel103;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel103;
                }
                __Vlabel103: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x6 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [6U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                              [6U]),8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [6U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [6U] >> 0x10U)),8,
                      (vlSelf->top__DOT__sregfile_inst__DOT__register
                       [6U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 7U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel104;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel104;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel104;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel104;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel104;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel104;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel104;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel104;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel104;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel104;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel104;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel104;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel104;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel104;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel104;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel104;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel104;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel104;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel104;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel104;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel104;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel104;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel104;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel104;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel104;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel104;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel104;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel104;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel104;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel104;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel104;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel104;
                }
                __Vlabel104: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x7 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [7U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                              [7U]),8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [7U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [7U] >> 0x10U)),8,
                      (vlSelf->top__DOT__sregfile_inst__DOT__register
                       [7U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 8U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel105;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel105;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel105;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel105;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel105;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel105;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel105;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel105;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel105;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel105;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel105;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel105;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel105;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel105;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel105;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel105;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel105;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel105;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel105;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel105;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel105;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel105;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel105;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel105;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel105;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel105;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel105;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel105;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel105;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel105;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel105;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel105;
                }
                __Vlabel105: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x8 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [8U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                              [8U]),8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [8U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [8U] >> 0x10U)),8,
                      (vlSelf->top__DOT__sregfile_inst__DOT__register
                       [8U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 9U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel106;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel106;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel106;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel106;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel106;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel106;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel106;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel106;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel106;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel106;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel106;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel106;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel106;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel106;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel106;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel106;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel106;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel106;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel106;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel106;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel106;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel106;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel106;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel106;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel106;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel106;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel106;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel106;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel106;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel106;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel106;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel106;
                }
                __Vlabel106: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x9 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [9U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                              [9U]),8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [9U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [9U] >> 0x10U)),8,
                      (vlSelf->top__DOT__sregfile_inst__DOT__register
                       [9U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0xaU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel107;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel107;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel107;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel107;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel107;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel107;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel107;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel107;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel107;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel107;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel107;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel107;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel107;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel107;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel107;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel107;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel107;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel107;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel107;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel107;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel107;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel107;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel107;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel107;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel107;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel107;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel107;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel107;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel107;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel107;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel107;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel107;
                }
                __Vlabel107: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x10 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0xaU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                [0xaU]),8,(0xffU & 
                                           (vlSelf->top__DOT__sregfile_inst__DOT__register
                                            [0xaU] 
                                            >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0xaU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0xaU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0xbU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel108;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel108;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel108;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel108;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel108;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel108;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel108;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel108;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel108;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel108;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel108;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel108;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel108;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel108;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel108;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel108;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel108;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel108;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel108;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel108;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel108;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel108;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel108;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel108;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel108;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel108;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel108;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel108;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel108;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel108;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel108;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel108;
                }
                __Vlabel108: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x11 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0xbU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                [0xbU]),8,(0xffU & 
                                           (vlSelf->top__DOT__sregfile_inst__DOT__register
                                            [0xbU] 
                                            >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0xbU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0xbU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0xcU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel109;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel109;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel109;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel109;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel109;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel109;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel109;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel109;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel109;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel109;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel109;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel109;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel109;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel109;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel109;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel109;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel109;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel109;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel109;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel109;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel109;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel109;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel109;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel109;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel109;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel109;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel109;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel109;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel109;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel109;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel109;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel109;
                }
                __Vlabel109: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x12 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0xcU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                [0xcU]),8,(0xffU & 
                                           (vlSelf->top__DOT__sregfile_inst__DOT__register
                                            [0xcU] 
                                            >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0xcU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0xcU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0xdU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel110;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel110;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel110;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel110;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel110;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel110;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel110;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel110;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel110;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel110;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel110;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel110;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel110;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel110;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel110;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel110;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel110;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel110;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel110;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel110;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel110;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel110;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel110;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel110;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel110;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel110;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel110;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel110;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel110;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel110;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel110;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel110;
                }
                __Vlabel110: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x13 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0xdU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                [0xdU]),8,(0xffU & 
                                           (vlSelf->top__DOT__sregfile_inst__DOT__register
                                            [0xdU] 
                                            >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0xdU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0xdU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0xeU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel111;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel111;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel111;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel111;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel111;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel111;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel111;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel111;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel111;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel111;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel111;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel111;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel111;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel111;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel111;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel111;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel111;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel111;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel111;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel111;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel111;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel111;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel111;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel111;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel111;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel111;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel111;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel111;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel111;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel111;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel111;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel111;
                }
                __Vlabel111: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x14 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0xeU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                [0xeU]),8,(0xffU & 
                                           (vlSelf->top__DOT__sregfile_inst__DOT__register
                                            [0xeU] 
                                            >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0xeU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0xeU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0xfU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel112;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel112;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel112;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel112;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel112;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel112;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel112;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel112;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel112;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel112;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel112;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel112;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel112;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel112;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel112;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel112;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel112;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel112;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel112;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel112;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel112;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel112;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel112;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel112;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel112;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel112;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel112;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel112;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel112;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel112;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel112;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel112;
                }
                __Vlabel112: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x15 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0xfU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                [0xfU]),8,(0xffU & 
                                           (vlSelf->top__DOT__sregfile_inst__DOT__register
                                            [0xfU] 
                                            >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0xfU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0xfU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x10U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel113;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel113;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel113;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel113;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel113;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel113;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel113;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel113;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel113;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel113;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel113;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel113;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel113;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel113;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel113;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel113;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel113;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel113;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel113;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel113;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel113;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel113;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel113;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel113;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel113;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel113;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel113;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel113;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel113;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel113;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel113;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel113;
                }
                __Vlabel113: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x16 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x10U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x10U]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x10U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x10U] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x10U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x11U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel114;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel114;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel114;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel114;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel114;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel114;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel114;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel114;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel114;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel114;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel114;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel114;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel114;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel114;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel114;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel114;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel114;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel114;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel114;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel114;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel114;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel114;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel114;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel114;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel114;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel114;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel114;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel114;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel114;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel114;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel114;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel114;
                }
                __Vlabel114: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x17 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x11U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x11U]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x11U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x11U] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x11U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x12U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel115;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel115;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel115;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel115;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel115;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel115;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel115;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel115;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel115;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel115;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel115;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel115;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel115;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel115;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel115;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel115;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel115;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel115;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel115;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel115;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel115;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel115;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel115;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel115;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel115;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel115;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel115;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel115;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel115;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel115;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel115;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel115;
                }
                __Vlabel115: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x18 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x12U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x12U]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x12U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x12U] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x12U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x13U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel116;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel116;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel116;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel116;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel116;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel116;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel116;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel116;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel116;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel116;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel116;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel116;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel116;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel116;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel116;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel116;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel116;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel116;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel116;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel116;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel116;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel116;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel116;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel116;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel116;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel116;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel116;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel116;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel116;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel116;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel116;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel116;
                }
                __Vlabel116: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x19 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x13U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x13U]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x13U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x13U] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x13U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x14U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel117;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel117;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel117;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel117;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel117;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel117;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel117;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel117;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel117;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel117;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel117;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel117;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel117;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel117;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel117;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel117;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel117;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel117;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel117;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel117;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel117;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel117;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel117;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel117;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel117;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel117;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel117;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel117;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel117;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel117;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel117;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel117;
                }
                __Vlabel117: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x20 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x14U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x14U]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x14U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x14U] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x14U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x15U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel118;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel118;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel118;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel118;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel118;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel118;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel118;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel118;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel118;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel118;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel118;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel118;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel118;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel118;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel118;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel118;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel118;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel118;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel118;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel118;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel118;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel118;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel118;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel118;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel118;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel118;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel118;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel118;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel118;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel118;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel118;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel118;
                }
                __Vlabel118: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x21 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x15U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x15U]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x15U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x15U] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x15U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x16U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel119;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel119;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel119;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel119;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel119;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel119;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel119;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel119;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel119;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel119;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel119;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel119;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel119;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel119;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel119;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel119;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel119;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel119;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel119;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel119;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel119;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel119;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel119;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel119;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel119;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel119;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel119;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel119;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel119;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel119;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel119;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel119;
                }
                __Vlabel119: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x22 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x16U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x16U]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x16U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x16U] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x16U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x17U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel120;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel120;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel120;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel120;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel120;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel120;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel120;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel120;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel120;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel120;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel120;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel120;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel120;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel120;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel120;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel120;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel120;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel120;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel120;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel120;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel120;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel120;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel120;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel120;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel120;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel120;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel120;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel120;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel120;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel120;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel120;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel120;
                }
                __Vlabel120: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x23 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x17U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x17U]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x17U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x17U] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x17U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x18U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel121;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel121;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel121;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel121;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel121;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel121;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel121;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel121;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel121;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel121;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel121;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel121;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel121;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel121;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel121;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel121;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel121;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel121;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel121;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel121;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel121;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel121;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel121;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel121;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel121;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel121;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel121;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel121;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel121;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel121;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel121;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel121;
                }
                __Vlabel121: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x24 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x18U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x18U]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x18U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x18U] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x18U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x19U;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel122;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel122;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel122;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel122;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel122;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel122;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel122;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel122;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel122;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel122;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel122;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel122;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel122;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel122;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel122;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel122;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel122;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel122;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel122;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel122;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel122;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel122;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel122;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel122;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel122;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel122;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel122;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel122;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel122;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel122;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel122;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel122;
                }
                __Vlabel122: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x25 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x19U],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x19U]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x19U] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x19U] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x19U] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x1aU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel123;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel123;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel123;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel123;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel123;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel123;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel123;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel123;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel123;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel123;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel123;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel123;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel123;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel123;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel123;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel123;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel123;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel123;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel123;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel123;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel123;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel123;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel123;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel123;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel123;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel123;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel123;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel123;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel123;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel123;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel123;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel123;
                }
                __Vlabel123: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x26 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x1aU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x1aU]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x1aU] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x1aU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x1aU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x1bU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel124;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel124;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel124;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel124;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel124;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel124;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel124;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel124;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel124;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel124;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel124;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel124;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel124;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel124;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel124;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel124;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel124;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel124;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel124;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel124;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel124;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel124;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel124;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel124;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel124;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel124;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel124;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel124;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel124;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel124;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel124;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel124;
                }
                __Vlabel124: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x27 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x1bU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x1bU]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x1bU] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x1bU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x1bU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x1cU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel125;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel125;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel125;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel125;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel125;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel125;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel125;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel125;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel125;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel125;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel125;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel125;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel125;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel125;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel125;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel125;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel125;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel125;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel125;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel125;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel125;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel125;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel125;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel125;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel125;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel125;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel125;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel125;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel125;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel125;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel125;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel125;
                }
                __Vlabel125: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x28 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x1cU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x1cU]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x1cU] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x1cU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x1cU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x1dU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel126;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel126;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel126;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel126;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel126;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel126;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel126;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel126;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel126;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel126;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel126;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel126;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel126;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel126;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel126;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel126;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel126;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel126;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel126;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel126;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel126;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel126;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel126;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel126;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel126;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel126;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel126;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel126;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel126;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel126;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel126;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel126;
                }
                __Vlabel126: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x29 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x1dU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x1dU]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x1dU] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x1dU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x1dU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x1eU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel127;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel127;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel127;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel127;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel127;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel127;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel127;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel127;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel127;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel127;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel127;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel127;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel127;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel127;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel127;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel127;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel127;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel127;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel127;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel127;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel127;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel127;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel127;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel127;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel127;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel127;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel127;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel127;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel127;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel127;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel127;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel127;
                }
                __Vlabel127: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x30 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x1eU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x1eU]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x1eU] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x1eU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x1eU] >> 0x18U));
            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx = 0x1fU;
            {
                if ((0x10U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t6   "};
                                    goto __Vlabel128;
                                } else {
                                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                        std::string{"t5   "};
                                    goto __Vlabel128;
                                }
                            } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t4   "};
                                goto __Vlabel128;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"t3   "};
                                goto __Vlabel128;
                            }
                        } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s11  "};
                                goto __Vlabel128;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s10  "};
                                goto __Vlabel128;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s9   "};
                            goto __Vlabel128;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s8   "};
                            goto __Vlabel128;
                        }
                    } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s7   "};
                                goto __Vlabel128;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"s6   "};
                                goto __Vlabel128;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s5   "};
                            goto __Vlabel128;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s4   "};
                            goto __Vlabel128;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s3   "};
                            goto __Vlabel128;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"s2   "};
                            goto __Vlabel128;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a7   "};
                        goto __Vlabel128;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"a6   "};
                        goto __Vlabel128;
                    }
                } else if ((8U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a5   "};
                                goto __Vlabel128;
                            } else {
                                __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                    std::string{"a4   "};
                                goto __Vlabel128;
                            }
                        } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a3   "};
                            goto __Vlabel128;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a2   "};
                            goto __Vlabel128;
                        }
                    } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a1   "};
                            goto __Vlabel128;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"a0   "};
                            goto __Vlabel128;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s1   "};
                        goto __Vlabel128;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"s0/fp"};
                        goto __Vlabel128;
                    }
                } else if ((4U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t2   "};
                            goto __Vlabel128;
                        } else {
                            __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                                std::string{"t1   "};
                            goto __Vlabel128;
                        }
                    } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"t0   "};
                        goto __Vlabel128;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"tp   "};
                        goto __Vlabel128;
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"gp   "};
                        goto __Vlabel128;
                    } else {
                        __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                            std::string{"sp   "};
                        goto __Vlabel128;
                    }
                } else if ((1U & (IData)(__Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__reg_idx))) {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"ra   "};
                    goto __Vlabel128;
                } else {
                    __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout = 
                        std::string{"zero "};
                    goto __Vlabel128;
                }
                __Vlabel128: ;
            }
            __Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name 
                = __Vfunc_top__DOT__sregfile_inst__DOT__get_reg_name__1__Vfuncout;
            VL_WRITEF("  x31 (%@): 0x%08x (bytes: %02x %02x %02x %02x)\n==================================================\n",
                      -1,&(__Vtask_top__DOT__sregfile_inst__DOT__dump_registers__0__unnamedblk2__DOT__unnamedblk3__DOT__reg_name),
                      32,vlSelf->top__DOT__sregfile_inst__DOT__register
                      [0x1fU],8,(0xffU & vlSelf->top__DOT__sregfile_inst__DOT__register
                                 [0x1fU]),8,(0xffU 
                                             & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                                [0x1fU] 
                                                >> 8U)),
                      8,(0xffU & (vlSelf->top__DOT__sregfile_inst__DOT__register
                                  [0x1fU] >> 0x10U)),
                      8,(vlSelf->top__DOT__sregfile_inst__DOT__register
                         [0x1fU] >> 0x18U));
            VL_FINISH_MT("../core/../core/top.sv", 30, "");
        }
    }
    if (vlSelf->rst_n) {
        if (VL_UNLIKELY((0U == VL_MODDIVS_III(32, vlSelf->top__DOT__cycle_count, (IData)(0xaU))))) {
            VL_WRITEF("TOP: Cycle %0d: PC=0x%x\n",32,
                      vlSelf->top__DOT__cycle_count,
                      32,vlSelf->top__DOT__pc_out);
        }
        if (VL_UNLIKELY(((~ (IData)(vlSelf->top__DOT__stall_pipeline)) 
                         & (0U != vlSelf->top__DOT__if_id_instr)))) {
            vlSelf->__Vdly__top__DOT__instruction_count 
                = ((IData)(1U) + vlSelf->top__DOT__instruction_count);
            VL_WRITEF("TOP: Executed instruction %0d: 0x%x at PC=0x%x\n",
                      32,vlSelf->top__DOT__instruction_count,
                      32,vlSelf->top__DOT__if_id_instr,
                      32,vlSelf->top__DOT__if_id_pc);
        }
    }
    if (vlSelf->rst_n) {
        if ((((IData)(vlSelf->top__DOT__ex_mem_mem_write) 
              & (2U == (IData)(vlSelf->top__DOT__ex_mem_mem_size))) 
             & (0x3fdU > vlSelf->top__DOT__ex_mem_alu_result))) {
            vlSelf->top__DOT__sdatamem_inst__DOT__verify_addr 
                = vlSelf->top__DOT__ex_mem_alu_result;
            vlSelf->top__DOT__sdatamem_inst__DOT__verify_data 
                = vlSelf->top__DOT__ex_mem_rs2_data;
        }
    }
    vlSelf->top__DOT__sdatamem_inst__DOT__verify_write 
        = ((IData)(vlSelf->rst_n) && (((IData)(vlSelf->top__DOT__ex_mem_mem_write) 
                                       & (2U == (IData)(vlSelf->top__DOT__ex_mem_mem_size))) 
                                      & (0x3fdU > vlSelf->top__DOT__ex_mem_alu_result)));
    vlSelf->top__DOT__cycle_count = vlSelf->__Vdly__top__DOT__cycle_count;
    vlSelf->top__DOT__instruction_count = vlSelf->__Vdly__top__DOT__instruction_count;
}

extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h5e3dfec6_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h392e18e9_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_ha96ed2bf_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_he4685dc5_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h72611ab3_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hf1f34e79_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    IData/*31:0*/ __Vdly__top__DOT__if_id_pc;
    __Vdly__top__DOT__if_id_pc = 0;
    IData/*31:0*/ __Vdly__top__DOT__if_id_instr;
    __Vdly__top__DOT__if_id_instr = 0;
    CData/*1:0*/ __Vdly__top__DOT__ex_mem_result_src;
    __Vdly__top__DOT__ex_mem_result_src = 0;
    CData/*0:0*/ __Vdly__top__DOT__id_ex_reg_write;
    __Vdly__top__DOT__id_ex_reg_write = 0;
    CData/*0:0*/ __Vdly__top__DOT__id_ex_mem_read;
    __Vdly__top__DOT__id_ex_mem_read = 0;
    CData/*0:0*/ __Vdly__top__DOT__id_ex_mem_write;
    __Vdly__top__DOT__id_ex_mem_write = 0;
    CData/*0:0*/ __Vdly__top__DOT__id_ex_branch;
    __Vdly__top__DOT__id_ex_branch = 0;
    IData/*31:0*/ __Vdly__top__DOT__id_ex_rs2_data;
    __Vdly__top__DOT__id_ex_rs2_data = 0;
    CData/*4:0*/ __Vdly__top__DOT__id_ex_rs2_addr;
    __Vdly__top__DOT__id_ex_rs2_addr = 0;
    CData/*4:0*/ __Vdly__top__DOT__id_ex_rd_addr;
    __Vdly__top__DOT__id_ex_rd_addr = 0;
    CData/*4:0*/ __Vdly__top__DOT__ex_mem_rd_addr;
    __Vdly__top__DOT__ex_mem_rd_addr = 0;
    CData/*0:0*/ __Vdly__top__DOT__ex_mem_reg_write;
    __Vdly__top__DOT__ex_mem_reg_write = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__sregfile_inst__DOT__register__v0;
    __Vdlyvdim0__top__DOT__sregfile_inst__DOT__register__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__sregfile_inst__DOT__register__v0;
    __Vdlyvval__top__DOT__sregfile_inst__DOT__register__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sregfile_inst__DOT__register__v0;
    __Vdlyvset__top__DOT__sregfile_inst__DOT__register__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sregfile_inst__DOT__register__v1;
    __Vdlyvset__top__DOT__sregfile_inst__DOT__register__v1 = 0;
    SData/*9:0*/ __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v0;
    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v0;
    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v0;
    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v1;
    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v1 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v1;
    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v1 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v1;
    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v1 = 0;
    SData/*9:0*/ __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v2;
    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v2 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v2;
    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v2 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v2;
    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v2 = 0;
    SData/*9:0*/ __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v3;
    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v3 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v3;
    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v3 = 0;
    SData/*9:0*/ __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v4;
    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v4 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v4;
    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v4 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v4;
    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v4 = 0;
    SData/*9:0*/ __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v5;
    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v5 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v5;
    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v5 = 0;
    SData/*9:0*/ __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v6;
    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v6 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v6;
    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v6 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v6;
    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v6 = 0;
    // Body
    VL_WRITEF("DECODE: Instruction: 0x%x\nDECODE: Opcode: 0x%x, funct3: 0x%x, funct7: 0x%x\nDECODE: rs1: x%0#, rs2: x%0#, rd: x%0#\n",
              32,vlSelf->top__DOT__if_id_instr,7,(0x7fU 
                                                  & vlSelf->top__DOT__if_id_instr),
              3,(7U & (vlSelf->top__DOT__if_id_instr 
                       >> 0xcU)),7,(vlSelf->top__DOT__if_id_instr 
                                    >> 0x19U),5,(0x1fU 
                                                 & (vlSelf->top__DOT__if_id_instr 
                                                    >> 0xfU)),
              5,(0x1fU & (vlSelf->top__DOT__if_id_instr 
                          >> 0x14U)),5,(0x1fU & (vlSelf->top__DOT__if_id_instr 
                                                 >> 7U)));
    __Vdly__top__DOT__id_ex_branch = vlSelf->top__DOT__id_ex_branch;
    __Vdly__top__DOT__id_ex_mem_write = vlSelf->top__DOT__id_ex_mem_write;
    __Vdly__top__DOT__id_ex_reg_write = vlSelf->top__DOT__id_ex_reg_write;
    __Vdly__top__DOT__ex_mem_result_src = vlSelf->top__DOT__ex_mem_result_src;
    __Vdly__top__DOT__if_id_pc = vlSelf->top__DOT__if_id_pc;
    __Vdly__top__DOT__id_ex_rd_addr = vlSelf->top__DOT__id_ex_rd_addr;
    __Vdly__top__DOT__id_ex_mem_read = vlSelf->top__DOT__id_ex_mem_read;
    __Vdly__top__DOT__id_ex_rs2_data = vlSelf->top__DOT__id_ex_rs2_data;
    __Vdly__top__DOT__ex_mem_reg_write = vlSelf->top__DOT__ex_mem_reg_write;
    __Vdly__top__DOT__ex_mem_rd_addr = vlSelf->top__DOT__ex_mem_rd_addr;
    __Vdly__top__DOT__id_ex_rs2_addr = vlSelf->top__DOT__id_ex_rs2_addr;
    __Vdly__top__DOT__if_id_instr = vlSelf->top__DOT__if_id_instr;
    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v0 = 0U;
    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v1 = 0U;
    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v2 = 0U;
    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v4 = 0U;
    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v6 = 0U;
    __Vdlyvset__top__DOT__sregfile_inst__DOT__register__v0 = 0U;
    __Vdlyvset__top__DOT__sregfile_inst__DOT__register__v1 = 0U;
    if (vlSelf->rst_n) {
        if (VL_UNLIKELY(vlSelf->top__DOT__ex_mem_mem_write)) {
            VL_WRITEF("DMEM: SAVE INSTRUCTION DETECTED\nDMEM: INSTRUCTION: 0x%x\nDMEM: MEMORY DEBUG: Writing to address 0x%x, data=0x%x, size=%0#\n",
                      32,vlSelf->top__DOT__ex_mem_instr,
                      32,vlSelf->top__DOT__ex_mem_alu_result,
                      32,vlSelf->top__DOT__ex_mem_rs2_data,
                      2,(IData)(vlSelf->top__DOT__ex_mem_mem_size));
            if ((0x3fdU <= vlSelf->top__DOT__ex_mem_alu_result)) {
                VL_WRITEF("DMEM: WARNING: Memory write out of bounds: addr=0x%x\n",
                          32,vlSelf->top__DOT__ex_mem_alu_result);
            } else {
                if (VL_UNLIKELY((2U & (IData)(vlSelf->top__DOT__ex_mem_mem_size)))) {
                    VL_WRITEF("DMEM: MEMORY WRITE WORD: addr=0x%x, data=0x%08x\n",
                              32,vlSelf->top__DOT__ex_mem_alu_result,
                              32,vlSelf->top__DOT__ex_mem_rs2_data);
                    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v0 
                        = (0xffU & vlSelf->top__DOT__ex_mem_rs2_data);
                    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v0 = 1U;
                    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v0 
                        = (0x3ffU & vlSelf->top__DOT__ex_mem_alu_result);
                    VL_WRITEF("DMEM:   Writing bytes: %02x %02x %02x %02x\n",
                              8,(0xffU & vlSelf->top__DOT__ex_mem_rs2_data),
                              8,(0xffU & (vlSelf->top__DOT__ex_mem_rs2_data 
                                          >> 8U)),8,
                              (0xffU & (vlSelf->top__DOT__ex_mem_rs2_data 
                                        >> 0x10U)),
                              8,(vlSelf->top__DOT__ex_mem_rs2_data 
                                 >> 0x18U));
                    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v1 
                        = (0xffU & (vlSelf->top__DOT__ex_mem_rs2_data 
                                    >> 8U));
                    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v1 = 1U;
                    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v1 
                        = (0x3ffU & ((IData)(1U) + vlSelf->top__DOT__ex_mem_alu_result));
                    VL_WRITEF("DMEM: ** MEMORY STORE: WORD 0x%x written to address 0x%x **\n",
                              32,vlSelf->top__DOT__ex_mem_rs2_data,
                              32,vlSelf->top__DOT__ex_mem_alu_result);
                    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v2 
                        = (0xffU & (vlSelf->top__DOT__ex_mem_rs2_data 
                                    >> 0x10U));
                    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v2 = 1U;
                    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v2 
                        = (0x3ffU & ((IData)(2U) + vlSelf->top__DOT__ex_mem_alu_result));
                    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v3 
                        = (vlSelf->top__DOT__ex_mem_rs2_data 
                           >> 0x18U);
                    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v3 
                        = (0x3ffU & ((IData)(3U) + vlSelf->top__DOT__ex_mem_alu_result));
                } else if ((1U & (IData)(vlSelf->top__DOT__ex_mem_mem_size))) {
                    VL_WRITEF("DMEM: MEMORY WRITE HALFWORD: addr=0x%x, data=%04x\n",
                              32,vlSelf->top__DOT__ex_mem_alu_result,
                              16,(0xffffU & vlSelf->top__DOT__ex_mem_rs2_data));
                    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v4 
                        = (0xffU & vlSelf->top__DOT__ex_mem_rs2_data);
                    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v4 = 1U;
                    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v4 
                        = (0x3ffU & vlSelf->top__DOT__ex_mem_alu_result);
                    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v5 
                        = (0xffU & (vlSelf->top__DOT__ex_mem_rs2_data 
                                    >> 8U));
                    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v5 
                        = (0x3ffU & ((IData)(1U) + vlSelf->top__DOT__ex_mem_alu_result));
                } else {
                    VL_WRITEF("DMEM: MEMORY WRITE BYTE: addr=0x%x, data=%02x\n",
                              32,vlSelf->top__DOT__ex_mem_alu_result,
                              8,(0xffU & vlSelf->top__DOT__ex_mem_rs2_data));
                    __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v6 
                        = (0xffU & vlSelf->top__DOT__ex_mem_rs2_data);
                    __Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v6 = 1U;
                    __Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v6 
                        = (0x3ffU & vlSelf->top__DOT__ex_mem_alu_result);
                }
                VL_WRITEF("DMEM: MEMORY POST-WRITE CHECK: Address 0x%x now contains bytes: %02x %02x %02x %02x\n",
                          32,vlSelf->top__DOT__ex_mem_alu_result,
                          8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                          [(0x3ffU & vlSelf->top__DOT__ex_mem_alu_result)],
                          8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                          [(0x3ffU & ((IData)(1U) + vlSelf->top__DOT__ex_mem_alu_result))],
                          8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                          [(0x3ffU & ((IData)(2U) + vlSelf->top__DOT__ex_mem_alu_result))],
                          8,vlSelf->top__DOT__sdatamem_inst__DOT__memory
                          [(0x3ffU & ((IData)(3U) + vlSelf->top__DOT__ex_mem_alu_result))]);
            }
        }
    } else {
        vlSelf->top__DOT__sdatamem_inst__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x400U, vlSelf->top__DOT__sdatamem_inst__DOT__unnamedblk1__DOT__i)) {
            vlSelf->top__DOT__sdatamem_inst__DOT__memory[(0x3ffU 
                                                          & vlSelf->top__DOT__sdatamem_inst__DOT__unnamedblk1__DOT__i)] = 0U;
            vlSelf->top__DOT__sdatamem_inst__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelf->top__DOT__sdatamem_inst__DOT__unnamedblk1__DOT__i);
        }
    }
    if (vlSelf->rst_n) {
        vlSelf->top__DOT__sregfile_inst__DOT__cycle_count 
            = (1ULL + vlSelf->top__DOT__sregfile_inst__DOT__cycle_count);
        if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__mem_wb_reg_write) 
                         & (0U != (IData)(vlSelf->top__DOT__mem_wb_rd_addr))))) {
            VL_WRITEF("REGFILE: Writing 0x%08x to x%0#\n",
                      32,vlSelf->top__DOT__rd_data,
                      5,(IData)(vlSelf->top__DOT__mem_wb_rd_addr));
            __Vdlyvval__top__DOT__sregfile_inst__DOT__register__v0 
                = vlSelf->top__DOT__rd_data;
            __Vdlyvset__top__DOT__sregfile_inst__DOT__register__v0 = 1U;
            __Vdlyvdim0__top__DOT__sregfile_inst__DOT__register__v0 
                = vlSelf->top__DOT__mem_wb_rd_addr;
        }
    } else {
        vlSelf->top__DOT__sregfile_inst__DOT__unnamedblk1__DOT__i = 0x20U;
        vlSelf->top__DOT__sregfile_inst__DOT__cycle_count = 0ULL;
        __Vdlyvset__top__DOT__sregfile_inst__DOT__register__v1 = 1U;
    }
    if (__Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v0) {
        vlSelf->top__DOT__sdatamem_inst__DOT__memory[__Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v0] 
            = __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v0;
    }
    if (__Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v1) {
        vlSelf->top__DOT__sdatamem_inst__DOT__memory[__Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v1] 
            = __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v1;
    }
    if (__Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v2) {
        vlSelf->top__DOT__sdatamem_inst__DOT__memory[__Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v2] 
            = __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v2;
        vlSelf->top__DOT__sdatamem_inst__DOT__memory[__Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v3] 
            = __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v3;
    }
    if (__Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v4) {
        vlSelf->top__DOT__sdatamem_inst__DOT__memory[__Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v4] 
            = __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v4;
        vlSelf->top__DOT__sdatamem_inst__DOT__memory[__Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v5] 
            = __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v5;
    }
    if (__Vdlyvset__top__DOT__sdatamem_inst__DOT__memory__v6) {
        vlSelf->top__DOT__sdatamem_inst__DOT__memory[__Vdlyvdim0__top__DOT__sdatamem_inst__DOT__memory__v6] 
            = __Vdlyvval__top__DOT__sdatamem_inst__DOT__memory__v6;
    }
    if (__Vdlyvset__top__DOT__sregfile_inst__DOT__register__v0) {
        vlSelf->top__DOT__sregfile_inst__DOT__register[__Vdlyvdim0__top__DOT__sregfile_inst__DOT__register__v0] 
            = __Vdlyvval__top__DOT__sregfile_inst__DOT__register__v0;
    }
    if (__Vdlyvset__top__DOT__sregfile_inst__DOT__register__v1) {
        vlSelf->top__DOT__sregfile_inst__DOT__register[0U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[1U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[2U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[3U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[4U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[5U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[6U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[7U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[8U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[9U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0xaU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0xbU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0xcU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0xdU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0xeU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0xfU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x10U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x11U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x12U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x13U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x14U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x15U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x16U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x17U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x18U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x19U] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x1aU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x1bU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x1cU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x1dU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x1eU] = 0U;
        vlSelf->top__DOT__sregfile_inst__DOT__register[0x1fU] = 0U;
    }
    if (vlSelf->rst_n) {
        if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__ex_mem_reg_write) 
                         & (0U != (IData)(vlSelf->top__DOT__ex_mem_rd_addr))))) {
            VL_WRITEF("TOP: PIPELINE: MEM/WB stage update - ex_mem_alu_result=0x%x, rd=x%0#\n",
                      32,vlSelf->top__DOT__ex_mem_alu_result,
                      5,(IData)(vlSelf->top__DOT__ex_mem_rd_addr));
        }
        vlSelf->top__DOT__mem_wb_alu_result = vlSelf->top__DOT__ex_mem_alu_result;
        vlSelf->top__DOT__mem_wb_mem_data = vlSelf->top__DOT__mem_rdata;
        vlSelf->top__DOT__mem_wb_pc = vlSelf->top__DOT__ex_mem_pc;
        vlSelf->top__DOT__mem_wb_rd_addr = vlSelf->top__DOT__ex_mem_rd_addr;
        vlSelf->top__DOT__mem_wb_reg_write = vlSelf->top__DOT__ex_mem_reg_write;
        vlSelf->top__DOT__mem_wb_result_src = vlSelf->top__DOT__ex_mem_result_src;
        vlSelf->top__DOT__mem_wb_instr = vlSelf->top__DOT__ex_mem_instr;
    } else {
        vlSelf->top__DOT__mem_wb_alu_result = 0U;
        vlSelf->top__DOT__mem_wb_mem_data = 0U;
        vlSelf->top__DOT__mem_wb_pc = 0U;
        vlSelf->top__DOT__mem_wb_rd_addr = 0U;
        vlSelf->top__DOT__mem_wb_reg_write = 0U;
        vlSelf->top__DOT__mem_wb_result_src = 0U;
        vlSelf->top__DOT__mem_wb_instr = 0U;
    }
    if (vlSelf->rst_n) {
        if (VL_UNLIKELY(vlSelf->top__DOT__stall_pipeline)) {
            VL_WRITEF("TOP: IF/ID: Stalled (keeping current values)\n");
        } else if (vlSelf->top__DOT__pc_src) {
            VL_WRITEF("TOP: IF/ID: Inserting NOP due to branch/jump\n");
            __Vdly__top__DOT__if_id_pc = vlSelf->top__DOT__pc_out;
            __Vdly__top__DOT__if_id_instr = 0x13U;
        } else {
            VL_WRITEF("TOP: IF/ID: Loading instruction 0x%x from PC 0x%x\n",
                      32,vlSelf->top__DOT__instr,32,
                      vlSelf->top__DOT__pc_out);
            __Vdly__top__DOT__if_id_pc = vlSelf->top__DOT__pc_out;
            __Vdly__top__DOT__if_id_instr = vlSelf->top__DOT__instr;
        }
        vlSelf->top__DOT__ex_mem_pc = vlSelf->top__DOT__id_ex_pc;
        vlSelf->top__DOT__ex_mem_rs2_data = vlSelf->top__DOT__forwarded_rs2_value;
        vlSelf->top__DOT__ex_mem_imm = vlSelf->top__DOT__id_ex_imm;
        vlSelf->top__DOT__ex_mem_mem_size = vlSelf->top__DOT__id_ex_mem_size;
        __Vdly__top__DOT__ex_mem_result_src = vlSelf->top__DOT__id_ex_result_src;
        vlSelf->top__DOT__ex_mem_zero_flag = vlSelf->top__DOT__salu_inst__DOT__zero_flag_d;
        vlSelf->top__DOT__ex_mem_jump = vlSelf->top__DOT__id_ex_jump;
        vlSelf->top__DOT__ex_mem_instr = vlSelf->top__DOT__id_ex_instr;
        vlSelf->top__DOT__ex_mem_jalr = vlSelf->top__DOT__id_ex_jalr;
        if (VL_UNLIKELY(vlSelf->top__DOT__stall_pipeline)) {
            VL_WRITEF("TOP: ID/EX: Inserting NOP due to stall\n");
            __Vdly__top__DOT__id_ex_reg_write = 0U;
            __Vdly__top__DOT__id_ex_mem_read = 0U;
            __Vdly__top__DOT__id_ex_mem_write = 0U;
            __Vdly__top__DOT__id_ex_branch = 0U;
            vlSelf->top__DOT__id_ex_jump = 0U;
            vlSelf->top__DOT__id_ex_instr = 0x13U;
        } else if (vlSelf->top__DOT__pc_src) {
            VL_WRITEF("TOP: ID/EX: Inserting NOP due to branch/jump\n");
            vlSelf->top__DOT__id_ex_pc = vlSelf->top__DOT__if_id_pc;
            vlSelf->top__DOT__id_ex_rs1_data = vlSelf->top__DOT__rs1_data;
            __Vdly__top__DOT__id_ex_rs2_data = vlSelf->top__DOT__rs2_data;
            vlSelf->top__DOT__id_ex_rs1_addr = vlSelf->top__DOT__rs1_addr;
            __Vdly__top__DOT__id_ex_rs2_addr = vlSelf->top__DOT__rs2_addr;
            __Vdly__top__DOT__id_ex_rd_addr = 0U;
            __Vdly__top__DOT__id_ex_reg_write = 0U;
            __Vdly__top__DOT__id_ex_mem_read = 0U;
            __Vdly__top__DOT__id_ex_mem_write = 0U;
            __Vdly__top__DOT__id_ex_branch = 0U;
            vlSelf->top__DOT__id_ex_jump = 0U;
            vlSelf->top__DOT__id_ex_result_src = 0U;
            vlSelf->top__DOT__id_ex_alu_op = 0U;
            vlSelf->top__DOT__id_ex_imm = 0U;
            vlSelf->top__DOT__id_ex_imm_valid = 0U;
            vlSelf->top__DOT__id_ex_instr = 0x13U;
        } else {
            vlSelf->top__DOT__id_ex_pc = vlSelf->top__DOT__if_id_pc;
            vlSelf->top__DOT__id_ex_rs1_data = vlSelf->top__DOT__rs1_data;
            __Vdly__top__DOT__id_ex_rs2_data = vlSelf->top__DOT__rs2_data;
            vlSelf->top__DOT__id_ex_imm = vlSelf->top__DOT__imm_value;
            vlSelf->top__DOT__id_ex_rs1_addr = vlSelf->top__DOT__rs1_addr;
            __Vdly__top__DOT__id_ex_rs2_addr = vlSelf->top__DOT__rs2_addr;
            __Vdly__top__DOT__id_ex_rd_addr = vlSelf->top__DOT__rd_addr;
            __Vdly__top__DOT__id_ex_reg_write = vlSelf->top__DOT__reg_write_en;
            __Vdly__top__DOT__id_ex_mem_read = vlSelf->top__DOT__mem_read;
            __Vdly__top__DOT__id_ex_mem_write = vlSelf->top__DOT__mem_write;
            vlSelf->top__DOT__id_ex_mem_size = vlSelf->top__DOT__mem_size;
            __Vdly__top__DOT__id_ex_branch = vlSelf->top__DOT__branch;
            vlSelf->top__DOT__id_ex_jump = vlSelf->top__DOT__jump;
            vlSelf->top__DOT__id_ex_result_src = vlSelf->top__DOT__result_src;
            vlSelf->top__DOT__id_ex_alu_op = vlSelf->top__DOT__alu_op;
            vlSelf->top__DOT__id_ex_imm_valid = vlSelf->top__DOT__imm_valid;
            vlSelf->top__DOT__id_ex_instr = vlSelf->top__DOT__if_id_instr;
            vlSelf->top__DOT__id_ex_jalr = vlSelf->top__DOT__jalr;
            VL_WRITEF("TOP: ID/EX: Processing instruction 0x%x\nTOP: ID/EX: rs1=x%0# (0x%x), rs2=x%0# (0x%x), rd=x%0#\n",
                      32,vlSelf->top__DOT__if_id_instr,
                      5,(IData)(vlSelf->top__DOT__rs1_addr),
                      32,vlSelf->top__DOT__rs1_data,
                      5,(IData)(vlSelf->top__DOT__rs2_addr),
                      32,vlSelf->top__DOT__rs2_data,
                      5,(IData)(vlSelf->top__DOT__rd_addr));
            if (VL_UNLIKELY(vlSelf->top__DOT__imm_valid)) {
                VL_WRITEF("TOP: ID/EX: imm=0x%x\n",
                          32,vlSelf->top__DOT__imm_value);
            }
            if (VL_UNLIKELY((0x2081b3U == vlSelf->top__DOT__if_id_instr))) {
                VL_WRITEF("TOP: ID/EX PIPELINE: ADD instruction entering EX stage\nTOP:   rs1_addr=x%0#, rs2_addr=x%0#, rd_addr=x%0#\nTOP:   rs1_data=0x%x, rs2_data=0x%x\n",
                          5,vlSelf->top__DOT__rs1_addr,
                          5,(IData)(vlSelf->top__DOT__rs2_addr),
                          5,vlSelf->top__DOT__rd_addr,
                          32,vlSelf->top__DOT__rs1_data,
                          32,vlSelf->top__DOT__rs2_data);
            }
        }
        __Vdly__top__DOT__ex_mem_rd_addr = vlSelf->top__DOT__id_ex_rd_addr;
        __Vdly__top__DOT__ex_mem_reg_write = vlSelf->top__DOT__id_ex_reg_write;
        vlSelf->top__DOT__ex_mem_mem_write = vlSelf->top__DOT__id_ex_mem_write;
        vlSelf->top__DOT__ex_mem_branch = vlSelf->top__DOT__id_ex_branch;
        if (VL_UNLIKELY(vlSelf->top__DOT__id_ex_mem_write)) {
            VL_WRITEF("TOP: STORE INSTRUCTION MOVING TO MEM STAGE:\nTOP:   rs2_addr=x%0#, forwarded=%b, forward_sel=%b\nTOP:   Original rs2_data=0x%x\n",
                      5,vlSelf->top__DOT__id_ex_rs2_addr,
                      1,(0U != (IData)(vlSelf->top__DOT__forward_b)),
                      2,(IData)(vlSelf->top__DOT__forward_b),
                      32,vlSelf->top__DOT__id_ex_rs2_data);
            if (VL_UNLIKELY((1U == (IData)(vlSelf->top__DOT__forward_b)))) {
                VL_WRITEF("TOP:   Forwarded rs2_data from WB=0x%x\n",
                          32,vlSelf->top__DOT__rd_data);
            } else if (VL_UNLIKELY((2U == (IData)(vlSelf->top__DOT__forward_b)))) {
                VL_WRITEF("TOP:   Forwarded rs2_data from MEM=0x%x\n",
                          32,vlSelf->top__DOT__ex_mem_alu_result);
            }
        }
        if (VL_UNLIKELY(vlSelf->top__DOT__id_ex_reg_write)) {
            VL_WRITEF("TOP: EX/MEM: ALU result=0x%x for rd=x%0#\n",
                      32,vlSelf->top__DOT__salu_inst__DOT__alu_res_d,
                      5,(IData)(vlSelf->top__DOT__id_ex_rd_addr));
        }
        if (VL_UNLIKELY(vlSelf->top__DOT__id_ex_branch)) {
            VL_WRITEF("TOP: EX/MEM: Branch condition=%b\n",
                      1,vlSelf->top__DOT__salu_inst__DOT__zero_flag_d);
        }
        if (VL_UNLIKELY(vlSelf->top__DOT__ex_mem_mem_read)) {
            VL_WRITEF("TOP: MEM/WB: Memory read data=0x%x from addr=0x%x\n",
                      32,vlSelf->top__DOT__mem_rdata,
                      32,vlSelf->top__DOT__ex_mem_alu_result);
        } else if (VL_UNLIKELY(vlSelf->top__DOT__ex_mem_reg_write)) {
            VL_WRITEF("TOP: MEM/WB: Writing back 0x%x to rd=x%0#\n",
                      32,((1U == (IData)(vlSelf->top__DOT__ex_mem_result_src))
                           ? vlSelf->top__DOT__mem_rdata
                           : vlSelf->top__DOT__ex_mem_alu_result),
                      5,(IData)(vlSelf->top__DOT__ex_mem_rd_addr));
        }
        if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__ex_mem_reg_write) 
                         & (0U != (IData)(vlSelf->top__DOT__ex_mem_rd_addr))))) {
            VL_WRITEF("TOP: PIPELINE: MEM/WB update - Setting mem_wb_reg_write=%b, mem_wb_rd_addr=x%0#, result_src=%b\n",
                      1,vlSelf->top__DOT__ex_mem_reg_write,
                      5,(IData)(vlSelf->top__DOT__ex_mem_rd_addr),
                      2,vlSelf->top__DOT__ex_mem_result_src);
        }
        vlSelf->top__DOT__ex_mem_alu_result = vlSelf->top__DOT__salu_inst__DOT__alu_res_d;
        vlSelf->top__DOT__ex_mem_mem_read = vlSelf->top__DOT__id_ex_mem_read;
    } else {
        __Vdly__top__DOT__if_id_pc = 0U;
        __Vdly__top__DOT__if_id_instr = 0U;
        vlSelf->top__DOT__id_ex_pc = 0U;
        vlSelf->top__DOT__id_ex_rs1_data = 0U;
        __Vdly__top__DOT__id_ex_rs2_data = 0U;
        vlSelf->top__DOT__id_ex_imm = 0U;
        vlSelf->top__DOT__id_ex_rs1_addr = 0U;
        __Vdly__top__DOT__id_ex_rs2_addr = 0U;
        __Vdly__top__DOT__id_ex_rd_addr = 0U;
        __Vdly__top__DOT__id_ex_reg_write = 0U;
        __Vdly__top__DOT__id_ex_mem_read = 0U;
        __Vdly__top__DOT__id_ex_mem_write = 0U;
        vlSelf->top__DOT__id_ex_mem_size = 0U;
        __Vdly__top__DOT__id_ex_branch = 0U;
        vlSelf->top__DOT__id_ex_jump = 0U;
        vlSelf->top__DOT__id_ex_result_src = 0U;
        vlSelf->top__DOT__id_ex_alu_op = 0U;
        vlSelf->top__DOT__id_ex_imm_valid = 0U;
        vlSelf->top__DOT__id_ex_instr = 0U;
        vlSelf->top__DOT__ex_mem_pc = 0U;
        vlSelf->top__DOT__ex_mem_alu_result = 0U;
        vlSelf->top__DOT__ex_mem_rs2_data = 0U;
        vlSelf->top__DOT__ex_mem_imm = 0U;
        __Vdly__top__DOT__ex_mem_rd_addr = 0U;
        __Vdly__top__DOT__ex_mem_reg_write = 0U;
        vlSelf->top__DOT__ex_mem_mem_read = 0U;
        vlSelf->top__DOT__ex_mem_mem_write = 0U;
        vlSelf->top__DOT__ex_mem_mem_size = 0U;
        __Vdly__top__DOT__ex_mem_result_src = 0U;
        vlSelf->top__DOT__ex_mem_zero_flag = 0U;
        vlSelf->top__DOT__ex_mem_branch = 0U;
        vlSelf->top__DOT__ex_mem_jump = 0U;
        vlSelf->top__DOT__ex_mem_instr = 0U;
        vlSelf->top__DOT__mem_wb_alu_result = 0U;
        vlSelf->top__DOT__mem_wb_mem_data = 0U;
        vlSelf->top__DOT__mem_wb_pc = 0U;
        vlSelf->top__DOT__mem_wb_rd_addr = 0U;
        vlSelf->top__DOT__mem_wb_reg_write = 0U;
        vlSelf->top__DOT__mem_wb_result_src = 0U;
        vlSelf->top__DOT__mem_wb_instr = 0U;
        vlSelf->top__DOT__id_ex_jalr = 0U;
        vlSelf->top__DOT__ex_mem_jalr = 0U;
    }
    vlSelf->top__DOT__id_ex_reg_write = __Vdly__top__DOT__id_ex_reg_write;
    vlSelf->top__DOT__id_ex_mem_write = __Vdly__top__DOT__id_ex_mem_write;
    vlSelf->top__DOT__id_ex_branch = __Vdly__top__DOT__id_ex_branch;
    vlSelf->top__DOT__ex_mem_result_src = __Vdly__top__DOT__ex_mem_result_src;
    vlSelf->top__DOT__if_id_pc = __Vdly__top__DOT__if_id_pc;
    vlSelf->top__DOT__id_ex_mem_read = __Vdly__top__DOT__id_ex_mem_read;
    vlSelf->top__DOT__id_ex_rd_addr = __Vdly__top__DOT__id_ex_rd_addr;
    vlSelf->top__DOT__id_ex_rs2_data = __Vdly__top__DOT__id_ex_rs2_data;
    vlSelf->top__DOT__id_ex_rs2_addr = __Vdly__top__DOT__id_ex_rs2_addr;
    vlSelf->top__DOT__ex_mem_reg_write = __Vdly__top__DOT__ex_mem_reg_write;
    vlSelf->top__DOT__ex_mem_rd_addr = __Vdly__top__DOT__ex_mem_rd_addr;
    vlSelf->top__DOT__if_id_instr = __Vdly__top__DOT__if_id_instr;
    vlSelf->top__DOT__take_branch = ((IData)(vlSelf->top__DOT__ex_mem_branch) 
                                     & (IData)(vlSelf->top__DOT__ex_mem_zero_flag));
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
    if (vlSelf->rst_n) {
        if ((1U & (~ (IData)(vlSelf->top__DOT__stall_pipeline)))) {
            vlSelf->top__DOT__pc_out = vlSelf->top__DOT__pc_inst__DOT__next_pc;
        }
    } else {
        vlSelf->top__DOT__pc_out = 0U;
    }
    vlSelf->top__DOT__rs1_addr = (0x1fU & (vlSelf->top__DOT__if_id_instr 
                                           >> 0xfU));
    vlSelf->top__DOT__rs2_addr = (0x1fU & (vlSelf->top__DOT__if_id_instr 
                                           >> 0x14U));
    vlSelf->top__DOT__rd_addr = (0x1fU & (vlSelf->top__DOT__if_id_instr 
                                          >> 7U));
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
    vlSelf->top__DOT__pc_src = ((IData)(vlSelf->top__DOT__take_branch) 
                                | (IData)(vlSelf->top__DOT__ex_mem_jump));
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

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

void Vtop___024root___timing_resume(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hef71830d__0.resume("@(posedge clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtop___024root___timing_commit(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hef71830d__0.commit("@(posedge clk)");
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
void Vtop___024root___eval_act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___timing_resume(vlSelf);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../core/../core/top.sv", 9, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../core/../core/top.sv", 9, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG
