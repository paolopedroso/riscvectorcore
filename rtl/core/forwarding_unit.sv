module forwarding_unit #(
    parameter int DATA_WIDTH = 32
) (
    // Register addresses from decode stage
    input logic [4:0] ex_rs1_addr,
    input logic [4:0] ex_rs2_addr,
    
    input logic mem_reg_write,
    input logic [4:0] mem_rd_addr,
    input logic wb_reg_write,
    input logic [4:0] wb_rd_addr,
    
    // Debug instruction tracking
    input logic [31:0] ex_instr,
    input logic [31:0] mem_instr,
    input logic [31:0] wb_instr,
    
    output logic [1:0] forward_a,
    output logic [1:0] forward_b
);

// Store instruction detection
wire is_store = (ex_instr[6:0] == 7'b0100011);

always_comb begin
    // Default: no forwarding
    forward_a = 2'b00;
    forward_b = 2'b00;
    
    // RS1 forwarding logic - simplified
    if (ex_rs1_addr != 5'b0) begin  // Don't forward for register x0
        // Check MEM stage forwarding (higher priority)
        if (mem_reg_write && (mem_rd_addr == ex_rs1_addr)) begin
            forward_a = 2'b10;
        end
        // Check WB stage forwarding
        else if (wb_reg_write && (wb_rd_addr == ex_rs1_addr)) begin
            forward_a = 2'b01;
        end
    end
    
    // RS2 forwarding logic - simplified
    if (ex_rs2_addr != 5'b0) begin  // Don't forward for register x0
        // Check MEM stage forwarding (higher priority)
        if (mem_reg_write && (mem_rd_addr == ex_rs2_addr)) begin
            forward_b = 2'b10;
        end
        // Check WB stage forwarding
        else if (wb_reg_write && (wb_rd_addr == ex_rs2_addr)) begin
            forward_b = 2'b01;
        end
    end
end
endmodule
