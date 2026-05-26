module alu (
    input  logic [31:0] a, b,
    input  logic [3:0]  alu_op,
    output logic [31:0] result
);
    always_comb begin
        unique case (alu_op)
            4'b0000: result = a + b;
            4'b0001: result = a - b;
            4'b0010: result = a << b[4:0];
            4'b0011: result = ($signed(a) < $signed(b)) ? 1 : 0;
            4'b0100: result = ($unsigned(a) < $unsigned(b)) ? 1 : 0;
            4'b0101: result = a ^ b;
            4'b0110: result = a >> b[4:0];
            4'b0111: result = $signed(a) >>> b[4:0];
            4'b1000: result = a | b;
            4'b1001: result = a & b;
            4'b1010: result = b; // LUI
            default: result = '0;
        endcase
    end
endmodule
