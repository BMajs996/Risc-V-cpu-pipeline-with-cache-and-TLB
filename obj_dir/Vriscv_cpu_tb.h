// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VRISCV_CPU_TB_H_
#define _VRISCV_CPU_TB_H_  // guard

#include "verilated_heavy.h"

//==========

class Vriscv_cpu_tb__Syms;
class Vriscv_cpu_tb_VerilatedVcd;


//----------

VL_MODULE(Vriscv_cpu_tb) {
  public:
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ riscv_cpu_tb__DOT__clk;
        CData/*0:0*/ riscv_cpu_tb__DOT__rst_n;
        CData/*0:0*/ riscv_cpu_tb__DOT__mem_ready;
        CData/*0:0*/ riscv_cpu_tb__DOT__mem_req;
        CData/*0:0*/ riscv_cpu_tb__DOT__mem_we;
        CData/*4:0*/ riscv_cpu_tb__DOT__dut__DOT__rd_ex;
        CData/*4:0*/ riscv_cpu_tb__DOT__dut__DOT__rd_mem;
        CData/*4:0*/ riscv_cpu_tb__DOT__dut__DOT__rd_wb;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__mem_read_ex;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__reg_write;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__mem_write;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__branch;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__jump;
        CData/*3:0*/ riscv_cpu_tb__DOT__dut__DOT__alu_op_id;
        CData/*3:0*/ riscv_cpu_tb__DOT__dut__DOT__alu_op_ex;
        CData/*1:0*/ riscv_cpu_tb__DOT__dut__DOT__mem_op;
        CData/*1:0*/ riscv_cpu_tb__DOT__dut__DOT__fwd_rs1;
        CData/*1:0*/ riscv_cpu_tb__DOT__dut__DOT__fwd_rs2;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__stall_if;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__stall_id;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__tlb_miss_d;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__cache_miss_d;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__itlb_hit;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__icache_hit;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__dtlb_hit;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__dcache_hit;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__refill_done_i;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__refill_done_d;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__miss_i_wire;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__miss_d_wire;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__dec__DOT__a_instr;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__hu__DOT__stall_ex;
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__hu__DOT__stall_mem;
        CData/*1:0*/ riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state;
        CData/*1:0*/ riscv_cpu_tb__DOT__dut__DOT__mc__DOT__next_state;
        CData/*1:0*/ riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state_q;
        CData/*2:0*/ riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt;
        IData/*31:0*/ riscv_cpu_tb__DOT__mem_rdata;
        IData/*31:0*/ riscv_cpu_tb__DOT__mem_addr;
        IData/*31:0*/ riscv_cpu_tb__DOT__mem_wdata;
        IData/*31:0*/ riscv_cpu_tb__DOT__cycle_cnt;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__pc_if;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__pc_id;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__inst_id;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__imm_id;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__rs1_ex;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__alu_result;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__imm_ex;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__alu_out_ex;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__mem_out_ex;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__wb_out;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__paddr_i;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__paddr_d;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__refill_idx_i;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__refill_vpn_i;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__refill_ppn_i;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__refill_idx_d;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__refill_data_d;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__icache__DOT__wr_data;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__icache__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__rf__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__wr_data;
    };
    struct {
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__mc__DOT__addr_reg;
        QData/*40:0*/ riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem[256];
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid[1024];
        IData/*16:0*/ riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags[1024];
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data[1024];
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[32];
        QData/*40:0*/ riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem[256];
        CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid[1024];
        IData/*16:0*/ riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags[1024];
        IData/*31:0*/ riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data[1024];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ riscv_cpu_tb__DOT__dut__DOT____Vcellinp__dcache__req;
    CData/*7:0*/ __Vtableidx1;
    CData/*2:0*/ __Vdly__riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt;
    CData/*0:0*/ __Vclklast__TOP__riscv_cpu_tb__DOT__clk;
    CData/*0:0*/ __Vclklast__TOP__riscv_cpu_tb__DOT__rst_n;
    IData/*31:0*/ __Vdly__riscv_cpu_tb__DOT__dut__DOT__pc_if;
    CData/*0:0*/ __Vm_traceActivity[5];
    static CData/*1:0*/ __Vtable1_riscv_cpu_tb__DOT__dut__DOT__mc__DOT__next_state[256];
    static CData/*0:0*/ __Vtable1_riscv_cpu_tb__DOT__mem_req[256];
    static CData/*0:0*/ __Vtable1_riscv_cpu_tb__DOT__mem_we[256];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vriscv_cpu_tb__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vriscv_cpu_tb);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vriscv_cpu_tb(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vriscv_cpu_tb();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vriscv_cpu_tb__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vriscv_cpu_tb__Syms* symsp, bool first);
  private:
    static QData _change_request(Vriscv_cpu_tb__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vriscv_cpu_tb__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vriscv_cpu_tb__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vriscv_cpu_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vriscv_cpu_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vriscv_cpu_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vriscv_cpu_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vriscv_cpu_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vriscv_cpu_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vriscv_cpu_tb__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vriscv_cpu_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
