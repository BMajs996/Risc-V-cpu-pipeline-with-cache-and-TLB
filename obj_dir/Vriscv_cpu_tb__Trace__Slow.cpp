// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_cpu_tb__Syms.h"


//======================

void Vriscv_cpu_tb::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vriscv_cpu_tb::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vriscv_cpu_tb__Syms* __restrict vlSymsp = static_cast<Vriscv_cpu_tb__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vriscv_cpu_tb::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vriscv_cpu_tb::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vriscv_cpu_tb__Syms* __restrict vlSymsp = static_cast<Vriscv_cpu_tb__Syms*>(userp);
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vriscv_cpu_tb::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_cpu_tb__Syms* __restrict vlSymsp = static_cast<Vriscv_cpu_tb__Syms*>(userp);
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"riscv_cpu_tb clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb rst_n", false,-1);
        tracep->declBus(c+106,"riscv_cpu_tb mem_rdata", false,-1, 31,0);
        tracep->declBit(c+107,"riscv_cpu_tb mem_ready", false,-1);
        tracep->declBus(c+3,"riscv_cpu_tb mem_addr", false,-1, 31,0);
        tracep->declBus(c+140,"riscv_cpu_tb mem_wdata", false,-1, 31,0);
        tracep->declBit(c+116,"riscv_cpu_tb mem_req", false,-1);
        tracep->declBit(c+100,"riscv_cpu_tb mem_we", false,-1);
        tracep->declBus(c+4,"riscv_cpu_tb cycle_cnt", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut XLEN", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut VA_W", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut PA_W", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut rst_n", false,-1);
        tracep->declBus(c+106,"riscv_cpu_tb dut mem_rdata", false,-1, 31,0);
        tracep->declBit(c+107,"riscv_cpu_tb dut mem_ready", false,-1);
        tracep->declBus(c+3,"riscv_cpu_tb dut mem_addr", false,-1, 31,0);
        tracep->declBus(c+140,"riscv_cpu_tb dut mem_wdata", false,-1, 31,0);
        tracep->declBit(c+116,"riscv_cpu_tb dut mem_req", false,-1);
        tracep->declBit(c+100,"riscv_cpu_tb dut mem_we", false,-1);
        tracep->declBus(c+117,"riscv_cpu_tb dut pc_if", false,-1, 31,0);
        tracep->declBus(c+101,"riscv_cpu_tb dut pc_id", false,-1, 31,0);
        tracep->declBus(c+102,"riscv_cpu_tb dut inst_fetch", false,-1, 31,0);
        tracep->declBus(c+7,"riscv_cpu_tb dut inst_id", false,-1, 31,0);
        tracep->declBus(c+8,"riscv_cpu_tb dut rs1_id", false,-1, 4,0);
        tracep->declBus(c+9,"riscv_cpu_tb dut rs2_id", false,-1, 4,0);
        tracep->declBus(c+10,"riscv_cpu_tb dut rd_ex", false,-1, 4,0);
        tracep->declBus(c+11,"riscv_cpu_tb dut rd_mem", false,-1, 4,0);
        tracep->declBus(c+12,"riscv_cpu_tb dut rd_wb", false,-1, 4,0);
        tracep->declBit(c+13,"riscv_cpu_tb dut mem_read_ex", false,-1);
        tracep->declBit(c+14,"riscv_cpu_tb dut reg_write", false,-1);
        tracep->declBit(c+15,"riscv_cpu_tb dut mem_write", false,-1);
        tracep->declBit(c+16,"riscv_cpu_tb dut branch", false,-1);
        tracep->declBit(c+17,"riscv_cpu_tb dut jump", false,-1);
        tracep->declBus(c+18,"riscv_cpu_tb dut imm_id", false,-1, 31,0);
        tracep->declBus(c+19,"riscv_cpu_tb dut rs1_raw", false,-1, 31,0);
        tracep->declBus(c+20,"riscv_cpu_tb dut rs2_raw", false,-1, 31,0);
        tracep->declBus(c+21,"riscv_cpu_tb dut rs1_ex", false,-1, 31,0);
        tracep->declBus(c+22,"riscv_cpu_tb dut rs2_ex", false,-1, 31,0);
        tracep->declBus(c+23,"riscv_cpu_tb dut alu_result", false,-1, 31,0);
        tracep->declBus(c+24,"riscv_cpu_tb dut imm_ex", false,-1, 31,0);
        tracep->declBus(c+25,"riscv_cpu_tb dut alu_out_ex", false,-1, 31,0);
        tracep->declBus(c+26,"riscv_cpu_tb dut mem_out_ex", false,-1, 31,0);
        tracep->declBus(c+27,"riscv_cpu_tb dut wb_data", false,-1, 31,0);
        tracep->declBus(c+28,"riscv_cpu_tb dut wb_out", false,-1, 31,0);
        tracep->declBus(c+29,"riscv_cpu_tb dut alu_op_id", false,-1, 3,0);
        tracep->declBus(c+30,"riscv_cpu_tb dut alu_op_ex", false,-1, 3,0);
        tracep->declBus(c+31,"riscv_cpu_tb dut mem_op", false,-1, 1,0);
        tracep->declBus(c+32,"riscv_cpu_tb dut fwd_rs1", false,-1, 1,0);
        tracep->declBus(c+33,"riscv_cpu_tb dut fwd_rs2", false,-1, 1,0);
        tracep->declBit(c+118,"riscv_cpu_tb dut en_if_id", false,-1);
        tracep->declBit(c+119,"riscv_cpu_tb dut en_id_ex", false,-1);
        tracep->declBit(c+120,"riscv_cpu_tb dut stall_if", false,-1);
        tracep->declBit(c+121,"riscv_cpu_tb dut stall_id", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut flush_ex", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut flush_mem", false,-1);
        tracep->declBit(c+122,"riscv_cpu_tb dut tlb_miss_i", false,-1);
        tracep->declBit(c+123,"riscv_cpu_tb dut cache_miss_i", false,-1);
        tracep->declBit(c+34,"riscv_cpu_tb dut tlb_miss_d", false,-1);
        tracep->declBit(c+35,"riscv_cpu_tb dut cache_miss_d", false,-1);
        tracep->declBit(c+124,"riscv_cpu_tb dut itlb_hit", false,-1);
        tracep->declBit(c+125,"riscv_cpu_tb dut icache_hit", false,-1);
        tracep->declBit(c+36,"riscv_cpu_tb dut dtlb_hit", false,-1);
        tracep->declBit(c+37,"riscv_cpu_tb dut dcache_hit", false,-1);
        tracep->declBus(c+126,"riscv_cpu_tb dut paddr_i", false,-1, 31,0);
        tracep->declBus(c+38,"riscv_cpu_tb dut paddr_d", false,-1, 31,0);
        tracep->declBus(c+39,"riscv_cpu_tb dut dcache_rdata", false,-1, 31,0);
        tracep->declBit(c+127,"riscv_cpu_tb dut refill_done_i", false,-1);
        tracep->declBit(c+128,"riscv_cpu_tb dut refill_done_d", false,-1);
        tracep->declBus(c+108,"riscv_cpu_tb dut refill_idx_i", false,-1, 31,0);
        tracep->declBus(c+109,"riscv_cpu_tb dut refill_vpn_i", false,-1, 31,0);
        tracep->declBus(c+110,"riscv_cpu_tb dut refill_ppn_i", false,-1, 31,0);
        tracep->declBus(c+5,"riscv_cpu_tb dut refill_idx_d", false,-1, 31,0);
        tracep->declBus(c+111,"riscv_cpu_tb dut refill_data_d", false,-1, 31,0);
        tracep->declBit(c+129,"riscv_cpu_tb dut miss_i_wire", false,-1);
        tracep->declBit(c+40,"riscv_cpu_tb dut miss_d_wire", false,-1);
        tracep->declBus(c+141,"riscv_cpu_tb dut if_id_pc WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut if_id_pc clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut if_id_pc rst_n", false,-1);
        tracep->declBit(c+118,"riscv_cpu_tb dut if_id_pc en", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut if_id_pc flush", false,-1);
        tracep->declBus(c+117,"riscv_cpu_tb dut if_id_pc d", false,-1, 31,0);
        tracep->declBus(c+101,"riscv_cpu_tb dut if_id_pc q", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut if_id_inst WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut if_id_inst clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut if_id_inst rst_n", false,-1);
        tracep->declBit(c+118,"riscv_cpu_tb dut if_id_inst en", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut if_id_inst flush", false,-1);
        tracep->declBus(c+102,"riscv_cpu_tb dut if_id_inst d", false,-1, 31,0);
        tracep->declBus(c+7,"riscv_cpu_tb dut if_id_inst q", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut itlb VA_W", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut itlb PA_W", false,-1, 31,0);
        tracep->declBus(c+143,"riscv_cpu_tb dut itlb OFFSET_W", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_cpu_tb dut itlb NUM_ENTRIES", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut itlb clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut itlb rst_n", false,-1);
        tracep->declBit(c+145,"riscv_cpu_tb dut itlb req", false,-1);
        tracep->declBus(c+117,"riscv_cpu_tb dut itlb vaddr", false,-1, 31,0);
        tracep->declBit(c+124,"riscv_cpu_tb dut itlb hit", false,-1);
        tracep->declBus(c+126,"riscv_cpu_tb dut itlb paddr", false,-1, 31,0);
        tracep->declBit(c+127,"riscv_cpu_tb dut itlb refill_valid", false,-1);
        tracep->declBus(c+112,"riscv_cpu_tb dut itlb refill_idx", false,-1, 7,0);
        tracep->declBus(c+113,"riscv_cpu_tb dut itlb refill_vpn", false,-1, 19,0);
        tracep->declBus(c+114,"riscv_cpu_tb dut itlb refill_ppn", false,-1, 19,0);
        tracep->declBus(c+146,"riscv_cpu_tb dut itlb IDX_W", false,-1, 31,0);
        tracep->declBus(c+147,"riscv_cpu_tb dut itlb ENTRY_W", false,-1, 31,0);
        tracep->declBus(c+130,"riscv_cpu_tb dut itlb idx", false,-1, 7,0);
        tracep->declBus(c+131,"riscv_cpu_tb dut itlb vpn", false,-1, 19,0);
        tracep->declBit(c+103,"riscv_cpu_tb dut itlb tag_match", false,-1);
        tracep->declBit(c+104,"riscv_cpu_tb dut itlb valid_bit", false,-1);
        tracep->declBus(c+41,"riscv_cpu_tb dut itlb unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut icache ADDR_W", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut icache DATA_W", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut icache LINE_SIZE", false,-1, 31,0);
        tracep->declBus(c+148,"riscv_cpu_tb dut icache NUM_LINES", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut icache clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut icache rst_n", false,-1);
        tracep->declBit(c+145,"riscv_cpu_tb dut icache req", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut icache wr_en", false,-1);
        tracep->declBus(c+126,"riscv_cpu_tb dut icache addr", false,-1, 31,0);
        tracep->declBus(c+149,"riscv_cpu_tb dut icache wr_data", false,-1, 31,0);
        tracep->declBit(c+125,"riscv_cpu_tb dut icache hit", false,-1);
        tracep->declBus(c+102,"riscv_cpu_tb dut icache rd_data", false,-1, 31,0);
        tracep->declBit(c+127,"riscv_cpu_tb dut icache refill_valid", false,-1);
        tracep->declBus(c+115,"riscv_cpu_tb dut icache refill_idx", false,-1, 9,0);
        tracep->declBus(c+111,"riscv_cpu_tb dut icache refill_data", false,-1, 31,0);
        tracep->declBus(c+150,"riscv_cpu_tb dut icache OFFSET_W", false,-1, 31,0);
        tracep->declBus(c+151,"riscv_cpu_tb dut icache IDX_W", false,-1, 31,0);
        tracep->declBus(c+152,"riscv_cpu_tb dut icache TAG_W", false,-1, 31,0);
        tracep->declBus(c+132,"riscv_cpu_tb dut icache idx", false,-1, 9,0);
        tracep->declBus(c+133,"riscv_cpu_tb dut icache tag", false,-1, 16,0);
        tracep->declBus(c+134,"riscv_cpu_tb dut icache word_off", false,-1, 3,0);
        tracep->declBit(c+105,"riscv_cpu_tb dut icache tag_match", false,-1);
        tracep->declBus(c+42,"riscv_cpu_tb dut icache unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+7,"riscv_cpu_tb dut dec inst", false,-1, 31,0);
        tracep->declBus(c+8,"riscv_cpu_tb dut dec rs1", false,-1, 4,0);
        tracep->declBus(c+9,"riscv_cpu_tb dut dec rs2", false,-1, 4,0);
        tracep->declBus(c+10,"riscv_cpu_tb dut dec rd", false,-1, 4,0);
        tracep->declBus(c+18,"riscv_cpu_tb dut dec imm", false,-1, 31,0);
        tracep->declBit(c+14,"riscv_cpu_tb dut dec reg_write", false,-1);
        tracep->declBit(c+13,"riscv_cpu_tb dut dec mem_read", false,-1);
        tracep->declBit(c+15,"riscv_cpu_tb dut dec mem_write", false,-1);
        tracep->declBit(c+16,"riscv_cpu_tb dut dec branch", false,-1);
        tracep->declBit(c+17,"riscv_cpu_tb dut dec jump", false,-1);
        tracep->declBus(c+29,"riscv_cpu_tb dut dec alu_op", false,-1, 3,0);
        tracep->declBus(c+31,"riscv_cpu_tb dut dec mem_op", false,-1, 1,0);
        tracep->declBit(c+43,"riscv_cpu_tb dut dec m_instr", false,-1);
        tracep->declBit(c+44,"riscv_cpu_tb dut dec div_instr", false,-1);
        tracep->declBit(c+45,"riscv_cpu_tb dut dec a_instr", false,-1);
        tracep->declBit(c+46,"riscv_cpu_tb dut dec lr_instr", false,-1);
        tracep->declBit(c+47,"riscv_cpu_tb dut dec sc_instr", false,-1);
        tracep->declBit(c+48,"riscv_cpu_tb dut dec amo_instr", false,-1);
        tracep->declBus(c+49,"riscv_cpu_tb dut dec amo_op", false,-1, 4,0);
        tracep->declBus(c+50,"riscv_cpu_tb dut dec opcode", false,-1, 6,0);
        tracep->declBus(c+51,"riscv_cpu_tb dut dec funct3", false,-1, 2,0);
        tracep->declBus(c+52,"riscv_cpu_tb dut dec funct7", false,-1, 6,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut rf XLEN", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut rf NUM_REGS", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut rf clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut rf rst_n", false,-1);
        tracep->declBus(c+8,"riscv_cpu_tb dut rf rs1", false,-1, 4,0);
        tracep->declBus(c+9,"riscv_cpu_tb dut rf rs2", false,-1, 4,0);
        tracep->declBus(c+12,"riscv_cpu_tb dut rf rd_wb", false,-1, 4,0);
        tracep->declBus(c+28,"riscv_cpu_tb dut rf wr_data_wb", false,-1, 31,0);
        tracep->declBit(c+53,"riscv_cpu_tb dut rf wr_en_wb", false,-1);
        tracep->declBus(c+19,"riscv_cpu_tb dut rf rd1", false,-1, 31,0);
        tracep->declBus(c+20,"riscv_cpu_tb dut rf rd2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+54+i*1,"riscv_cpu_tb dut rf regs", true,(i+0), 31,0);}}
        tracep->declBus(c+86,"riscv_cpu_tb dut rf unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut id_ex_imm WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut id_ex_imm clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut id_ex_imm rst_n", false,-1);
        tracep->declBit(c+119,"riscv_cpu_tb dut id_ex_imm en", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut id_ex_imm flush", false,-1);
        tracep->declBus(c+18,"riscv_cpu_tb dut id_ex_imm d", false,-1, 31,0);
        tracep->declBus(c+24,"riscv_cpu_tb dut id_ex_imm q", false,-1, 31,0);
        tracep->declBus(c+153,"riscv_cpu_tb dut id_ex_aluop WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut id_ex_aluop clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut id_ex_aluop rst_n", false,-1);
        tracep->declBit(c+119,"riscv_cpu_tb dut id_ex_aluop en", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut id_ex_aluop flush", false,-1);
        tracep->declBus(c+29,"riscv_cpu_tb dut id_ex_aluop d", false,-1, 3,0);
        tracep->declBus(c+30,"riscv_cpu_tb dut id_ex_aluop q", false,-1, 3,0);
        tracep->declBus(c+150,"riscv_cpu_tb dut id_ex_rd WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut id_ex_rd clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut id_ex_rd rst_n", false,-1);
        tracep->declBit(c+119,"riscv_cpu_tb dut id_ex_rd en", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut id_ex_rd flush", false,-1);
        tracep->declBus(c+10,"riscv_cpu_tb dut id_ex_rd d", false,-1, 4,0);
        tracep->declBus(c+10,"riscv_cpu_tb dut id_ex_rd q", false,-1, 4,0);
        tracep->declBus(c+150,"riscv_cpu_tb dut id_ex_rd_mem WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut id_ex_rd_mem clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut id_ex_rd_mem rst_n", false,-1);
        tracep->declBit(c+145,"riscv_cpu_tb dut id_ex_rd_mem en", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut id_ex_rd_mem flush", false,-1);
        tracep->declBus(c+10,"riscv_cpu_tb dut id_ex_rd_mem d", false,-1, 4,0);
        tracep->declBus(c+11,"riscv_cpu_tb dut id_ex_rd_mem q", false,-1, 4,0);
        tracep->declBus(c+150,"riscv_cpu_tb dut id_ex_rd_wb WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut id_ex_rd_wb clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut id_ex_rd_wb rst_n", false,-1);
        tracep->declBit(c+145,"riscv_cpu_tb dut id_ex_rd_wb en", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut id_ex_rd_wb flush", false,-1);
        tracep->declBus(c+11,"riscv_cpu_tb dut id_ex_rd_wb d", false,-1, 4,0);
        tracep->declBus(c+12,"riscv_cpu_tb dut id_ex_rd_wb q", false,-1, 4,0);
        tracep->declBus(c+21,"riscv_cpu_tb dut alu a", false,-1, 31,0);
        tracep->declBus(c+24,"riscv_cpu_tb dut alu b", false,-1, 31,0);
        tracep->declBus(c+30,"riscv_cpu_tb dut alu alu_op", false,-1, 3,0);
        tracep->declBus(c+23,"riscv_cpu_tb dut alu result", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut ex_mem_alu WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut ex_mem_alu clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut ex_mem_alu rst_n", false,-1);
        tracep->declBit(c+145,"riscv_cpu_tb dut ex_mem_alu en", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut ex_mem_alu flush", false,-1);
        tracep->declBus(c+23,"riscv_cpu_tb dut ex_mem_alu d", false,-1, 31,0);
        tracep->declBus(c+25,"riscv_cpu_tb dut ex_mem_alu q", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut ex_mem_out WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut ex_mem_out clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut ex_mem_out rst_n", false,-1);
        tracep->declBit(c+145,"riscv_cpu_tb dut ex_mem_out en", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut ex_mem_out flush", false,-1);
        tracep->declBus(c+23,"riscv_cpu_tb dut ex_mem_out d", false,-1, 31,0);
        tracep->declBus(c+26,"riscv_cpu_tb dut ex_mem_out q", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut dtlb VA_W", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut dtlb PA_W", false,-1, 31,0);
        tracep->declBus(c+143,"riscv_cpu_tb dut dtlb OFFSET_W", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_cpu_tb dut dtlb NUM_ENTRIES", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut dtlb clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut dtlb rst_n", false,-1);
        tracep->declBit(c+87,"riscv_cpu_tb dut dtlb req", false,-1);
        tracep->declBus(c+26,"riscv_cpu_tb dut dtlb vaddr", false,-1, 31,0);
        tracep->declBit(c+36,"riscv_cpu_tb dut dtlb hit", false,-1);
        tracep->declBus(c+38,"riscv_cpu_tb dut dtlb paddr", false,-1, 31,0);
        tracep->declBit(c+128,"riscv_cpu_tb dut dtlb refill_valid", false,-1);
        tracep->declBus(c+154,"riscv_cpu_tb dut dtlb refill_idx", false,-1, 7,0);
        tracep->declBus(c+155,"riscv_cpu_tb dut dtlb refill_vpn", false,-1, 19,0);
        tracep->declBus(c+155,"riscv_cpu_tb dut dtlb refill_ppn", false,-1, 19,0);
        tracep->declBus(c+146,"riscv_cpu_tb dut dtlb IDX_W", false,-1, 31,0);
        tracep->declBus(c+147,"riscv_cpu_tb dut dtlb ENTRY_W", false,-1, 31,0);
        tracep->declBus(c+88,"riscv_cpu_tb dut dtlb idx", false,-1, 7,0);
        tracep->declBus(c+89,"riscv_cpu_tb dut dtlb vpn", false,-1, 19,0);
        tracep->declBit(c+90,"riscv_cpu_tb dut dtlb tag_match", false,-1);
        tracep->declBit(c+91,"riscv_cpu_tb dut dtlb valid_bit", false,-1);
        tracep->declBus(c+92,"riscv_cpu_tb dut dtlb unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut dcache ADDR_W", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut dcache DATA_W", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut dcache LINE_SIZE", false,-1, 31,0);
        tracep->declBus(c+148,"riscv_cpu_tb dut dcache NUM_LINES", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut dcache clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut dcache rst_n", false,-1);
        tracep->declBit(c+93,"riscv_cpu_tb dut dcache req", false,-1);
        tracep->declBit(c+15,"riscv_cpu_tb dut dcache wr_en", false,-1);
        tracep->declBus(c+38,"riscv_cpu_tb dut dcache addr", false,-1, 31,0);
        tracep->declBus(c+156,"riscv_cpu_tb dut dcache wr_data", false,-1, 31,0);
        tracep->declBit(c+37,"riscv_cpu_tb dut dcache hit", false,-1);
        tracep->declBus(c+39,"riscv_cpu_tb dut dcache rd_data", false,-1, 31,0);
        tracep->declBit(c+128,"riscv_cpu_tb dut dcache refill_valid", false,-1);
        tracep->declBus(c+157,"riscv_cpu_tb dut dcache refill_idx", false,-1, 9,0);
        tracep->declBus(c+158,"riscv_cpu_tb dut dcache refill_data", false,-1, 31,0);
        tracep->declBus(c+150,"riscv_cpu_tb dut dcache OFFSET_W", false,-1, 31,0);
        tracep->declBus(c+151,"riscv_cpu_tb dut dcache IDX_W", false,-1, 31,0);
        tracep->declBus(c+152,"riscv_cpu_tb dut dcache TAG_W", false,-1, 31,0);
        tracep->declBus(c+94,"riscv_cpu_tb dut dcache idx", false,-1, 9,0);
        tracep->declBus(c+95,"riscv_cpu_tb dut dcache tag", false,-1, 16,0);
        tracep->declBus(c+96,"riscv_cpu_tb dut dcache word_off", false,-1, 3,0);
        tracep->declBit(c+97,"riscv_cpu_tb dut dcache tag_match", false,-1);
        tracep->declBus(c+98,"riscv_cpu_tb dut dcache unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+141,"riscv_cpu_tb dut mem_wb_data WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut mem_wb_data clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut mem_wb_data rst_n", false,-1);
        tracep->declBit(c+145,"riscv_cpu_tb dut mem_wb_data en", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut mem_wb_data flush", false,-1);
        tracep->declBus(c+27,"riscv_cpu_tb dut mem_wb_data d", false,-1, 31,0);
        tracep->declBus(c+28,"riscv_cpu_tb dut mem_wb_data q", false,-1, 31,0);
        tracep->declBus(c+8,"riscv_cpu_tb dut hu rs1_id", false,-1, 4,0);
        tracep->declBus(c+9,"riscv_cpu_tb dut hu rs2_id", false,-1, 4,0);
        tracep->declBus(c+10,"riscv_cpu_tb dut hu rd_ex", false,-1, 4,0);
        tracep->declBus(c+11,"riscv_cpu_tb dut hu rd_mem", false,-1, 4,0);
        tracep->declBus(c+12,"riscv_cpu_tb dut hu rd_wb", false,-1, 4,0);
        tracep->declBit(c+13,"riscv_cpu_tb dut hu mem_read_ex", false,-1);
        tracep->declBit(c+122,"riscv_cpu_tb dut hu tlb_miss_i", false,-1);
        tracep->declBit(c+123,"riscv_cpu_tb dut hu cache_miss_i", false,-1);
        tracep->declBit(c+34,"riscv_cpu_tb dut hu tlb_miss_d", false,-1);
        tracep->declBit(c+35,"riscv_cpu_tb dut hu cache_miss_d", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut hu branch_mispredict", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut hu exception_taken", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut hu m_busy", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut hu a_busy", false,-1);
        tracep->declBit(c+120,"riscv_cpu_tb dut hu stall_if", false,-1);
        tracep->declBit(c+121,"riscv_cpu_tb dut hu stall_id", false,-1);
        tracep->declBit(c+135,"riscv_cpu_tb dut hu stall_ex", false,-1);
        tracep->declBit(c+136,"riscv_cpu_tb dut hu stall_mem", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut hu flush_ex", false,-1);
        tracep->declBit(c+142,"riscv_cpu_tb dut hu flush_mem", false,-1);
        tracep->declBus(c+32,"riscv_cpu_tb dut hu fwd_rs1", false,-1, 1,0);
        tracep->declBus(c+33,"riscv_cpu_tb dut hu fwd_rs2", false,-1, 1,0);
        tracep->declBit(c+1,"riscv_cpu_tb dut mc clk", false,-1);
        tracep->declBit(c+2,"riscv_cpu_tb dut mc rst_n", false,-1);
        tracep->declBit(c+129,"riscv_cpu_tb dut mc miss_i", false,-1);
        tracep->declBit(c+40,"riscv_cpu_tb dut mc miss_d", false,-1);
        tracep->declBus(c+117,"riscv_cpu_tb dut mc vaddr_i", false,-1, 31,0);
        tracep->declBus(c+26,"riscv_cpu_tb dut mc vaddr_d", false,-1, 31,0);
        tracep->declBit(c+127,"riscv_cpu_tb dut mc refill_done_i", false,-1);
        tracep->declBit(c+128,"riscv_cpu_tb dut mc refill_done_d", false,-1);
        tracep->declBus(c+108,"riscv_cpu_tb dut mc refill_idx_i", false,-1, 31,0);
        tracep->declBus(c+109,"riscv_cpu_tb dut mc refill_vpn_i", false,-1, 31,0);
        tracep->declBus(c+110,"riscv_cpu_tb dut mc refill_ppn_i", false,-1, 31,0);
        tracep->declBus(c+5,"riscv_cpu_tb dut mc refill_idx_d", false,-1, 31,0);
        tracep->declBus(c+111,"riscv_cpu_tb dut mc refill_data_d", false,-1, 31,0);
        tracep->declBus(c+3,"riscv_cpu_tb dut mc mem_addr", false,-1, 31,0);
        tracep->declBus(c+140,"riscv_cpu_tb dut mc mem_wdata", false,-1, 31,0);
        tracep->declBit(c+116,"riscv_cpu_tb dut mc mem_req", false,-1);
        tracep->declBit(c+100,"riscv_cpu_tb dut mc mem_we", false,-1);
        tracep->declBus(c+106,"riscv_cpu_tb dut mc mem_rdata", false,-1, 31,0);
        tracep->declBit(c+107,"riscv_cpu_tb dut mc mem_ready", false,-1);
        tracep->declBus(c+137,"riscv_cpu_tb dut mc state", false,-1, 1,0);
        tracep->declBus(c+138,"riscv_cpu_tb dut mc next_state", false,-1, 1,0);
        tracep->declBus(c+99,"riscv_cpu_tb dut mc state_q", false,-1, 1,0);
        tracep->declBus(c+139,"riscv_cpu_tb dut mc delay_cnt", false,-1, 2,0);
        tracep->declBus(c+6,"riscv_cpu_tb dut mc addr_reg", false,-1, 31,0);
    }
}

void Vriscv_cpu_tb::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vriscv_cpu_tb::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_cpu_tb__Syms* __restrict vlSymsp = static_cast<Vriscv_cpu_tb__Syms*>(userp);
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vriscv_cpu_tb::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_cpu_tb__Syms* __restrict vlSymsp = static_cast<Vriscv_cpu_tb__Syms*>(userp);
    Vriscv_cpu_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->riscv_cpu_tb__DOT__clk));
        tracep->fullBit(oldp+2,(vlTOPp->riscv_cpu_tb__DOT__rst_n));
        tracep->fullIData(oldp+3,(vlTOPp->riscv_cpu_tb__DOT__mem_addr),32);
        tracep->fullIData(oldp+4,(vlTOPp->riscv_cpu_tb__DOT__cycle_cnt),32);
        tracep->fullIData(oldp+5,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_d),32);
        tracep->fullIData(oldp+6,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__addr_reg),32);
        tracep->fullIData(oldp+7,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id),32);
        tracep->fullCData(oldp+8,((0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                            >> 0xfU))),5);
        tracep->fullCData(oldp+9,((0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                            >> 0x14U))),5);
        tracep->fullCData(oldp+10,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_ex),5);
        tracep->fullCData(oldp+11,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_mem),5);
        tracep->fullCData(oldp+12,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_wb),5);
        tracep->fullBit(oldp+13,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex));
        tracep->fullBit(oldp+14,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write));
        tracep->fullBit(oldp+15,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write));
        tracep->fullBit(oldp+16,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__branch));
        tracep->fullBit(oldp+17,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__jump));
        tracep->fullIData(oldp+18,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_id),32);
        tracep->fullIData(oldp+19,(((0U == (0x1fU & 
                                            (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0xfU)))
                                     ? 0U : vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs
                                    [(0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                               >> 0xfU))])),32);
        tracep->fullIData(oldp+20,(((0U == (0x1fU & 
                                            (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0x14U)))
                                     ? 0U : vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs
                                    [(0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                               >> 0x14U))])),32);
        tracep->fullIData(oldp+21,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rs1_ex),32);
        tracep->fullIData(oldp+22,(((1U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs2))
                                     ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_out_ex
                                     : ((2U == (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs2))
                                         ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex
                                         : ((0U == 
                                             (0x1fU 
                                              & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                 >> 0x14U)))
                                             ? 0U : 
                                            vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs
                                            [(0x1fU 
                                              & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                 >> 0x14U))])))),32);
        tracep->fullIData(oldp+23,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_result),32);
        tracep->fullIData(oldp+24,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__imm_ex),32);
        tracep->fullIData(oldp+25,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_out_ex),32);
        tracep->fullIData(oldp+26,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex),32);
        tracep->fullIData(oldp+27,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex)
                                     ? ((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache_hit)
                                         ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data
                                        [(0x3ffU & 
                                          (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                           >> 5U))]
                                         : 0U) : vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex)),32);
        tracep->fullIData(oldp+28,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__wb_out),32);
        tracep->fullCData(oldp+29,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_id),4);
        tracep->fullCData(oldp+30,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__alu_op_ex),4);
        tracep->fullCData(oldp+31,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_op),2);
        tracep->fullCData(oldp+32,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs1),2);
        tracep->fullCData(oldp+33,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__fwd_rs2),2);
        tracep->fullBit(oldp+34,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__tlb_miss_d));
        tracep->fullBit(oldp+35,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__cache_miss_d));
        tracep->fullBit(oldp+36,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb_hit));
        tracep->fullBit(oldp+37,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache_hit));
        tracep->fullIData(oldp+38,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d),32);
        tracep->fullIData(oldp+39,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache_hit)
                                     ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__data
                                    [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                                >> 5U))]
                                     : 0U)),32);
        tracep->fullBit(oldp+40,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__miss_d_wire));
        tracep->fullIData(oldp+41,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+42,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__unnamedblk1__DOT__i),32);
        tracep->fullBit(oldp+43,(((0x33U == (0x7fU 
                                             & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) 
                                  & ((1U == (0x3fU 
                                             & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                >> 0x19U))) 
                                     | (5U == (0x3fU 
                                               & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                  >> 0x19U)))))));
        tracep->fullBit(oldp+44,(((0x33U == (0x7fU 
                                             & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)) 
                                  & (5U == (0x3fU & 
                                            (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0x19U))))));
        tracep->fullBit(oldp+45,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dec__DOT__a_instr));
        tracep->fullBit(oldp+46,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dec__DOT__a_instr) 
                                  & (2U == (0x3fU & 
                                            (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0x19U))))));
        tracep->fullBit(oldp+47,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dec__DOT__a_instr) 
                                  & (3U == (0x3fU & 
                                            (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0x19U))))));
        tracep->fullBit(oldp+48,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dec__DOT__a_instr) 
                                  & (0x38U >= (0x3fU 
                                               & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                                  >> 0x19U))))));
        tracep->fullCData(oldp+49,((0x1fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0x19U))),5);
        tracep->fullCData(oldp+50,((0x7fU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id)),7);
        tracep->fullCData(oldp+51,((7U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+52,((0x7fU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__inst_id 
                                             >> 0x19U))),7);
        tracep->fullBit(oldp+53,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__reg_write) 
                                  & (0U != (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rd_wb)))));
        tracep->fullIData(oldp+54,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[0]),32);
        tracep->fullIData(oldp+55,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[1]),32);
        tracep->fullIData(oldp+56,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[2]),32);
        tracep->fullIData(oldp+57,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[3]),32);
        tracep->fullIData(oldp+58,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[4]),32);
        tracep->fullIData(oldp+59,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[5]),32);
        tracep->fullIData(oldp+60,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[6]),32);
        tracep->fullIData(oldp+61,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[7]),32);
        tracep->fullIData(oldp+62,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[8]),32);
        tracep->fullIData(oldp+63,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[9]),32);
        tracep->fullIData(oldp+64,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[10]),32);
        tracep->fullIData(oldp+65,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[11]),32);
        tracep->fullIData(oldp+66,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[12]),32);
        tracep->fullIData(oldp+67,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[13]),32);
        tracep->fullIData(oldp+68,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[14]),32);
        tracep->fullIData(oldp+69,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[15]),32);
        tracep->fullIData(oldp+70,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[16]),32);
        tracep->fullIData(oldp+71,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[17]),32);
        tracep->fullIData(oldp+72,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[18]),32);
        tracep->fullIData(oldp+73,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[19]),32);
        tracep->fullIData(oldp+74,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[20]),32);
        tracep->fullIData(oldp+75,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[21]),32);
        tracep->fullIData(oldp+76,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[22]),32);
        tracep->fullIData(oldp+77,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[23]),32);
        tracep->fullIData(oldp+78,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[24]),32);
        tracep->fullIData(oldp+79,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[25]),32);
        tracep->fullIData(oldp+80,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[26]),32);
        tracep->fullIData(oldp+81,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[27]),32);
        tracep->fullIData(oldp+82,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[28]),32);
        tracep->fullIData(oldp+83,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[29]),32);
        tracep->fullIData(oldp+84,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[30]),32);
        tracep->fullIData(oldp+85,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__regs[31]),32);
        tracep->fullIData(oldp+86,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__rf__DOT__unnamedblk1__DOT__i),32);
        tracep->fullBit(oldp+87,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_write) 
                                  | (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_read_ex))));
        tracep->fullCData(oldp+88,((0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                             >> 0xcU))),8);
        tracep->fullIData(oldp+89,((0xfffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                                >> 0xcU))),20);
        tracep->fullBit(oldp+90,(((0xfffffU & (IData)(
                                                      (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem
                                                       [
                                                       (0xffU 
                                                        & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                                           >> 0xcU))] 
                                                       >> 0x14U))) 
                                  == (0xfffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                                  >> 0xcU)))));
        tracep->fullBit(oldp+91,((1U & (IData)((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__tlb_mem
                                                [(0xffU 
                                                  & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mem_out_ex 
                                                     >> 0xcU))] 
                                                >> 0x28U)))));
        tracep->fullIData(oldp+92,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dtlb__DOT__unnamedblk1__DOT__i),32);
        tracep->fullBit(oldp+93,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT____Vcellinp__dcache__req));
        tracep->fullSData(oldp+94,((0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                              >> 5U))),10);
        tracep->fullIData(oldp+95,((0x1ffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                                >> 0xaU))),17);
        tracep->fullCData(oldp+96,((7U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                          >> 2U))),4);
        tracep->fullBit(oldp+97,((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__tags
                                  [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                              >> 5U))] 
                                  == (0x1ffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_d 
                                                  >> 0xaU)))));
        tracep->fullIData(oldp+98,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__unnamedblk1__DOT__i),32);
        tracep->fullCData(oldp+99,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state_q),2);
        tracep->fullBit(oldp+100,(vlTOPp->riscv_cpu_tb__DOT__mem_we));
        tracep->fullIData(oldp+101,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_id),32);
        tracep->fullIData(oldp+102,(((IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit)
                                      ? vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__data
                                     [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                                 >> 5U))]
                                      : 0U)),32);
        tracep->fullBit(oldp+103,(((0xfffffU & (IData)(
                                                       (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem
                                                        [
                                                        (0xffU 
                                                         & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                                            >> 0xcU))] 
                                                        >> 0x14U))) 
                                   == (0xfffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                                   >> 0xcU)))));
        tracep->fullBit(oldp+104,((1U & (IData)((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb__DOT__tlb_mem
                                                 [(0xffU 
                                                   & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                                      >> 0xcU))] 
                                                 >> 0x28U)))));
        tracep->fullBit(oldp+105,((vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__tags
                                   [(0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                               >> 5U))] 
                                   == (0x1ffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                                   >> 0xaU)))));
        tracep->fullIData(oldp+106,(vlTOPp->riscv_cpu_tb__DOT__mem_rdata),32);
        tracep->fullBit(oldp+107,(vlTOPp->riscv_cpu_tb__DOT__mem_ready));
        tracep->fullIData(oldp+108,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_i),32);
        tracep->fullIData(oldp+109,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_vpn_i),32);
        tracep->fullIData(oldp+110,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_ppn_i),32);
        tracep->fullIData(oldp+111,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_data_d),32);
        tracep->fullCData(oldp+112,((0xffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_i)),8);
        tracep->fullIData(oldp+113,((0xfffffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_vpn_i)),20);
        tracep->fullIData(oldp+114,((0xfffffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_ppn_i)),20);
        tracep->fullSData(oldp+115,((0x3ffU & vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_idx_i)),10);
        tracep->fullBit(oldp+116,(vlTOPp->riscv_cpu_tb__DOT__mem_req));
        tracep->fullIData(oldp+117,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if),32);
        tracep->fullBit(oldp+118,((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_if)))));
        tracep->fullBit(oldp+119,((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_id)))));
        tracep->fullBit(oldp+120,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_if));
        tracep->fullBit(oldp+121,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__stall_id));
        tracep->fullBit(oldp+122,((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit)))));
        tracep->fullBit(oldp+123,((1U & (~ (IData)(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit)))));
        tracep->fullBit(oldp+124,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__itlb_hit));
        tracep->fullBit(oldp+125,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache_hit));
        tracep->fullIData(oldp+126,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i),32);
        tracep->fullBit(oldp+127,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_i));
        tracep->fullBit(oldp+128,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__refill_done_d));
        tracep->fullBit(oldp+129,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__miss_i_wire));
        tracep->fullCData(oldp+130,((0xffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                              >> 0xcU))),8);
        tracep->fullIData(oldp+131,((0xfffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__pc_if 
                                                 >> 0xcU))),20);
        tracep->fullSData(oldp+132,((0x3ffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                               >> 5U))),10);
        tracep->fullIData(oldp+133,((0x1ffffU & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                                 >> 0xaU))),17);
        tracep->fullCData(oldp+134,((7U & (vlTOPp->riscv_cpu_tb__DOT__dut__DOT__paddr_i 
                                           >> 2U))),4);
        tracep->fullBit(oldp+135,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__hu__DOT__stall_ex));
        tracep->fullBit(oldp+136,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__hu__DOT__stall_mem));
        tracep->fullCData(oldp+137,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__state),2);
        tracep->fullCData(oldp+138,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__next_state),2);
        tracep->fullCData(oldp+139,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__mc__DOT__delay_cnt),3);
        tracep->fullIData(oldp+140,(vlTOPp->riscv_cpu_tb__DOT__mem_wdata),32);
        tracep->fullIData(oldp+141,(0x20U),32);
        tracep->fullBit(oldp+142,(0U));
        tracep->fullIData(oldp+143,(0xcU),32);
        tracep->fullIData(oldp+144,(0x100U),32);
        tracep->fullBit(oldp+145,(1U));
        tracep->fullIData(oldp+146,(8U),32);
        tracep->fullIData(oldp+147,(0x29U),32);
        tracep->fullIData(oldp+148,(0x400U),32);
        tracep->fullIData(oldp+149,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__icache__DOT__wr_data),32);
        tracep->fullIData(oldp+150,(5U),32);
        tracep->fullIData(oldp+151,(0xaU),32);
        tracep->fullIData(oldp+152,(0x11U),32);
        tracep->fullIData(oldp+153,(4U),32);
        tracep->fullCData(oldp+154,(0U),8);
        tracep->fullIData(oldp+155,(0U),20);
        tracep->fullIData(oldp+156,(vlTOPp->riscv_cpu_tb__DOT__dut__DOT__dcache__DOT__wr_data),32);
        tracep->fullSData(oldp+157,(0U),10);
        tracep->fullIData(oldp+158,(0U),32);
    }
}
