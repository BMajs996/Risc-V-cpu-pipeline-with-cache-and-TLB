// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_cpu_tb.h for the primary calling header

#include "Vriscv_cpu_tb.h"
#include "Vriscv_cpu_tb__Syms.h"

//==========

void Vriscv_cpu_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vriscv_cpu_tb::eval\n"); );
    Vriscv_cpu_tb__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("tb/riscv_cpu_tb.sv", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vriscv_cpu_tb::_eval_initial_loop(Vriscv_cpu_tb__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("tb/riscv_cpu_tb.sv", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vriscv_cpu_tb::_sequent__TOP__2(Vriscv_cpu_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_cpu_tb::_sequent__TOP__2\n"); );
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__riscv_cpu_tb__DOT__cycle_cnt;
    // Body
    __Vdly__riscv_cpu_tb__DOT__cycle_cnt = vlTOPp->riscv_cpu_tb__DOT__cycle_cnt;
    __Vdly__riscv_cpu_tb__DOT__cycle_cnt = ((IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)
                                             ? ((IData)(1U) 
                                                + vlTOPp->riscv_cpu_tb__DOT__cycle_cnt)
                                             : 0U);
    if (VL_UNLIKELY((0xc8U == vlTOPp->riscv_cpu_tb__DOT__cycle_cnt))) {
        VL_WRITEF("\360\237\224\215 Sim complete at t=%0t (cycle=%0#)\n",
                  64,(0x3e8ULL * (QData)(VL_TIME_UNITED_Q(1000))),
                  32,vlTOPp->riscv_cpu_tb__DOT__cycle_cnt);
        VL_FINISH_MT("tb/riscv_cpu_tb.sv", 37, "");
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_d 
        = (0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                     >> 2U));
    vlTOPp->riscv_cpu_tb__DOT__mem_addr = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__addr_reg;
    vlTOPp->riscv_cpu_tb__DOT__cycle_cnt = __Vdly__riscv_cpu_tb__DOT__cycle_cnt;
    if ((0U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state))) {
        if (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__miss_i_wire) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__addr_reg 
                = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if;
        } else {
            if (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__miss_d_wire) {
                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__addr_reg 
                    = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex;
            }
        }
    }
}

VL_INLINE_OPT void Vriscv_cpu_tb::_sequent__TOP__3(Vriscv_cpu_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_cpu_tb::_sequent__TOP__3\n"); );
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem__v0;
    CData/*0:0*/ __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem__v0;
    CData/*0:0*/ __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid__v0;
    CData/*0:0*/ __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags__v0;
    CData/*0:0*/ __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data__v0;
    CData/*4:0*/ __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs__v0;
    CData/*4:0*/ __Vdly__riscv_cpu_tb__DOT__dut__DOT__rd_ex;
    CData/*0:0*/ __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem__v0;
    CData/*0:0*/ __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid__v0;
    CData/*0:0*/ __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags__v0;
    CData/*0:0*/ __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v0;
    CData/*4:0*/ __Vdlyvlsb__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1;
    CData/*0:0*/ __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1;
    SData/*9:0*/ __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid__v0;
    SData/*9:0*/ __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags__v0;
    SData/*9:0*/ __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data__v0;
    SData/*9:0*/ __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid__v0;
    SData/*9:0*/ __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags__v0;
    SData/*9:0*/ __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v0;
    SData/*9:0*/ __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1;
    IData/*16:0*/ __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags__v0;
    IData/*31:0*/ __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data__v0;
    IData/*31:0*/ __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs__v0;
    IData/*16:0*/ __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags__v0;
    IData/*31:0*/ __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1;
    QData/*40:0*/ __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem__v0;
    // Body
    __Vdly__riscv_cpu_tb__DOT__dut__DOT__rd_ex = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_ex;
    __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data__v0 = 0U;
    vlTOPp->__Vdly__riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt 
        = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt;
    __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid__v0 = 0U;
    __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags__v0 = 0U;
    __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid__v0 = 0U;
    __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags__v0 = 0U;
    vlTOPp->__Vdly__riscv_cpu_tb__DOT__dut__DOT__pc_if 
        = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if;
    __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem__v0 = 0U;
    __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem__v0 = 0U;
    __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs__v0 = 0U;
    __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v0 = 0U;
    __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1 = 0U;
    if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__unnamedblk1__DOT__i = 0x20U;
    }
    if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[1U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[2U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[3U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[4U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[5U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[6U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[7U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[8U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[9U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0xaU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0xbU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0xcU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0xdU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0xeU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0xfU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x10U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x11U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x12U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x13U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x14U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x15U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x16U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x17U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x18U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x19U] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x1aU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x1bU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x1cU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x1dU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x1eU] = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0x1fU] = 0U;
    }
    if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(1,32,32, 0x400U, vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__unnamedblk1__DOT__i)) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid[(0x3ffU 
                                                                     & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__unnamedblk1__DOT__i)] = 0U;
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags[(0x3ffU 
                                                                    & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__unnamedblk1__DOT__i)] = 0U;
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data[(0x3ffU 
                                                                    & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__unnamedblk1__DOT__i)] = 0U;
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__unnamedblk1__DOT__i);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(1,32,32, 0x400U, vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__unnamedblk1__DOT__i)) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid[(0x3ffU 
                                                                     & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__unnamedblk1__DOT__i)] = 0U;
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags[(0x3ffU 
                                                                    & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__unnamedblk1__DOT__i)] = 0U;
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data[(0x3ffU 
                                                                    & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__unnamedblk1__DOT__i)] = 0U;
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__unnamedblk1__DOT__i);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(1,32,32, 0x100U, vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__unnamedblk1__DOT__i)) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem[(0xffU 
                                                                     & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__unnamedblk1__DOT__i)] = 0ULL;
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__unnamedblk1__DOT__i);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(1,32,32, 0x100U, vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__unnamedblk1__DOT__i)) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem[(0xffU 
                                                                     & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__unnamedblk1__DOT__i)] = 0ULL;
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__unnamedblk1__DOT__i);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)))) {
        vlTOPp->riscv_cpu_tb__DOT__mem_we = 0U;
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_id)))) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex 
                = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id;
        }
    } else {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex = 0U;
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_id)))) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex 
                = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_id;
        }
    } else {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex = 0U;
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_out_ex 
            = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_result;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state_q 
            = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state;
    } else {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_out_ex = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state_q = 0U;
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_id)))) {
            __Vdly__riscv_cpu_tb__DOT__dut__DOT__rd_ex 
                = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_ex;
        }
    } else {
        __Vdly__riscv_cpu_tb__DOT__dut__DOT__rd_ex = 0U;
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_i) {
            __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data__v0 
                = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_data_d;
            __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data__v0 = 1U;
            __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data__v0 
                = (0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                             >> 5U));
        }
    }
    if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)))) {
        vlTOPp->__Vdly__riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt = 0U;
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_i) {
            __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid__v0 = 1U;
            __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid__v0 
                = (0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                             >> 5U));
        }
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_i) {
            __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags__v0 
                = (0x1ffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                               >> 0xaU));
            __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags__v0 = 1U;
            __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags__v0 
                = (0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                             >> 5U));
        }
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_if)))) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_id 
                = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if;
        }
    } else {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_id = 0U;
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_d) {
            __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid__v0 = 1U;
            __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid__v0 
                = (0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                             >> 5U));
        }
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_d) {
            __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags__v0 
                = (0x1ffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                               >> 0xaU));
            __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags__v0 = 1U;
            __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags__v0 
                = (0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                             >> 5U));
        }
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_if)))) {
            vlTOPp->__Vdly__riscv_cpu_tb__DOT__dut__DOT__pc_if 
                = ((IData)(4U) + vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if);
        }
    } else {
        vlTOPp->__Vdly__riscv_cpu_tb__DOT__dut__DOT__pc_if = 0x80000000U;
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_d) {
            __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem__v0 = 1U;
        }
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_i) {
            __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem__v0 
                = (0x10000000000ULL | (((QData)((IData)(
                                                        (0xfffffU 
                                                         & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_vpn_i))) 
                                        << 0x14U) | (QData)((IData)(
                                                                    (0xfffffU 
                                                                     & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_ppn_i)))));
            __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem__v0 = 1U;
            __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem__v0 
                = (0xffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_i);
        }
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if ((((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write) 
              & (0U != (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_wb))) 
             & (0U != (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_wb)))) {
            __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs__v0 
                = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__wb_out;
            __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs__v0 = 1U;
            __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs__v0 
                = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_wb;
        }
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_d) {
            __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v0 = 1U;
            __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v0 
                = (0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                             >> 5U));
        } else {
            if ((((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT____Vcellinp__dcache__req) 
                  & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write)) 
                 & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache_hit))) {
                __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1 
                    = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__wr_data;
                __Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1 = 1U;
                __Vdlyvlsb__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1 = 0U;
                __Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1 
                    = (0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                 >> 5U));
            }
        }
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        if ((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_if)))) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                = ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit)
                    ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data
                   [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                               >> 5U))] : 0U);
        }
    } else {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id = 0U;
    }
    if (__Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid__v0) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid[__Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid__v0] = 1U;
    }
    if (__Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags__v0) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags[__Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags__v0] 
            = __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags__v0;
    }
    if (__Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid__v0) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid[__Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid__v0] = 1U;
    }
    if (__Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags__v0) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags[__Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags__v0] 
            = __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags__v0;
    }
    if (__Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem__v0) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem[0U] = 0x10000000000ULL;
    }
    if (__Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem__v0) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem[__Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem__v0] 
            = __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem__v0;
    }
    if (__Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs__v0) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[__Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs__v0] 
            = __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs__v0;
    }
    if (__Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data__v0) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data[__Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data__v0] 
            = __Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data__v0;
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_wb 
            = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__wb_out 
            = ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex)
                ? ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache_hit)
                    ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data
                   [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                               >> 5U))] : 0U) : vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex);
    } else {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_wb = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__wb_out = 0U;
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dec__DOT__a_instr 
        = ((0x2fU == (0x7fU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) 
           & (2U == (7U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                           >> 0xcU))));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write = 0U;
    if ((0x40U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
        if ((0x20U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
            if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write = 1U;
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
            if ((0x10U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write = 1U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write = 1U;
                            }
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write = 1U;
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write = 1U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write = 1U;
                            }
                        }
                    }
                }
            } else {
                if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__branch = 0U;
    if ((0x40U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
        if ((0x20U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
            if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__branch = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__jump = 0U;
    if ((0x40U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
        if ((0x20U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
            if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__jump = 1U;
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__jump = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id = 0U;
    if ((0x40U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
        if ((0x20U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
            if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id = 0U;
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id = 0U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id = 0U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
            if ((0x10U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id 
                                    = ((0x17U == (0x7fU 
                                                  & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id))
                                        ? 0U : 0xaU);
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id 
                                    = (7U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id = 0U;
                            }
                        }
                    }
                } else {
                    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id = 0U;
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id 
                                    = ((0x17U == (0x7fU 
                                                  & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id))
                                        ? 0U : 0xaU);
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id 
                                    = (7U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            } else {
                if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id = 0U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_op = 2U;
    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
            if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_op 
                                    = (3U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_op 
                                    = (3U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_id = (
                                                   (0x40U 
                                                    & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                    ? 
                                                   ((0x20U 
                                                     & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                     ? 
                                                    ((0x10U 
                                                      & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                       ? 
                                                      ((4U 
                                                        & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                        ? 
                                                       ((2U 
                                                         & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                          ? 
                                                         ((0xffe00000U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                             >> 0x1fU)))) 
                                                              << 0x15U)) 
                                                          | ((0x100000U 
                                                              & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                 >> 0xbU)) 
                                                             | ((0xff000U 
                                                                 & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id) 
                                                                | ((0x800U 
                                                                    & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                       >> 9U)) 
                                                                   | (0x7feU 
                                                                      & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                         >> 0x14U))))))
                                                          : 0U)
                                                         : 0U)
                                                        : 0U)
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                          ? 
                                                         ((0xffffe000U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                             >> 0x1fU)))) 
                                                              << 0xdU)) 
                                                          | ((0x1000U 
                                                              & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                 >> 0x13U)) 
                                                             | ((0x800U 
                                                                 & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                    << 4U)) 
                                                                | ((0x7e0U 
                                                                    & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                       >> 0x14U)) 
                                                                   | (0x1eU 
                                                                      & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                         >> 7U))))))
                                                          : 0U)
                                                         : 0U))))
                                                     : 0U)
                                                    : 
                                                   ((0x20U 
                                                     & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                     ? 
                                                    ((0x10U 
                                                      & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                      ? 
                                                     ((8U 
                                                       & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                        ? 
                                                       ((2U 
                                                         & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                          ? 
                                                         (0xfffff000U 
                                                          & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                          : 0U)
                                                         : 0U)
                                                        : 
                                                       ((2U 
                                                         & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                          ? 
                                                         ((0xfffff000U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                             >> 0x1fU)))) 
                                                              << 0xcU)) 
                                                          | (0xfffU 
                                                             & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                >> 0x14U)))
                                                          : 0U)
                                                         : 0U)))
                                                      : 
                                                     ((8U 
                                                       & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                          ? 
                                                         ((0xfffff000U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                             >> 0x1fU)))) 
                                                              << 0xcU)) 
                                                          | (0xfffU 
                                                             & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                >> 0x14U)))
                                                          : 0U)
                                                         : 0U))))
                                                     : 
                                                    ((0x10U 
                                                      & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                      ? 
                                                     ((8U 
                                                       & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                        ? 
                                                       ((2U 
                                                         & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                          ? 
                                                         (0xfffff000U 
                                                          & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                          : 0U)
                                                         : 0U)
                                                        : 
                                                       ((2U 
                                                         & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                          ? 
                                                         ((0xfffff000U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                             >> 0x1fU)))) 
                                                              << 0xcU)) 
                                                          | (0xfffU 
                                                             & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                >> 0x14U)))
                                                          : 0U)
                                                         : 0U)))
                                                      : 
                                                     ((8U 
                                                       & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)
                                                          ? 
                                                         ((0xfffff000U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                             >> 0x1fU)))) 
                                                              << 0xcU)) 
                                                          | (0xfffU 
                                                             & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                                >> 0x14U)))
                                                          : 0U)
                                                         : 0U))))));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write = 0U;
    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
            if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write = 1U;
                            }
                        }
                    }
                } else {
                    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    if (__Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v0) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data[__Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v0] = 0U;
    }
    if (__Vdlyvset__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data[__Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1] 
            = (((~ ((IData)(0xffffffffU) << (IData)(__Vdlyvlsb__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1))) 
                & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data
                [__Vdlyvdim0__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1]) 
               | (__Vdlyvval__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1 
                  << (IData)(__Vdlyvlsb__riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data__v1)));
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex = 0U;
    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
            if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                    if ((4U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex = 1U;
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                            if ((1U & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) {
                                vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->riscv_cpu_tb__DOT__rst_n) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem 
            = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_ex;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
            = vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_result;
    } else {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem = 0U;
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex = 0U;
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT____Vcellinp__dcache__req 
        = ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write) 
           | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_ex = __Vdly__riscv_cpu_tb__DOT__dut__DOT__rd_ex;
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs2 = 0U;
    if (((0U != (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_ex)) 
         & ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_ex) 
            == (0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                         >> 0x14U))))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs2 = 1U;
    } else {
        if (((0U != (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem)) 
             & ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem) 
                == (0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                             >> 0x14U))))) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs2 = 2U;
        }
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs1 = 0U;
    if (((0U != (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_ex)) 
         & ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_ex) 
            == (0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                         >> 0xfU))))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs1 = 1U;
    } else {
        if (((0U != (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem)) 
             & ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem) 
                == (0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                             >> 0xfU))))) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs1 = 2U;
        }
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb_hit = 
        ((((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write) 
           | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex)) 
          & (IData)((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem
                     [(0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                >> 0xcU))] >> 0x28U))) 
         & ((0xfffffU & (IData)((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem
                                 [(0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                            >> 0xcU))] 
                                 >> 0x14U))) == (0xfffffU 
                                                 & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                                    >> 0xcU))));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex = (
                                                   (1U 
                                                    == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs1))
                                                    ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_out_ex
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs1))
                                                     ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex
                                                     : 
                                                    ((0U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                          >> 0xfU)))
                                                      ? 0U
                                                      : 
                                                     vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs
                                                     [
                                                     (0x1fU 
                                                      & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                         >> 0xfU))])));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__tlb_miss_d 
        = (((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write) 
            | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex)) 
           & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb_hit)));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d = 
        ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb_hit)
          ? ((0xfffff000U & ((IData)((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem
                                      [(0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                                 >> 0xcU))] 
                                      >> 0x14U)) << 0xcU)) 
             | (0xfffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex))
          : 0U);
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_result 
        = ((8U & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
            ? ((4U & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                ? 0U : ((2U & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                         ? ((1U & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                             ? 0U : vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex)
                         : ((1U & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                             ? (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex 
                                & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex)
                             : (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex 
                                | vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex))))
            : ((4U & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                ? ((2U & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                    ? ((1U & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                        ? VL_SHIFTRS_III(32,32,5, vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex, 
                                         (0x1fU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex))
                        : (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex 
                           >> (0x1fU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex)))
                    : ((1U & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                        ? (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex 
                           ^ vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex)
                        : ((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex 
                            < vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex)
                            ? 1U : 0U))) : ((2U & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                                             ? ((1U 
                                                 & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                                                 ? 
                                                (VL_LTS_III(1,32,32, vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex, vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex)
                                                  ? 1U
                                                  : 0U)
                                                 : 
                                                (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex 
                                                 << 
                                                 (0x1fU 
                                                  & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex)))
                                             : ((1U 
                                                 & (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex))
                                                 ? 
                                                (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex 
                                                 - vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex)
                                                 : 
                                                (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex 
                                                 + vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex)))));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache_hit 
        = (((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT____Vcellinp__dcache__req) 
            & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__valid
            [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                        >> 5U))]) & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags
                                     [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                                 >> 5U))] 
                                     == (0x1ffffU & 
                                         (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                          >> 0xaU))));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__cache_miss_d 
        = (((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write) 
            | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex)) 
           & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache_hit)));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__miss_d_wire 
        = ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__tlb_miss_d) 
           | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__cache_miss_d));
}

VL_INLINE_OPT void Vriscv_cpu_tb::_sequent__TOP__5(Vriscv_cpu_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_cpu_tb::_sequent__TOP__5\n"); );
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt 
        = (((1U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state)) 
            | (2U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state)))
            ? ((IData)(vlTOPp->riscv_cpu_tb__DOT__mem_ready)
                ? (7U & ((IData)(1U) + (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt)))
                : 0U) : 0U);
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_data_d 
        = vlTOPp->riscv_cpu_tb__DOT__mem_rdata;
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_vpn_i 
        = (0xfffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                       >> 0xcU));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_ppn_i 
        = (0xfffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                       >> 0xcU));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_i 
        = (0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                    >> 0xcU));
    vlTOPp->riscv_cpu_tb__DOT__mem_ready = vlTOPp->riscv_cpu_tb__DOT__mem_req;
    vlTOPp->riscv_cpu_tb__DOT__mem_rdata = 0U;
}

VL_INLINE_OPT void Vriscv_cpu_tb::_sequent__TOP__6(Vriscv_cpu_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_cpu_tb::_sequent__TOP__6\n"); );
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt 
        = vlTOPp->__Vdly__riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt;
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if = vlTOPp->__Vdly__riscv_cpu_tb__DOT__dut__DOT__pc_if;
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state 
        = ((IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)
            ? (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__next_state)
            : 0U);
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_id = ((IData)(4U) 
                                                  + vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if);
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit = 
        ((IData)((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem
                  [(0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                             >> 0xcU))] >> 0x28U)) 
         & ((0xfffffU & (IData)((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem
                                 [(0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                            >> 0xcU))] 
                                 >> 0x14U))) == (0xfffffU 
                                                 & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                                    >> 0xcU))));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i = 
        ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit)
          ? ((0xfffff000U & ((IData)((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem
                                      [(0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                                 >> 0xcU))] 
                                      >> 0x14U)) << 0xcU)) 
             | (0xfffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if))
          : 0U);
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_i 
        = ((1U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state_q)) 
           & (3U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state)));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_d 
        = ((2U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state_q)) 
           & (3U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state)));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit 
        = (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__valid
           [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                       >> 5U))] & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags
                                   [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                               >> 5U))] 
                                   == (0x1ffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                                   >> 0xaU))));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__miss_i_wire 
        = (1U & ((~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit)) 
                 | (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit))));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__hu__DOT__stall_mem = 0U;
    if ((1U & ((((~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit)) 
                 | (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit))) 
                | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__tlb_miss_d)) 
               | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__cache_miss_d)))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__hu__DOT__stall_mem = 1U;
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__hu__DOT__stall_ex = 0U;
    if ((1U & ((((~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit)) 
                 | (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit))) 
                | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__tlb_miss_d)) 
               | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__cache_miss_d)))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__hu__DOT__stall_ex = 1U;
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_id = 0U;
    if ((1U & ((((~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit)) 
                 | (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit))) 
                | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__tlb_miss_d)) 
               | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__cache_miss_d)))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_id = 1U;
    }
    if (((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex) 
         & (0U != (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem)))) {
        if (((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem) 
             == (0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 0x14U)))) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_id = 1U;
        }
    }
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_if = 0U;
    if ((1U & ((((~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit)) 
                 | (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit))) 
                | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__tlb_miss_d)) 
               | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__cache_miss_d)))) {
        vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_if = 1U;
    }
    if (((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex) 
         & (0U != (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem)))) {
        if (((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem) 
             == (0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                          >> 0xfU)))) {
            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_if = 1U;
        }
    }
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__miss_d_wire) 
                             << 7U) | (((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__miss_i_wire) 
                                        << 6U) | (((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt) 
                                                   << 3U) 
                                                  | (((IData)(vlTOPp->riscv_cpu_tb__DOT__mem_ready) 
                                                      << 2U) 
                                                     | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state)))));
    vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__next_state 
        = vlTOPp->__Vtable1_riscv_cpu_tb__DOT__dut__DOT__mc__DOT__next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->riscv_cpu_tb__DOT__mem_req = vlTOPp->__Vtable1_riscv_cpu_tb__DOT__mem_req
        [vlTOPp->__Vtableidx1];
    vlTOPp->riscv_cpu_tb__DOT__mem_we = vlTOPp->__Vtable1_riscv_cpu_tb__DOT__mem_we
        [vlTOPp->__Vtableidx1];
}

void Vriscv_cpu_tb::_eval(Vriscv_cpu_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_cpu_tb::_eval\n"); );
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->riscv_cpu_tb__DOT__clk) & 
         (~ (IData)(vlTOPp->__Vclklast__TOP__riscv_cpu_tb__DOT__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlTOPp->riscv_cpu_tb__DOT__clk) & 
          (~ (IData)(vlTOPp->__Vclklast__TOP__riscv_cpu_tb__DOT__clk))) 
         | ((~ (IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP__riscv_cpu_tb__DOT__rst_n)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->riscv_cpu_tb__DOT__clk) & 
         (~ (IData)(vlTOPp->__Vclklast__TOP__riscv_cpu_tb__DOT__clk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    if ((((IData)(vlTOPp->riscv_cpu_tb__DOT__clk) & 
          (~ (IData)(vlTOPp->__Vclklast__TOP__riscv_cpu_tb__DOT__clk))) 
         | ((~ (IData)(vlTOPp->riscv_cpu_tb__DOT__rst_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP__riscv_cpu_tb__DOT__rst_n)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__riscv_cpu_tb__DOT__clk 
        = vlTOPp->riscv_cpu_tb__DOT__clk;
    vlTOPp->__Vclklast__TOP__riscv_cpu_tb__DOT__rst_n 
        = vlTOPp->riscv_cpu_tb__DOT__rst_n;
}

VL_INLINE_OPT QData Vriscv_cpu_tb::_change_request(Vriscv_cpu_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_cpu_tb::_change_request\n"); );
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vriscv_cpu_tb::_change_request_1(Vriscv_cpu_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_cpu_tb::_change_request_1\n"); );
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vriscv_cpu_tb::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_cpu_tb::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
