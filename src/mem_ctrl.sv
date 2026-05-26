module mem_ctrl (
    input  logic                     clk, rst_n,
    input  logic                     miss_i, miss_d,
    input  logic [31:0]              vaddr_i, vaddr_d,
    output logic                     refill_done_i, refill_done_d,
    output logic [31:0]              refill_idx_i, refill_vpn_i, refill_ppn_i,
    output logic [31:0]              refill_idx_d, refill_data_d,
    output logic [31:0]              mem_addr, mem_wdata,
    output logic                     mem_req, mem_we,
    input  logic [31:0]              mem_rdata,
    input  logic                     mem_ready
);
    typedef enum logic [1:0] {IDLE, REFILL_I, REFILL_D, DONE} state_t;
    state_t state, next_state;
    logic [1:0] state_q; // Explicit previous-state register
    logic [2:0] delay_cnt;
    logic [31:0] addr_reg;

    // State register
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE; state_q <= 2'b0; delay_cnt <= 0;
            mem_req <= 0; mem_we <= 0;
        end else begin
            state_q <= state;
            state <= next_state;
        end
    end

    // Next-state logic (combinational)
    always_comb begin
        next_state = state;
        mem_req = 0; mem_we = 0;
        unique case (state)
            IDLE: begin
                if (miss_i) next_state = REFILL_I;
                else if (miss_d) next_state = REFILL_D;
            end
            REFILL_I, REFILL_D: begin
                mem_req = 1;
                if (mem_ready && delay_cnt >= 2) next_state = DONE;
            end
            DONE: next_state = IDLE;
        endcase
    end

    // Delay counter (sequential)
    always_ff @(posedge clk) begin
        if (state == REFILL_I || state == REFILL_D) begin
            if (mem_ready) delay_cnt <= delay_cnt + 1;
            else delay_cnt <= 0;
        end else delay_cnt <= 0;
    end

    // Refill done pulses (1-cycle)
    assign refill_done_i = (state_q == 2'b01 && state == DONE);
    assign refill_done_d = (state_q == 2'b10 && state == DONE);

    // Address & refill data pipeline
    always_ff @(posedge clk) begin
        if (state == IDLE) begin
            if (miss_i) addr_reg <= vaddr_i;
            else if (miss_d) addr_reg <= vaddr_d;
        end
        mem_addr <= addr_reg;
        refill_idx_i  <= vaddr_i[12 +: 8];
        refill_vpn_i  <= vaddr_i[12 +: 20];
        refill_ppn_i  <= vaddr_i[12 +: 20];
        refill_idx_d  <= vaddr_d[2 +: 10];
        refill_data_d <= mem_rdata;
    end
endmodule
