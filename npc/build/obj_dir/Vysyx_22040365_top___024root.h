// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_22040365_top.h for the primary calling header

#ifndef VERILATED_VYSYX_22040365_TOP___024ROOT_H_
#define VERILATED_VYSYX_22040365_TOP___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vysyx_22040365_top__Syms;
class Vysyx_22040365_top_VerilatedVcd;


//----------

VL_MODULE(Vysyx_22040365_top___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN(inst,31,0);
    VL_OUT64(out,63,0);

    // LOCAL SIGNALS
    CData/*7:0*/ ysyx_22040365_top__DOT__inst_type;
    CData/*0:0*/ ysyx_22040365_top__DOT__wen_rd;
    CData/*6:0*/ ysyx_22040365_top__DOT__u_ysyx_22040365_id__DOT__opcode;
    QData/*63:0*/ ysyx_22040365_top__DOT__rs1_data;
    VlUnpacked<QData/*63:0*/, 5> ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT__rf;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;
    QData/*63:0*/ ysyx_22040365_top__DOT__u_ysyx_22040365_regfile__DOT____Vlvbound1;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vysyx_22040365_top__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vysyx_22040365_top___024root);  ///< Copying not allowed
  public:
    Vysyx_22040365_top___024root(const char* name);
    ~Vysyx_22040365_top___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vysyx_22040365_top__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
