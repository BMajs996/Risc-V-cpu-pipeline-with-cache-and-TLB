// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_cpu_tb__Syms.h"


void Vriscv_cpu_tb::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_cpu_tb__Syms* __restrict vlSymsp = static_cast<Vriscv_cpu_tb__Syms*>(userp);
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vriscv_cpu_tb::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_cpu_tb__Syms* __restrict vlSymsp = static_cast<Vriscv_cpu_tb__Syms*>(userp);
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgBit(oldp+0,(vlTOPp->riscv_cpu_tb__DOT__clk));
            tracep->chgBit(oldp+1,(vlTOPp->riscv_cpu_tb__DOT__rst_n));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+2,(vlTOPp->riscv_cpu_tb__DOT__mem_addr),32);
            tracep->chgIData(oldp+3,(vlTOPp->riscv_cpu_tb__DOT__cycle_cnt),32);
            tracep->chgIData(oldp+4,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_d),32);
            tracep->chgIData(oldp+5,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__addr_reg),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+6,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id),32);
            tracep->chgCData(oldp+7,((0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                               >> 0xfU))),5);
            tracep->chgCData(oldp+8,((0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                               >> 0x14U))),5);
            tracep->chgCData(oldp+9,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_ex),5);
            tracep->chgCData(oldp+10,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem),5);
            tracep->chgCData(oldp+11,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_wb),5);
            tracep->chgBit(oldp+12,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex));
            tracep->chgBit(oldp+13,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write));
            tracep->chgBit(oldp+14,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write));
            tracep->chgBit(oldp+15,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__branch));
            tracep->chgBit(oldp+16,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__jump));
            tracep->chgIData(oldp+17,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_id),32);
            tracep->chgIData(oldp+18,(((0U == (0x1fU 
                                               & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                  >> 0xfU)))
                                        ? 0U : vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs
                                       [(0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                  >> 0xfU))])),32);
            tracep->chgIData(oldp+19,(((0U == (0x1fU 
                                               & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                  >> 0x14U)))
                                        ? 0U : vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs
                                       [(0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                  >> 0x14U))])),32);
            tracep->chgIData(oldp+20,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex),32);
            tracep->chgIData(oldp+21,(((1U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs2))
                                        ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_out_ex
                                        : ((2U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs2))
                                            ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex
                                            : ((0U 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                    >> 0x14U)))
                                                ? 0U
                                                : vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs
                                               [(0x1fU 
                                                 & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                    >> 0x14U))])))),32);
            tracep->chgIData(oldp+22,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_result),32);
            tracep->chgIData(oldp+23,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex),32);
            tracep->chgIData(oldp+24,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_out_ex),32);
            tracep->chgIData(oldp+25,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex),32);
            tracep->chgIData(oldp+26,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex)
                                        ? ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache_hit)
                                            ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data
                                           [(0x3ffU 
                                             & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                                >> 5U))]
                                            : 0U) : vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex)),32);
            tracep->chgIData(oldp+27,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__wb_out),32);
            tracep->chgCData(oldp+28,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id),4);
            tracep->chgCData(oldp+29,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex),4);
            tracep->chgCData(oldp+30,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_op),2);
            tracep->chgCData(oldp+31,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs1),2);
            tracep->chgCData(oldp+32,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs2),2);
            tracep->chgBit(oldp+33,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__tlb_miss_d));
            tracep->chgBit(oldp+34,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__cache_miss_d));
            tracep->chgBit(oldp+35,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb_hit));
            tracep->chgBit(oldp+36,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache_hit));
            tracep->chgIData(oldp+37,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d),32);
            tracep->chgIData(oldp+38,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache_hit)
                                        ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data
                                       [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                                   >> 5U))]
                                        : 0U)),32);
            tracep->chgBit(oldp+39,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__miss_d_wire));
            tracep->chgIData(oldp+40,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__unnamedblk1__DOT__i),32);
            tracep->chgIData(oldp+41,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__unnamedblk1__DOT__i),32);
            tracep->chgBit(oldp+42,(((0x33U == (0x7fU 
                                                & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) 
                                     & ((1U == (0x3fU 
                                                & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                   >> 0x19U))) 
                                        | (5U == (0x3fU 
                                                  & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                     >> 0x19U)))))));
            tracep->chgBit(oldp+43,(((0x33U == (0x7fU 
                                                & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) 
                                     & (5U == (0x3fU 
                                               & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                  >> 0x19U))))));
            tracep->chgBit(oldp+44,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dec__DOT__a_instr));
            tracep->chgBit(oldp+45,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dec__DOT__a_instr) 
                                     & (2U == (0x3fU 
                                               & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                  >> 0x19U))))));
            tracep->chgBit(oldp+46,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dec__DOT__a_instr) 
                                     & (3U == (0x3fU 
                                               & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                  >> 0x19U))))));
            tracep->chgBit(oldp+47,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dec__DOT__a_instr) 
                                     & (0x38U >= (0x3fU 
                                                  & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                     >> 0x19U))))));
            tracep->chgCData(oldp+48,((0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                >> 0x19U))),5);
            tracep->chgCData(oldp+49,((0x7fU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)),7);
            tracep->chgCData(oldp+50,((7U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+51,((0x7fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                >> 0x19U))),7);
            tracep->chgBit(oldp+52,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write) 
                                     & (0U != (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_wb)))));
            tracep->chgIData(oldp+53,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0]),32);
            tracep->chgIData(oldp+54,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[1]),32);
            tracep->chgIData(oldp+55,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[2]),32);
            tracep->chgIData(oldp+56,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[3]),32);
            tracep->chgIData(oldp+57,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[4]),32);
            tracep->chgIData(oldp+58,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[5]),32);
            tracep->chgIData(oldp+59,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[6]),32);
            tracep->chgIData(oldp+60,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[7]),32);
            tracep->chgIData(oldp+61,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[8]),32);
            tracep->chgIData(oldp+62,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[9]),32);
            tracep->chgIData(oldp+63,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[10]),32);
            tracep->chgIData(oldp+64,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[11]),32);
            tracep->chgIData(oldp+65,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[12]),32);
            tracep->chgIData(oldp+66,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[13]),32);
            tracep->chgIData(oldp+67,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[14]),32);
            tracep->chgIData(oldp+68,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[15]),32);
            tracep->chgIData(oldp+69,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[16]),32);
            tracep->chgIData(oldp+70,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[17]),32);
            tracep->chgIData(oldp+71,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[18]),32);
            tracep->chgIData(oldp+72,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[19]),32);
            tracep->chgIData(oldp+73,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[20]),32);
            tracep->chgIData(oldp+74,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[21]),32);
            tracep->chgIData(oldp+75,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[22]),32);
            tracep->chgIData(oldp+76,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[23]),32);
            tracep->chgIData(oldp+77,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[24]),32);
            tracep->chgIData(oldp+78,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[25]),32);
            tracep->chgIData(oldp+79,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[26]),32);
            tracep->chgIData(oldp+80,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[27]),32);
            tracep->chgIData(oldp+81,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[28]),32);
            tracep->chgIData(oldp+82,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[29]),32);
            tracep->chgIData(oldp+83,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[30]),32);
            tracep->chgIData(oldp+84,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[31]),32);
            tracep->chgIData(oldp+85,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__unnamedblk1__DOT__i),32);
            tracep->chgBit(oldp+86,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write) 
                                     | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex))));
            tracep->chgCData(oldp+87,((0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                                >> 0xcU))),8);
            tracep->chgIData(oldp+88,((0xfffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                                   >> 0xcU))),20);
            tracep->chgBit(oldp+89,(((0xfffffU & (IData)(
                                                         (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem
                                                          [
                                                          (0xffU 
                                                           & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                                              >> 0xcU))] 
                                                          >> 0x14U))) 
                                     == (0xfffffU & 
                                         (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                          >> 0xcU)))));
            tracep->chgBit(oldp+90,((1U & (IData)((
                                                   vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem
                                                   [
                                                   (0xffU 
                                                    & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                                       >> 0xcU))] 
                                                   >> 0x28U)))));
            tracep->chgIData(oldp+91,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__unnamedblk1__DOT__i),32);
            tracep->chgBit(oldp+92,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT____Vcellinp__dcache__req));
            tracep->chgSData(oldp+93,((0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                                 >> 5U))),10);
            tracep->chgIData(oldp+94,((0x1ffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                                   >> 0xaU))),17);
            tracep->chgCData(oldp+95,((7U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                             >> 2U))),4);
            tracep->chgBit(oldp+96,((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags
                                     [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                                 >> 5U))] 
                                     == (0x1ffffU & 
                                         (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                          >> 0xaU)))));
            tracep->chgIData(oldp+97,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__unnamedblk1__DOT__i),32);
            tracep->chgCData(oldp+98,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state_q),2);
        }
        if (VL_UNLIKELY((vlTOPp->__Vm_traceActivity
                         [2U] | vlTOPp->__Vm_traceActivity
                         [4U]))) {
            tracep->chgBit(oldp+99,(vlTOPp->riscv_cpu_tb__DOT__mem_we));
            tracep->chgIData(oldp+100,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_id),32);
            tracep->chgIData(oldp+101,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit)
                                         ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data
                                        [(0x3ffU & 
                                          (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                           >> 5U))]
                                         : 0U)),32);
            tracep->chgBit(oldp+102,(((0xfffffU & (IData)(
                                                          (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem
                                                           [
                                                           (0xffU 
                                                            & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                                               >> 0xcU))] 
                                                           >> 0x14U))) 
                                      == (0xfffffU 
                                          & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                             >> 0xcU)))));
            tracep->chgBit(oldp+103,((1U & (IData)(
                                                   (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem
                                                    [
                                                    (0xffU 
                                                     & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                                        >> 0xcU))] 
                                                    >> 0x28U)))));
            tracep->chgBit(oldp+104,((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags
                                      [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                                  >> 5U))] 
                                      == (0x1ffffU 
                                          & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                             >> 0xaU)))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgIData(oldp+105,(vlTOPp->riscv_cpu_tb__DOT__mem_rdata),32);
            tracep->chgBit(oldp+106,(vlTOPp->riscv_cpu_tb__DOT__mem_ready));
            tracep->chgIData(oldp+107,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_i),32);
            tracep->chgIData(oldp+108,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_vpn_i),32);
            tracep->chgIData(oldp+109,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_ppn_i),32);
            tracep->chgIData(oldp+110,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_data_d),32);
            tracep->chgCData(oldp+111,((0xffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_i)),8);
            tracep->chgIData(oldp+112,((0xfffffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_vpn_i)),20);
            tracep->chgIData(oldp+113,((0xfffffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_ppn_i)),20);
            tracep->chgSData(oldp+114,((0x3ffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_i)),10);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgBit(oldp+115,(vlTOPp->riscv_cpu_tb__DOT__mem_req));
            tracep->chgIData(oldp+116,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if),32);
            tracep->chgBit(oldp+117,((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_if)))));
            tracep->chgBit(oldp+118,((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_id)))));
            tracep->chgBit(oldp+119,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_if));
            tracep->chgBit(oldp+120,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_id));
            tracep->chgBit(oldp+121,((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit)))));
            tracep->chgBit(oldp+122,((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit)))));
            tracep->chgBit(oldp+123,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit));
            tracep->chgBit(oldp+124,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit));
            tracep->chgIData(oldp+125,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i),32);
            tracep->chgBit(oldp+126,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_i));
            tracep->chgBit(oldp+127,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_d));
            tracep->chgBit(oldp+128,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__miss_i_wire));
            tracep->chgCData(oldp+129,((0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                                 >> 0xcU))),8);
            tracep->chgIData(oldp+130,((0xfffffU & 
                                        (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                         >> 0xcU))),20);
            tracep->chgSData(oldp+131,((0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                                  >> 5U))),10);
            tracep->chgIData(oldp+132,((0x1ffffU & 
                                        (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                         >> 0xaU))),17);
            tracep->chgCData(oldp+133,((7U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                              >> 2U))),4);
            tracep->chgBit(oldp+134,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__hu__DOT__stall_ex));
            tracep->chgBit(oldp+135,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__hu__DOT__stall_mem));
            tracep->chgCData(oldp+136,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state),2);
            tracep->chgCData(oldp+137,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__next_state),2);
            tracep->chgCData(oldp+138,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt),3);
        }
    }
}

void Vriscv_cpu_tb::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vriscv_cpu_tb__Syms* __restrict vlSymsp = static_cast<Vriscv_cpu_tb__Syms*>(userp);
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
    }
}
