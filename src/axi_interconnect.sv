module axi_interconnect #(
    parameter ADDR_W = 32, DATA_W = 32, ID_W = 4,
    parameter S_BASE  [0:1] = '{32'h8000_0000, 32'h4000_0000},
    parameter S_LIMIT [0:1] = '{32'h9FFF_FFFF, 32'h4000_0FFF}
)(
    input  logic clk, rst_n,
    input  logic [1:0] m_arvalid, m_arlock,
    output logic [1:0] m_arready,
    input  logic [1:0][ADDR_W-1:0] m_araddr,
    input  logic [1:0][ID_W-1:0] m_arid,
    input  logic [1:0] m_awvalid, m_awlock,
    output logic [1:0] m_awready,
    input  logic [1:0][ADDR_W-1:0] m_awaddr,
    input  logic [1:0][ID_W-1:0] m_awid,
    input  logic [1:0][DATA_W/8-1:0] m_wstrb,
    input  logic [1:0][DATA_W-1:0] m_wdata,
    input  logic [1:0] m_wvalid,
    output logic [1:0] m_wready,
    output logic [1:0] m_rvalid, m_rlast,
    input  logic [1:0] m_rready,
    output logic [1:0][DATA_W-1:0] m_rdata,
    output logic [1:0][1:0] m_rresp,
    output logic [1:0][ID_W-1:0] m_rid,
    output logic [1:0] m_bvalid,
    input  logic [1:0] m_bready,
    output logic [1:0][1:0] m_bresp,
    output logic [1:0][ID_W-1:0] m_bid,
    output logic [1:0] s_arvalid, s_arlock,
    input  logic [1:0] s_arready,
    output logic [1:0][ADDR_W-1:0] s_araddr,
    output logic [1:0][ID_W-1:0] s_arid,
    output logic [1:0] s_awvalid, s_awlock,
    input  logic [1:0] s_awready,
    output logic [1:0][ADDR_W-1:0] s_awaddr,
    output logic [1:0][ID_W-1:0] s_awid,
    output logic [1:0] s_wvalid, s_wlast,
    input  logic [1:0] s_wready,
    output logic [1:0][DATA_W/8-1:0] s_wstrb,
    output logic [1:0][DATA_W-1:0] s_wdata,
    input  logic [1:0] s_rvalid, s_rlast,
    output logic [1:0] s_rready,
    input  logic [1:0][DATA_W-1:0] s_rdata,
    input  logic [1:0][1:0] s_rresp,
    input  logic [1:0][ID_W-1:0] s_rid,
    input  logic [1:0] s_bvalid,
    output logic [1:0] s_bready,
    input  logic [1:0][1:0] s_bresp,
    input  logic [1:0][ID_W-1:0] s_bid
);
    logic [1:0] s_sel_ar, s_sel_aw;
    assign s_sel_ar[0] = (m_araddr[0] >= S_BASE[0] && m_araddr[0] <= S_LIMIT[0]) ? 1'b1 : 1'b0;
    assign s_sel_ar[1] = ~s_sel_ar[0] & (m_araddr[1] >= S_BASE[1] && m_araddr[1] <= S_LIMIT[1]) ? 1'b1 : 1'b0;
    assign s_sel_aw[0] = (m_awaddr[0] >= S_BASE[0] && m_awaddr[0] <= S_LIMIT[0]) ? 1'b1 : 1'b0;
    assign s_sel_aw[1] = ~s_sel_aw[0] & (m_awaddr[1] >= S_BASE[1] && m_awaddr[1] <= S_LIMIT[1]) ? 1'b1 : 1'b0;
    assign s_arvalid = m_arvalid & {s_sel_ar[1], s_sel_ar[0]};
    assign s_araddr = m_araddr; assign s_arid = m_arid; assign s_arlock = m_arlock;
    assign s_awvalid = m_awvalid & {s_sel_aw[1], s_sel_aw[0]};
    assign s_awaddr = m_awaddr; assign s_awid = m_awid; assign s_awlock = m_awlock;
    assign s_wvalid = m_wvalid; assign s_wstrb = m_wstrb; assign s_wdata = m_wdata; assign s_wlast = 1'b1;
    assign m_arready = s_arready & s_arvalid; assign m_awready = s_awready & s_awvalid; assign m_wready = s_wready & s_wvalid;
    assign s_rready = m_rready & m_rvalid; assign s_bready = m_bready & m_bvalid;
    assign m_rvalid = s_rvalid; assign m_rdata = s_rdata; assign m_rlast = s_rlast; assign m_rid = s_rid; assign m_rresp = s_rresp;
    assign m_bvalid = s_bvalid; assign m_bid = s_bid; assign m_bresp = s_bresp;
endmodule
