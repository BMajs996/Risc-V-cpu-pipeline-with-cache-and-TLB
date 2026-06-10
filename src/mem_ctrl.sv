module mem_ctrl (
    input  logic clk, rst_n, miss_i, miss_d,
    input  logic [31:0] vaddr_i, vaddr_d,
    output logic refill_done_i, refill_done_d,
    output logic [7:0] refill_idx_i,
    output logic [19:0] refill_vpn_i, refill_ppn_i,
    output logic [9:0] refill_idx_d,
    output logic [31:0] refill_data_d,
    output logic [31:0] mem_addr, mem_wdata,
    output logic mem_req, mem_we,
    input  logic [31:0] mem_rdata,
    input  logic mem_ready
);
    typedef enum logic [1:0] {IDLE, WAIT, DONE} state_t;
    state_t state;
    logic [1:0] cnt;
    logic [31:0] addr_reg;
    logic is_i_miss;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE; cnt <= 0; mem_req <= 0; mem_we <= 0;
            refill_done_i <= 0; refill_done_d <= 0; mem_addr <= 0; is_i_miss <= 0;
        end else begin
            refill_done_i <= 0; refill_done_d <= 0;
            if (state == IDLE) begin
                if (miss_i) begin state <= WAIT; mem_req <= 1; addr_reg <= vaddr_i; is_i_miss <= 1; end
                else if (miss_d) begin state <= WAIT; mem_req <= 1; addr_reg <= vaddr_d; is_i_miss <= 0; end
            end else if (state == WAIT) begin
                mem_req <= 1;
                if (mem_ready) begin
                    cnt <= cnt + 1;
                    if (cnt >= 1) begin state <= DONE; mem_req <= 0; end
                end
            end else if (state == DONE) begin
                if (is_i_miss) refill_done_i <= 1;
                else refill_done_d <= 1;
                state <= IDLE; cnt <= 0;
            end
            mem_addr <= addr_reg;
            refill_idx_i <= vaddr_i[12 +: 8]; refill_vpn_i <= vaddr_i[12 +: 20]; refill_ppn_i <= vaddr_i[12 +: 20];
            refill_idx_d <= vaddr_d[2 +: 10]; refill_data_d <= mem_rdata;
        end
    end
endmodule
