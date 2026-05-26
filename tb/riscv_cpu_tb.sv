`timescale 1ns/1ps
module riscv_cpu_tb;
    logic clk, rst_n;
    logic [31:0] mem_rdata;
    logic mem_ready;
    logic [31:0] mem_addr, mem_wdata;
    logic mem_req, mem_we;
    
    // Cycle counter for Verilator-safe termination
    logic [31:0] cycle_cnt;

    riscv_cpu_top dut (
        .clk, .rst_n, .mem_rdata, .mem_ready, .mem_addr, .mem_wdata, .mem_req, .mem_we
    );

    // Clock generator (Verilator-safe: single statement per timing control)
    initial begin clk = 0; forever #5 clk = ~clk; end

    // Reset sequence
    initial begin rst_n = 0; #10; rst_n = 1; end

    // Memory model (synchronous to clk)
    always @(posedge clk) begin
        mem_ready <= mem_req;
        mem_rdata <= 32'h0000_0000; // NOP-like instruction
    end

    // Cycle counter (Verilator-safe: always_ff)
    always_ff @(posedge clk) begin
        if (!rst_n) cycle_cnt <= 0;
        else cycle_cnt <= cycle_cnt + 1;
        
        // Terminate after 200 cycles (200 * 10ns = 2000ns simulated time)
        if (cycle_cnt == 200) begin
            $display("🔍 Sim complete at t=%0t (cycle=%0d)", $time, cycle_cnt);
            #10; // Allow VCD engine to flush
            $finish;
        end
    end
endmodule
