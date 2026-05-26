module riscv_cpu_top #(parameter XLEN=32, VA_W=32, PA_W=32)(
    input  logic clk, rst_n,
    input  logic [XLEN-1:0] mem_rdata,
    input  logic mem_ready,
    output logic [PA_W-1:0] mem_addr,
    output logic [XLEN-1:0] mem_wdata,
    output logic mem_req, mem_we
);
    // === SIGNALS ===
    logic [VA_W-1:0] pc_if, pc_id;
    logic [31:0] inst_fetch, inst_id;
    logic [4:0] rs1_id, rs2_id, rd_ex, rd_mem, rd_wb;
    logic mem_read_ex, reg_write, mem_write, branch, jump;
    logic [31:0] imm_id, rs1_raw, rs2_raw, rs1_ex, rs2_ex, alu_result, imm_ex, alu_out_ex, mem_out_ex, wb_data, wb_out;
    logic [3:0] alu_op_id, alu_op_ex;
    logic [1:0] mem_op, fwd_rs1, fwd_rs2;
    logic en_if_id, en_id_ex, stall_if, stall_id, flush_ex, flush_mem;
    logic tlb_miss_i, cache_miss_i, tlb_miss_d, cache_miss_d;
    logic itlb_hit, icache_hit, dtlb_hit, dcache_hit;
    logic [PA_W-1:0] paddr_i, paddr_d;
    logic [31:0] dcache_rdata;
    
    // Refill signals from mem_ctrl
    logic refill_done_i, refill_done_d;
    logic [31:0] refill_idx_i, refill_vpn_i, refill_ppn_i, refill_idx_d, refill_data_d;
    logic miss_i_wire, miss_d_wire;

    assign pc_id = pc_if + 4;
    assign en_if_id = !stall_if; 
    assign en_id_ex = !stall_id;
    assign miss_i_wire = tlb_miss_i | cache_miss_i;
    assign miss_d_wire = tlb_miss_d | cache_miss_d;
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) pc_if <= 32'h80000000;
        else if (en_if_id) pc_if <= pc_if + 4;
    end

    pipeline_reg #(.WIDTH(VA_W)) if_id_pc (.clk, .rst_n, .en(en_if_id), .flush(1'b0), .d(pc_if), .q(pc_id));
    pipeline_reg #(.WIDTH(32)) if_id_inst (.clk, .rst_n, .en(en_if_id), .flush(1'b0), .d(inst_fetch), .q(inst_id));

    tlb #(.VA_W(VA_W), .PA_W(PA_W)) itlb (
        .clk, .rst_n, .req(1'b1), .vaddr(pc_if), .paddr(paddr_i), .hit(itlb_hit), 
        .refill_valid(refill_done_i), .refill_idx(refill_idx_i[7:0]), 
        .refill_vpn(refill_vpn_i), .refill_ppn(refill_ppn_i));
    assign tlb_miss_i = ~itlb_hit;
    
    cache #(.ADDR_W(PA_W), .DATA_W(32)) icache (
        .clk, .rst_n, .req(1'b1), .wr_en(1'b0), .addr(paddr_i), .rd_data(inst_fetch), 
        .hit(icache_hit), .refill_valid(refill_done_i), .refill_idx(refill_idx_i[9:0]), 
        .refill_data({4{refill_data_d}})); // Broadcast for 32B line
    assign cache_miss_i = ~icache_hit;

    decoder dec (.inst(inst_id), .rs1(rs1_id), .rs2(rs2_id), .rd(rd_ex), .imm(imm_id),
                 .reg_write, .mem_read(mem_read_ex), .mem_write, .branch, .jump,
                 .alu_op(alu_op_id), .mem_op);
    
    regfile rf (.clk, .rst_n, .rs1(rs1_id), .rs2(rs2_id), .rd_wb(rd_wb), .wr_data_wb(wb_out),
                .wr_en_wb(reg_write && (rd_wb != 0)), .rd1(rs1_raw), .rd2(rs2_raw));

    pipeline_reg #(.WIDTH(32)) id_ex_imm (.clk, .rst_n, .en(en_id_ex), .flush(flush_ex), .d(imm_id), .q(imm_ex));
    pipeline_reg #(.WIDTH(4)) id_ex_aluop (.clk, .rst_n, .en(en_id_ex), .flush(flush_ex), .d(alu_op_id), .q(alu_op_ex));
    pipeline_reg #(.WIDTH(5)) id_ex_rd (.clk, .rst_n, .en(en_id_ex), .flush(flush_ex), .d(rd_ex), .q(rd_ex));
    pipeline_reg #(.WIDTH(5)) id_ex_rd_mem (.clk, .rst_n, .en(1'b1), .flush(flush_mem), .d(rd_ex), .q(rd_mem));
    pipeline_reg #(.WIDTH(5)) id_ex_rd_wb (.clk, .rst_n, .en(1'b1), .flush(1'b0), .d(rd_mem), .q(rd_wb));

    assign rs1_ex = (fwd_rs1 == 1) ? alu_out_ex : (fwd_rs1 == 2) ? mem_out_ex : rs1_raw;
    assign rs2_ex = (fwd_rs2 == 1) ? alu_out_ex : (fwd_rs2 == 2) ? mem_out_ex : rs2_raw;
    alu alu (.a(rs1_ex), .b(imm_ex), .alu_op(alu_op_ex), .result(alu_result));
    
    pipeline_reg #(.WIDTH(32)) ex_mem_alu (.clk, .rst_n, .en(1'b1), .flush(flush_ex), .d(alu_result), .q(alu_out_ex));
    pipeline_reg #(.WIDTH(32)) ex_mem_out (.clk, .rst_n, .en(1'b1), .flush(flush_ex), .d(alu_result), .q(mem_out_ex));

    tlb #(.VA_W(VA_W), .PA_W(PA_W)) dtlb (
        .clk, .rst_n, .req(mem_write||mem_read_ex), .vaddr(mem_out_ex), .paddr(paddr_d), .hit(dtlb_hit),
        .refill_valid(refill_done_d), .refill_idx(0), .refill_vpn(0), .refill_ppn(0));
    assign tlb_miss_d = (mem_write||mem_read_ex) && ~dtlb_hit;
    
    cache #(.ADDR_W(PA_W), .DATA_W(32)) dcache (
        .clk, .rst_n, .req(mem_write||mem_read_ex), .wr_en(mem_write), .addr(paddr_d), 
        .rd_data(dcache_rdata), .hit(dcache_hit), .refill_valid(refill_done_d), .refill_idx(0), .refill_data(0));
    assign cache_miss_d = (mem_write||mem_read_ex) && ~dcache_hit;

    assign wb_data = mem_read_ex ? dcache_rdata : mem_out_ex;
    pipeline_reg #(.WIDTH(32)) mem_wb_data (.clk, .rst_n, .en(1'b1), .flush(flush_mem), .d(wb_data), .q(wb_out));

    hazard_unit hu (
        .rs1_id, .rs2_id, .rd_ex, .rd_mem, .rd_wb, .mem_read_ex,
        .tlb_miss_i, .cache_miss_i, .tlb_miss_d, .cache_miss_d,
        .branch_mispredict(1'b0), .exception_taken(1'b0),
        .m_busy(1'b0), .a_busy(1'b0),
        .stall_if, .stall_id, .stall_ex(), .stall_mem(),
        .flush_ex, .flush_mem, .fwd_rs1, .fwd_rs2);

    mem_ctrl mc (
        .clk, .rst_n, .miss_i(miss_i_wire), .miss_d(miss_d_wire),
        .vaddr_i(pc_if), .vaddr_d(mem_out_ex),
        .refill_done_i, .refill_idx_i, .refill_vpn_i, .refill_ppn_i,
        .refill_done_d, .refill_idx_d, .refill_data_d,
        .mem_addr, .mem_wdata, .mem_req, .mem_we, .mem_rdata, .mem_ready);
endmodule
