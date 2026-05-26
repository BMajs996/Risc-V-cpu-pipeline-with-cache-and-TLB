module pipeline_reg #(parameter WIDTH = 32)(
    input  logic             clk, rst_n,
    input  logic             en, flush,
    input  logic [WIDTH-1:0] d,
    output logic [WIDTH-1:0] q
);
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) q <= '0;
        else if (flush) q <= '0;
        else if (en)  q <= d;
    end
endmodule
