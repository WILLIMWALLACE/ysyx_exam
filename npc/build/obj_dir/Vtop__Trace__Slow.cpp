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
        tracep->declBit(c+31,"rst", false,-1);
        tracep->declBit(c+32,"clk", false,-1);
        tracep->declBit(c+33,"ps2_clk", false,-1);
        tracep->declBit(c+34,"ps2_data", false,-1);
        tracep->declBus(c+35,"ledr", false,-1, 15,0);
        tracep->declBus(c+36,"seg0", false,-1, 7,0);
        tracep->declBus(c+37,"seg1", false,-1, 7,0);
        tracep->declBus(c+38,"seg4", false,-1, 7,0);
        tracep->declBus(c+39,"seg5", false,-1, 7,0);
        tracep->declBit(c+31,"top rst", false,-1);
        tracep->declBit(c+32,"top clk", false,-1);
        tracep->declBit(c+33,"top ps2_clk", false,-1);
        tracep->declBit(c+34,"top ps2_data", false,-1);
        tracep->declBus(c+35,"top ledr", false,-1, 15,0);
        tracep->declBus(c+36,"top seg0", false,-1, 7,0);
        tracep->declBus(c+37,"top seg1", false,-1, 7,0);
        tracep->declBus(c+38,"top seg4", false,-1, 7,0);
        tracep->declBus(c+39,"top seg5", false,-1, 7,0);
        tracep->declBus(c+10,"top led_flag", false,-1, 7,0);
        {int i; for (i=0; i<9; i++) {
                tracep->declBus(c+1+i*1,"top segs", true,(i+0), 7,0);}}
        tracep->declBit(c+11,"top nextdata_n", false,-1);
        tracep->declBus(c+12,"top data", false,-1, 7,0);
        tracep->declBus(c+13,"top mc", false,-1, 7,0);
        tracep->declBit(c+14,"top ready", false,-1);
        tracep->declBit(c+15,"top overflow", false,-1);
        tracep->declBus(c+16,"top cnt", false,-1, 2,0);
        tracep->declBus(c+17,"top count", false,-1, 3,0);
        tracep->declBit(c+18,"top sampling", false,-1);
        tracep->declBit(c+32,"top my_keyboard clk", false,-1);
        tracep->declBit(c+40,"top my_keyboard resetn", false,-1);
        tracep->declBit(c+33,"top my_keyboard ps2_clk", false,-1);
        tracep->declBit(c+34,"top my_keyboard ps2_data", false,-1);
        tracep->declBit(c+11,"top my_keyboard nextdata_n", false,-1);
        tracep->declBus(c+12,"top my_keyboard data", false,-1, 7,0);
        tracep->declBit(c+14,"top my_keyboard ready", false,-1);
        tracep->declBit(c+15,"top my_keyboard overflow", false,-1);
        tracep->declBit(c+18,"top my_keyboard sampling", false,-1);
        tracep->declBus(c+17,"top my_keyboard count", false,-1, 3,0);
        tracep->declBus(c+19,"top my_keyboard buffer", false,-1, 9,0);
        tracep->declBus(c+20,"top my_keyboard ps2_clk_sync", false,-1, 2,0);
        {int i; for (i=0; i<8; i++) {
                tracep->declBus(c+21+i*1,"top my_keyboard fifo", true,(i+0), 7,0);}}
        tracep->declBus(c+29,"top my_keyboard w_ptr", false,-1, 2,0);
        tracep->declBus(c+30,"top my_keyboard r_ptr", false,-1, 2,0);
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
        tracep->fullCData(oldp+10,(vlSelf->top__DOT__led_flag),8);
        tracep->fullBit(oldp+11,(vlSelf->top__DOT__nextdata_n));
        tracep->fullCData(oldp+12,(vlSelf->top__DOT__my_keyboard__DOT__fifo
                                   [vlSelf->top__DOT__my_keyboard__DOT__r_ptr]),8);
        tracep->fullCData(oldp+13,(vlSelf->top__DOT__mc),8);
        tracep->fullBit(oldp+14,(vlSelf->top__DOT__ready));
        tracep->fullBit(oldp+15,(vlSelf->top__DOT__overflow));
        tracep->fullCData(oldp+16,(vlSelf->top__DOT__cnt),3);
        tracep->fullCData(oldp+17,(vlSelf->top__DOT__count),4);
        tracep->fullBit(oldp+18,(vlSelf->top__DOT__sampling));
        tracep->fullSData(oldp+19,(vlSelf->top__DOT__my_keyboard__DOT__buffer),10);
        tracep->fullCData(oldp+20,(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync),3);
        tracep->fullCData(oldp+21,(vlSelf->top__DOT__my_keyboard__DOT__fifo[0]),8);
        tracep->fullCData(oldp+22,(vlSelf->top__DOT__my_keyboard__DOT__fifo[1]),8);
        tracep->fullCData(oldp+23,(vlSelf->top__DOT__my_keyboard__DOT__fifo[2]),8);
        tracep->fullCData(oldp+24,(vlSelf->top__DOT__my_keyboard__DOT__fifo[3]),8);
        tracep->fullCData(oldp+25,(vlSelf->top__DOT__my_keyboard__DOT__fifo[4]),8);
        tracep->fullCData(oldp+26,(vlSelf->top__DOT__my_keyboard__DOT__fifo[5]),8);
        tracep->fullCData(oldp+27,(vlSelf->top__DOT__my_keyboard__DOT__fifo[6]),8);
        tracep->fullCData(oldp+28,(vlSelf->top__DOT__my_keyboard__DOT__fifo[7]),8);
        tracep->fullCData(oldp+29,(vlSelf->top__DOT__my_keyboard__DOT__w_ptr),3);
        tracep->fullCData(oldp+30,(vlSelf->top__DOT__my_keyboard__DOT__r_ptr),3);
        tracep->fullBit(oldp+31,(vlSelf->rst));
        tracep->fullBit(oldp+32,(vlSelf->clk));
        tracep->fullBit(oldp+33,(vlSelf->ps2_clk));
        tracep->fullBit(oldp+34,(vlSelf->ps2_data));
        tracep->fullSData(oldp+35,(vlSelf->ledr),16);
        tracep->fullCData(oldp+36,(vlSelf->seg0),8);
        tracep->fullCData(oldp+37,(vlSelf->seg1),8);
        tracep->fullCData(oldp+38,(vlSelf->seg4),8);
        tracep->fullCData(oldp+39,(vlSelf->seg5),8);
        tracep->fullBit(oldp+40,((1U & (~ (IData)(vlSelf->rst)))));
    }
}
