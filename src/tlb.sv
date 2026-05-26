module tlb #(parameter VA_W = 32, PA_W = 32, OFFSET_W = 12, NUM_ENTRIES = 256)(
    input  logic                         clk, rst_n, req,
    input  logic [VA_W-1:0]              vaddr,
    output logic                         hit,
    output logic [PA_W-1:0]              paddr,
    input  logic                         refill_valid,
    input  logic [$clog2(NUM_ENTRIES)-1:0] refill_idx,
    input  logic [VA_W-OFFSET_W-1:0]     refill_vpn,
    input  logic [PA_W-OFFSET_W-1:0]     refill_ppn
);
    localparam IDX_W = $clog2(NUM_ENTRIES);
    localparam ENTRY_W = 1 + (VA_W-OFFSET_W) + (PA_W-OFFSET_W);
    logic [ENTRY_W-1:0] tlb_mem [NUM_ENTRIES];
    wire [IDX_W-1:0] idx = vaddr[OFFSET_W +: IDX_W];
    wire [VA_W-OFFSET_W-1:0] vpn = vaddr[OFFSET_W +: (VA_W-OFFSET_W)];
    wire tag_match = tlb_mem[idx][PA_W-OFFSET_W +: (VA_W-OFFSET_W)] == vpn;
    wire valid_bit = tlb_mem[idx][ENTRY_W-1];
    
    assign hit = req && valid_bit && tag_match;
    assign paddr = hit ? {tlb_mem[idx][PA_W-OFFSET_W +: (PA_W-OFFSET_W)], vaddr[OFFSET_W-1:0]} : '0;
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i=0; i<NUM_ENTRIES; i=i+1) tlb_mem[i] = '0; // Blocking = for loop init
        end else if (refill_valid) begin
            tlb_mem[refill_idx] <= {1'b1, refill_vpn, refill_ppn};
        end
    end
endmodule
