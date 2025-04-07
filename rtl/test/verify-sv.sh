#!/bin/bash

# Script to check for Verilator compatibility issues

# Set paths
RTL_DIR="$(pwd)/../core"
TB_DIR="$(pwd)/../tb"
TEST_DIR="$(pwd)"

# Function to check for common Verilator issues in a file
check_file() {
    local file=$1
    echo "Checking $file for potential Verilator issues..."
    
    # Check for uninitialized variables in always_comb blocks
    if grep -n "always_comb" "$file" >/dev/null; then
        echo "  - Found always_comb blocks, checking for proper initialization..."
        # This is a simplistic check - a real check would be more involved
        # Ideally, all variables assigned in always_comb should have a default value
    fi
    
    # Check for unbounded arrays
    if grep -n "\[\]" "$file" >/dev/null; then
        echo "  - WARNING: Found unbounded array(s) which may cause issues with Verilator"
        grep -n "\[\]" "$file"
    fi
    
    # Check for system tasks that might not be supported
    if grep -n "\$\(random\|urandom\|dist_\|enum\|cast\)" "$file" >/dev/null; then
        echo "  - WARNING: Found potentially unsupported SystemVerilog system tasks"
        grep -n "\$\(random\|urandom\|dist_\|enum\|cast\)" "$file"
    fi
    
    # Check for incomplete case statements
    if grep -n "case[^:]*:" "$file" | grep -v "default:" >/dev/null; then
        echo "  - WARNING: Found case statements without default: clause"
        grep -n "case[^:]*:" "$file" | grep -v "default:"
    fi
    
    # Check for latches due to incomplete if statements in combinational logic
    if grep -n "always_comb" "$file" >/dev/null; then
        if grep -n "if[^;]*;" "$file" | grep -v "else" >/dev/null; then
            echo "  - WARNING: Found if without else in always_comb blocks, might create latches"
            grep -n -A 5 "always_comb" "$file" | grep -n "if[^;]*;" | grep -v "else"
        fi
    fi
    
    # Check for print_alu_op function in salu.sv
    if [[ "$file" == *"salu.sv" ]]; then
        if grep -n "print_alu_op" "$file" >/dev/null; then
            echo "  - Found print_alu_op function, checking implementation..."
            if ! grep -n "function.*void.*print_alu_op" "$file" >/dev/null; then
                echo "  - WARNING: print_alu_op function might be incorrectly defined"
            fi
        fi
    fi
    
    # Check for syntax in always_ff blocks
    if grep -n "always_ff" "$file" >/dev/null; then
        echo "  - Found always_ff blocks, checking for proper asynchronous reset usage..."
        if grep -n "always_ff.*posedge.*negedge" "$file" >/dev/null; then
            if ! grep -n "if.*!rst_n" "$file" >/dev/null; then
                echo "  - WARNING: always_ff with posedge/negedge but possible missing reset check"
            fi
        fi
    fi
}

# Main script
echo "Checking SystemVerilog files for Verilator compatibility..."

# Check all SV files in the core directory
for file in "$RTL_DIR"/*.sv; do
    check_file "$file"
done

echo "Checking simulation script..."
if [[ -f "$TB_DIR/sim_main.cpp" ]]; then
    echo "  - sim_main.cpp exists"
    
    # Check for proper top-level signal access
    if grep -n "top__DOT__" "$TB_DIR/sim_main.cpp" >/dev/null; then
        echo "  - Found top-level signal access patterns"
    else
        echo "  - WARNING: Might be missing proper top-level signal access"
    fi
else
    echo "  - WARNING: sim_main.cpp not found"
fi

echo "Checking Makefile..."
if [[ -f "$TB_DIR/Makefile" ]]; then
    echo "  - Makefile exists"
    
    # Check for appropriate Verilator flags
    if grep -n "verilator" "$TB_DIR/Makefile" >/dev/null; then
        echo "  - Found Verilator command"
        
        # Check for trace flag
        if grep -n "\-\-trace" "$TB_DIR/Makefile" >/dev/null; then
            echo "  - Found trace flag"
        else
            echo "  - WARNING: Missing --trace flag, might not generate VCD file"
        fi
        
        # Check for include paths
        if grep -n "\-I.*core" "$TB_DIR/Makefile" >/dev/null; then
            echo "  - Found core include path"
        else
            echo "  - WARNING: Might be missing include path to core directory"
        fi
    else
        echo "  - WARNING: Verilator command not found in Makefile"
    fi
else
    echo "  - WARNING: Makefile not found"
fi

echo "Compatibility check complete."
