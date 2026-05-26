module hazard_unit (
    input  logic [4:0]  rs1_id, rs2_id, rd_ex, rd_mem, rd_wb,
    input  logic        mem_read_ex, tlb_miss_i, cache_miss_i, tlb_miss_d, cache_miss_d,
    input  logic        branch_mispredict, exception_taken, m_busy, a_busy,
    output logic        stall_if, stall_id, stall_ex, stall_mem, flush_ex, flush_mem,
    output logic [1:0]  fwd_rs1, fwd_rs2
);
    always_comb begin
        stall_if = 0; stall_id = 0; stall_ex = 0; stall_mem = 0;
        flush_ex = 0; flush_mem = 0; fwd_rs1 = 0; fwd_rs2 = 0;
        if (tlb_miss_i || cache_miss_i || tlb_miss_d || cache_miss_d || exception_taken) begin
            stall_if = 1; stall_id = 1; stall_ex = 1; stall_mem = 1;
        end
        if (m_busy) stall_ex = 1;
        if (a_busy) stall_mem = 1;
        if (mem_read_ex && (rd_mem != 0)) begin
            if (rd_mem == rs1_id) stall_if = 1;
            if (rd_mem == rs2_id) stall_id = 1;
        end
        if (branch_mispredict || exception_taken) flush_ex = 1;
        if (rd_ex != 0 && rd_ex == rs1_id) fwd_rs1 = 1; else if (rd_mem != 0 && rd_mem == rs1_id) fwd_rs1 = 2;
        if (rd_ex != 0 && rd_ex == rs2_id) fwd_rs2 = 1; else if (rd_mem != 0 && rd_mem == rs2_id) fwd_rs2 = 2;
    end
endmodule
