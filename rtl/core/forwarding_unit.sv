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


always_comb begin
    // Default: no forwarding
    forward_a = 2'b00;
    forward_b = 2'b00;
    
    // RS1 forwarding logic - priorities forwarding from MEM stage over WB stage
    if (ex_rs1_addr != 5'b0) begin  // Don't forward for register x0
        // Forward from MEM stage (higher priority)
        if (mem_reg_write && (mem_rd_addr == ex_rs1_addr)) begin
            forward_a = 2'b10;
            
            // Debug output
            `ifdef SIMULATION
                $display("FWD: Forwarding rs1 from MEM stage: x%0d", mem_rd_addr);
            `endif
        end
        // Forward from WB stage (lower priority)
        else if (wb_reg_write && (wb_rd_addr == ex_rs1_addr)) begin
            forward_a = 2'b01;
            
            // Debug output
            `ifdef SIMULATION
                $display("FWD: Forwarding rs1 from WB stage: x%0d", wb_rd_addr);
            `endif
        end
    end
    
    // RS2 forwarding logic - similar priority scheme
    if (ex_rs2_addr != 5'b0) begin  // Don't forward for register x0
        // Forward from MEM stage (higher priority)
        if (mem_reg_write && (mem_rd_addr == ex_rs2_addr)) begin
            forward_b = 2'b10;
            
            // Debug output
            `ifdef SIMULATION
                $display("FWD: Forwarding rs2 from MEM stage: x%0d", mem_rd_addr);
            `endif
        end
        // Forward from WB stage (lower priority)
        else if (wb_reg_write && (wb_rd_addr == ex_rs2_addr)) begin
            forward_b = 2'b01;
            
            // Debug output
            `ifdef SIMULATION
                $display("FWD: Forwarding rs2 from WB stage: x%0d", wb_rd_addr);
            `endif
        end
    end
end
endmodule
