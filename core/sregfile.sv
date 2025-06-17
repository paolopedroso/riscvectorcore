/*
 * Register File
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 *
 */

module sregfile #(
    parameter int DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst_n,
    
    // Register addresses
    input logic [4:0] rs1_addr_i,  // Source register 1
    input logic [4:0] rs2_addr_i,  // Source register 2
    input logic [4:0] rd_addr_i,   // Destination register
    
    // Control signals
    input logic regw_en_i,       // Register write enable
    
    // Data ports
    input logic [DATA_WIDTH-1:0] rd_data_i,  // Data to write
    output logic [DATA_WIDTH-1:0] rs1_data_o, // Data from rs1
    output logic [DATA_WIDTH-1:0] rs2_data_o  // Data from rs2
);

// Register file (1024 bits)
logic [DATA_WIDTH-1:0] register [32];
logic [63:0] cycle_count;  // Cycle counter for debug

// Function to get register ABI name
function string get_reg_name(input [4:0] reg_idx);
    case(reg_idx)
        5'd0: return "zero ";
        5'd1: return "ra   ";
        5'd2: return "sp   ";
        5'd3: return "gp   ";
        5'd4: return "tp   ";
        5'd5: return "t0   ";
        5'd6: return "t1   ";
        5'd7: return "t2   ";
        5'd8: return "s0/fp";
        5'd9: return "s1   ";
        5'd10: return "a0   ";
        5'd11: return "a1   ";
        5'd12: return "a2   ";
        5'd13: return "a3   ";
        5'd14: return "a4   ";
        5'd15: return "a5   ";
        5'd16: return "a6   ";
        5'd17: return "a7   ";
        5'd18: return "s2   ";
        5'd19: return "s3   ";
        5'd20: return "s4   ";
        5'd21: return "s5   ";
        5'd22: return "s6   ";
        5'd23: return "s7   ";
        5'd24: return "s8   ";
        5'd25: return "s9   ";
        5'd26: return "s10  ";
        5'd27: return "s11  ";
        5'd28: return "t3   ";
        5'd29: return "t4   ";
        5'd30: return "t5   ";
        5'd31: return "t6   ";
        default: return "??   ";
    endcase
endfunction

// Register write logic
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        // Initialize all registers to zero
        for (int i = 0; i < 32; i++) begin
            register[i] <= 0;
        end
        cycle_count <= 0;
    end else begin
        cycle_count <= cycle_count + 1;
        
        // Write to register if write enable is asserted and rd != x0
        if (regw_en_i && (rd_addr_i != 0)) begin
            register[rd_addr_i] <= rd_data_i;
            
            // Debug writes
            // `ifdef SIMULATION
            //     $display("REGFILE: Writing 0x%08x to x%0d", rd_data_i, rd_addr_i);
            // `endif

        end
    end
end

// FIXED CODE:
always_comb begin
    // Normal read logic for both rs1 and rs2 - let forwarding unit handle special cases
    rs1_data_o = (rs1_addr_i == 0) ? 0 : register[rs1_addr_i];
    rs2_data_o = (rs2_addr_i == 0) ? 0 : register[rs2_addr_i];

    if (regw_en_i && rd_addr_i != 0) begin
        if (rs1_addr_i == rd_addr_i) 
            rs1_data_o = rd_data_i;
        if (rs2_addr_i == rd_addr_i)
            rs2_data_o = rd_data_i;
    end
end

// Register dump task for debugging
task dump_registers;
    begin
        $display("REGFILE: ========== Register File Dump (Cycle %0d) ==========", cycle_count);
        for (int i = 0; i < 32; i++) begin
            automatic string reg_name = get_reg_name(5'(i));
            
            $display("  x%0d (%s): 0x%08x (bytes: %02x %02x %02x %02x)", 
                    i, reg_name, 
                    register[i], register[i][7:0], register[i][15:8], 
                    register[i][23:16], register[i][31:24]);
        end
        $display("==================================================");
    end
endtask

endmodule
