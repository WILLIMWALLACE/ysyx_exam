// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_22040365_top__Syms.h"


void Vysyx_22040365_top___024root__traceChgSub0(Vysyx_22040365_top___024root* vlSelf, VerilatedVcd* tracep);

void Vysyx_22040365_top___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vysyx_22040365_top___024root* const __restrict vlSelf = static_cast<Vysyx_22040365_top___024root*>(voidSelf);
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vysyx_22040365_top___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vysyx_22040365_top___024root__traceChgSub0(Vysyx_22040365_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgQData(oldp+0,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[0]),64);
            tracep->chgQData(oldp+2,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[1]),64);
            tracep->chgQData(oldp+4,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[2]),64);
            tracep->chgQData(oldp+6,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[3]),64);
            tracep->chgQData(oldp+8,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[4]),64);
            tracep->chgQData(oldp+10,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[5]),64);
            tracep->chgQData(oldp+12,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[6]),64);
            tracep->chgQData(oldp+14,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[7]),64);
            tracep->chgQData(oldp+16,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[8]),64);
            tracep->chgQData(oldp+18,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[9]),64);
            tracep->chgQData(oldp+20,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[10]),64);
            tracep->chgQData(oldp+22,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[11]),64);
            tracep->chgQData(oldp+24,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[12]),64);
            tracep->chgQData(oldp+26,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[13]),64);
            tracep->chgQData(oldp+28,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[14]),64);
            tracep->chgQData(oldp+30,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[15]),64);
            tracep->chgQData(oldp+32,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[16]),64);
            tracep->chgQData(oldp+34,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[17]),64);
            tracep->chgQData(oldp+36,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[18]),64);
            tracep->chgQData(oldp+38,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[19]),64);
            tracep->chgQData(oldp+40,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[20]),64);
            tracep->chgQData(oldp+42,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[21]),64);
            tracep->chgQData(oldp+44,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[22]),64);
            tracep->chgQData(oldp+46,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[23]),64);
            tracep->chgQData(oldp+48,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[24]),64);
            tracep->chgQData(oldp+50,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[25]),64);
            tracep->chgQData(oldp+52,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[26]),64);
            tracep->chgQData(oldp+54,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[27]),64);
            tracep->chgQData(oldp+56,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[28]),64);
            tracep->chgQData(oldp+58,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[29]),64);
            tracep->chgQData(oldp+60,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[30]),64);
            tracep->chgQData(oldp+62,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[31]),64);
        }
        tracep->chgBit(oldp+64,(vlSelf->clk));
        tracep->chgIData(oldp+65,(vlSelf->inst),32);
        tracep->chgQData(oldp+66,(vlSelf->out),64);
        tracep->chgBit(oldp+68,((IData)((0x13U == (0x707fU 
                                                   & vlSelf->inst)))));
        tracep->chgCData(oldp+69,((0x1fU & (vlSelf->inst 
                                            >> 0xfU))),5);
        tracep->chgCData(oldp+70,((0x1fU & (vlSelf->inst 
                                            >> 7U))),5);
        tracep->chgQData(oldp+71,((((- (QData)((IData)(
                                                       (vlSelf->inst 
                                                        >> 0x1fU)))) 
                                    << 0xcU) | (QData)((IData)(
                                                               (vlSelf->inst 
                                                                >> 0x14U))))),64);
        tracep->chgQData(oldp+73,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs
                                  [(0x1fU & (vlSelf->inst 
                                             >> 0xfU))]),64);
        tracep->chgQData(oldp+75,(vlSelf->ysyx_22040365_top__DOT__rd_data),64);
        tracep->chgCData(oldp+77,((0x7fU & vlSelf->inst)),7);
        tracep->chgCData(oldp+78,((7U & (vlSelf->inst 
                                         >> 0xcU))),3);
    }
}

void Vysyx_22040365_top___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    Vysyx_22040365_top___024root* const __restrict vlSelf = static_cast<Vysyx_22040365_top___024root*>(voidSelf);
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    }
}
