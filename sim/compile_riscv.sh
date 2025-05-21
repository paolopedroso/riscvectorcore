#!/bin/bash
# Script to compile RISC-V assembly using objdump for better insight
set -e  # Exit on any error

# Configuration
CORE_DIR="../core"  # Adjust as needed
TEST_DIR="../test"  # Directory where the test files are located
ASM_FILE="$1"
TIMESTAMP=$(date +%s)

if [ -z "$ASM_FILE" ]; then
    echo "Usage: $0 <assembly_file.s>"
    exit 1
fi

# Try to find it in the TEST_DIR
if [[ -f "$TEST_DIR/$ASM_FILE" ]]; then
    ASM_FILE="$TEST_DIR/$ASM_FILE"
    echo "Found assembly file at: $ASM_FILE"
else
    echo "Error: Cannot find assembly file $ASM_FILE"
    echo "Looked in current directory and $TEST_DIR"
    exit 1
fi

# Get filename without extension
BASENAME=$(basename "$ASM_FILE" .s)

echo "Compiling $ASM_FILE for RISC-V core..."

# Step 1: Create a minimal linker script if it doesn't exist
echo "Creating a simple linker script..."
cat > linker.ld << 'EOF'
SECTIONS
{
  . = 0x0;
  .text : { *(.text) }
}
EOF

# Step 2: Use GCC to compile assembly directly (provides better position handling)
echo "Compiling with GCC (includes proper assembly and linking)..."
riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -nostdlib -nostartfiles -T linker.ld -o "$BASENAME.elf" "$ASM_FILE"

# Step 3: Use objdump to see what instructions we actually have
echo "Dumping object code to examine compiled instructions..."
riscv64-unknown-elf-objdump -d "$BASENAME.elf" > "$BASENAME.dump"
cat "$BASENAME.dump"

# Step 4: Extract instructions from the dump
echo "Extracting instructions from objdump output..."
cat > instr_list.sv << 'EOF'
    // First reset all memory locations to zero
    for (int i = 0; i < MEM_SIZE; i++) begin
        imem[i] = 32'h0;
    end

EOF

# Extract instruction addresses and values, process them for instruction memory
grep "^ " "$BASENAME.dump" | grep -v "file format" | awk '{print $2, $1}' | 
while read -r INSTR ADDR; do
    # Remove the colon from address
    ADDR=${ADDR%:}
    # Convert address to decimal and divide by 4 to get word index
    INDEX=$((16#${ADDR} / 4))
    echo "    imem[$INDEX] = 32'h$INSTR;  // Address 0x$ADDR" >> instr_list.sv
done

# Step 5: Update instr_mem.sv
echo "Updating instruction memory..."
INSTR_FILE="$CORE_DIR/instr_mem.sv"

# Backup original file
BACKUP_FILE="${INSTR_FILE}.bak.${TIMESTAMP}"
cp "$INSTR_FILE" "$BACKUP_FILE"

# Create a fixed template with markers for initialization
cat > instr_mem_fixed.sv << 'EOF'
/*
 * Instruction Memory
 *
 * @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
 *
 * @license Apache 2.0
 */

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
    
    // Read logic - enhanced with safety checks
    always_comb begin
        // Use memory index appropriate for word addressing
        // addr_i is in bytes, divide by 4 to get word address
        int mem_index;
        
        // First convert to unsigned to avoid negative indices
        // Then divide by 4 (shift right by 2) to get word address
        // Then mask to just the needed bits based on memory size
        mem_index = int'(($unsigned(addr_i) >> 2) & (MEM_SIZE - 1));
        
        // Debug output
        `ifdef SIMULATION
            $display("IMEM: Reading from address 0x%h, mem_index=%0d, instruction=0x%h", 
                     addr_i, mem_index, imem[mem_index]);
            if (addr_i > 32'h00000100) begin
                $display("WARNING: PC is outside expected program range! addr=0x%h", addr_i);
            end
        `endif
        
        // Return instruction at calculated index with bounds check
        if (mem_index < MEM_SIZE && mem_index >= 0) begin
            instr_o = imem[mem_index];
        end else begin
            instr_o = 32'h00000013;  // Return a NOP for out-of-bounds
            `ifdef SIMULATION
                $display("ERROR: Memory access out of bounds! index=%0d", mem_index);
            `endif
        end
    end

// Just ONE initialization block to avoid conflicts
initial begin
    // Generated from $ASM_FILE on $(date)
INITIALIZATION_PLACEHOLDER
end

endmodule
EOF

# Update the placeholder with our instruction list
sed -e '/INITIALIZATION_PLACEHOLDER/r instr_list.sv' \
    -e '/INITIALIZATION_PLACEHOLDER/d' \
    instr_mem_fixed.sv > "$INSTR_FILE"

if [ ! -d temp ]; then
    mkdir -p temp
fi
mv -f "$BASENAME.elf" "$BASENAME.dump" "$BASENAME.bin" "$BASENAME.o" "$BACKUP_FILE" instr_mem_fixed.sv instr_list.sv linker.ld temp/
# Backup original file
echo "Moved temporary and backup files to temp/ directory."

echo "Compilation complete! Instruction memory updated with new code."
echo "Run the simulation to test your assembly code."