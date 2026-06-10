module regfile #(parameter XLEN = 32, NUM_REGS = 32)(
    input  logic                     clk, rst_n,
    input  logic [$clog2(NUM_REGS)-1:0] rs1, rs2, rd_wb,
    input  logic [XLEN-1:0]          wr_data_wb,
    input  logic                     wr_en_wb,
    output logic [XLEN-1:0]          rd1, rd2
);
    logic [XLEN-1:0] regs [0:NUM_REGS-1];
    assign rd1 = (rs1 == 0) ? '0 : regs[rs1];
    assign rd2 = (rs2 == 0) ? '0 : regs[rs2];
    
    // FIXED: Use non-blocking (<=) for ALL array writes in clocked logic
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i=0; i<NUM_REGS; i=i+1) regs[i] <= '0;
        end else if (wr_en_wb && rd_wb != 0) begin
            regs[rd_wb] <= wr_data_wb;
        end
    end
endmodule
