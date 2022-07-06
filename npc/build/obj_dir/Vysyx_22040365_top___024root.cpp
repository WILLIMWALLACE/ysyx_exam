// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_22040365_top.h for the primary calling header

#include "Vysyx_22040365_top___024root.h"
#include "Vysyx_22040365_top__Syms.h"

#include "verilated_dpi.h"

//==========

extern "C" void quit();

VL_INLINE_OPT void Vysyx_22040365_top___024root____Vdpiimwrap_ysyx_22040365_top__DOT__quit_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root____Vdpiimwrap_ysyx_22040365_top__DOT__quit_TOP\n"); );
    // Body
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    quit();
}

VL_INLINE_OPT void Vysyx_22040365_top___024root___combo__TOP__1(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___combo__TOP__1\n"); );
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
                                                                                "/home/jmx/ysyx-workbench/npc/vsrc/ysyx_22040365_top.v", 0xfU);
    }
}

VL_INLINE_OPT void Vysyx_22040365_top___024root___sequent__TOP__3(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___sequent__TOP__3\n"); );
    // Variables
    CData/*4:0*/ __Vdlyvdim0__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs__v0;
    QData/*63:0*/ __Vdlyvval__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs__v0;
    // Body
    __Vdlyvval__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs__v0 
        = vlSelf->ysyx_22040365_top__DOT__rd_data;
    __Vdlyvdim0__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs__v0 
        = (0x1fU & (vlSelf->inst >> 7U));
    vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[__Vdlyvdim0__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs__v0] 
        = __Vdlyvval__ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs__v0;
}

VL_INLINE_OPT void Vysyx_22040365_top___024root___combo__TOP__4(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___combo__TOP__4\n"); );
    // Body
    vlSelf->ysyx_22040365_top__DOT__rd_data = ((1U 
                                                == (IData)(vlSelf->ysyx_22040365_top__DOT__inst_type))
                                                ? (
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
                                                                       >> 0x14U)))))
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelf->ysyx_22040365_top__DOT__inst_type))
                                                    ? 0ULL
                                                    : 0xffffffffffffffffULL));
    vlSelf->out = vlSelf->ysyx_22040365_top__DOT__rd_data;
}

void Vysyx_22040365_top___024root___eval(Vysyx_22040365_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040365_top___024root___eval\n"); );
    // Body
    Vysyx_22040365_top___024root___combo__TOP__1(vlSelf);
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vysyx_22040365_top___024root___sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vysyx_22040365_top___024root___combo__TOP__4(vlSelf);
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
