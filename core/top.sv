/*
 * 32-bit RISC-V Vector Core
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

module top #(
    parameter int DATA_WIDTH = 32,
    parameter int MAX_PC = 32'h00000100  // Limit PC to reasonable program space
) (
    input logic clk,
    input logic rst_n
);

// Define a maximum cycle count to prevent infinite loops
localparam int MAX_CYCLES = 2000;  // Adjust as needed
int cycle_count = 0;

// Cycle counter to detect infinite loops
`ifdef SIMULATION
always @(posedge clk) begin
    if (!rst_n) begin
        cycle_count <= cycle_count + 1;
        if (cycle_count >= MAX_CYCLES) begin
            $display("TOP: WARNING: Maximum cycle count (%0d) reached. Terminating simulation.", MAX_CYCLES);
            // Add register dump and endianness comparison before termination
            sregfile_inst.dump_registers();
            $finish;
        end
    end
end
`endif

// Internal signals
// Program counter and instruction signals
logic [DATA_WIDTH-1:0] pc_out;
logic [DATA_WIDTH-1:0] instr;
logic                  instr_valid;
logic                  stall_pipeline;
logic                  pc_write;
logic                  take_branch;
logic                  pc_src;

logic [6:0]             opcode;
logic [4:0]             rs1_addr;
logic [4:0]             rs2_addr;
logic [4:0]             rd_addr;
logic [2:0]             funct3; 
logic [6:0]             funct7; 
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
logic [31:0]            last_pc;
logic [9:0]             same_pc_counter;  // Track how many cycles PC has been unchanged
logic                   detected_infinite_loop;

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

logic [DATA_WIDTH-1:0] forwarded_rs1_value;
logic [DATA_WIDTH-1:0] forwarded_rs2_value;

// JALR case
logic jalr;
logic id_ex_jalr;  // ID/EX pipeline register
logic ex_mem_jalr;  // EX/MEM pipeline register

logic [DATA_WIDTH-1:0] ex_mem_rs1_data_jalr;  // New register to store rs1 for JALR

// LUI case
logic mem_unsigned;
logic id_ex_mem_unsigned;
logic ex_mem_mem_unsigned;

// Control signals
assign instr_valid = 1'b1;
assign take_branch = ex_mem_branch && ex_mem_zero_flag;
assign pc_src = take_branch || ex_mem_jump;
assign pc_write = !stall_pipeline;

assign opcode   = if_id_instr[6:0];
assign rs1_addr = if_id_instr[19:15];  // Extract rs1 (bits 19:15)
assign rs2_addr = if_id_instr[24:20];  // Extract rs2 (bits 24:20)
assign rd_addr  = if_id_instr[11:7];    // Extract rd (bits 11:7) 
assign funct3   = if_id_instr[14:12];
assign funct7   = if_id_instr[31:25];


    // Enhanced ALU input selection with debug output
    always_comb begin
        // Select forwarded RS1 value
        case (forward_a)
            2'b00: forwarded_rs1_value = id_ex_rs1_data;
            2'b01: forwarded_rs1_value = rd_data;             // From WB stage
            2'b10: forwarded_rs1_value = ex_mem_alu_result;   // From MEM stage
            default: forwarded_rs1_value = id_ex_rs1_data;
        endcase
        
        // Select forwarded RS2 value
        case (forward_b)
            2'b00: forwarded_rs2_value = id_ex_rs2_data;
            2'b01: forwarded_rs2_value = rd_data;             // From WB stage
            2'b10: forwarded_rs2_value = ex_mem_alu_result;   // From MEM stage
            default: forwarded_rs2_value = id_ex_rs2_data;
        endcase
        
        // Handle special cases for ALU input A
        // Check instruction opcode to handle LUI and AUIPC
        // Use the opcode bits directly without declaring a variable
        case (id_ex_instr[6:0])  // Direct use of opcode bits
            7'b0110111: begin // LUI - use 0 as input A
                alu_input_a = 32'b0;
            end
            7'b0010111: begin // AUIPC - use PC as input A
                alu_input_a = id_ex_pc;
            end
            default: begin
                alu_input_a = forwarded_rs1_value;
            end
        endcase
        
        // For ALU input B, check if immediate should be used
        if (id_ex_imm_valid) begin
            alu_input_b = id_ex_imm;
        end else begin
            alu_input_b = forwarded_rs2_value;
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
        id_ex_mem_unsigned <= '0; // LUI
        
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

        id_ex_jalr <= 1'b0;
        ex_mem_jalr <= 1'b0;
        ex_mem_rs1_data_jalr <= '0;
    end
    else begin
        // Update IF/ID stage - controlled by stall
        if (!stall_pipeline) begin
            if (pc_src) begin
                if_id_pc <= pc_out;
                if_id_instr <= 32'h00000013;  // NOP instruction (addi x0, x0, 0)

            end else begin
                if_id_pc <= pc_out;
                if_id_instr <= instr;

            end
        end 
        
        else begin
            
            `ifdef SIMULATION
                $display("TOP: IF/ID: Stalled (keeping current values)");
            `endif
            // Keep existing values during stall - no update needed
        end
        
        if (stall_pipeline) begin
            // Insert bubble on stall
            id_ex_reg_write <= 1'b0;
            id_ex_mem_read <= 1'b0;
            id_ex_mem_write <= 1'b0;
            id_ex_branch <= 1'b0;
            id_ex_jump <= 1'b0;
            id_ex_instr <= 32'h00000013;  // NOP

        end else if (pc_src) begin
            id_ex_pc <= if_id_pc;
            id_ex_rs1_data <= rs1_data;
            id_ex_rs2_data <= rs2_data;
            id_ex_rs1_addr <= rs1_addr;
            id_ex_rs2_addr <= rs2_addr;
            id_ex_rd_addr <= 5'b0;
            id_ex_reg_write <= 1'b0;
            id_ex_mem_read <= 1'b0;
            id_ex_mem_write <= 1'b0;
            id_ex_branch <= 1'b0;
            id_ex_jump <= 1'b0;
            id_ex_result_src <= 2'b00;
            id_ex_alu_op <= 4'b0000;
            id_ex_imm <= '0;
            id_ex_imm_valid <= 1'b0;
            id_ex_instr <= 32'h00000013;

        end else begin
            if (id_ex_jalr) begin
                ex_mem_rs1_data_jalr <= forwarded_rs1_value;
            end
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
            id_ex_jalr <= jalr;
            id_ex_mem_unsigned <= mem_unsigned;
        end
        
        // Update EX/MEM stage
        ex_mem_pc <= id_ex_pc;
        ex_mem_alu_result <= alu_result;
        ex_mem_rs2_data <= forwarded_rs2_value;
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

        ex_mem_jalr <= id_ex_jalr;

        ex_mem_mem_unsigned <= id_ex_mem_unsigned;
    end
end

always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        mem_wb_alu_result <= '0;
        mem_wb_mem_data <= '0;
        mem_wb_pc <= '0;
        mem_wb_rd_addr <= '0;
        mem_wb_reg_write <= '0;
        mem_wb_result_src <= '0;
        mem_wb_instr <= '0;
    end else begin
        // Update MEM/WB stage unconditionally
        mem_wb_alu_result <= ex_mem_alu_result;
        mem_wb_mem_data <= mem_rdata;
        mem_wb_pc <= ex_mem_pc;
        mem_wb_rd_addr <= ex_mem_rd_addr;
        mem_wb_reg_write <= ex_mem_reg_write;
        mem_wb_result_src <= ex_mem_result_src;
        mem_wb_instr <= ex_mem_instr;
        
        // `ifdef SIMULATION
        //     if (ex_mem_reg_write && ex_mem_rd_addr != 5'b0) begin
        //         $display("TOP: PIPELINE: MEM/WB stage update - ex_mem_alu_result=0x%h, rd=x%0d",
        //                 ex_mem_alu_result, ex_mem_rd_addr);
        //     end
        // `endif

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
    .pc_out(pc_out),

    .jalr_en(ex_mem_jalr),
    .rs1_data(ex_mem_rs1_data_jalr)
);

instr_mem instr_mem_inst (
    .clk(clk),
    .rst_n(rst_n),
    .addr_i(pc_out),
    .instr_o(instr)
);

control control_inst (
    .instr_in(if_id_instr),
    .instr_valid(instr_valid),
    .opcode_in(opcode),
    .funct3_in(funct3),
    .funct7_in(funct7),
    .reg_write_en_o(reg_write_en),
    .alu_op_o(alu_op),
    .mem_read_o(mem_read),
    .mem_write_o(mem_write),
    .mem_size_o(mem_size),
    .branch_o(branch),
    .jump_o(jump),
    .result_src_o(result_src),
    .uses_rs1_o(uses_rs1),
    .uses_rs2_o(uses_rs2),
    .jalr_o(jalr),
    .mem_unsigned_o(mem_unsigned)
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
    .regw_en_i(mem_wb_reg_write)
);

signex signex_inst (
    .opcode_in(opcode),
    .instr_in(if_id_instr),
    .imm_valid_o(imm_valid),
    .imm_value_o(imm_value)
);

// Execute modules
salu salu_inst (
    .rs1_data_i(alu_input_a),
    .rs2_data_i(alu_input_b),
    .alu_op_in(id_ex_alu_op),
    .alu_res_o(alu_result),
    .zero_flag_o(zero_flag),
    .negative_flag_o(negative_flag),
    .overflow_flag_o(overflow_flag)
);

// Memory modules
datamem datamem_inst (
    .clk(clk),
    .rst_n(rst_n),
    .mem_read_i(ex_mem_mem_read),
    .mem_write_i(ex_mem_mem_write),
    .mem_size_i(ex_mem_mem_size),
    .addr_i(ex_mem_alu_result),
    .wdata_i(ex_mem_rs2_data),
    .rdata_o(mem_rdata),

    // Added debug output for memory operations -- REMOVE IN FINAL VERSION
    .curr_instr(ex_mem_instr),
    .curr_pc(ex_mem_pc),

    // LUI case
    .mem_unsigned_i(ex_mem_mem_unsigned)
);

// Writeback module
wbmux wbmux_inst (
    .result_src_i(mem_wb_result_src),
    .alu_result(mem_wb_alu_result),
    .mem_rdata(mem_wb_mem_data),
    .pc_i(mem_wb_pc),
    .rd_data_o(rd_data)
);

// Hazard handling modules
hazard_detection hazard_detect_inst (
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
    // Added regfile read data for additional checking
    // .reg_rs2_data(sregfile_inst.register[id_ex_rs2_addr]),
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
int instruction_count = 0;

// Monitor key signals
always @(posedge clk) begin
    if (rst_n) begin
        // Note: cycle_count increment is already handled in the earlier block
        
        // Monitor PC at reset
        if (cycle_count % 10 == 0) begin
            $display("TOP: Cycle %0d: PC=0x%h", cycle_count, pc_out);
        end
        
        // Monitor instruction execution
        if (!stall_pipeline && if_id_instr != 32'h0) begin
            instruction_count <= instruction_count + 1;
            $display("TOP: Executed instruction %0d: 0x%h at PC=0x%h", 
                     instruction_count, if_id_instr, if_id_pc);
        end
    end
end

// Enhanced PC range checking
always @(posedge clk) begin
    if (rst_n && pc_out > MAX_PC) begin
        $display("TOP: WARNING: PC (0x%h) is beyond expected program range", pc_out);
        $display("TOP: This may indicate an execution error or jump to invalid memory");
    end
end
`endif

// EBREAK/ECALL detection at multiple pipeline stages
`ifdef SIMULATION
always @(posedge clk) begin
    int fd;

    if (rst_n) begin
        // Check at IF/ID stage
        if (if_id_instr == 32'h00100073) begin // EBREAK
            $display("TOP: \n==== EBREAK DETECTED at IF/ID stage (PC=0x%h) ====", if_id_pc);
            
            // Create register dump file for verification
            fd = $fopen("register_dump.txt", "w");
            
            if (fd != 0) begin
                for (int i = 0; i < 32; i = i + 1) begin
                    $fdisplay(fd, "x%0d=%0d", i, sregfile_inst.register[i]);
                end
                $fclose(fd);
                $display("TOP: Register dump created: register_dump.txt");
            end else begin
                $display("TOP: Error: Could not create register dump file");
            end
            
            sregfile_inst.dump_registers();
            $finish;
        end
        
        // Check at ID/EX stage (in case it was missed in IF/ID)
        if (id_ex_instr == 32'h00100073) begin // EBREAK
            $display("TOP: \n==== EBREAK DETECTED at ID/EX stage (PC=0x%h) ====", id_ex_pc);
            sregfile_inst.dump_registers();
            $finish;
        end
        
        // Also check for ECALL (sometimes used as alternative exit)
        if (if_id_instr == 32'h00000073 || id_ex_instr == 32'h00000073) begin
            $display("TOP: \n==== ECALL DETECTED (PC=0x%h) ====", 
                    (if_id_instr == 32'h00000073) ? if_id_pc : id_ex_pc);
            sregfile_inst.dump_registers();
            $finish;
        end
    end
end
`endif



endmodule
