/*
 * 32-bit RISC-V Vector Core - Fixed Version
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
    if (rst_n) begin
        cycle_count <= cycle_count + 1;
        if (cycle_count >= MAX_CYCLES) begin
            $display("WARNING: Maximum cycle count (%0d) reached. Terminating simulation.", MAX_CYCLES);
            // Add register dump and endianness comparison before termination
            sregfile_inst.dump_registers();
            display_endianness_comparison();
            $finish;
        end
    end
end
`endif

`ifdef SIMULATION
// Debug instruction decode
always @(posedge clk) begin
    if (rst_n) begin
        // Track the ADD instructions specifically
        if (if_id_instr == 32'h002081b3) begin // ADD x3, x1, x2
            $display("FOUND ADD INSTRUCTION (x3 = x1 + x2)");
            
            // Show source register values
            $display("REGISTER VALUES: x1=0x%h, x2=0x%h", 
                     sregfile_inst.register[1], 
                     sregfile_inst.register[2]);
                     
            // Track this instruction through pipeline stages
            $display("ADD in ID/EX: rs1=x%0d (0x%h), rs2=x%0d (0x%h), rd=x%0d",
                     id_ex_rs1_addr, id_ex_rs1_data, 
                     id_ex_rs2_addr, id_ex_rs2_data,
                     id_ex_rd_addr);
        end
        
        // Track memory operations
        if (ex_mem_mem_write) begin
            $display("MEMORY WRITE OPERATION: addr=0x%h, data=0x%h, size=%0d", 
                    ex_mem_alu_result, ex_mem_rs2_data, ex_mem_mem_size);
        end
        
        if (ex_mem_mem_read) begin
            $display("MEMORY READ OPERATION: addr=0x%h, size=%0d", 
                    ex_mem_alu_result, ex_mem_mem_size);
        end
        
        // Track when ADD instruction moves to EX/MEM stage
        if (id_ex_instr == 32'h002081b3) begin
            $display("ADD in EX/MEM: ALU result = 0x%h, rd=x%0d, reg_write=%b",
                     alu_result, id_ex_rd_addr, id_ex_reg_write);
        end
        
        // Track when ADD instruction moves to MEM/WB stage
        if (ex_mem_instr == 32'h002081b3) begin
            $display("ADD in MEM/WB: result = 0x%h, rd=x%0d, reg_write=%b",
                     ex_mem_alu_result, ex_mem_rd_addr, ex_mem_reg_write);
                     
            // Check register file update
            $display("Register x3 should be updated to 0x%h", ex_mem_alu_result);
        end
    end
end

// Register file write monitoring
always @(posedge clk) begin
    if (rst_n && mem_wb_reg_write && mem_wb_rd_addr != 5'b0) begin
        $display("TOP: About to write to register x%0d, value=0x%h, reg_write_en=%b", 
                 mem_wb_rd_addr, rd_data, mem_wb_reg_write);
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

// Control signals
assign instr_valid = 1'b1;
assign take_branch = ex_mem_branch && ex_mem_zero_flag;
assign pc_src = take_branch || ex_mem_jump;
assign pc_write = !stall_pipeline;

// Debug signals
`ifdef SIMULATION
    // Function to print instruction
    function void print_instr_info(input string stage, input logic [31:0] instr_val);
        $display("%s Stage Instruction: 0x%h", stage, instr_val);
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
            
            // Decode instruction type for better debugging - without local variables
            if (id_ex_instr[6:0] == 7'b0010011) begin
                if (id_ex_instr[14:12] == 3'b001)
                    $display("SLLI instruction: Using imm = 0x%h as shift amount", id_ex_imm);
                else
                    $display("I-type instruction: Using imm = 0x%h", id_ex_imm);
            end
        `endif
    end else begin
        alu_input_b = alu_rs2_input;
        `ifdef SIMULATION
            $display("ALU_B: Using rs2 data (possibly forwarded): x%0d = 0x%h", id_ex_rs2_addr, alu_rs2_input);
            
            // Decode instruction type for better debugging - without local variables
            if (id_ex_instr[6:0] == 7'b0110011) begin
                if (id_ex_instr[14:12] == 3'b000 && id_ex_instr[31:25] == 7'b0000000)
                    $display("ADD instruction: Using rs2 = 0x%h as second operand", alu_rs2_input);
                else
                    $display("R-type instruction: Using rs2 = 0x%h", alu_rs2_input);
            end
        `endif
    end
    
    // Final safety check to ensure ADD instruction has correct operands
    if (id_ex_instr == 32'h002081b3) begin
        // This is the ADD x3, x1, x2 instruction
        // Verify and print ALU inputs for debugging
        `ifdef SIMULATION
            $display("ADD INSTRUCTION VERIFICATION:");
            $display("  rs1=x1 (addr=%0d), value=0x%h", id_ex_rs1_addr, alu_input_a);
            $display("  rs2=x2 (addr=%0d), value=0x%h", id_ex_rs2_addr, alu_input_b);
            $display("  rd=x3 (addr=%0d)", id_ex_rd_addr);
            
            if (id_ex_rs1_addr != 5'd1 || id_ex_rs2_addr != 5'd2 || id_ex_rd_addr != 5'd3) begin
                $display("WARNING: Register addresses for ADD instruction may be incorrect!");
                $display("Expected: rs1=x1, rs2=x2, rd=x3");
                $display("Actual: rs1=x%0d, rs2=x%0d, rd=x%0d", id_ex_rs1_addr, id_ex_rs2_addr, id_ex_rd_addr);
            end
        `endif
    end
end

// Pipeline registers update - The fixed version
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        // Reset all pipeline registers (no changes needed here)
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
            // Keep existing values during stall - no update needed
        end
        
        // Update ID/EX stage - FIX: Be explicit about what happens during stalls
        if (stall_pipeline) begin
            // Insert bubble on stall - explicitly set all control signals to inactive
            id_ex_reg_write <= 1'b0;
            id_ex_mem_read <= 1'b0;
            id_ex_mem_write <= 1'b0;
            id_ex_branch <= 1'b0;
            id_ex_jump <= 1'b0;
            id_ex_instr <= 32'h00000013;  // NOP
            // FIX: Keep register addresses valid but set control signals to 0
            // This ensures correct forwarding but prevents updates
            `ifdef SIMULATION
                $display("ID/EX: Inserting NOP due to stall");
            `endif
        end else if (pc_src) begin
            // Insert bubble on branch/jump taken - FIX: explicitly set all control signals
            id_ex_pc <= if_id_pc;         // Keep the PC value
            id_ex_rs1_data <= rs1_data;   // Keep the register data
            id_ex_rs2_data <= rs2_data;
            id_ex_rs1_addr <= rs1_addr;   // Keep the register addresses
            id_ex_rs2_addr <= rs2_addr;
            id_ex_rd_addr <= 5'b0;        // FIX: Set destination to x0 (no write)
            id_ex_reg_write <= 1'b0;      // Disable register write
            id_ex_mem_read <= 1'b0;       // Disable memory operations
            id_ex_mem_write <= 1'b0;
            id_ex_branch <= 1'b0;         // Disable branch/jump
            id_ex_jump <= 1'b0;
            id_ex_result_src <= 2'b00;    // Default to ALU result
            id_ex_alu_op <= 4'b0000;      // Default to ADD operation
            id_ex_imm <= '0;              // Zero immediate
            id_ex_imm_valid <= 1'b0;      // Disable immediate
            id_ex_instr <= 32'h00000013;  // NOP instruction
            `ifdef SIMULATION
                $display("ID/EX: Inserting NOP due to branch/jump");
            `endif
        end else begin
            // Normal operation - keep the same logic
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

            // Add debug to track values through pipeline
            `ifdef SIMULATION
                if (if_id_instr == 32'h002081b3) begin  // ADD x3, x1, x2
                    $display("ID/EX PIPELINE: ADD instruction entering EX stage");
                    $display("  rs1_addr=x%0d, rs2_addr=x%0d, rd_addr=x%0d", 
                            rs1_addr, rs2_addr, rd_addr);
                    $display("  rs1_data=0x%h, rs2_data=0x%h", rs1_data, rs2_data);
                end
            `endif
        end
        
        // Update EX/MEM stage - FIX: Be consistent with the forwarded data
        // Update EX/MEM stage
        ex_mem_pc <= id_ex_pc;
        ex_mem_alu_result <= alu_result;

        // FIX: Use the correct forwarded value for rs2_data (for memory writes)
        // Updated logic for forwarding in store instructions
        if (id_ex_mem_write) begin
            // For store instructions, ensure forwarded data is used
            if (forward_b == 2'b01) begin
                // WB stage forwarding
                ex_mem_rs2_data <= rd_data;
            end else if (forward_b == 2'b10) begin
                // MEM stage forwarding
                ex_mem_rs2_data <= ex_mem_alu_result;
            end else begin
                // No forwarding
                ex_mem_rs2_data <= id_ex_rs2_data;
            end
        end else begin
            // Normal case for non-store instructions
            ex_mem_rs2_data <= id_ex_rs2_data;
        end

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

        // Add extra debug for store instructions
        `ifdef SIMULATION
            if (id_ex_mem_write) begin
                $display("STORE INSTRUCTION MOVING TO MEM STAGE:");
                $display("  rs2_addr=x%0d, forwarded=%b, forward_sel=%b", 
                        id_ex_rs2_addr, (forward_b != 2'b00), forward_b);
                $display("  Original rs2_data=0x%h", id_ex_rs2_data);
                case (forward_b)
                    2'b01: $display("  Forwarded rs2_data from WB=0x%h", rd_data);
                    2'b10: $display("  Forwarded rs2_data from MEM=0x%h", ex_mem_alu_result);
                endcase
                $display("  Final rs2_data to memory=0x%h", ex_mem_rs2_data);
            end
        `endif

        `ifdef SIMULATION
            if (id_ex_reg_write) 
                $display("EX/MEM: ALU result=0x%h for rd=x%0d", alu_result, id_ex_rd_addr);
            if (id_ex_branch)
                $display("EX/MEM: Branch condition=%b", zero_flag);
        `endif
        
        // Update MEM/WB stage
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
                        
            // Debug code for register write tracking
            if (ex_mem_reg_write && ex_mem_rd_addr != 5'b0) begin
                $display("PIPELINE: MEM/WB update - Setting mem_wb_reg_write=%b, mem_wb_rd_addr=x%0d, result_src=%b",
                        ex_mem_reg_write, ex_mem_rd_addr, ex_mem_result_src);
            end
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

// Debug signals for register file inputs
`ifdef SIMULATION
always @(posedge clk) begin
    if (rst_n && mem_wb_reg_write && mem_wb_rd_addr != 5'b0) begin
        $display("TOP: About to write to register x%0d, value=0x%h, reg_write_en=%b", 
                 mem_wb_rd_addr, rd_data, mem_wb_reg_write);
    end
end
`endif

`ifdef SIMULATION
// Enhanced jump tracking
always @(posedge clk) begin
    if (rst_n && if_id_instr[6:0] == 7'b1101111) begin  // JAL opcode
        $display("JUMP TRACKING: JAL detected at PC=0x%h, instr=0x%h", if_id_pc, if_id_instr);
        $display("JUMP TRACKING: Target should be PC=0x%h", if_id_pc + $signed({{12{if_id_instr[31]}}, if_id_instr[19:12], if_id_instr[20], if_id_instr[30:21], 1'b0}));
    end
    
    if (rst_n && ex_mem_jump) begin
        $display("JUMP TRACKING: Jump executing in MEM stage, PC=0x%h, target=0x%h", 
                 ex_mem_pc, ex_mem_pc + ex_mem_imm);
    end
end
`endif

sregfile sregfile_inst (
    .clk(clk),
    .rst_n(rst_n),
    .rs1_addr_i(rs1_addr),
    .rs1_data_o(rs1_data),
    .rs2_addr_i(rs2_addr),
    .rs2_data_o(rs2_data),
    .rd_addr_i(mem_wb_rd_addr),
    .rd_data_i(rd_data),
    .reg_write_i(mem_wb_reg_write)
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
int instruction_count = 0;

// Monitor key signals
always @(posedge clk) begin
    if (rst_n) begin
        // Note: cycle_count increment is already handled in the earlier block
        
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

// Enhanced PC range checking
always @(posedge clk) begin
    if (rst_n && pc_out > MAX_PC) begin
        $display("WARNING: PC (0x%h) is beyond expected program range", pc_out);
        $display("This may indicate an execution error or jump to invalid memory");
    end
end
`endif

task display_endianness_comparison;
    int i;
    logic [31:0] raw;
    
    $display("\n=== Register Values (Native RISC-V Little-Endian) ===");
    for (i = 1; i < 32; i++) begin
        raw = sregfile_inst.register[i];
        $display("  x%0d = 0x%08h (Bytes: %02x %02x %02x %02x)", 
                 i, raw, 
                 raw[7:0], raw[15:8], raw[23:16], raw[31:24]);
    end
endtask

// Add this block before endmodule
// Improved infinite loop detection logic - reduce threshold from 50 to 20 cycles
`ifdef SIMULATION
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        last_pc <= 32'hFFFFFFFF;  // Invalid initial value
        same_pc_counter <= 10'd0;
        detected_infinite_loop <= 1'b0;
    end else begin
        // Check if we're executing the same instruction repeatedly
        if (pc_out == last_pc) begin
            // Increment counter if we've been at the same PC
            if (same_pc_counter < 10'd20) begin  // Reduced from 50 to 20 cycles before detection
                same_pc_counter <= same_pc_counter + 1;
            end else if (!detected_infinite_loop) begin
                // Check the opcode to see if this is likely an infinite loop
                // JAL (opcode 1101111) or JALR (opcode 1100111) to same address
                if (instr[6:0] == 7'b1101111 || instr[6:0] == 7'b1100111) begin
                    $display("DETECTED: Infinite loop at PC=0x%08x, instruction=0x%08x", 
                             pc_out, instr);
                    $display("SIMULATION: Program appears to have terminated with infinite loop.");
                    
                    detected_infinite_loop <= 1'b1;
                    
                    // Display register values and endianness comparison
                    sregfile_inst.dump_registers();
                    display_endianness_comparison();
                    
                    // Gracefully terminate simulation
                    $finish;
                end
            end
        end else begin
            // Reset counter when PC changes
            same_pc_counter <= 10'd0;
        end
        
        last_pc <= pc_out;
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
            $display("\n==== EBREAK DETECTED at IF/ID stage (PC=0x%h) ====", if_id_pc);
            
            // Create register dump file for verification
            fd = $fopen("register_dump.txt", "w");
            
            if (fd != 0) begin
                for (int i = 0; i < 32; i = i + 1) begin
                    $fdisplay(fd, "x%0d=%0d", i, sregfile_inst.register[i]);
                end
                $fclose(fd);
                $display("Register dump created: register_dump.txt");
            end else begin
                $display("Error: Could not create register dump file");
            end
            
            sregfile_inst.dump_registers();
            $finish;
        end
        
        // Check at ID/EX stage (in case it was missed in IF/ID)
        if (id_ex_instr == 32'h00100073) begin // EBREAK
            $display("\n==== EBREAK DETECTED at ID/EX stage (PC=0x%h) ====", id_ex_pc);
            sregfile_inst.dump_registers();
            $finish;
        end
        
        // Also check for ECALL (sometimes used as alternative exit)
        if (if_id_instr == 32'h00000073 || id_ex_instr == 32'h00000073) begin
            $display("\n==== ECALL DETECTED (PC=0x%h) ====", 
                    (if_id_instr == 32'h00000073) ? if_id_pc : id_ex_pc);
            sregfile_inst.dump_registers();
            $finish;
        end
    end
end
`endif

// Add this check in the Monitor section of top.sv to verify register values
`ifdef SIMULATION
// Register value verification for initial instructions
always @(posedge clk) begin
    if (rst_n) begin
        // After the first two instructions should have executed (using cycle_count instead)
        if (cycle_count == 3) begin  // Changed from total_cycles to cycle_count
            $display("REGISTER VERIFICATION AT CYCLE 3:");
            $display("  x1 should be 1, actual value: 0x%h", sregfile_inst.register[1]);
            $display("  x2 should be 2, actual value: 0x%h", sregfile_inst.register[2]);
        end
        
        // Before ADD instruction executes (at PC=0x8)
        if (pc_out == 32'h00000008) begin
            $display("REGISTER CHECK BEFORE ADD: x1=0x%h, x2=0x%h", 
                     sregfile_inst.register[1], 
                     sregfile_inst.register[2]);
        end
    end
end
`endif

`ifdef SIMULATION
// Memory operation tracking
always @(posedge clk) begin
    if (rst_n) begin
        // Track the store instruction (SW x3, 0(x0))
        if (if_id_instr == 32'h00302023) begin
            $display("STORE INSTRUCTION DETECTED: SW x3, 0(x0)");
            $display("  Current value of x3: 0x%h", sregfile_inst.register[3]);
        end
        
        // Track the load instruction (LW x6, 0(x0))
        if (if_id_instr == 32'h00002303) begin
            $display("LOAD INSTRUCTION DETECTED: LW x6, 0(x0)");
            $display("  Memory at address 0: bytes %02x %02x %02x %02x",
                     sdatamem_inst.memory[0], 
                     sdatamem_inst.memory[1],
                     sdatamem_inst.memory[2],
                     sdatamem_inst.memory[3]);
        end
        
        // Track when memory writes actually happen
        if (ex_mem_mem_write && ex_mem_mem_size == 2'b10) begin
            $display("MEMORY WRITE EXECUTING: addr=0x%h, data=0x%h",
                     ex_mem_alu_result, ex_mem_rs2_data);
        end
    end
end
`endif

`ifdef SIMULATION
// Critical instruction tracking
always @(posedge clk) begin
    if (rst_n) begin
        static int instr_count = 0;
        
        // Track instruction execution by PC value
        if (pc_out == 32'h0) begin
            $display("\n=== Starting Program Execution ===\n");
            instr_count = 0;
        end
        
        // Increment counter only when a new instruction is fetched
        if (if_id_instr != 32'h0 && !stall_pipeline) begin
            instr_count++;
            
            case (instr_count)
                1: $display("Instruction 1: ADDI x1, x0, 1 - Setting x1=1");
                2: $display("Instruction 2: ADDI x2, x0, 2 - Setting x2=2");
                3: begin
                    $display("Instruction 3: ADD x3, x1, x2 - Should set x3=3");
                    $display("  Register values - x1=%0d, x2=%0d", 
                             sregfile_inst.register[1], sregfile_inst.register[2]);
                    $display("  Correctly decoded: rs1=x%0d, rs2=x%0d, rd=x%0d", 
                             rs1_addr, rs2_addr, rd_addr);
                end
            endcase
        end
    end
end
`endif

`ifdef SIMULATION
always @(posedge clk) begin
    if (rst_n && id_ex_instr[6:0] == 7'b0100011) begin  // Store opcode
        $display("STORE INSTRUCTION IN EX STAGE: instr=0x%h, rs2_addr=x%0d, rs2_data=0x%h",
                 id_ex_instr, id_ex_rs2_addr, id_ex_rs2_data);
        if (forward_b != 2'b00) begin
            $display("STORE FORWARDING ACTIVE: forward_b=%b", forward_b);
        end
    end
end
`endif

`ifdef SIMULATION
always @(posedge clk) begin
    if (rst_n && ex_mem_mem_write) begin
        $display("MEMORY STORE EXECUTION: addr=0x%h, data=0x%h", 
                 ex_mem_alu_result, ex_mem_rs2_data);
        if (ex_mem_alu_result == 0) begin
            $display("  MEMORY STORE TO ADDRESS 0: Storing value 0x%h", ex_mem_rs2_data);
            if (ex_mem_rs2_data != 3) begin
                $display("  WARNING: Expected to store value 3 (register x3), but storing 0x%h",
                         ex_mem_rs2_data);
            end else begin
                $display("  SUCCESS: Correctly storing value 3 from register x3");
            end
        end
    end
end

`endif

`ifdef SIMULATION
// Add enhanced tracking for memory operations
always @(posedge clk) begin
    if (rst_n) begin
        // Track store instructions specifically
        if (ex_mem_mem_write) begin
            $display("\nEXECUTING MEMORY STORE: addr=0x%h, data=0x%h", 
                     ex_mem_alu_result, ex_mem_rs2_data);
            
            if (ex_mem_instr[6:0] == 7'b0100011) begin
                // S-type instruction
                logic [4:0] local_rs2_addr = ex_mem_instr[24:20];
                $display("  STORE INSTRUCTION: Using rs2=x%0d (value=0x%h)", 
                         local_rs2_addr, ex_mem_rs2_data);
            end
            
            if (ex_mem_alu_result == 0) begin
                $display("  CRITICAL STORE TO ADDRESS 0: val=0x%h", ex_mem_rs2_data);
            end
        end
        
        // Track load instructions specifically
        if (ex_mem_mem_read) begin
            $display("\nEXECUTING MEMORY LOAD: addr=0x%h", ex_mem_alu_result);
            if (ex_mem_alu_result == 0) begin
                $display("  CRITICAL LOAD FROM ADDRESS 0");
                $display("  Memory contents: %02x %02x %02x %02x", 
                         sdatamem_inst.memory[0], sdatamem_inst.memory[1],
                         sdatamem_inst.memory[2], sdatamem_inst.memory[3]);
            end
        end
    end
end

// Add verification for store-load sequence
logic [31:0] address_0_contents;
always @(posedge clk) begin
    if (rst_n) begin
        // Track changes to memory at address 0
        address_0_contents = {sdatamem_inst.memory[3], sdatamem_inst.memory[2],
                              sdatamem_inst.memory[1], sdatamem_inst.memory[0]};
                             
        // Verify content changes at address 0
        if (ex_mem_mem_write && ex_mem_alu_result == 0) begin
            $display("VERIFICATION: About to store 0x%h to address 0", ex_mem_rs2_data);
        end
        
        // Check for loads by examining the result_src signal
        // LW instruction typically uses result_src = 01
        if (mem_wb_result_src == 2'b01 && mem_wb_alu_result == 0) begin
            $display("VERIFICATION: Loaded 0x%h from address 0", mem_wb_mem_data);
            if (mem_wb_mem_data == 3) begin
                $display("VERIFICATION PASSED: Successfully loaded correct value (3) from address 0");
            end else begin
                $display("VERIFICATION FAILED: Expected to load 3, got 0x%h", mem_wb_mem_data);
            end
        end
    end
end
`endif

endmodule
