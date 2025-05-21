#!/bin/bash

# Script to update Makefile for better Verilator compatibility

# Set path
TB_DIR="$(pwd)/../tb"

if [ ! -f "$TB_DIR/Makefile" ]; then
    echo "Error: Makefile not found in $TB_DIR"
    exit 1
fi

echo "Backing up original Makefile..."
cp "$TB_DIR/Makefile" "$TB_DIR/Makefile.bak"

echo "Updating Makefile for better Verilator compatibility..."

# Add/modify Verilator flags
sed -i 's/verilator --cc/verilator --cc --exe --build -j 0 -Wall -Wno-fatal --trace/' "$TB_DIR/Makefile"

# Make sure the core directory is included
if ! grep -q "\-I.*core" "$TB_DIR/Makefile"; then
    sed -i 's/verilator --cc/verilator --cc -I..\/core/' "$TB_DIR/Makefile"
fi

# Ensure all files are included
echo "Checking for missing module files in Makefile..."
CORE_FILES=$(ls ../core/*.sv)
for file in $CORE_FILES; do
    base_file=$(basename "$file")
    if ! grep -q "$base_file" "$TB_DIR/Makefile"; then
        echo "Adding missing file: $base_file"
        sed -i "s/top.sv/top.sv ..\/core\/$base_file/" "$TB_DIR/Makefile"
    fi
done

echo "Makefile updated successfully!"
