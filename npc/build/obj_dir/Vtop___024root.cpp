// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop___024root.h"
#include "Vtop__Syms.h"

//==========

VL_INLINE_OPT void Vtop___024root___combo__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__2\n"); );
    // Body
    vlSelf->VGA_CLK = vlSelf->clk;
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__3\n"); );
    // Variables
    CData/*0:0*/ __Vdlyvset__top__DOT__pix__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__pix__v16;
    CData/*0:0*/ __Vdlyvset__top__DOT__pix__v32;
    CData/*3:0*/ __Vdly__top__DOT__y;
    CData/*3:0*/ __Vdly__top__DOT__count;
    CData/*2:0*/ __Vdly__top__DOT__my_keyboard__DOT__w_ptr;
    CData/*2:0*/ __Vdly__top__DOT__my_keyboard__DOT__r_ptr;
    CData/*0:0*/ __Vdly__top__DOT__overflow;
    CData/*0:0*/ __Vdly__top__DOT__ready;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__my_keyboard__DOT__fifo__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_keyboard__DOT__fifo__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_keyboard__DOT__fifo__v0;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v32;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v33;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v34;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v35;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v36;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v37;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v38;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v39;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v40;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v41;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v42;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v43;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v44;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v45;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v46;
    SData/*8:0*/ __Vdlyvval__top__DOT__pix__v47;
    SData/*8:0*/ __Vdly__top__DOT__pix_line;
    SData/*9:0*/ __Vdly__top__DOT__vga_ctrl__DOT__x_cnt;
    SData/*9:0*/ __Vdly__top__DOT__vga_ctrl__DOT__y_cnt;
    // Body
    __Vdly__top__DOT__y = vlSelf->top__DOT__y;
    __Vdly__top__DOT__pix_line = vlSelf->top__DOT__pix_line;
    __Vdly__top__DOT__vga_ctrl__DOT__y_cnt = vlSelf->top__DOT__vga_ctrl__DOT__y_cnt;
    __Vdly__top__DOT__vga_ctrl__DOT__x_cnt = vlSelf->top__DOT__vga_ctrl__DOT__x_cnt;
    __Vdly__top__DOT__my_keyboard__DOT__w_ptr = vlSelf->top__DOT__my_keyboard__DOT__w_ptr;
    __Vdly__top__DOT__ready = vlSelf->top__DOT__ready;
    __Vdly__top__DOT__overflow = vlSelf->top__DOT__overflow;
    __Vdly__top__DOT__count = vlSelf->top__DOT__count;
    __Vdly__top__DOT__my_keyboard__DOT__r_ptr = vlSelf->top__DOT__my_keyboard__DOT__r_ptr;
    __Vdlyvset__top__DOT__my_keyboard__DOT__fifo__v0 = 0U;
    __Vdlyvset__top__DOT__pix__v0 = 0U;
    __Vdlyvset__top__DOT__pix__v16 = 0U;
    __Vdlyvset__top__DOT__pix__v32 = 0U;
    if (vlSelf->rst) {
        vlSelf->top__DOT__led_flag = 0U;
        __Vdly__top__DOT__y = 0U;
    } else {
        vlSelf->top__DOT__led_flag = (0x7fU & (IData)(vlSelf->top__DOT__pix_line));
        __Vdly__top__DOT__y = ((IData)(vlSelf->VGA_BLANK_N)
                                ? ((8U == (IData)(vlSelf->top__DOT__y))
                                    ? 0U : (0xfU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelf->top__DOT__y))))
                                : 0U);
    }
    vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = ((6U & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->ps2_clk));
    if (vlSelf->rst) {
        vlSelf->top__DOT__vga_data = 0U;
        __Vdly__top__DOT__pix_line = 0U;
    } else if ((0x10U > (IData)(vlSelf->top__DOT__v_addr))) {
        vlSelf->top__DOT__vga_data = (((0U < (IData)(vlSelf->top__DOT__h_addr)) 
                                       & (0x240U > (IData)(vlSelf->top__DOT__h_addr)))
                                       ? (((8U >= (IData)(vlSelf->top__DOT__y)) 
                                           & ((IData)(vlSelf->top__DOT__pix_line) 
                                              >> (IData)(vlSelf->top__DOT__y)))
                                           ? 0xffffffU
                                           : 0U) : 0U);
        __Vdly__top__DOT__pix_line = vlSelf->top__DOT__pix
            [(0xfU & (IData)(vlSelf->top__DOT__v_addr))];
    } else {
        __Vdly__top__DOT__pix_line = vlSelf->top__DOT__pix_line;
        vlSelf->top__DOT__vga_data = 0U;
    }
    if (vlSelf->rst) {
        __Vdly__top__DOT__vga_ctrl__DOT__x_cnt = 1U;
        __Vdly__top__DOT__vga_ctrl__DOT__y_cnt = 1U;
    } else if ((0x320U == (IData)(vlSelf->top__DOT__vga_ctrl__DOT__x_cnt))) {
        __Vdly__top__DOT__vga_ctrl__DOT__y_cnt = ((0x20dU 
                                                   == (IData)(vlSelf->top__DOT__vga_ctrl__DOT__y_cnt))
                                                   ? 1U
                                                   : 
                                                  (0x3ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->top__DOT__vga_ctrl__DOT__y_cnt))));
        __Vdly__top__DOT__vga_ctrl__DOT__x_cnt = 1U;
    } else {
        __Vdly__top__DOT__vga_ctrl__DOT__x_cnt = (0x3ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->top__DOT__vga_ctrl__DOT__x_cnt)));
    }
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
    if (vlSelf->rst) {
        __Vdlyvset__top__DOT__pix__v0 = 1U;
    } else if ((0x15U == (IData)(vlSelf->top__DOT__mc))) {
        __Vdlyvset__top__DOT__pix__v16 = 1U;
    } else {
        __Vdlyvval__top__DOT__pix__v32 = vlSelf->top__DOT__pix
            [0xfU];
        __Vdlyvset__top__DOT__pix__v32 = 1U;
        __Vdlyvval__top__DOT__pix__v33 = vlSelf->top__DOT__pix
            [0xeU];
        __Vdlyvval__top__DOT__pix__v34 = vlSelf->top__DOT__pix
            [0xdU];
        __Vdlyvval__top__DOT__pix__v35 = vlSelf->top__DOT__pix
            [0xcU];
        __Vdlyvval__top__DOT__pix__v36 = vlSelf->top__DOT__pix
            [0xbU];
        __Vdlyvval__top__DOT__pix__v37 = vlSelf->top__DOT__pix
            [0xaU];
        __Vdlyvval__top__DOT__pix__v38 = vlSelf->top__DOT__pix
            [9U];
        __Vdlyvval__top__DOT__pix__v39 = vlSelf->top__DOT__pix
            [8U];
        __Vdlyvval__top__DOT__pix__v40 = vlSelf->top__DOT__pix
            [7U];
        __Vdlyvval__top__DOT__pix__v41 = vlSelf->top__DOT__pix
            [6U];
        __Vdlyvval__top__DOT__pix__v42 = vlSelf->top__DOT__pix
            [5U];
        __Vdlyvval__top__DOT__pix__v43 = vlSelf->top__DOT__pix
            [4U];
        __Vdlyvval__top__DOT__pix__v44 = vlSelf->top__DOT__pix
            [3U];
        __Vdlyvval__top__DOT__pix__v45 = vlSelf->top__DOT__pix
            [2U];
        __Vdlyvval__top__DOT__pix__v46 = vlSelf->top__DOT__pix
            [1U];
        __Vdlyvval__top__DOT__pix__v47 = vlSelf->top__DOT__pix
            [0U];
    }
    vlSelf->top__DOT__y = __Vdly__top__DOT__y;
    vlSelf->top__DOT__pix_line = __Vdly__top__DOT__pix_line;
    vlSelf->top__DOT__vga_ctrl__DOT__x_cnt = __Vdly__top__DOT__vga_ctrl__DOT__x_cnt;
    vlSelf->top__DOT__vga_ctrl__DOT__y_cnt = __Vdly__top__DOT__vga_ctrl__DOT__y_cnt;
    vlSelf->top__DOT__my_keyboard__DOT__w_ptr = __Vdly__top__DOT__my_keyboard__DOT__w_ptr;
    vlSelf->top__DOT__count = __Vdly__top__DOT__count;
    vlSelf->top__DOT__overflow = __Vdly__top__DOT__overflow;
    vlSelf->top__DOT__ready = __Vdly__top__DOT__ready;
    vlSelf->top__DOT__my_keyboard__DOT__r_ptr = __Vdly__top__DOT__my_keyboard__DOT__r_ptr;
    if (__Vdlyvset__top__DOT__my_keyboard__DOT__fifo__v0) {
        vlSelf->top__DOT__my_keyboard__DOT__fifo[__Vdlyvdim0__top__DOT__my_keyboard__DOT__fifo__v0] 
            = __Vdlyvval__top__DOT__my_keyboard__DOT__fifo__v0;
    }
    if (__Vdlyvset__top__DOT__pix__v0) {
        vlSelf->top__DOT__pix[0U] = 0U;
        vlSelf->top__DOT__pix[1U] = 0U;
        vlSelf->top__DOT__pix[2U] = 0U;
        vlSelf->top__DOT__pix[3U] = 0U;
        vlSelf->top__DOT__pix[4U] = 0U;
        vlSelf->top__DOT__pix[5U] = 0U;
        vlSelf->top__DOT__pix[6U] = 0U;
        vlSelf->top__DOT__pix[7U] = 0U;
        vlSelf->top__DOT__pix[8U] = 0U;
        vlSelf->top__DOT__pix[9U] = 0U;
        vlSelf->top__DOT__pix[0xaU] = 0U;
        vlSelf->top__DOT__pix[0xbU] = 0U;
        vlSelf->top__DOT__pix[0xfU] = 0U;
        vlSelf->top__DOT__pix[0xeU] = 0U;
        vlSelf->top__DOT__pix[0xdU] = 0U;
        vlSelf->top__DOT__pix[0xcU] = 0U;
    }
    if (__Vdlyvset__top__DOT__pix__v16) {
        vlSelf->top__DOT__pix[0U] = 0U;
        vlSelf->top__DOT__pix[1U] = 0U;
        vlSelf->top__DOT__pix[2U] = 0x7cU;
        vlSelf->top__DOT__pix[3U] = 0xc6U;
        vlSelf->top__DOT__pix[4U] = 0xc6U;
        vlSelf->top__DOT__pix[5U] = 0xc6U;
        vlSelf->top__DOT__pix[6U] = 0xc6U;
        vlSelf->top__DOT__pix[7U] = 0xc6U;
        vlSelf->top__DOT__pix[8U] = 0xc6U;
        vlSelf->top__DOT__pix[9U] = 0xd6U;
        vlSelf->top__DOT__pix[0xaU] = 0xf6U;
        vlSelf->top__DOT__pix[0xbU] = 0x7cU;
        vlSelf->top__DOT__pix[0xcU] = 0x60U;
        vlSelf->top__DOT__pix[0xdU] = 0xe0U;
        vlSelf->top__DOT__pix[0xeU] = 0U;
        vlSelf->top__DOT__pix[0xfU] = 0U;
    }
    if (__Vdlyvset__top__DOT__pix__v32) {
        vlSelf->top__DOT__pix[0xfU] = __Vdlyvval__top__DOT__pix__v32;
        vlSelf->top__DOT__pix[0xeU] = __Vdlyvval__top__DOT__pix__v33;
        vlSelf->top__DOT__pix[0xdU] = __Vdlyvval__top__DOT__pix__v34;
        vlSelf->top__DOT__pix[0xcU] = __Vdlyvval__top__DOT__pix__v35;
        vlSelf->top__DOT__pix[0xbU] = __Vdlyvval__top__DOT__pix__v36;
        vlSelf->top__DOT__pix[0xaU] = __Vdlyvval__top__DOT__pix__v37;
        vlSelf->top__DOT__pix[9U] = __Vdlyvval__top__DOT__pix__v38;
        vlSelf->top__DOT__pix[8U] = __Vdlyvval__top__DOT__pix__v39;
        vlSelf->top__DOT__pix[7U] = __Vdlyvval__top__DOT__pix__v40;
        vlSelf->top__DOT__pix[6U] = __Vdlyvval__top__DOT__pix__v41;
        vlSelf->top__DOT__pix[5U] = __Vdlyvval__top__DOT__pix__v42;
        vlSelf->top__DOT__pix[4U] = __Vdlyvval__top__DOT__pix__v43;
        vlSelf->top__DOT__pix[3U] = __Vdlyvval__top__DOT__pix__v44;
        vlSelf->top__DOT__pix[2U] = __Vdlyvval__top__DOT__pix__v45;
        vlSelf->top__DOT__pix[1U] = __Vdlyvval__top__DOT__pix__v46;
        vlSelf->top__DOT__pix[0U] = __Vdlyvval__top__DOT__pix__v47;
    }
    vlSelf->top__DOT__sampling = (IData)((4U == (6U 
                                                 & (IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync))));
    vlSelf->VGA_R = (0xffU & (vlSelf->top__DOT__vga_data 
                              >> 0x10U));
    vlSelf->VGA_G = (0xffU & (vlSelf->top__DOT__vga_data 
                              >> 8U));
    vlSelf->VGA_B = (0xffU & vlSelf->top__DOT__vga_data);
    vlSelf->VGA_HSYNC = (0x60U < (IData)(vlSelf->top__DOT__vga_ctrl__DOT__x_cnt));
    vlSelf->top__DOT__vga_ctrl__DOT__h_valid = ((0x90U 
                                                 < (IData)(vlSelf->top__DOT__vga_ctrl__DOT__x_cnt)) 
                                                & (0x310U 
                                                   >= (IData)(vlSelf->top__DOT__vga_ctrl__DOT__x_cnt)));
    vlSelf->VGA_VSYNC = (2U < (IData)(vlSelf->top__DOT__vga_ctrl__DOT__y_cnt));
    vlSelf->top__DOT__vga_ctrl__DOT__v_valid = ((0x23U 
                                                 < (IData)(vlSelf->top__DOT__vga_ctrl__DOT__y_cnt)) 
                                                & (0x203U 
                                                   >= (IData)(vlSelf->top__DOT__vga_ctrl__DOT__y_cnt)));
    vlSelf->top__DOT__data = vlSelf->top__DOT__my_keyboard__DOT__fifo
        [vlSelf->top__DOT__my_keyboard__DOT__r_ptr];
    vlSelf->ledr = (((IData)(vlSelf->top__DOT__led_flag) 
                     << 9U) | (((IData)(vlSelf->top__DOT__sampling) 
                                << 7U) | (((IData)(vlSelf->top__DOT__count) 
                                           << 3U) | 
                                          (((IData)(vlSelf->top__DOT__overflow) 
                                            << 2U) 
                                           | (((IData)(vlSelf->top__DOT__ready) 
                                               << 1U) 
                                              | ((8U 
                                                  >= (IData)(vlSelf->top__DOT__y)) 
                                                 & ((IData)(vlSelf->top__DOT__pix_line) 
                                                    >> (IData)(vlSelf->top__DOT__y))))))));
    if (vlSelf->top__DOT__vga_ctrl__DOT__h_valid) {
        vlSelf->top__DOT__h_addr = (0x3ffU & ((IData)(vlSelf->top__DOT__vga_ctrl__DOT__x_cnt) 
                                              - (IData)(0x91U)));
        vlSelf->VGA_BLANK_N = ((IData)(vlSelf->top__DOT__vga_ctrl__DOT__v_valid) 
                               & 1U);
    } else {
        vlSelf->top__DOT__h_addr = 0U;
        vlSelf->VGA_BLANK_N = 0U;
    }
    vlSelf->top__DOT__v_addr = ((IData)(vlSelf->top__DOT__vga_ctrl__DOT__v_valid)
                                 ? (0x3ffU & ((IData)(vlSelf->top__DOT__vga_ctrl__DOT__y_cnt) 
                                              - (IData)(0x24U)))
                                 : 0U);
}

VL_INLINE_OPT void Vtop___024root___combo__TOP__4(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__4\n"); );
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
    Vtop___024root___combo__TOP__2(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    Vtop___024root___combo__TOP__4(vlSelf);
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
