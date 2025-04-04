module instr_mem #(
    parameter int DATA_WIDTH = 32,
    parameter int MEM_SIZE = 1024
) (
    input logic clk,
    input logic rst_n,
    input logic [DATA_WIDTH-1:0] addr_i,
    output logic [DATA_WIDTH-1:0] instr_o
);
    // Memory array
    logic [DATA_WIDTH-1:0] imem [MEM_SIZE-1:0];
    
    // Read logic - combinational
    always_comb begin
        instr_o = imem[addr_i[DATA_WIDTH-1:2]]; // Word-aligned access
    end
// Generated from assembly file
initial begin
    for (int i = 0; i < MEM_SIZE; i++) begin
        imem[i] = 32'h0;
    end

    imem[0] = 32'h00100093;  // Instruction at address 0
    imem[1] = 32'h00200113;  // Instruction at address 1
    imem[2] = 32'h002081b3;  // Instruction at address 2
    imem[3] = 32'h00219213;  // Instruction at address 3
    imem[4] = 32'h00a27293;  // Instruction at address 4
    imem[5] = 32'h00302023;  // Instruction at address 5
    imem[6] = 32'h00002303;  // Instruction at address 6
    imem[7] = 32'h008003ef;  // Instruction at address 7
    imem[8] = 32'h07b00413;  // Instruction at address 8
    imem[9] = 32'h02a00493;  // Instruction at address 9
end
endmodule
