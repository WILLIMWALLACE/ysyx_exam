// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__traceChgSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

void Vtop___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vtop___024root* const __restrict vlSelf = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vtop___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vtop___024root__traceChgSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
            tracep->chgCData(oldp+0,(vlSelf->top__DOT__segs[0]),8);
            tracep->chgCData(oldp+1,(vlSelf->top__DOT__segs[1]),8);
            tracep->chgCData(oldp+2,(vlSelf->top__DOT__segs[2]),8);
            tracep->chgCData(oldp+3,(vlSelf->top__DOT__segs[3]),8);
            tracep->chgCData(oldp+4,(vlSelf->top__DOT__segs[4]),8);
            tracep->chgCData(oldp+5,(vlSelf->top__DOT__segs[5]),8);
            tracep->chgCData(oldp+6,(vlSelf->top__DOT__segs[6]),8);
            tracep->chgCData(oldp+7,(vlSelf->top__DOT__segs[7]),8);
            tracep->chgCData(oldp+8,(vlSelf->top__DOT__segs[8]),8);
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+9,(vlSelf->top__DOT__nextdata_n));
            tracep->chgCData(oldp+10,(vlSelf->top__DOT__mc),8);
            tracep->chgCData(oldp+11,(vlSelf->top__DOT__cnt),3);
            tracep->chgBit(oldp+12,(vlSelf->top__DOT__flag));
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+13,(vlSelf->top__DOT__led_flag),7);
            tracep->chgCData(oldp+14,(vlSelf->top__DOT__data),8);
            tracep->chgBit(oldp+15,(vlSelf->top__DOT__ready));
            tracep->chgBit(oldp+16,(vlSelf->top__DOT__overflow));
            tracep->chgCData(oldp+17,(vlSelf->top__DOT__count),4);
            tracep->chgBit(oldp+18,(vlSelf->top__DOT__sampling));
            tracep->chgCData(oldp+19,(vlSelf->top__DOT__c_state),3);
            tracep->chgSData(oldp+20,(vlSelf->top__DOT__pix[0]),9);
            tracep->chgSData(oldp+21,(vlSelf->top__DOT__pix[1]),9);
            tracep->chgSData(oldp+22,(vlSelf->top__DOT__pix[2]),9);
            tracep->chgSData(oldp+23,(vlSelf->top__DOT__pix[3]),9);
            tracep->chgSData(oldp+24,(vlSelf->top__DOT__pix[4]),9);
            tracep->chgSData(oldp+25,(vlSelf->top__DOT__pix[5]),9);
            tracep->chgSData(oldp+26,(vlSelf->top__DOT__pix[6]),9);
            tracep->chgSData(oldp+27,(vlSelf->top__DOT__pix[7]),9);
            tracep->chgSData(oldp+28,(vlSelf->top__DOT__pix[8]),9);
            tracep->chgSData(oldp+29,(vlSelf->top__DOT__pix[9]),9);
            tracep->chgSData(oldp+30,(vlSelf->top__DOT__pix[10]),9);
            tracep->chgSData(oldp+31,(vlSelf->top__DOT__pix[11]),9);
            tracep->chgSData(oldp+32,(vlSelf->top__DOT__pix[12]),9);
            tracep->chgSData(oldp+33,(vlSelf->top__DOT__pix[13]),9);
            tracep->chgSData(oldp+34,(vlSelf->top__DOT__pix[14]),9);
            tracep->chgSData(oldp+35,(vlSelf->top__DOT__pix[15]),9);
            tracep->chgSData(oldp+36,(vlSelf->top__DOT__pix_line),9);
            tracep->chgCData(oldp+37,(vlSelf->top__DOT__y),4);
            tracep->chgSData(oldp+38,(((IData)(vlSelf->top__DOT__vga_ctrl__DOT__h_valid)
                                        ? (0x3ffU & 
                                           ((IData)(vlSelf->top__DOT__vga_ctrl__DOT__x_cnt) 
                                            - (IData)(0x91U)))
                                        : 0U)),10);
            tracep->chgSData(oldp+39,(vlSelf->top__DOT__v_addr),10);
            tracep->chgIData(oldp+40,(vlSelf->top__DOT__vga_data),24);
            tracep->chgSData(oldp+41,(vlSelf->top__DOT__vga_ctrl__DOT__x_cnt),10);
            tracep->chgSData(oldp+42,(vlSelf->top__DOT__vga_ctrl__DOT__y_cnt),10);
            tracep->chgBit(oldp+43,(vlSelf->top__DOT__vga_ctrl__DOT__h_valid));
            tracep->chgBit(oldp+44,(vlSelf->top__DOT__vga_ctrl__DOT__v_valid));
            tracep->chgSData(oldp+45,(vlSelf->top__DOT__my_keyboard__DOT__buffer),10);
            tracep->chgCData(oldp+46,(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync),3);
            tracep->chgCData(oldp+47,(vlSelf->top__DOT__my_keyboard__DOT__fifo[0]),8);
            tracep->chgCData(oldp+48,(vlSelf->top__DOT__my_keyboard__DOT__fifo[1]),8);
            tracep->chgCData(oldp+49,(vlSelf->top__DOT__my_keyboard__DOT__fifo[2]),8);
            tracep->chgCData(oldp+50,(vlSelf->top__DOT__my_keyboard__DOT__fifo[3]),8);
            tracep->chgCData(oldp+51,(vlSelf->top__DOT__my_keyboard__DOT__fifo[4]),8);
            tracep->chgCData(oldp+52,(vlSelf->top__DOT__my_keyboard__DOT__fifo[5]),8);
            tracep->chgCData(oldp+53,(vlSelf->top__DOT__my_keyboard__DOT__fifo[6]),8);
            tracep->chgCData(oldp+54,(vlSelf->top__DOT__my_keyboard__DOT__fifo[7]),8);
            tracep->chgCData(oldp+55,(vlSelf->top__DOT__my_keyboard__DOT__w_ptr),3);
            tracep->chgCData(oldp+56,(vlSelf->top__DOT__my_keyboard__DOT__r_ptr),3);
        }
        tracep->chgBit(oldp+57,(vlSelf->rst));
        tracep->chgBit(oldp+58,(vlSelf->clk));
        tracep->chgBit(oldp+59,(vlSelf->ps2_clk));
        tracep->chgBit(oldp+60,(vlSelf->ps2_data));
        tracep->chgSData(oldp+61,(vlSelf->ledr),16);
        tracep->chgBit(oldp+62,(vlSelf->VGA_CLK));
        tracep->chgBit(oldp+63,(vlSelf->VGA_HSYNC));
        tracep->chgBit(oldp+64,(vlSelf->VGA_VSYNC));
        tracep->chgBit(oldp+65,(vlSelf->VGA_BLANK_N));
        tracep->chgCData(oldp+66,(vlSelf->VGA_R),8);
        tracep->chgCData(oldp+67,(vlSelf->VGA_G),8);
        tracep->chgCData(oldp+68,(vlSelf->VGA_B),8);
        tracep->chgCData(oldp+69,(vlSelf->seg0),8);
        tracep->chgCData(oldp+70,(vlSelf->seg1),8);
        tracep->chgCData(oldp+71,(vlSelf->seg4),8);
        tracep->chgCData(oldp+72,(vlSelf->seg5),8);
        tracep->chgCData(oldp+73,(((IData)(vlSelf->rst)
                                    ? 0U : ((((0xf0U 
                                               != (IData)(vlSelf->top__DOT__data)) 
                                              & (IData)(vlSelf->top__DOT__flag)) 
                                             & (IData)(vlSelf->top__DOT__ready))
                                             ? 1U : 
                                            (((0xf0U 
                                               == (IData)(vlSelf->top__DOT__data)) 
                                              & (IData)(vlSelf->top__DOT__ready))
                                              ? 2U : 
                                             (((~ (IData)(vlSelf->top__DOT__flag)) 
                                               & (IData)(vlSelf->top__DOT__ready))
                                               ? 4U
                                               : 0U))))),3);
        tracep->chgBit(oldp+74,((1U & (~ (IData)(vlSelf->rst)))));
    }
}

void Vtop___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    Vtop___024root* const __restrict vlSelf = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    }
}
