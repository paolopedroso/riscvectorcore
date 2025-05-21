#!/bin/bash

# Set error handling
set -e  # Exit on any error
set -o pipefail

# Set paths based on your directory structure
RTL_DIR="../core"
SIM_DIR="."
CURRENT_DIR=$(pwd)

echo "Using paths:"
echo "  Current directory: $CURRENT_DIR"
echo "  RTL_DIR: $RTL_DIR"
echo "  SIM_DIR: $SIM_DIR"

# Find Makefile
if [ -f "Makefile" ]; then
    echo "Using Makefile in current directory"
    MAKEFILE_DIR="."
elif [ -f "../sim/Makefile" ]; then
    echo "Using Makefile in ../sim directory"
    MAKEFILE_DIR="../sim"
    cd "$MAKEFILE_DIR"
else
    echo "Error: Cannot find Makefile"
    echo "Searching for Makefile..."
    find .. -name "Makefile" -type f
    exit 1
fi

# Run the simulation manually if Makefile is not available
if [ ! -f "Makefile" ]; then
    echo "No Makefile found, running Verilator directly"
    if [ -f "sim_main.cpp" ]; then
        echo "Found sim_main.cpp, building simulation..."
        # Compile with Verilator directly
        verilator --cc --exe --build -j 0 -Wall -Wno-fatal --timing --trace -I"$RTL_DIR" sim_main.cpp "$RTL_DIR"/*.sv --top-module top
        
        # Run the simulation
        echo "Running simulation..."
        ./obj_dir/Vtop | tee simulation_output.log
    else
        echo "Error: Cannot find sim_main.cpp"
        exit 1
    fi
else
    # Use the Makefile
    echo "Using Makefile to build and run simulation"
    
    # Clean previous build
    if grep -q "clean" Makefile; then
        echo "Cleaning previous build artifacts..."
        make clean || echo "Clean failed, continuing anyway"
    fi
    
    # Build
    echo "Building simulation..."
    make || { 
        echo "Build failed. Check for errors in the Verilator output."
        exit 1
    }
    
    # Run
    echo "Running simulation..."
    make run | tee simulation_output.log
fi

# Check for register dump file
if [ -f "register_dump.txt" ]; then
    echo "Simulation completed. Register dump generated."
    echo "Debug information has been saved to simulation_output.log"
else
    echo "Warning: No register_dump.txt file generated"
fi

# Return to original directory
cd "$CURRENT_DIR"

echo "Test completed."
