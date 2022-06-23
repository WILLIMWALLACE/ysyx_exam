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
            tracep->chgCData(oldp+9,(vlSelf->top__DOT__led_flag),8);
            tracep->chgBit(oldp+10,(vlSelf->top__DOT__nextdata_n));
            tracep->chgCData(oldp+11,(vlSelf->top__DOT__my_keyboard__DOT__fifo
                                      [vlSelf->top__DOT__my_keyboard__DOT__r_ptr]),8);
            tracep->chgCData(oldp+12,(vlSelf->top__DOT__mc),8);
            tracep->chgBit(oldp+13,(vlSelf->top__DOT__ready));
            tracep->chgBit(oldp+14,(vlSelf->top__DOT__overflow));
            tracep->chgCData(oldp+15,(vlSelf->top__DOT__cnt),3);
            tracep->chgCData(oldp+16,(vlSelf->top__DOT__count),4);
            tracep->chgBit(oldp+17,(vlSelf->top__DOT__sampling));
            tracep->chgSData(oldp+18,(vlSelf->top__DOT__my_keyboard__DOT__buffer),10);
            tracep->chgCData(oldp+19,(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync),3);
            tracep->chgCData(oldp+20,(vlSelf->top__DOT__my_keyboard__DOT__fifo[0]),8);
            tracep->chgCData(oldp+21,(vlSelf->top__DOT__my_keyboard__DOT__fifo[1]),8);
            tracep->chgCData(oldp+22,(vlSelf->top__DOT__my_keyboard__DOT__fifo[2]),8);
            tracep->chgCData(oldp+23,(vlSelf->top__DOT__my_keyboard__DOT__fifo[3]),8);
            tracep->chgCData(oldp+24,(vlSelf->top__DOT__my_keyboard__DOT__fifo[4]),8);
            tracep->chgCData(oldp+25,(vlSelf->top__DOT__my_keyboard__DOT__fifo[5]),8);
            tracep->chgCData(oldp+26,(vlSelf->top__DOT__my_keyboard__DOT__fifo[6]),8);
            tracep->chgCData(oldp+27,(vlSelf->top__DOT__my_keyboard__DOT__fifo[7]),8);
            tracep->chgCData(oldp+28,(vlSelf->top__DOT__my_keyboard__DOT__w_ptr),3);
            tracep->chgCData(oldp+29,(vlSelf->top__DOT__my_keyboard__DOT__r_ptr),3);
        }
        tracep->chgBit(oldp+30,(vlSelf->rst));
        tracep->chgBit(oldp+31,(vlSelf->clk));
        tracep->chgBit(oldp+32,(vlSelf->ps2_clk));
        tracep->chgBit(oldp+33,(vlSelf->ps2_data));
        tracep->chgSData(oldp+34,(vlSelf->ledr),16);
        tracep->chgCData(oldp+35,(vlSelf->seg0),8);
        tracep->chgCData(oldp+36,(vlSelf->seg1),8);
        tracep->chgCData(oldp+37,(vlSelf->seg4),8);
        tracep->chgCData(oldp+38,(vlSelf->seg5),8);
        tracep->chgBit(oldp+39,((1U & (~ (IData)(vlSelf->rst)))));
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
    }
}
