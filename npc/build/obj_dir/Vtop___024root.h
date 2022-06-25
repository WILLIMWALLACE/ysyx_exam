// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_OUT8(VGA_CLK,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(ps2_clk,0,0);
    VL_IN8(ps2_data,0,0);
    VL_OUT8(VGA_HSYNC,0,0);
    VL_OUT8(VGA_VSYNC,0,0);
    VL_OUT8(VGA_BLANK_N,0,0);
    VL_OUT8(VGA_R,7,0);
    VL_OUT8(VGA_G,7,0);
    VL_OUT8(VGA_B,7,0);
    VL_OUT8(seg0,7,0);
    VL_OUT8(seg1,7,0);
    VL_OUT8(seg4,7,0);
    VL_OUT8(seg5,7,0);
    VL_OUT16(ledr,15,0);

    // LOCAL SIGNALS
    CData/*6:0*/ top__DOT__led_flag;
    CData/*0:0*/ top__DOT__nextdata_n;
    CData/*7:0*/ top__DOT__data;
    CData/*7:0*/ top__DOT__mc;
    CData/*0:0*/ top__DOT__ready;
    CData/*0:0*/ top__DOT__overflow;
    CData/*2:0*/ top__DOT__cnt;
    CData/*3:0*/ top__DOT__count;
    CData/*0:0*/ top__DOT__sampling;
    CData/*2:0*/ top__DOT__c_state;
    CData/*0:0*/ top__DOT__flag;
    CData/*3:0*/ top__DOT__y;
    CData/*2:0*/ top__DOT__my_keyboard__DOT__ps2_clk_sync;
    CData/*2:0*/ top__DOT__my_keyboard__DOT__w_ptr;
    CData/*2:0*/ top__DOT__my_keyboard__DOT__r_ptr;
    CData/*0:0*/ top__DOT__vga_ctrl__DOT__h_valid;
    CData/*0:0*/ top__DOT__vga_ctrl__DOT__v_valid;
    SData/*8:0*/ top__DOT__pix_line;
    SData/*9:0*/ top__DOT__h_addr;
    SData/*9:0*/ top__DOT__v_addr;
    SData/*9:0*/ top__DOT__my_keyboard__DOT__buffer;
    SData/*9:0*/ top__DOT__vga_ctrl__DOT__x_cnt;
    SData/*9:0*/ top__DOT__vga_ctrl__DOT__y_cnt;
    IData/*23:0*/ top__DOT__vga_data;
    VlUnpacked<SData/*8:0*/, 16> top__DOT__pix;
    VlUnpacked<CData/*7:0*/, 9> top__DOT__segs;
    VlUnpacked<CData/*7:0*/, 8> top__DOT__my_keyboard__DOT__fifo;

    // LOCAL VARIABLES
    CData/*0:0*/ top__DOT__my_keyboard__DOT____Vlvbound1;
    CData/*0:0*/ __Vdlyvset__top__DOT__pix__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__pix__v16;
    CData/*0:0*/ __Vdlyvset__top__DOT__pix__v32;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__VGA_CLK;
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
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop___024root);  ///< Copying not allowed
  public:
    Vtop___024root(const char* name);
    ~Vtop___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
