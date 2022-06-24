// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop___024root.h"
#include "Vtop__Syms.h"

//==========

VL_INLINE_OPT void Vtop___024root___sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__2\n"); );
    // Variables
    CData/*3:0*/ __Vdly__top__DOT__count;
    CData/*2:0*/ __Vdly__top__DOT__my_keyboard__DOT__w_ptr;
    CData/*2:0*/ __Vdly__top__DOT__my_keyboard__DOT__r_ptr;
    CData/*0:0*/ __Vdly__top__DOT__overflow;
    CData/*0:0*/ __Vdly__top__DOT__ready;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__my_keyboard__DOT__fifo__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_keyboard__DOT__fifo__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_keyboard__DOT__fifo__v0;
    // Body
    __Vdly__top__DOT__my_keyboard__DOT__w_ptr = vlSelf->top__DOT__my_keyboard__DOT__w_ptr;
    __Vdly__top__DOT__ready = vlSelf->top__DOT__ready;
    __Vdly__top__DOT__overflow = vlSelf->top__DOT__overflow;
    __Vdly__top__DOT__count = vlSelf->top__DOT__count;
    __Vdly__top__DOT__my_keyboard__DOT__r_ptr = vlSelf->top__DOT__my_keyboard__DOT__r_ptr;
    __Vdlyvset__top__DOT__my_keyboard__DOT__fifo__v0 = 0U;
    vlSelf->top__DOT__led_flag = 0U;
    vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = ((6U & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->ps2_clk));
    vlSelf->top__DOT__c_state = ((IData)(vlSelf->rst)
                                  ? 0U : ((IData)(vlSelf->rst)
                                           ? 0U : (
                                                   (((0xf0U 
                                                      != (IData)(vlSelf->top__DOT__data)) 
                                                     & (IData)(vlSelf->top__DOT__flag)) 
                                                    & (IData)(vlSelf->top__DOT__ready))
                                                    ? 1U
                                                    : 
                                                   (((0xf0U 
                                                      == (IData)(vlSelf->top__DOT__data)) 
                                                     & (IData)(vlSelf->top__DOT__ready))
                                                     ? 2U
                                                     : 
                                                    (((~ (IData)(vlSelf->top__DOT__flag)) 
                                                      & (IData)(vlSelf->top__DOT__ready))
                                                      ? 4U
                                                      : 0U)))));
    if (vlSelf->rst) {
        __Vdly__top__DOT__count = 0U;
        __Vdly__top__DOT__my_keyboard__DOT__w_ptr = 0U;
        __Vdly__top__DOT__my_keyboard__DOT__r_ptr = 0U;
        __Vdly__top__DOT__overflow = 0U;
        __Vdly__top__DOT__ready = 0U;
    } else {
        if (vlSelf->top__DOT__ready) {
            if ((1U & (~ (IData)(vlSelf->top__DOT__nextdata_n)))) {
                __Vdly__top__DOT__my_keyboard__DOT__r_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_keyboard__DOT__r_ptr)));
                if (((IData)(vlSelf->top__DOT__my_keyboard__DOT__w_ptr) 
                     == (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_keyboard__DOT__r_ptr))))) {
                    __Vdly__top__DOT__ready = 0U;
                }
            }
        }
        if (vlSelf->top__DOT__sampling) {
            if ((0xaU == (IData)(vlSelf->top__DOT__count))) {
                if ((((~ (IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer)) 
                      & (IData)(vlSelf->ps2_data)) 
                     & VL_REDXOR_32((0x1ffU & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer) 
                                               >> 1U))))) {
                    __Vdlyvval__top__DOT__my_keyboard__DOT__fifo__v0 
                        = (0xffU & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer) 
                                    >> 1U));
                    __Vdlyvset__top__DOT__my_keyboard__DOT__fifo__v0 = 1U;
                    __Vdlyvdim0__top__DOT__my_keyboard__DOT__fifo__v0 
                        = vlSelf->top__DOT__my_keyboard__DOT__w_ptr;
                    __Vdly__top__DOT__ready = 1U;
                    __Vdly__top__DOT__my_keyboard__DOT__w_ptr 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_keyboard__DOT__w_ptr)));
                    __Vdly__top__DOT__overflow = ((IData)(vlSelf->top__DOT__overflow) 
                                                  | ((IData)(vlSelf->top__DOT__my_keyboard__DOT__r_ptr) 
                                                     == 
                                                     (7U 
                                                      & ((IData)(1U) 
                                                         + (IData)(vlSelf->top__DOT__my_keyboard__DOT__w_ptr)))));
                }
                __Vdly__top__DOT__count = 0U;
            } else {
                vlSelf->top__DOT__my_keyboard__DOT____Vlvbound1 
                    = vlSelf->ps2_data;
                if ((9U >= (IData)(vlSelf->top__DOT__count))) {
                    vlSelf->top__DOT__my_keyboard__DOT__buffer 
                        = (((~ ((IData)(1U) << (IData)(vlSelf->top__DOT__count))) 
                            & (IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer)) 
                           | (0x3ffU & ((IData)(vlSelf->top__DOT__my_keyboard__DOT____Vlvbound1) 
                                        << (IData)(vlSelf->top__DOT__count))));
                }
                __Vdly__top__DOT__count = (0xfU & ((IData)(1U) 
                                                   + (IData)(vlSelf->top__DOT__count)));
            }
        }
    }
    vlSelf->top__DOT__my_keyboard__DOT__w_ptr = __Vdly__top__DOT__my_keyboard__DOT__w_ptr;
    vlSelf->top__DOT__count = __Vdly__top__DOT__count;
    vlSelf->top__DOT__overflow = __Vdly__top__DOT__overflow;
    vlSelf->top__DOT__ready = __Vdly__top__DOT__ready;
    vlSelf->top__DOT__my_keyboard__DOT__r_ptr = __Vdly__top__DOT__my_keyboard__DOT__r_ptr;
    if (__Vdlyvset__top__DOT__my_keyboard__DOT__fifo__v0) {
        vlSelf->top__DOT__my_keyboard__DOT__fifo[__Vdlyvdim0__top__DOT__my_keyboard__DOT__fifo__v0] 
            = __Vdlyvval__top__DOT__my_keyboard__DOT__fifo__v0;
    }
    vlSelf->top__DOT__sampling = (IData)((4U == (6U 
                                                 & (IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync))));
    vlSelf->top__DOT__data = vlSelf->top__DOT__my_keyboard__DOT__fifo
        [vlSelf->top__DOT__my_keyboard__DOT__r_ptr];
}

VL_INLINE_OPT void Vtop___024root___combo__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__3\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->top__DOT__flag = 1U;
    } else if ((1U == (IData)(vlSelf->top__DOT__c_state))) {
        vlSelf->top__DOT__flag = 1U;
    } else if ((2U == (IData)(vlSelf->top__DOT__c_state))) {
        vlSelf->top__DOT__flag = 0U;
    } else if ((4U == (IData)(vlSelf->top__DOT__c_state))) {
        vlSelf->top__DOT__flag = 1U;
    }
    vlSelf->top__DOT__nextdata_n = ((~ (IData)(vlSelf->rst)) 
                                    & ((1U != (IData)(vlSelf->top__DOT__c_state)) 
                                       & ((2U != (IData)(vlSelf->top__DOT__c_state)) 
                                          & (4U != (IData)(vlSelf->top__DOT__c_state)))));
    if (vlSelf->rst) {
        vlSelf->top__DOT__cnt = 0U;
    } else if ((1U != (IData)(vlSelf->top__DOT__c_state))) {
        if ((2U == (IData)(vlSelf->top__DOT__c_state))) {
            vlSelf->top__DOT__cnt = (7U & ((IData)(1U) 
                                           + (IData)(vlSelf->top__DOT__cnt)));
        }
    }
    if (vlSelf->rst) {
        vlSelf->top__DOT__mc = 0U;
    } else if ((1U == (IData)(vlSelf->top__DOT__c_state))) {
        vlSelf->top__DOT__mc = vlSelf->top__DOT__data;
    } else if ((2U == (IData)(vlSelf->top__DOT__c_state))) {
        vlSelf->top__DOT__mc = vlSelf->top__DOT__data;
    } else if ((4U == (IData)(vlSelf->top__DOT__c_state))) {
        vlSelf->top__DOT__mc = vlSelf->top__DOT__data;
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
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vtop___024root___combo__TOP__3(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData Vtop___024root___change_request_1(Vtop___024root* vlSelf);

VL_INLINE_OPT QData Vtop___024root___change_request(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request\n"); );
    // Body
    return (Vtop___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vtop___024root___change_request_1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
}
#endif  // VL_DEBUG
