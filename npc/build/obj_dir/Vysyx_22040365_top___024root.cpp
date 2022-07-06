// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_22040365_top.h for the primary calling header

#include "Vysyx_22040365_top___024root.h"
#include "Vysyx_22040365_top__Syms.h"

//==========

VL_INLINE_OPT void Vysyx_22040365_top___024root___sequent__TOP__1(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___sequent__TOP__1\n"); );
    // Variables
    CData/*1:0*/ __Vdlyvdim0__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf__v0;
    QData/*63:0*/ ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT____Vlvbound1;
    QData/*63:0*/ __Vdlyvval__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf__v0;
    // Body
    __Vdlyvset__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf__v0 = 0U;
    ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT____Vlvbound1 
        = vlSelf->ysyx_22040365_top__DOT__rd_data;
    if ((2U >= (3U & (vlSelf->inst >> 7U)))) {
        __Vdlyvval__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf__v0 
            = ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT____Vlvbound1;
        __Vdlyvset__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf__v0 = 1U;
        __Vdlyvdim0__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf__v0 
            = (3U & (vlSelf->inst >> 7U));
    }
    if (__Vdlyvset__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf__v0) {
        vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[__Vdlyvdim0__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf__v0] 
            = __Vdlyvval__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf__v0;
    }
}

VL_INLINE_OPT void Vysyx_22040365_top___024root___settle__TOP__2(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___settle__TOP__2\n"); );
    // Body
    vlSelf->ysyx_22040365_top__DOT__rd_data = ((IData)(
                                                       (0x10U 
                                                        == 
                                                        (0x707cU 
                                                         & vlSelf->inst)))
                                                ? (
                                                   ((2U 
                                                     >= 
                                                     (3U 
                                                      & (vlSelf->inst 
                                                         >> 0xfU)))
                                                     ? 
                                                    vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf
                                                    [
                                                    (3U 
                                                     & (vlSelf->inst 
                                                        >> 0xfU))]
                                                     : 0ULL) 
                                                   + 
                                                   (((- (QData)((IData)(
                                                                        (vlSelf->inst 
                                                                         >> 0x1fU)))) 
                                                     << 0xcU) 
                                                    | (QData)((IData)(
                                                                      (vlSelf->inst 
                                                                       >> 0x14U)))))
                                                : 0ULL);
    vlSelf->out = vlSelf->ysyx_22040365_top__DOT__rd_data;
}

void Vysyx_22040365_top___024root___eval(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vysyx_22040365_top___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vysyx_22040365_top___024root___settle__TOP__2(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData Vysyx_22040365_top___024root___change_request_1(Vysyx_22040365_top___024root* vlSelf);

VL_INLINE_OPT QData Vysyx_22040365_top___024root___change_request(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___change_request\n"); );
    // Body
    return (Vysyx_22040365_top___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vysyx_22040365_top___024root___change_request_1(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vysyx_22040365_top___024root___eval_debug_assertions(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
