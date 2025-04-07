/*
 * 32-bit RISC-V Vector Core
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module top #(
    parameter int DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst_n
);

// Internal signals
// Program counter and instruction signals
logic [DATA_WIDTH-1:0] pc_out;
logic [DATA_WIDTH-1:0] instr;
logic                  instr_valid;
logic                  stall_pipeline;
logic                  pc_write;
logic                  take_branch;
logic                  pc_src;

// Decoder signals
logic [4:0]             rs1_addr;
logic [4:0]             rs2_addr;
logic [4:0]             rd_addr;
logic                   reg_write_en;
logic [DATA_WIDTH-1:0]  imm_value;
logic                   imm_valid;
logic [3:0]             alu_op;
logic                   mem_read;
logic                   mem_write;
logic [1:0]             mem_size;
logic                   branch;
logic                   jump;
logic [1:0]             result_src;
logic                   uses_rs1;
logic                   uses_rs2;

// Register file signals
logic [DATA_WIDTH-1:0]  rs1_data;
logic [DATA_WIDTH-1:0]  rs2_data;
logic [DATA_WIDTH-1:0]  rd_data;

// ALU signals
logic [DATA_WIDTH-1:0]  alu_result;
logic                   zero_flag;
logic                   negative_flag;
logic                   overflow_flag;
logic [DATA_WIDTH-1:0]  alu_input_a;
logic [DATA_WIDTH-1:0]  alu_input_b;
logic [DATA_WIDTH-1:0]  alu_rs2_input;
logic [1:0]             forward_a;
logic [1:0]             forward_b;

// Memory signals
logic [DATA_WIDTH-1:0]  mem_rdata;

// Pipeline registers
// IF/ID
logic [DATA_WIDTH-1:0] if_id_pc;
logic [DATA_WIDTH-1:0] if_id_instr;

// ID/EX
logic [DATA_WIDTH-1:0] id_ex_pc;
logic [DATA_WIDTH-1:0] id_ex_rs1_data;
logic [DATA_WIDTH-1:0] id_ex_rs2_data;
logic [DATA_WIDTH-1:0] id_ex_imm;
logic [4:0]            id_ex_rs1_addr;
logic [4:0]            id_ex_rs2_addr;
logic [4:0]            id_ex_rd_addr;
logic                  id_ex_reg_write;
logic                  id_ex_mem_read;
logic                  id_ex_mem_write;
logic [1:0]            id_ex_mem_size;
logic                  id_ex_branch;
logic                  id_ex_jump;
logic [1:0]            id_ex_result_src;
logic [3:0]            id_ex_alu_op;
logic                  id_ex_imm_valid;
logic [DATA_WIDTH-1:0] id_ex_instr;      // Track instruction for debugging

// EX/MEM
logic [DATA_WIDTH-1:0] ex_mem_pc;
logic [DATA_WIDTH-1:0] ex_mem_alu_result;
logic [DATA_WIDTH-1:0] ex_mem_rs2_data;
logic [DATA_WIDTH-1:0] ex_mem_imm;
logic [4:0]            ex_mem_rd_addr;
logic                  ex_mem_reg_write;
logic                  ex_mem_mem_read;
logic                  ex_mem_mem_write;
logic [1:0]            ex_mem_mem_size;
logic [1:0]            ex_mem_result_src;
logic                  ex_mem_zero_flag;
logic                  ex_mem_branch;
logic                  ex_mem_jump;
logic [DATA_WIDTH-1:0] ex_mem_instr;     // Track instruction for debugging

// MEM/WB
logic [DATA_WIDTH-1:0] mem_wb_alu_result;
logic [DATA_WIDTH-1:0] mem_wb_mem_data;
logic [DATA_WIDTH-1:0] mem_wb_pc;
logic [4:0]            mem_wb_rd_addr;
logic                  mem_wb_reg_write;
logic [1:0]            mem_wb_result_src;
logic [DATA_WIDTH-1:0] mem_wb_instr;     // Track instruction for debugging

// Control signals
assign instr_valid = 1'b1;
assign take_branch = ex_mem_branch && ex_mem_zero_flag;
assign pc_src = take_branch || ex_mem_jump;
assign pc_write = !stall_pipeline;

// Debug signals
`ifdef SIMULATION
    // Function to print instruction
    function automatic void print_instr_info(input string stage, input logic [31:0] instr);
        $display("%s Stage Instruction: 0x%h", stage, instr);
    endfunction
`endif

// Enhanced ALU input selection with debug output
always_comb begin
    // Select ALU input A based on forwarding control
    case (forward_a)
        2'b00: begin
            alu_input_a = id_ex_rs1_data;
            `ifdef SIMULATION
                $display("ALU_A: Using rs1 data directly: x%0d = 0x%h", id_ex_rs1_addr, id_ex_rs1_data);
            `endif
        end
        2'b01: begin
            alu_input_a = rd_data;
            `ifdef SIMULATION
                $display("ALU_A: Using WB forwarded data: x%0d = 0x%h", mem_wb_rd_addr, rd_data);
            `endif
        end
        2'b10: begin
            alu_input_a = ex_mem_alu_result;
            `ifdef SIMULATION
                $display("ALU_A: Using MEM forwarded data: x%0d = 0x%h", ex_mem_rd_addr, ex_mem_alu_result);
            `endif
        end
        default: begin
            alu_input_a = id_ex_rs1_data;
            `ifdef SIMULATION
                $display("ALU_A: Default case - Using rs1 data: x%0d = 0x%h", id_ex_rs1_addr, id_ex_rs1_data);
            `endif
        end
    endcase
    
    // Select ALU input B based on forwarding control
    case (forward_b)
        2'b00: begin
            alu_rs2_input = id_ex_rs2_data;
            `ifdef SIMULATION
                $display("ALU_B (reg): Using rs2 data directly: x%0d = 0x%h", id_ex_rs2_addr, id_ex_rs2_data);
            `endif
        end
        2'b01: begin
            alu_rs2_input = rd_data;
            `ifdef SIMULATION
                $display("ALU_B (reg): Using WB forwarded data: x%0d = 0x%h", mem_wb_rd_addr, rd_data);
            `endif
        end
        2'b10: begin
            alu_rs2_input = ex_mem_alu_result;
            `ifdef SIMULATION
                $display("ALU_B (reg): Using MEM forwarded data: x%0d = 0x%h", ex_mem_rd_addr, ex_mem_alu_result);
            `endif
        end
        default: begin
            alu_rs2_input = id_ex_rs2_data;
            `ifdef SIMULATION
                $display("ALU_B (reg): Default case - Using rs2 data: x%0d = 0x%h", id_ex_rs2_addr, id_ex_rs2_data);
            `endif
        end
    endcase
    
    // Select immediate value or register value for ALU input B
    if (id_ex_imm_valid) begin
        alu_input_b = id_ex_imm;
        `ifdef SIMULATION
            $display("ALU_B: Using immediate: 0x%h", id_ex_imm);
        `endif
    end else begin
        alu_input_b = alu_rs2_input;
        `ifdef SIMULATION
            $display("ALU_B: Using rs2 data (possibly forwarded): x%0d = 0x%h", id_ex_rs2_addr, alu_rs2_input);
        `endif
    end
end

// Pipeline registers update
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        // Reset all pipeline registers
        if_id_pc <= '0;
        if_id_instr <= '0;
        
        id_ex_pc <= '0;
        id_ex_rs1_data <= '0;
        id_ex_rs2_data <= '0;
        id_ex_imm <= '0;
        id_ex_rs1_addr <= '0;
        id_ex_rs2_addr <= '0;
        id_ex_rd_addr <= '0;
        id_ex_reg_write <= '0;
        id_ex_mem_read <= '0;
        id_ex_mem_write <= '0;
        id_ex_mem_size <= '0;
        id_ex_branch <= '0;
        id_ex_jump <= '0;
        id_ex_result_src <= '0;
        id_ex_alu_op <= '0;
        id_ex_imm_valid <= '0;
        id_ex_instr <= '0;
        
        ex_mem_pc <= '0;
        ex_mem_alu_result <= '0;
        ex_mem_rs2_data <= '0;
        ex_mem_imm <= '0;
        ex_mem_rd_addr <= '0;
        ex_mem_reg_write <= '0;
        ex_mem_mem_read <= '0;
        ex_mem_mem_write <= '0;
        ex_mem_mem_size <= '0;
        ex_mem_result_src <= '0;
        ex_mem_zero_flag <= '0;
        ex_mem_branch <= '0;
        ex_mem_jump <= '0;
        ex_mem_instr <= '0;
        
        mem_wb_alu_result <= '0;
        mem_wb_mem_data <= '0;
        mem_wb_pc <= '0;
        mem_wb_rd_addr <= '0;
        mem_wb_reg_write <= '0;
        mem_wb_result_src <= '0;
        mem_wb_instr <= '0;
    end
    else begin
        // Update IF/ID stage - controlled by stall
        if (!stall_pipeline) begin
            if (pc_src) begin
                // On branch/jump, insert a bubble (NOP) into the pipeline
                if_id_pc <= pc_out;
                if_id_instr <= 32'h00000013;  // NOP instruction (addi x0, x0, 0)
                `ifdef SIMULATION
                    $display("IF/ID: Inserting NOP due to branch/jump");
                `endif
            end else begin
                if_id_pc <= pc_out;
                if_id_instr <= instr;
                `ifdef SIMULATION
                    $display("IF/ID: Loading instruction 0x%h from PC 0x%h", instr, pc_out);
                `endif
            end
        end else begin
            `ifdef SIMULATION
                $display("IF/ID: Stalled (keeping current values)");
            `endif
        end
        
        // Update ID/EX stage
        if (stall_pipeline) begin
            // Insert bubble on stall
            id_ex_reg_write <= 1'b0;
            id_ex_mem_read <= 1'b0;
            id_ex_mem_write <= 1'b0;
            id_ex_branch <= 1'b0;
            id_ex_jump <= 1'b0;
            id_ex_instr <= 32'h00000013;  // NOP
            `ifdef SIMULATION
                $display("ID/EX: Inserting NOP due to stall");
            `endif
        end else if (pc_src) begin
            // Insert bubble on branch/jump taken
            id_ex_reg_write <= 1'b0;
            id_ex_mem_read <= 1'b0;
            id_ex_mem_write <= 1'b0;
            id_ex_branch <= 1'b0;
            id_ex_jump <= 1'b0;
            id_ex_instr <= 32'h00000013;  // NOP
            `ifdef SIMULATION
                $display("ID/EX: Inserting NOP due to branch/jump");
            `endif
        end else begin
            // Normal operation
            id_ex_pc <= if_id_pc;
            id_ex_rs1_data <= rs1_data;
            id_ex_rs2_data <= rs2_data;
            id_ex_imm <= imm_value;
            id_ex_rs1_addr <= rs1_addr;
            id_ex_rs2_addr <= rs2_addr;
            id_ex_rd_addr <= rd_addr;
            id_ex_reg_write <= reg_write_en;
            id_ex_mem_read <= mem_read;
            id_ex_mem_write <= mem_write;
            id_ex_mem_size <= mem_size;
            id_ex_branch <= branch;
            id_ex_jump <= jump;
            id_ex_result_src <= result_src;
            id_ex_alu_op <= alu_op;
            id_ex_imm_valid <= imm_valid;
            id_ex_instr <= if_id_instr;
            `ifdef SIMULATION
                $display("ID/EX: Processing instruction 0x%h", if_id_instr);
                $display("ID/EX: rs1=x%0d (0x%h), rs2=x%0d (0x%h), rd=x%0d",
                         rs1_addr, rs1_data, rs2_addr, rs2_data, rd_addr);
                if (imm_valid) $display("ID/EX: imm=0x%h", imm_value);
            `endif
        end
        
        // Update EX/MEM stage - Always update these registers
        ex_mem_pc <= id_ex_pc;
        ex_mem_alu_result <= alu_result;
        ex_mem_rs2_data <= alu_rs2_input; // Use forwarded value
        ex_mem_imm <= id_ex_imm;
        ex_mem_rd_addr <= id_ex_rd_addr;
        ex_mem_reg_write <= id_ex_reg_write;
        ex_mem_mem_read <= id_ex_mem_read;
        ex_mem_mem_write <= id_ex_mem_write;
        ex_mem_mem_size <= id_ex_mem_size;
        ex_mem_result_src <= id_ex_result_src;
        ex_mem_zero_flag <= zero_flag;
        ex_mem_branch <= id_ex_branch;
        ex_mem_jump <= id_ex_jump;
        ex_mem_instr <= id_ex_instr;
        `ifdef SIMULATION
            if (id_ex_reg_write) 
                $display("EX/MEM: ALU result=0x%h for rd=x%0d", alu_result, id_ex_rd_addr);
            if (id_ex_branch)
                $display("EX/MEM: Branch condition=%b", zero_flag);
        `endif
        
        // Update MEM/WB stage - Always update these registers
        mem_wb_alu_result <= ex_mem_alu_result;
        mem_wb_mem_data <= mem_rdata;
        mem_wb_pc <= ex_mem_pc;
        mem_wb_rd_addr <= ex_mem_rd_addr;
        mem_wb_reg_write <= ex_mem_reg_write;
        mem_wb_result_src <= ex_mem_result_src;
        mem_wb_instr <= ex_mem_instr;
        `ifdef SIMULATION
            if (ex_mem_mem_read)
                $display("MEM/WB: Memory read data=0x%h from addr=0x%h", 
                         mem_rdata, ex_mem_alu_result);
            else if (ex_mem_reg_write)
                $display("MEM/WB: Writing back 0x%h to rd=x%0d", 
                         (ex_mem_result_src == 2'b01) ? mem_rdata : ex_mem_alu_result,
                         ex_mem_rd_addr);
        `endif
    end
end

// Instruction modules
program_counter pc_inst (
    .clk(clk),
    .rst_n(rst_n),
    .pc_write(pc_write),
    .branch_en(take_branch),
    .jmp_en(ex_mem_jump),
    .imm(ex_mem_imm),
    .pc_i(pc_src ? ex_mem_pc : pc_out),
    .pc_out(pc_out)
);

instr_mem instr_mem_inst (
    .clk(clk),
    .rst_n(rst_n),
    .addr_i(pc_out),
    .instr_o(instr)
);

// Decode modules
sdecode sdecode_inst (
    .clk(clk),
    .rst_n(rst_n),
    .instr_in(if_id_instr),
    .instr_valid(instr_valid),
    .rs1_addr_o(rs1_addr),
    .rs2_addr_o(rs2_addr),
    .rd_addr_o(rd_addr),
    .reg_write_en_o(reg_write_en),
    .imm_value_o(imm_value),
    .imm_valid_o(imm_valid),
    .alu_op_o(alu_op),
    .mem_read_o(mem_read),
    .mem_write_o(mem_write),
    .mem_size_o(mem_size),
    .branch_o(branch),
    .jump_o(jump),
    .result_src_o(result_src),
    .uses_rs1_o(uses_rs1),
    .uses_rs2_o(uses_rs2)
);

sregfile sregfile_inst (
    .clk(clk),
    .rst_n(rst_n),
    .rs1_addr_i(rs1_addr),
    .rs1_data_o(rs1_data),
    .rs2_addr_i(rs2_addr),
    .rs2_data_o(rs2_data),
    .rd_addr_i(mem_wb_rd_addr),
    .rd_data_i(rd_data),
    .reg_write_en_i(mem_wb_reg_write)
);

// Execute modules
salu salu_inst (
    .clk(clk),
    .rst_n(rst_n),
    .rs1_data_i(alu_input_a),
    .rs2_data_i(alu_input_b),
    .alu_op_in(id_ex_alu_op),
    .alu_res_o(alu_result),
    .zero_flag_o(zero_flag),
    .negative_flag_o(negative_flag),
    .overflow_flag_o(overflow_flag)
);

// Memory modules
sdatamem sdatamem_inst (
    .clk(clk),
    .rst_n(rst_n),
    .mem_read_i(ex_mem_mem_read),
    .mem_write_i(ex_mem_mem_write),
    .mem_size_i(ex_mem_mem_size),
    .addr_i(ex_mem_alu_result),
    .wdata_i(ex_mem_rs2_data),
    .rdata_o(mem_rdata)
);

// Writeback module
swbmux swbmux_inst (
    .result_src_i(mem_wb_result_src),
    .alu_result(mem_wb_alu_result),
    .mem_rdata(mem_wb_mem_data),
    .pc_i(mem_wb_pc),
    .rd_data_o(rd_data)
);

// Hazard handling modules
shazard_detection shazard_detect_inst (
    .id_rs1_addr(rs1_addr),
    .id_rs2_addr(rs2_addr),
    .id_uses_rs1(uses_rs1),
    .id_uses_rs2(uses_rs2),
    .ex_mem_read(id_ex_mem_read),
    .ex_rd_addr(id_ex_rd_addr),
    .stall_pipeline(stall_pipeline)
);

forwarding_unit forward_inst (
    .ex_rs1_addr(id_ex_rs1_addr),
    .ex_rs2_addr(id_ex_rs2_addr),
    .mem_reg_write(ex_mem_reg_write),
    .mem_rd_addr(ex_mem_rd_addr),
    .wb_reg_write(mem_wb_reg_write),
    .wb_rd_addr(mem_wb_rd_addr),
    // Debug instruction tracking
    .ex_instr(id_ex_instr),
    .mem_instr(ex_mem_instr),
    .wb_instr(mem_wb_instr),
    // Outputs
    .forward_a(forward_a),
    .forward_b(forward_b)
);

`ifdef SIMULATION
// Track statistics
int cycle_count = 0;
int instruction_count = 0;

// Monitor key signals
always @(posedge clk) begin
    if (rst_n) begin
        cycle_count <= cycle_count + 1;
        
        // Monitor PC at reset
        if (cycle_count <= 5) begin
            $display("Cycle %0d: PC=0x%h", cycle_count, pc_out);
        end
        
        // Monitor instruction execution
        if (!stall_pipeline && if_id_instr != 32'h0) begin
            instruction_count <= instruction_count + 1;
            $display("Executed instruction %0d: 0x%h at PC=0x%h", 
                     instruction_count, if_id_instr, if_id_pc);
        end
    end
end
`endif

endmodule
