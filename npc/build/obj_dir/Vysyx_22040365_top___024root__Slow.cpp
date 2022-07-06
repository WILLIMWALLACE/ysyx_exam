// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_22040365_top.h for the primary calling header

#include "Vysyx_22040365_top___024root.h"
#include "Vysyx_22040365_top__Syms.h"

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

void Vysyx_22040365_top___024root___eval_initial(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vysyx_22040365_top___024root___settle__TOP__2(Vysyx_22040365_top___024root* vlSelf);

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
    vlSelf->ysyx_22040365_top__DOT__rd_data = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[__Vi0] = VL_RAND_RESET_Q(64);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
