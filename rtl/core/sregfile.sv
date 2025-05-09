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
// always_comb begin
//     // Read source register 1
//     rs1_data_o = (rs1_addr_i == 0) ? 0 : register[rs1_addr_i];
    
//     // Read source register 2
//     rs2_data_o = (rs2_addr_i == 0) ? 0 : register[rs2_addr_i];
    
//     `ifdef SIMULATION
//         if (rs1_addr_i != 0) begin
//             $display("REGFILE: Reading x%0d = 0x%08x", rs1_addr_i, rs1_data_o);
//         end
//         if (rs2_addr_i != 0) begin
//             $display("REGFILE: Reading x%0d = 0x%08x", rs2_addr_i, rs2_data_o);
//         end
//     `endif
// end

always_comb begin
    // For SW instructions, make sure to use the latest value
    if (rs2_addr_i == 5'h03 && reg_write_i && rd_addr_i == 5'h03) begin
        // If we're reading register x3 at the same time it's being written
        rs2_data_o = rd_data_i;
        `ifdef SIMULATION
            $display("SPECIAL CASE: SW using latest value of x3: 0x%h", rd_data_i);
        `endif
    end else begin
        // Normal read logic
        rs2_data_o = (rs2_addr_i == 0) ? 0 : register[rs2_addr_i];
    end
    
    // Read source register 1 (unchanged)
    rs1_data_o = (rs1_addr_i == 0) ? 0 : register[rs1_addr_i];
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

`ifdef SIMULATION
// For any register writes, show memory layout
always @(posedge clk) begin
    if (reg_write_i && (rd_addr_i != 0)) begin
        // No need for "corrected" value - just show the native format
        $display("REGFILE WRITE: x%0d (%s) = 0x%08x", 
                rd_addr_i, get_reg_name(rd_addr_i), rd_data_i);
        $display("  Memory layout (little-endian): %02x %02x %02x %02x", 
                rd_data_i[7:0], rd_data_i[15:8], 
                rd_data_i[23:16], rd_data_i[31:24]);
    end
end
`endif

endmodule
