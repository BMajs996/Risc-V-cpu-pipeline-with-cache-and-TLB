module decoder (
    input  logic [31:0] inst,
    output logic [4:0]  rs1, rs2, rd,
    output logic [31:0] imm,
    output logic        reg_write, mem_read, mem_write, branch, jump,
    output logic [3:0]  alu_op,
    output logic [1:0]  mem_op,
    output logic        m_instr, div_instr, a_instr, lr_instr, sc_instr, amo_instr,
    output logic [4:0]  amo_op
);
    logic [6:0] opcode = inst[6:0];
    logic [2:0] funct3 = inst[14:12];
    logic [6:0] funct7 = inst[31:25];
    assign rs1 = inst[19:15]; assign rs2 = inst[24:20]; assign rd = inst[11:7];
    assign m_instr  = (opcode == 7'b0110011) && (funct7[5:0] == 6'b000001 || funct7[5:0] == 6'b000101);
    assign div_instr = (opcode == 7'b0110011) && funct7[5:0] == 6'b000101;
    assign a_instr  = (opcode == 7'b0101111) && funct3 == 3'b010;
    assign lr_instr = a_instr && funct7[5:0] == 6'b000010;
    assign sc_instr = a_instr && funct7[5:0] == 6'b000011;
    assign amo_instr = a_instr && (funct7[5:0] >= 6'b000000) && (funct7[5:0] <= 6'b111000);
    assign amo_op   = {3'b0, funct7[4:0]}; // Zero-extend to 5 bits

    always_comb begin
        imm = '0; reg_write = 0; mem_read = 0; mem_write = 0; branch = 0; jump = 0; alu_op = 4'b0000; mem_op = 2'b10;
        unique case (opcode)
            7'b0110011, 7'b0010011: imm = {{20{inst[31]}}, inst[31:20]}; // I-type style
            7'b0000011: imm = {{20{inst[31]}}, inst[31:20]};
            7'b0100011: imm = {{20{inst[31]}}, inst[31:20]};
            7'b1100011: imm = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
            7'b0110111, 7'b0010111: imm = {inst[31:12], 12'b0};
            7'b1101111: imm = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};
            default: imm = '0;
        endcase
        unique case (opcode)
            7'b0110011: begin reg_write = 1; alu_op = funct3 + 4'b0000; end
            7'b0010011: begin reg_write = 1; alu_op = funct3 + 4'b0000; end
            7'b0000011: begin mem_read = 1; reg_write = 1; mem_op = funct3[1:0]; alu_op = 4'b0000; end
            7'b0100011: begin mem_write = 1; mem_op = funct3[1:0]; alu_op = 4'b0000; end
            7'b1100011: begin branch = 1; alu_op = 4'b0000; end
            7'b0110111, 7'b0010111: begin reg_write = 1; alu_op = (opcode == 7'b0010111) ? 4'b0000 : 4'b1010; end
            7'b1101111: begin jump = 1; reg_write = 1; alu_op = 4'b0000; end
            7'b1100111: begin jump = 1; reg_write = 1; alu_op = 4'b0000; end
            7'b0101111: begin reg_write = 1; mem_read = 1; mem_write = 1; alu_op = 4'b0000; end
            default: ;
        endcase
    end
endmodule
