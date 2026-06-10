module riscv_cpu_top #(parameter XLEN=32, VA_W=32, PA_W=32)(
    input  logic clk, rst_n,
    input  logic [XLEN-1:0] mem_rdata,
    input  logic mem_ready,
    output logic [PA_W-1:0] mem_addr,
    output logic [XLEN-1:0] mem_wdata,
    output logic mem_req, mem_we
);
    // === ALL CONTROL SIGNALS REGISTERED ===
    logic [VA_W-1:0] pc_if, pc_id, pc_next;
    logic [31:0]     inst_fetch, inst_id;
    logic [4:0]      rs1_id, rs2_id, rd_id, rd_ex, rd_mem, rd_wb;
    logic            mem_read_ex, reg_write, mem_write;
    logic [31:0]     imm_id, rs1_raw, rs2_raw, rs1_ex, rs2_ex, alu_result, imm_ex, alu_out_ex, mem_out_ex, wb_data, wb_out;
    logic [3:0]      alu_op_id, alu_op_ex;
    logic [1:0]      mem_op, fwd_rs1, fwd_rs2;
    logic            en_if_id, en_id_ex, flush_ex, flush_mem;
    logic            stall_if, stall_id;
    logic            tlb_miss_i, cache_miss_i, tlb_miss_d, cache_miss_d;
    logic            itlb_hit, icache_hit, dtlb_hit, dcache_hit;
    logic [PA_W-1:0] paddr_i, paddr_d;
    logic [31:0]     dcache_rdata;
    logic            refill_done_i, refill_done_d;
    logic [7:0]      refill_idx_i;
    logic [19:0]     refill_vpn_i, refill_ppn_i;
    logic [9:0]      refill_idx_d;
    logic [31:0]     refill_data_d;
    logic            miss_i_q, miss_d_q; // Registered miss signals
    logic            h_stall_if, h_stall_id, h_flush_ex, h_flush_mem;
    logic [1:0]      h_fwd_rs1, h_fwd_rs2;
    logic            dec_m_instr, dec_div_instr, dec_a_instr, dec_lr_instr, dec_sc_instr, dec_amo_instr;
    logic [4:0]      dec_amo_op;

    assign pc_next = pc_if + 4;
    assign en_if_id = !stall_if;
    assign en_id_ex = !stall_id;

    // === PC & CONTROL REGISTERS (Breaks all eval loops) ===
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc_if <= 32'h80000000; stall_if <= 0; stall_id <= 0; flush_ex <= 0; flush_mem <= 0;
            fwd_rs1 <= 0; fwd_rs2 <= 0; miss_i_q <= 0; miss_d_q <= 0;
        end else begin
            if (en_if_id) pc_if <= pc_next;
            stall_if <= h_stall_if; stall_id <= h_stall_id;
            flush_ex <= h_flush_ex; flush_mem <= h_flush_mem;
            fwd_rs1 <= h_fwd_rs1; fwd_rs2 <= h_fwd_rs2;
            miss_i_q <= tlb_miss_i | cache_miss_i;
            miss_d_q <= tlb_miss_d | cache_miss_d;
        end
    end

    // === IF/ID ===
    pipeline_reg #(.WIDTH(VA_W)) if_id_pc (.clk, .rst_n, .en(en_if_id), .flush(1'b0), .d(pc_if), .q(pc_id));
    pipeline_reg #(.WIDTH(32))  if_id_inst (.clk, .rst_n, .en(en_if_id), .flush(1'b0), .d(inst_fetch), .q(inst_id));

    // === FETCH: TLB & Cache ===
    tlb #(.VA_W(VA_W), .PA_W(PA_W)) itlb (.clk, .rst_n, .req(1'b1), .vaddr(pc_if), .paddr(paddr_i), .hit(itlb_hit),
        .refill_valid(refill_done_i), .refill_idx(refill_idx_i), .refill_vpn(refill_vpn_i), .refill_ppn(refill_ppn_i));
    assign tlb_miss_i = ~itlb_hit;

    cache #(.ADDR_W(PA_W), .DATA_W(32)) icache (.clk, .rst_n, .req(1'b1), .wr_en(1'b0), .addr(paddr_i), .wr_data('0), .rd_data(inst_fetch),
        .hit(icache_hit), .refill_valid(refill_done_i), .refill_idx({2'b00, refill_idx_i}), .refill_data(refill_data_d));
    assign cache_miss_i = ~icache_hit;

    // === DECODE ===
    decoder dec (.inst(inst_id), .rs1(rs1_id), .rs2(rs2_id), .rd(rd_id), .imm(imm_id),
                 .reg_write, .mem_read(mem_read_ex), .mem_write, .branch(), .jump(), .alu_op(alu_op_id), .mem_op,
                 .m_instr(dec_m_instr), .div_instr(dec_div_instr), .a_instr(dec_a_instr),
                 .lr_instr(dec_lr_instr), .sc_instr(dec_sc_instr), .amo_instr(dec_amo_instr), .amo_op(dec_amo_op));
    regfile rf (.clk, .rst_n, .rs1(rs1_id), .rs2(rs2_id), .rd_wb(rd_wb), .wr_data_wb(wb_out),
                .wr_en_wb(reg_write && (rd_wb != 0)), .rd1(rs1_raw), .rd2(rs2_raw));

    // === ID/EX ===
    pipeline_reg #(.WIDTH(32)) id_ex_imm (.clk, .rst_n, .en(en_id_ex), .flush(flush_ex), .d(imm_id), .q(imm_ex));
    pipeline_reg #(.WIDTH(4))  id_ex_aluop (.clk, .rst_n, .en(en_id_ex), .flush(flush_ex), .d(alu_op_id), .q(alu_op_ex));
    pipeline_reg #(.WIDTH(5))  id_ex_rd (.clk, .rst_n, .en(en_id_ex), .flush(flush_ex), .d(rd_id), .q(rd_ex));

    // === EX ===
    assign rs1_ex = (fwd_rs1 == 1) ? alu_out_ex : (fwd_rs1 == 2) ? mem_out_ex : rs1_raw;
    assign rs2_ex = (fwd_rs2 == 1) ? alu_out_ex : (fwd_rs2 == 2) ? mem_out_ex : rs2_raw;
    alu alu (.a(rs1_ex), .b(imm_ex), .alu_op(alu_op_ex), .result(alu_result));
    
    pipeline_reg #(.WIDTH(32)) ex_mem_alu (.clk, .rst_n, .en(1'b1), .flush(flush_ex), .d(alu_result), .q(alu_out_ex));
    pipeline_reg #(.WIDTH(32)) ex_mem_out (.clk, .rst_n, .en(1'b1), .flush(flush_ex), .d(alu_result), .q(mem_out_ex));
    pipeline_reg #(.WIDTH(5))  ex_mem_rd (.clk, .rst_n, .en(1'b1), .flush(flush_mem), .d(rd_ex), .q(rd_mem));

    // === MEM ===
    tlb #(.VA_W(VA_W), .PA_W(PA_W)) dtlb (.clk, .rst_n, .req(mem_write||mem_read_ex), .vaddr(mem_out_ex), .paddr(paddr_d), .hit(dtlb_hit),
        .refill_valid(refill_done_d), .refill_idx(8'b0), .refill_vpn(20'b0), .refill_ppn(20'b0));
    assign tlb_miss_d = (mem_write||mem_read_ex) && ~dtlb_hit;

    cache #(.ADDR_W(PA_W), .DATA_W(32)) dcache (.clk, .rst_n, .req(mem_write||mem_read_ex), .wr_en(mem_write), .addr(paddr_d), .wr_data(rs2_ex),
        .rd_data(dcache_rdata), .hit(dcache_hit), .refill_valid(refill_done_d), .refill_idx(refill_idx_d), .refill_data(32'b0));
    assign cache_miss_d = (mem_write||mem_read_ex) && ~dcache_hit;

    // === MEM/WB ===
    assign wb_data = mem_read_ex ? dcache_rdata : mem_out_ex;
    pipeline_reg #(.WIDTH(32)) mem_wb_data (.clk, .rst_n, .en(1'b1), .flush(flush_mem), .d(wb_data), .q(wb_out));
    pipeline_reg #(.WIDTH(5))  mem_wb_rd (.clk, .rst_n, .en(1'b1), .flush(flush_mem), .d(rd_mem), .q(rd_wb));

    // === HAZARD UNIT (Registered Outputs) ===
    hazard_unit hu (.rs1_id, .rs2_id, .rd_ex, .rd_mem, .rd_wb, .mem_read_ex,
        .tlb_miss_i, .cache_miss_i, .tlb_miss_d, .cache_miss_d,
        .branch_mispredict(1'b0), .exception_taken(1'b0), .m_busy(1'b0), .a_busy(1'b0),
        .stall_if(h_stall_if), .stall_id(h_stall_id), .stall_ex(), .stall_mem(),
        .flush_ex(h_flush_ex), .flush_mem(h_flush_mem), .fwd_rs1(h_fwd_rs1), .fwd_rs2(h_fwd_rs2));

    // === MEM CTRL (Uses REGISTERED misses, breaks loop) ===
    mem_ctrl mc (.clk, .rst_n, .miss_i(miss_i_q), .miss_d(miss_d_q),
        .vaddr_i(pc_if), .vaddr_d(mem_out_ex), .refill_done_i, .refill_idx_i, .refill_vpn_i, .refill_ppn_i,
        .refill_done_d, .refill_idx_d, .refill_data_d, .mem_addr, .mem_wdata, .mem_req, .mem_we, .mem_rdata, .mem_ready);
endmodule
