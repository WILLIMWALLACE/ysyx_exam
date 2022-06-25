// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__traceInitSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vtop___024root__traceInitTop(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vtop___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vtop___024root__traceInitSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+57,"rst", false,-1);
        tracep->declBit(c+58,"clk", false,-1);
        tracep->declBit(c+59,"ps2_clk", false,-1);
        tracep->declBit(c+60,"ps2_data", false,-1);
        tracep->declBus(c+61,"ledr", false,-1, 15,0);
        tracep->declBit(c+62,"VGA_CLK", false,-1);
        tracep->declBit(c+63,"VGA_HSYNC", false,-1);
        tracep->declBit(c+64,"VGA_VSYNC", false,-1);
        tracep->declBit(c+65,"VGA_BLANK_N", false,-1);
        tracep->declBus(c+66,"VGA_R", false,-1, 7,0);
        tracep->declBus(c+67,"VGA_G", false,-1, 7,0);
        tracep->declBus(c+68,"VGA_B", false,-1, 7,0);
        tracep->declBus(c+69,"seg0", false,-1, 7,0);
        tracep->declBus(c+70,"seg1", false,-1, 7,0);
        tracep->declBus(c+71,"seg4", false,-1, 7,0);
        tracep->declBus(c+72,"seg5", false,-1, 7,0);
        tracep->declBit(c+57,"top rst", false,-1);
        tracep->declBit(c+58,"top clk", false,-1);
        tracep->declBit(c+59,"top ps2_clk", false,-1);
        tracep->declBit(c+60,"top ps2_data", false,-1);
        tracep->declBus(c+61,"top ledr", false,-1, 15,0);
        tracep->declBit(c+62,"top VGA_CLK", false,-1);
        tracep->declBit(c+63,"top VGA_HSYNC", false,-1);
        tracep->declBit(c+64,"top VGA_VSYNC", false,-1);
        tracep->declBit(c+65,"top VGA_BLANK_N", false,-1);
        tracep->declBus(c+66,"top VGA_R", false,-1, 7,0);
        tracep->declBus(c+67,"top VGA_G", false,-1, 7,0);
        tracep->declBus(c+68,"top VGA_B", false,-1, 7,0);
        tracep->declBus(c+69,"top seg0", false,-1, 7,0);
        tracep->declBus(c+70,"top seg1", false,-1, 7,0);
        tracep->declBus(c+71,"top seg4", false,-1, 7,0);
        tracep->declBus(c+72,"top seg5", false,-1, 7,0);
        tracep->declBus(c+14,"top led_flag", false,-1, 6,0);
        tracep->declBit(c+10,"top nextdata_n", false,-1);
        tracep->declBus(c+15,"top data", false,-1, 7,0);
        tracep->declBus(c+11,"top mc", false,-1, 7,0);
        tracep->declBit(c+16,"top ready", false,-1);
        tracep->declBit(c+17,"top overflow", false,-1);
        tracep->declBus(c+12,"top cnt", false,-1, 2,0);
        tracep->declBus(c+18,"top count", false,-1, 3,0);
        tracep->declBit(c+19,"top sampling", false,-1);
        tracep->declBus(c+20,"top c_state", false,-1, 2,0);
        tracep->declBus(c+73,"top n_state", false,-1, 2,0);
        tracep->declBit(c+13,"top flag", false,-1);
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+21+i*1,"top pix", true,(i+0), 8,0);}}
        tracep->declBus(c+37,"top pix_line", false,-1, 8,0);
        tracep->declBus(c+75,"top y", false,-1, 3,0);
        tracep->declBus(c+38,"top h_addr", false,-1, 9,0);
        tracep->declBus(c+39,"top v_addr", false,-1, 9,0);
        tracep->declBus(c+40,"top vga_data", false,-1, 23,0);
        {int i; for (i=0; i<9; i++) {
                tracep->declBus(c+1+i*1,"top segs", true,(i+0), 7,0);}}
        tracep->declBit(c+58,"top vga_ctrl pclk", false,-1);
        tracep->declBit(c+57,"top vga_ctrl reset", false,-1);
        tracep->declBus(c+40,"top vga_ctrl vga_data", false,-1, 23,0);
        tracep->declBus(c+38,"top vga_ctrl h_addr", false,-1, 9,0);
        tracep->declBus(c+39,"top vga_ctrl v_addr", false,-1, 9,0);
        tracep->declBit(c+63,"top vga_ctrl hsync", false,-1);
        tracep->declBit(c+64,"top vga_ctrl vsync", false,-1);
        tracep->declBit(c+65,"top vga_ctrl valid", false,-1);
        tracep->declBus(c+66,"top vga_ctrl vga_r", false,-1, 7,0);
        tracep->declBus(c+67,"top vga_ctrl vga_g", false,-1, 7,0);
        tracep->declBus(c+68,"top vga_ctrl vga_b", false,-1, 7,0);
        tracep->declBus(c+76,"top vga_ctrl h_frontporch", false,-1, 31,0);
        tracep->declBus(c+77,"top vga_ctrl h_active", false,-1, 31,0);
        tracep->declBus(c+78,"top vga_ctrl h_backporch", false,-1, 31,0);
        tracep->declBus(c+79,"top vga_ctrl h_total", false,-1, 31,0);
        tracep->declBus(c+80,"top vga_ctrl v_frontporch", false,-1, 31,0);
        tracep->declBus(c+81,"top vga_ctrl v_active", false,-1, 31,0);
        tracep->declBus(c+82,"top vga_ctrl v_backporch", false,-1, 31,0);
        tracep->declBus(c+83,"top vga_ctrl v_total", false,-1, 31,0);
        tracep->declBus(c+41,"top vga_ctrl x_cnt", false,-1, 9,0);
        tracep->declBus(c+42,"top vga_ctrl y_cnt", false,-1, 9,0);
        tracep->declBit(c+43,"top vga_ctrl h_valid", false,-1);
        tracep->declBit(c+44,"top vga_ctrl v_valid", false,-1);
        tracep->declBit(c+58,"top my_keyboard clk", false,-1);
        tracep->declBit(c+74,"top my_keyboard resetn", false,-1);
        tracep->declBit(c+59,"top my_keyboard ps2_clk", false,-1);
        tracep->declBit(c+60,"top my_keyboard ps2_data", false,-1);
        tracep->declBit(c+10,"top my_keyboard nextdata_n", false,-1);
        tracep->declBus(c+15,"top my_keyboard data", false,-1, 7,0);
        tracep->declBit(c+16,"top my_keyboard ready", false,-1);
        tracep->declBit(c+17,"top my_keyboard overflow", false,-1);
        tracep->declBit(c+19,"top my_keyboard sampling", false,-1);
        tracep->declBus(c+18,"top my_keyboard count", false,-1, 3,0);
        tracep->declBus(c+45,"top my_keyboard buffer", false,-1, 9,0);
        tracep->declBus(c+46,"top my_keyboard ps2_clk_sync", false,-1, 2,0);
        {int i; for (i=0; i<8; i++) {
                tracep->declBus(c+47+i*1,"top my_keyboard fifo", true,(i+0), 7,0);}}
        tracep->declBus(c+55,"top my_keyboard w_ptr", false,-1, 2,0);
        tracep->declBus(c+56,"top my_keyboard r_ptr", false,-1, 2,0);
    }
}

void Vtop___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vtop___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vtop___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vtop___024root__traceRegister(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vtop___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vtop___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vtop___024root__traceCleanup, vlSelf);
    }
}

void Vtop___024root__traceFullSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vtop___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vtop___024root* const __restrict vlSelf = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vtop___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vtop___024root__traceFullSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlSelf->top__DOT__segs[0]),8);
        tracep->fullCData(oldp+2,(vlSelf->top__DOT__segs[1]),8);
        tracep->fullCData(oldp+3,(vlSelf->top__DOT__segs[2]),8);
        tracep->fullCData(oldp+4,(vlSelf->top__DOT__segs[3]),8);
        tracep->fullCData(oldp+5,(vlSelf->top__DOT__segs[4]),8);
        tracep->fullCData(oldp+6,(vlSelf->top__DOT__segs[5]),8);
        tracep->fullCData(oldp+7,(vlSelf->top__DOT__segs[6]),8);
        tracep->fullCData(oldp+8,(vlSelf->top__DOT__segs[7]),8);
        tracep->fullCData(oldp+9,(vlSelf->top__DOT__segs[8]),8);
        tracep->fullBit(oldp+10,(vlSelf->top__DOT__nextdata_n));
        tracep->fullCData(oldp+11,(vlSelf->top__DOT__mc),8);
        tracep->fullCData(oldp+12,(vlSelf->top__DOT__cnt),3);
        tracep->fullBit(oldp+13,(vlSelf->top__DOT__flag));
        tracep->fullCData(oldp+14,(vlSelf->top__DOT__led_flag),7);
        tracep->fullCData(oldp+15,(vlSelf->top__DOT__data),8);
        tracep->fullBit(oldp+16,(vlSelf->top__DOT__ready));
        tracep->fullBit(oldp+17,(vlSelf->top__DOT__overflow));
        tracep->fullCData(oldp+18,(vlSelf->top__DOT__count),4);
        tracep->fullBit(oldp+19,(vlSelf->top__DOT__sampling));
        tracep->fullCData(oldp+20,(vlSelf->top__DOT__c_state),3);
        tracep->fullSData(oldp+21,(vlSelf->top__DOT__pix[0]),9);
        tracep->fullSData(oldp+22,(vlSelf->top__DOT__pix[1]),9);
        tracep->fullSData(oldp+23,(vlSelf->top__DOT__pix[2]),9);
        tracep->fullSData(oldp+24,(vlSelf->top__DOT__pix[3]),9);
        tracep->fullSData(oldp+25,(vlSelf->top__DOT__pix[4]),9);
        tracep->fullSData(oldp+26,(vlSelf->top__DOT__pix[5]),9);
        tracep->fullSData(oldp+27,(vlSelf->top__DOT__pix[6]),9);
        tracep->fullSData(oldp+28,(vlSelf->top__DOT__pix[7]),9);
        tracep->fullSData(oldp+29,(vlSelf->top__DOT__pix[8]),9);
        tracep->fullSData(oldp+30,(vlSelf->top__DOT__pix[9]),9);
        tracep->fullSData(oldp+31,(vlSelf->top__DOT__pix[10]),9);
        tracep->fullSData(oldp+32,(vlSelf->top__DOT__pix[11]),9);
        tracep->fullSData(oldp+33,(vlSelf->top__DOT__pix[12]),9);
        tracep->fullSData(oldp+34,(vlSelf->top__DOT__pix[13]),9);
        tracep->fullSData(oldp+35,(vlSelf->top__DOT__pix[14]),9);
        tracep->fullSData(oldp+36,(vlSelf->top__DOT__pix[15]),9);
        tracep->fullSData(oldp+37,(vlSelf->top__DOT__pix_line),9);
        tracep->fullSData(oldp+38,(((IData)(vlSelf->top__DOT__vga_ctrl__DOT__h_valid)
                                     ? (0x3ffU & ((IData)(vlSelf->top__DOT__vga_ctrl__DOT__x_cnt) 
                                                  - (IData)(0x91U)))
                                     : 0U)),10);
        tracep->fullSData(oldp+39,(vlSelf->top__DOT__v_addr),10);
        tracep->fullIData(oldp+40,(vlSelf->top__DOT__vga_data),24);
        tracep->fullSData(oldp+41,(vlSelf->top__DOT__vga_ctrl__DOT__x_cnt),10);
        tracep->fullSData(oldp+42,(vlSelf->top__DOT__vga_ctrl__DOT__y_cnt),10);
        tracep->fullBit(oldp+43,(vlSelf->top__DOT__vga_ctrl__DOT__h_valid));
        tracep->fullBit(oldp+44,(vlSelf->top__DOT__vga_ctrl__DOT__v_valid));
        tracep->fullSData(oldp+45,(vlSelf->top__DOT__my_keyboard__DOT__buffer),10);
        tracep->fullCData(oldp+46,(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync),3);
        tracep->fullCData(oldp+47,(vlSelf->top__DOT__my_keyboard__DOT__fifo[0]),8);
        tracep->fullCData(oldp+48,(vlSelf->top__DOT__my_keyboard__DOT__fifo[1]),8);
        tracep->fullCData(oldp+49,(vlSelf->top__DOT__my_keyboard__DOT__fifo[2]),8);
        tracep->fullCData(oldp+50,(vlSelf->top__DOT__my_keyboard__DOT__fifo[3]),8);
        tracep->fullCData(oldp+51,(vlSelf->top__DOT__my_keyboard__DOT__fifo[4]),8);
        tracep->fullCData(oldp+52,(vlSelf->top__DOT__my_keyboard__DOT__fifo[5]),8);
        tracep->fullCData(oldp+53,(vlSelf->top__DOT__my_keyboard__DOT__fifo[6]),8);
        tracep->fullCData(oldp+54,(vlSelf->top__DOT__my_keyboard__DOT__fifo[7]),8);
        tracep->fullCData(oldp+55,(vlSelf->top__DOT__my_keyboard__DOT__w_ptr),3);
        tracep->fullCData(oldp+56,(vlSelf->top__DOT__my_keyboard__DOT__r_ptr),3);
        tracep->fullBit(oldp+57,(vlSelf->rst));
        tracep->fullBit(oldp+58,(vlSelf->clk));
        tracep->fullBit(oldp+59,(vlSelf->ps2_clk));
        tracep->fullBit(oldp+60,(vlSelf->ps2_data));
        tracep->fullSData(oldp+61,(vlSelf->ledr),16);
        tracep->fullBit(oldp+62,(vlSelf->VGA_CLK));
        tracep->fullBit(oldp+63,(vlSelf->VGA_HSYNC));
        tracep->fullBit(oldp+64,(vlSelf->VGA_VSYNC));
        tracep->fullBit(oldp+65,(vlSelf->VGA_BLANK_N));
        tracep->fullCData(oldp+66,(vlSelf->VGA_R),8);
        tracep->fullCData(oldp+67,(vlSelf->VGA_G),8);
        tracep->fullCData(oldp+68,(vlSelf->VGA_B),8);
        tracep->fullCData(oldp+69,(vlSelf->seg0),8);
        tracep->fullCData(oldp+70,(vlSelf->seg1),8);
        tracep->fullCData(oldp+71,(vlSelf->seg4),8);
        tracep->fullCData(oldp+72,(vlSelf->seg5),8);
        tracep->fullCData(oldp+73,(((IData)(vlSelf->rst)
                                     ? 0U : ((((0xf0U 
                                                != (IData)(vlSelf->top__DOT__data)) 
                                               & (IData)(vlSelf->top__DOT__flag)) 
                                              & (IData)(vlSelf->top__DOT__ready))
                                              ? 1U : 
                                             (((0xf0U 
                                                == (IData)(vlSelf->top__DOT__data)) 
                                               & (IData)(vlSelf->top__DOT__ready))
                                               ? 2U
                                               : ((
                                                   (~ (IData)(vlSelf->top__DOT__flag)) 
                                                   & (IData)(vlSelf->top__DOT__ready))
                                                   ? 4U
                                                   : 0U))))),3);
        tracep->fullBit(oldp+74,((1U & (~ (IData)(vlSelf->rst)))));
        tracep->fullCData(oldp+75,(vlSelf->top__DOT__y),4);
        tracep->fullIData(oldp+76,(0x60U),32);
        tracep->fullIData(oldp+77,(0x90U),32);
        tracep->fullIData(oldp+78,(0x310U),32);
        tracep->fullIData(oldp+79,(0x320U),32);
        tracep->fullIData(oldp+80,(2U),32);
        tracep->fullIData(oldp+81,(0x23U),32);
        tracep->fullIData(oldp+82,(0x203U),32);
        tracep->fullIData(oldp+83,(0x20dU),32);
    }
}
