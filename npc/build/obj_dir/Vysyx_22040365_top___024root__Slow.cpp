// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_22040365_top.h for the primary calling header

#include "Vysyx_22040365_top___024root.h"
#include "Vysyx_22040365_top__Syms.h"

#include "verilated_dpi.h"

//==========


void Vysyx_22040365_top___024root___ctor_var_reset(Vysyx_22040365_top___024root* vlSelf);

Vysyx_22040365_top___024root::Vysyx_22040365_top___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vysyx_22040365_top___024root___ctor_var_reset(this);
}

void Vysyx_22040365_top___024root::__Vconfigure(Vysyx_22040365_top__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vysyx_22040365_top___024root::~Vysyx_22040365_top___024root() {
}

void Vysyx_22040365_top___024root____Vdpiimwrap_ysyx_22040365_top__DOT__quit_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno);

void Vysyx_22040365_top___024root___settle__TOP__2(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___settle__TOP__2\n"); );
    // Body
    vlSelf->ysyx_22040365_top__DOT__inst_type = (((IData)(
                                                          (0x73U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->inst))) 
                                                  << 1U) 
                                                 | (IData)(
                                                           (0x13U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->inst))));
    if ((2U == (IData)(vlSelf->ysyx_22040365_top__DOT__inst_type))) {
        Vysyx_22040365_top___024root____Vdpiimwrap_ysyx_22040365_top__DOT__quit_TOP(
                                                                                (&(vlSymsp->__Vscope_ysyx_22040365_top)), 
                                                                                "/home/jmx/ysyx-workbench/npc/vsrc/ysyx_22040365_top.v", 0x12U);
    }
    if ((1U == (IData)(vlSelf->ysyx_22040365_top__DOT__inst_type))) {
        vlSelf->ysyx_22040365_top__DOT__rd_data = (
                                                   vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs
                                                   [
                                                   (0x1fU 
                                                    & (vlSelf->inst 
                                                       >> 0xfU))] 
                                                   + 
                                                   (((- (QData)((IData)(
                                                                        (vlSelf->inst 
                                                                         >> 0x1fU)))) 
                                                     << 0xcU) 
                                                    | (QData)((IData)(
                                                                      (vlSelf->inst 
                                                                       >> 0x14U)))));
    } else if ((2U == (IData)(vlSelf->ysyx_22040365_top__DOT__inst_type))) {
        vlSelf->ysyx_22040365_top__DOT__rd_data = 0ULL;
    }
    vlSelf->out = vlSelf->ysyx_22040365_top__DOT__rd_data;
}

void Vysyx_22040365_top___024root___eval_initial(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vysyx_22040365_top___024root___eval_settle(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___eval_settle\n"); );
    // Body
    Vysyx_22040365_top___024root___settle__TOP__2(vlSelf);
}

void Vysyx_22040365_top___024root___final(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___final\n"); );
}

void Vysyx_22040365_top___024root___ctor_var_reset(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->out = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_22040365_top__DOT__inst_type = VL_RAND_RESET_I(2);
    vlSelf->ysyx_22040365_top__DOT__rd_data = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[__Vi0] = VL_RAND_RESET_Q(64);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
