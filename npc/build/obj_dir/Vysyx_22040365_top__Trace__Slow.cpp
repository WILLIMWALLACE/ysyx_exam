// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_22040365_top__Syms.h"


void Vysyx_22040365_top___024root__traceInitSub0(Vysyx_22040365_top___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vysyx_22040365_top___024root__traceInitTop(Vysyx_22040365_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vysyx_22040365_top___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vysyx_22040365_top___024root__traceInitSub0(Vysyx_22040365_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+11,"clk", false,-1);
        tracep->declBus(c+12,"inst", false,-1, 31,0);
        tracep->declQuad(c+13,"out", false,-1, 63,0);
        tracep->declBit(c+11,"ysyx_22040365_top clk", false,-1);
        tracep->declBus(c+12,"ysyx_22040365_top inst", false,-1, 31,0);
        tracep->declQuad(c+13,"ysyx_22040365_top out", false,-1, 63,0);
        tracep->declBit(c+15,"ysyx_22040365_top inst_type", false,-1);
        tracep->declBus(c+16,"ysyx_22040365_top rs1_addr", false,-1, 4,0);
        tracep->declBus(c+17,"ysyx_22040365_top rd_addr", false,-1, 4,0);
        tracep->declQuad(c+18,"ysyx_22040365_top imm_I", false,-1, 63,0);
        tracep->declBit(c+26,"ysyx_22040365_top ren_rs1", false,-1);
        tracep->declQuad(c+20,"ysyx_22040365_top rs1_data", false,-1, 63,0);
        tracep->declQuad(c+22,"ysyx_22040365_top rd_data", false,-1, 63,0);
        tracep->declBit(c+26,"ysyx_22040365_top wen_rd", false,-1);
        tracep->declBus(c+12,"ysyx_22040365_top u_ysyx_22040365_id inst", false,-1, 31,0);
        tracep->declBit(c+15,"ysyx_22040365_top u_ysyx_22040365_id inst_type", false,-1);
        tracep->declBus(c+16,"ysyx_22040365_top u_ysyx_22040365_id rs1", false,-1, 4,0);
        tracep->declBus(c+17,"ysyx_22040365_top u_ysyx_22040365_id rd", false,-1, 4,0);
        tracep->declQuad(c+18,"ysyx_22040365_top u_ysyx_22040365_id imm_I", false,-1, 63,0);
        tracep->declBit(c+26,"ysyx_22040365_top u_ysyx_22040365_id ren_rs1", false,-1);
        tracep->declBus(c+24,"ysyx_22040365_top u_ysyx_22040365_id opcode", false,-1, 6,0);
        tracep->declBus(c+25,"ysyx_22040365_top u_ysyx_22040365_id func3", false,-1, 2,0);
        tracep->declBit(c+15,"ysyx_22040365_top u_ysyx_22040365_id addi", false,-1);
        tracep->declBit(c+11,"ysyx_22040365_top u_ysyx_22040365_regfile clk", false,-1);
        tracep->declQuad(c+22,"ysyx_22040365_top u_ysyx_22040365_regfile wdata", false,-1, 63,0);
        tracep->declBus(c+17,"ysyx_22040365_top u_ysyx_22040365_regfile waddr", false,-1, 4,0);
        tracep->declBit(c+26,"ysyx_22040365_top u_ysyx_22040365_regfile wen", false,-1);
        tracep->declBit(c+26,"ysyx_22040365_top u_ysyx_22040365_regfile ren_rs1", false,-1);
        tracep->declBus(c+16,"ysyx_22040365_top u_ysyx_22040365_regfile raddr", false,-1, 4,0);
        tracep->declQuad(c+20,"ysyx_22040365_top u_ysyx_22040365_regfile rdata", false,-1, 63,0);
        {int i; for (i=0; i<5; i++) {
                tracep->declQuad(c+1+i*2,"ysyx_22040365_top u_ysyx_22040365_regfile regs", true,(i+0), 63,0);}}
        tracep->declQuad(c+20,"ysyx_22040365_top u_ysyx_22040365_ex op1", false,-1, 63,0);
        tracep->declQuad(c+18,"ysyx_22040365_top u_ysyx_22040365_ex op2", false,-1, 63,0);
        tracep->declBit(c+15,"ysyx_22040365_top u_ysyx_22040365_ex op_type", false,-1);
        tracep->declBit(c+26,"ysyx_22040365_top u_ysyx_22040365_ex wen_rd", false,-1);
        tracep->declQuad(c+22,"ysyx_22040365_top u_ysyx_22040365_ex ex_result", false,-1, 63,0);
    }
}

void Vysyx_22040365_top___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vysyx_22040365_top___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vysyx_22040365_top___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vysyx_22040365_top___024root__traceRegister(Vysyx_22040365_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vysyx_22040365_top___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vysyx_22040365_top___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vysyx_22040365_top___024root__traceCleanup, vlSelf);
    }
}

void Vysyx_22040365_top___024root__traceFullSub0(Vysyx_22040365_top___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vysyx_22040365_top___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vysyx_22040365_top___024root* const __restrict vlSelf = static_cast<Vysyx_22040365_top___024root*>(voidSelf);
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vysyx_22040365_top___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vysyx_22040365_top___024root__traceFullSub0(Vysyx_22040365_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040365_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullQData(oldp+1,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[0]),64);
        tracep->fullQData(oldp+3,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[1]),64);
        tracep->fullQData(oldp+5,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[2]),64);
        tracep->fullQData(oldp+7,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[3]),64);
        tracep->fullQData(oldp+9,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs[4]),64);
        tracep->fullBit(oldp+11,(vlSelf->clk));
        tracep->fullIData(oldp+12,(vlSelf->inst),32);
        tracep->fullQData(oldp+13,(vlSelf->out),64);
        tracep->fullBit(oldp+15,((IData)((0x13U == 
                                          (0x707fU 
                                           & vlSelf->inst)))));
        tracep->fullCData(oldp+16,((0x1fU & (vlSelf->inst 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+17,((0x1fU & (vlSelf->inst 
                                             >> 7U))),5);
        tracep->fullQData(oldp+18,((((- (QData)((IData)(
                                                        (vlSelf->inst 
                                                         >> 0x1fU)))) 
                                     << 0xcU) | (QData)((IData)(
                                                                (vlSelf->inst 
                                                                 >> 0x14U))))),64);
        tracep->fullQData(oldp+20,(((4U >= (7U & (vlSelf->inst 
                                                  >> 0xfU)))
                                     ? vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__regs
                                    [(7U & (vlSelf->inst 
                                            >> 0xfU))]
                                     : 0ULL)),64);
        tracep->fullQData(oldp+22,(vlSelf->ysyx_22040365_top__DOT__rd_data),64);
        tracep->fullCData(oldp+24,((0x7fU & vlSelf->inst)),7);
        tracep->fullCData(oldp+25,((7U & (vlSelf->inst 
                                          >> 0xcU))),3);
        tracep->fullBit(oldp+26,(1U));
    }
}
