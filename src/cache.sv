module cache #(parameter ADDR_W = 32, DATA_W = 32, LINE_SIZE = 32, NUM_LINES = 1024)(
    input  logic                         clk, rst_n, req, wr_en,
    input  logic [ADDR_W-1:0]            addr,
    input  logic [DATA_W-1:0]            wr_data,
    output logic                         hit,
    output logic [DATA_W-1:0]            rd_data,
    input  logic                         refill_valid,
    input  logic [$clog2(NUM_LINES)-1:0] refill_idx,
    input  logic [LINE_SIZE-1:0]         refill_data
);
    localparam OFFSET_W = $clog2(LINE_SIZE);
    localparam IDX_W = $clog2(NUM_LINES);
    localparam TAG_W = ADDR_W - IDX_W - OFFSET_W;
    
    logic valid [NUM_LINES];
    logic [TAG_W-1:0] tags [NUM_LINES];
    logic [LINE_SIZE-1:0] data [NUM_LINES];
    
    wire [IDX_W-1:0] idx = addr[OFFSET_W +: IDX_W];
    wire [TAG_W-1:0] tag = addr[IDX_W +: TAG_W];
    wire [OFFSET_W-2:0] word_off = addr[OFFSET_W-1:2];
    wire tag_match = tags[idx] == tag;
    
    assign hit = req && valid[idx] && tag_match;
    assign rd_data = hit ? data[idx][word_off*DATA_W +: DATA_W] : '0;
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i=0; i<NUM_LINES; i=i+1) begin // Blocking = for loop init
                valid[i] = 0;
                tags[i] = 0;
                data[i] = '0;
            end
        end else if (refill_valid) begin
            valid[idx] <= 1; tags[idx] <= tag; data[idx] <= refill_data;
        end else if (req && wr_en && hit) begin
            data[idx][word_off*DATA_W +: DATA_W] <= wr_data;
        end
    end
endmodule
