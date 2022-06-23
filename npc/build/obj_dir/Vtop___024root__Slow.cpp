// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop___024root.h"
#include "Vtop__Syms.h"

//==========


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(Vtop__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vtop___024root::~Vtop___024root() {
}

void Vtop___024root___settle__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__segs[0U] = 0xfdU;
    vlSelf->top__DOT__segs[1U] = 0x60U;
    vlSelf->top__DOT__segs[2U] = 0xdaU;
    vlSelf->top__DOT__segs[3U] = 0xf2U;
    vlSelf->top__DOT__segs[4U] = 0x66U;
    vlSelf->top__DOT__segs[5U] = 0xb6U;
    vlSelf->top__DOT__segs[6U] = 0xbeU;
    vlSelf->top__DOT__segs[7U] = 0xe0U;
    vlSelf->top__DOT__segs[8U] = 0xffU;
    vlSelf->top__DOT__sampling = (IData)((4U == (6U 
                                                 & (IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync))));
    if ((0x15U == (IData)(vlSelf->top__DOT__mc))) {
        vlSelf->seg0 = (0xffU & (~ vlSelf->top__DOT__segs
                                 [5U]));
        vlSelf->seg1 = (0xffU & (~ vlSelf->top__DOT__segs
                                 [1U]));
    } else {
        vlSelf->seg0 = (0xffU & ((0x23U == (IData)(vlSelf->top__DOT__mc))
                                  ? (~ vlSelf->top__DOT__segs
                                     [3U]) : (~ vlSelf->top__DOT__segs
                                              [8U])));
        vlSelf->seg1 = (0xffU & ((0x23U == (IData)(vlSelf->top__DOT__mc))
                                  ? (~ vlSelf->top__DOT__segs
                                     [2U]) : (~ vlSelf->top__DOT__segs
                                              [8U])));
    }
    if ((4U & (IData)(vlSelf->top__DOT__cnt))) {
        vlSelf->seg5 = (0xffU & (~ vlSelf->top__DOT__segs
                                 [8U]));
        vlSelf->seg4 = (0xffU & (~ vlSelf->top__DOT__segs
                                 [8U]));
    } else {
        vlSelf->seg5 = (0xffU & ((2U & (IData)(vlSelf->top__DOT__cnt))
                                  ? ((1U & (IData)(vlSelf->top__DOT__cnt))
                                      ? (~ vlSelf->top__DOT__segs
                                         [0U]) : (~ 
                                                  vlSelf->top__DOT__segs
                                                  [0U]))
                                  : ((1U & (IData)(vlSelf->top__DOT__cnt))
                                      ? (~ vlSelf->top__DOT__segs
                                         [0U]) : (~ 
                                                  vlSelf->top__DOT__segs
                                                  [0U]))));
        vlSelf->seg4 = (0xffU & ((2U & (IData)(vlSelf->top__DOT__cnt))
                                  ? ((1U & (IData)(vlSelf->top__DOT__cnt))
                                      ? (~ vlSelf->top__DOT__segs
                                         [3U]) : (~ 
                                                  vlSelf->top__DOT__segs
                                                  [2U]))
                                  : ((1U & (IData)(vlSelf->top__DOT__cnt))
                                      ? (~ vlSelf->top__DOT__segs
                                         [1U]) : (~ 
                                                  vlSelf->top__DOT__segs
                                                  [0U]))));
    }
    vlSelf->ledr = (((IData)(vlSelf->top__DOT__led_flag) 
                     << 8U) | (((IData)(vlSelf->top__DOT__sampling) 
                                << 7U) | (((IData)(vlSelf->top__DOT__count) 
                                           << 3U) | 
                                          (((IData)(vlSelf->top__DOT__overflow) 
                                            << 2U) 
                                           | (((IData)(vlSelf->top__DOT__ready) 
                                               << 1U) 
                                              | (IData)(vlSelf->top__DOT__nextdata_n))))));
}

void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->ps2_clk = VL_RAND_RESET_I(1);
    vlSelf->ps2_data = VL_RAND_RESET_I(1);
    vlSelf->ledr = VL_RAND_RESET_I(16);
    vlSelf->seg0 = VL_RAND_RESET_I(8);
    vlSelf->seg1 = VL_RAND_RESET_I(8);
    vlSelf->seg4 = VL_RAND_RESET_I(8);
    vlSelf->seg5 = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__led_flag = VL_RAND_RESET_I(8);
    for (int __Vi0=0; __Vi0<9; ++__Vi0) {
        vlSelf->top__DOT__segs[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__nextdata_n = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mc = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__overflow = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cnt = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__count = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__sampling = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__my_keyboard__DOT__buffer = VL_RAND_RESET_I(10);
    vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->top__DOT__my_keyboard__DOT__fifo[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__my_keyboard__DOT__w_ptr = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__my_keyboard__DOT__r_ptr = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__my_keyboard__DOT____Vlvbound1 = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
