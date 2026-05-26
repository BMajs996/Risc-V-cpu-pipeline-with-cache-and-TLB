module axi_exclusive_ctrl #(parameter ADDR_W = 32, DATA_W = 32, ID_W = 4)(
    input  logic                     clk, rst_n, lr_req, sc_req, amo_req,
    input  logic [ADDR_W-1:0]        addr,
    input  logic [DATA_W-1:0]        amo_wr_data,
    output logic                     lr_ack, sc_success, amo_ack,
    output logic [DATA_W-1:0]        lr_data, amo_rd_data,
    output logic                     axi_arvalid, axi_arlock,
    output logic [ADDR_W-1:0]        axi_araddr,
    output logic [ID_W-1:0]          axi_arid,
    input  logic                     axi_arready,
    input  logic                     axi_rvalid, axi_rready,
    input  logic [DATA_W-1:0]        axi_rdata,
    input  logic [1:0]               axi_rresp,
    output logic                     axi_awvalid, axi_awlock,
    output logic [ADDR_W-1:0]        axi_awaddr,
    output logic [ID_W-1:0]          axi_awid,
    input  logic                     axi_awready,
    output logic                     axi_wvalid,
    output logic [DATA_W-1:0]        axi_wdata,
    input  logic                     axi_wready,
    input  logic                     axi_bvalid, axi_bready,
    input  logic [1:0]               axi_bresp
);
    logic lr_valid; logic [ADDR_W-1:0] lr_addr_reg; logic [1:0] state;
    assign axi_rready = (state==1 || state==3); assign axi_bready = (state==2 || state==4);
    assign axi_wvalid = (state==2 || state==4); assign axi_arid = ID_W'(1); assign axi_awid = ID_W'(1);
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin state <= 0; lr_valid <= 0; lr_ack <= 0; sc_success <= 0; amo_ack <= 0; end
        else begin
            case (state)
                0: if (lr_req) begin axi_arvalid=1; axi_arlock=1; state<=1; end
                   else if (sc_req) begin axi_awvalid=1; axi_awlock=1; axi_wvalid=1; state<=2; end
                   else if (amo_req) begin axi_arvalid=1; axi_arlock=1; state<=3; end
                1: if (axi_rvalid && axi_rready) begin lr_addr_reg=addr; lr_valid=(axi_rresp==2'b00); state<=0; lr_ack=1; lr_data=axi_rdata; end
                2: if (axi_bvalid && axi_bready) begin sc_success=(axi_bresp==2'b00)&&lr_valid&&(lr_addr_reg==addr); lr_valid=0; state<=0; end
                3: if (axi_rvalid && axi_rready) begin lr_addr_reg=addr; lr_valid=(axi_rresp==2'b00); state<=4; amo_rd_data=axi_rdata; end
                4: if (axi_bvalid && axi_bready) begin amo_ack=(axi_bresp==2'b00); lr_valid=0; state<=0; end
                default: state<=0;
            endcase
        end
    end
endmodule
