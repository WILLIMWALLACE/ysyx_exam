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
        tracep->declBit(c+16,"clk", false,-1);
        tracep->declBus(c+17,"inst", false,-1, 31,0);
        tracep->declQuad(c+18,"out", false,-1, 63,0);
        tracep->declBit(c+16,"ysyx_22040365_top clk", false,-1);
        tracep->declBus(c+17,"ysyx_22040365_top inst", false,-1, 31,0);
        tracep->declQuad(c+18,"ysyx_22040365_top out", false,-1, 63,0);
        tracep->declBus(c+11,"ysyx_22040365_top inst_type", false,-1, 7,0);
        tracep->declBus(c+20,"ysyx_22040365_top rs1_addr", false,-1, 4,0);
        tracep->declBus(c+21,"ysyx_22040365_top rd_addr", false,-1, 4,0);
        tracep->declQuad(c+22,"ysyx_22040365_top imm_I", false,-1, 63,0);
        tracep->declBit(c+12,"ysyx_22040365_top ren_rs1", false,-1);
        tracep->declQuad(c+13,"ysyx_22040365_top rs1_data", false,-1, 63,0);
        tracep->declQuad(c+24,"ysyx_22040365_top rd_data", false,-1, 63,0);
        tracep->declBit(c+15,"ysyx_22040365_top wen_rd", false,-1);
        tracep->declBus(c+17,"ysyx_22040365_top u_ysyx_22040365_id inst", false,-1, 31,0);
        tracep->declBus(c+11,"ysyx_22040365_top u_ysyx_22040365_id inst_type", false,-1, 7,0);
        tracep->declBus(c+20,"ysyx_22040365_top u_ysyx_22040365_id rs1", false,-1, 4,0);
        tracep->declBus(c+21,"ysyx_22040365_top u_ysyx_22040365_id rd", false,-1, 4,0);
        tracep->declQuad(c+22,"ysyx_22040365_top u_ysyx_22040365_id imm_I", false,-1, 63,0);
        tracep->declBit(c+12,"ysyx_22040365_top u_ysyx_22040365_id ren_rs1", false,-1);
        tracep->declBus(c+28,"ysyx_22040365_top u_ysyx_22040365_id opcode", false,-1, 6,0);
        tracep->declBus(c+26,"ysyx_22040365_top u_ysyx_22040365_id func3", false,-1, 2,0);
        tracep->declBit(c+27,"ysyx_22040365_top u_ysyx_22040365_id addi", false,-1);
        tracep->declBus(c+29,"ysyx_22040365_top u_ysyx_22040365_regfile ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+30,"ysyx_22040365_top u_ysyx_22040365_regfile DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+16,"ysyx_22040365_top u_ysyx_22040365_regfile clk", false,-1);
        tracep->declQuad(c+24,"ysyx_22040365_top u_ysyx_22040365_regfile wdata", false,-1, 63,0);
        tracep->declBus(c+21,"ysyx_22040365_top u_ysyx_22040365_regfile waddr", false,-1, 4,0);
        tracep->declBit(c+15,"ysyx_22040365_top u_ysyx_22040365_regfile wen", false,-1);
        tracep->declBit(c+12,"ysyx_22040365_top u_ysyx_22040365_regfile ren_rs1", false,-1);
        tracep->declBus(c+20,"ysyx_22040365_top u_ysyx_22040365_regfile raddr", false,-1, 4,0);
        tracep->declQuad(c+13,"ysyx_22040365_top u_ysyx_22040365_regfile rdata", false,-1, 63,0);
        {int i; for (i=0; i<5; i++) {
                tracep->declQuad(c+1+i*2,"ysyx_22040365_top u_ysyx_22040365_regfile rf", true,(i+0), 63,0);}}
        tracep->declQuad(c+13,"ysyx_22040365_top u_ysyx_22040365_ex op1", false,-1, 63,0);
        tracep->declQuad(c+22,"ysyx_22040365_top u_ysyx_22040365_ex op2", false,-1, 63,0);
        tracep->declBus(c+11,"ysyx_22040365_top u_ysyx_22040365_ex op_type", false,-1, 7,0);
        tracep->declBit(c+15,"ysyx_22040365_top u_ysyx_22040365_ex wen_rd", false,-1);
        tracep->declQuad(c+24,"ysyx_22040365_top u_ysyx_22040365_ex ex_result", false,-1, 63,0);
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
        tracep->fullQData(oldp+1,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[0]),64);
        tracep->fullQData(oldp+3,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[1]),64);
        tracep->fullQData(oldp+5,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[2]),64);
        tracep->fullQData(oldp+7,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[3]),64);
        tracep->fullQData(oldp+9,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf[4]),64);
        tracep->fullCData(oldp+11,(vlSelf->ysyx_22040365_top__DOT__inst_type),8);
        tracep->fullBit(oldp+12,((1U == (IData)(vlSelf->ysyx_22040365_top__DOT__inst_type))));
        tracep->fullQData(oldp+13,(vlSelf->ysyx_22040365_top__DOT__rs1_data),64);
        tracep->fullBit(oldp+15,(vlSelf->ysyx_22040365_top__DOT__wen_rd));
        tracep->fullBit(oldp+16,(vlSelf->clk));
        tracep->fullIData(oldp+17,(vlSelf->inst),32);
        tracep->fullQData(oldp+18,(vlSelf->out),64);
        tracep->fullCData(oldp+20,((0x1fU & (vlSelf->inst 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+21,((0x1fU & (vlSelf->inst 
                                             >> 7U))),5);
        tracep->fullQData(oldp+22,((((- (QData)((IData)(
                                                        (vlSelf->inst 
                                                         >> 0x1fU)))) 
                                     << 0xcU) | (QData)((IData)(
                                                                (vlSelf->inst 
                                                                 >> 0x14U))))),64);
        tracep->fullQData(oldp+24,(((1U == (IData)(vlSelf->ysyx_22040365_top__DOT__inst_type))
                                     ? (vlSelf->ysyx_22040365_top__DOT__rs1_data 
                                        + (((- (QData)((IData)(
                                                               (vlSelf->inst 
                                                                >> 0x1fU)))) 
                                            << 0xcU) 
                                           | (QData)((IData)(
                                                             (vlSelf->inst 
                                                              >> 0x14U)))))
                                     : 0ULL)),64);
        tracep->fullCData(oldp+26,((7U & (vlSelf->inst 
                                          >> 0xcU))),3);
        tracep->fullBit(oldp+27,((1U & (IData)(((0x10U 
                                                 == 
                                                 (0x7cU 
                                                  & (IData)(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_id__DOT__opcode))) 
                                                & (0U 
                                                   == 
                                                   (0x7000U 
                                                    & vlSelf->inst)))))));
        tracep->fullCData(oldp+28,(vlSelf->ysyx_22040365_top__DOT__u_ysyx_22040365_id__DOT__opcode),7);
        tracep->fullIData(oldp+29,(5U),32);
        tracep->fullIData(oldp+30,(0x40U),32);
    }
}
