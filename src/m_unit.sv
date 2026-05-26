module m_unit #(parameter XLEN = 32)(
    input  logic             clk, rst_n, exec,
    input  logic [XLEN-1:0]  rs1, rs2,
    input  logic [2:0]       funct3,
    output logic [XLEN-1:0]  result,
    output logic             busy, done
);
    logic [63:0] prod;
    assign prod = (funct3[0]==1 || funct3[1:0]==2'b10) ? ($signed(rs1) * $signed(rs2)) : (unsigned'(rs1) * unsigned'(rs2));
    logic [5:0] cnt; logic [1:0] state;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin state <= 0; cnt <= 0; busy <= 0; done <= 0; result <= '0; end
        else begin
            case (state)
                0: if (exec) begin state <= (funct3[2]) ? 1 : 2; busy <= funct3[2]; done <= !funct3[2]; result <= (funct3[2]) ? '0 : prod[XLEN-1:0]; end
                1: if (cnt >= 31) begin state <= 2; busy <= 0; done <= 1; result <= prod[XLEN-1:0]; end else cnt <= cnt + 1;
                2: if (!exec) state <= 0; else begin done <= 1; result <= prod[XLEN-1:0]; end
            endcase
        end
    end
endmodule
