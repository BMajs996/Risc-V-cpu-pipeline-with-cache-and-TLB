`timescale 1ns/1ps
module riscv_cpu_tb;
    // Clock generation for simulation.
    logic clk = 0;
    always #5 clk = ~clk;

    logic rst_n = 0;
    initial begin
        $dumpfile("obj_dir/Vriscv_cpu_tb.vcd");
        $dumpvars(0, riscv_cpu_tb);
        #20 rst_n = 1;
        $display("✅ Reset released at t=%0t", $time);
    end

    // HARD WATCHDOG (Does NOT depend on clk)
    initial begin
        #10000;
        $display("⏱️ Watchdog triggered at t=%0t. Forcing exit.", $time);
        $finish;
    end

    logic [31:0] mem_rdata = 0;
    logic mem_ready = 0;
    logic [31:0] mem_addr, mem_wdata;
    logic mem_req, mem_we;
    logic [31:0] cycle_cnt = 0;

    riscv_cpu_top dut (.*);

    // Cycle counter (runs on clk)
    always @(posedge clk) begin
        if (rst_n) begin
            mem_ready <= mem_req;
            mem_rdata <= 32'h0;
        end
        cycle_cnt <= cycle_cnt + 1;
        
        if (cycle_cnt == 50)  $display("🔄 Cycle 50  | PC=%h | stall=%b", dut.pc_if, dut.stall_if);
        if (cycle_cnt == 100) $display("🔄 Cycle 100 | PC=%h | stall=%b", dut.pc_if, dut.stall_if);
        if (cycle_cnt == 200) begin
            $display("🏁 Simulation complete at t=%0t", $time);
            $finish;
        end
    end
endmodule
