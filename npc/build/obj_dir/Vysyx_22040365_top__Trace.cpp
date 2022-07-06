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
            tracep->chgQData(oldp+0,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[0]),64);
            tracep->chgQData(oldp+2,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[1]),64);
            tracep->chgQData(oldp+4,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[2]),64);
            tracep->chgQData(oldp+6,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[3]),64);
            tracep->chgQData(oldp+8,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[4]),64);
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+10,(vlSelf->ysyx_22040365_top__DOT__inst_type),8);
            tracep->chgBit(oldp+11,((1U == (IData)(vlSelf->ysyx_22040365_top__DOT__inst_type))));
            tracep->chgQData(oldp+12,(vlSelf->ysyx_22040365_top__DOT__rs1_data),64);
            tracep->chgBit(oldp+14,(vlSelf->ysyx_22040365_top__DOT__wen_rd));
        }
        tracep->chgBit(oldp+15,(vlSelf->clk));
        tracep->chgIData(oldp+16,(vlSelf->inst),32);
        tracep->chgQData(oldp+17,(vlSelf->out),64);
        tracep->chgCData(oldp+19,((0x1fU & (vlSelf->inst 
                                            >> 0xfU))),5);
        tracep->chgCData(oldp+20,((0x1fU & (vlSelf->inst 
                                            >> 7U))),5);
        tracep->chgQData(oldp+21,((((- (QData)((IData)(
                                                       (vlSelf->inst 
                                                        >> 0x1fU)))) 
                                    << 0xcU) | (QData)((IData)(
                                                               (vlSelf->inst 
                                                                >> 0x14U))))),64);
        tracep->chgQData(oldp+23,(((1U == (IData)(vlSelf->ysyx_22040365_top__DOT__inst_type))
                                    ? (vlSelf->ysyx_22040365_top__DOT__rs1_data 
                                       + (((- (QData)((IData)(
                                                              (vlSelf->inst 
                                                               >> 0x1fU)))) 
                                           << 0xcU) 
                                          | (QData)((IData)(
                                                            (vlSelf->inst 
                                                             >> 0x14U)))))
                                    : 0ULL)),64);
        tracep->chgCData(oldp+25,((7U & (vlSelf->inst 
                                         >> 0xcU))),3);
        tracep->chgBit(oldp+26,((1U & (IData)(((0x10U 
                                                == 
                                                (0x7cU 
                                                 & (IData)(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_id__DOT__opcode))) 
                                               & (0U 
                                                  == 
                                                  (0x7000U 
                                                   & vlSelf->inst)))))));
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
        vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    }
}
