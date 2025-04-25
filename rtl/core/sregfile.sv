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
    input logic reg_write_i,       // Register write enable
    
    // Data ports
    input logic [DATA_WIDTH-1:0] rd_data_i,  // Data to write
    output logic [DATA_WIDTH-1:0] rs1_data_o, // Data from rs1
    output logic [DATA_WIDTH-1:0] rs2_data_o  // Data from rs2
);

// Register file
logic [DATA_WIDTH-1:0] register [32];
logic [63:0] cycle_count;  // Cycle counter for debug

// Function to correct endianness for display
function [31:0] correct_endianness(input [31:0] value);
    return {value[7:0], value[15:8], value[23:16], value[31:24]};
endfunction

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
        if (reg_write_i && (rd_addr_i != 0)) begin
            register[rd_addr_i] <= rd_data_i;
            
            `ifdef SIMULATION
                $display("REGFILE: Writing 0x%08x to x%0d", rd_data_i, rd_addr_i);
                // Also show the byte order for debugging
                $display("  Byte order: %02x %02x %02x %02x", 
                        rd_data_i[7:0], rd_data_i[15:8], rd_data_i[23:16], rd_data_i[31:24]);
            `endif
        end
    end
end

// Read logic - combinational
always_comb begin
    // Read source register 1
    rs1_data_o = (rs1_addr_i == 0) ? 0 : register[rs1_addr_i];
    
    // Read source register 2
    rs2_data_o = (rs2_addr_i == 0) ? 0 : register[rs2_addr_i];
    
    `ifdef SIMULATION
        if (rs1_addr_i != 0) begin
            $display("REGFILE: Reading x%0d = 0x%08x", rs1_addr_i, rs1_data_o);
        end
        if (rs2_addr_i != 0) begin
            $display("REGFILE: Reading x%0d = 0x%08x", rs2_addr_i, rs2_data_o);
        end
    `endif
end

// Register dump task for debugging
task dump_registers;
    int i;
    logic [31:0] raw_value, corrected_value;
    string reg_name;
    
    $display("REGFILE: ========== Register File Dump (Cycle %0d) ==========", cycle_count);
    for (i = 0; i < 32; i++) begin
        raw_value = register[i];
        corrected_value = correct_endianness(raw_value);
        
        // Standard ABI register names
        reg_name = get_reg_name(i);
        
        $display("  x%0d (%s): 0x%08x", i, reg_name, corrected_value);
        $display("     RAW: 0x%08x (bytes: %02x %02x %02x %02x)", 
                raw_value, 
                raw_value[7:0], raw_value[15:8], raw_value[23:16], raw_value[31:24]);
        $display("     CORRECTED: 0x%08x (bytes: %02x %02x %02x %02x)", 
                corrected_value,
                corrected_value[7:0], corrected_value[15:8], 
                corrected_value[23:16], corrected_value[31:24]);
    end
    $display("==================================================");
endtask

// Improved debug with endianness tracking
`ifdef SIMULATION
// For any register writes, check and report endianness issues
always @(posedge clk) begin
    if (reg_write_i && (rd_addr_i != 0)) begin
        logic [31:0] corrected = correct_endianness(rd_data_i);
        if (rd_data_i != corrected) begin
            $display("REGFILE ENDIANNESS NOTE: Writing to x%0d", rd_addr_i);
            $display("  Original: 0x%08x (bytes: %02x %02x %02x %02x)", 
                    rd_data_i,
                    rd_data_i[7:0], rd_data_i[15:8], rd_data_i[23:16], rd_data_i[31:24]);
            $display("  Swapped:  0x%08x (bytes: %02x %02x %02x %02x)", 
                    corrected,
                    corrected[7:0], corrected[15:8], corrected[23:16], corrected[31:24]);
        end
    end
end
`endif

endmodule
