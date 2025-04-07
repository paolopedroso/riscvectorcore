# 
# Testbench Makefile
# 
# @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
# 
# @license Apache 2.0
# 

# Paths
RTL_DIR = ../core
TB_DIR = .

# Verilator configuration
VERILATOR = verilator
VERILATOR_OPTS = --cc --exe --build -j 0 -Wall -Wno-fatal
VERILATOR_OPTS += --trace  # Generate VCD trace
VERILATOR_OPTS += --trace-max-array 1024  # Limit array size in trace
VERILATOR_OPTS += --trace-max-width 256   # Limit signal width in trace
VERILATOR_OPTS += -I$(RTL_DIR)  # Include path for RTL files
VERILATOR_OPTS += -DSIMULATION  # Define SIMULATION for conditional code

# C++ sources (in TB_DIR)
CPP_SRCS = $(TB_DIR)/sim_main.cpp

# SystemVerilog sources (from RTL_DIR)
SV_SRCS = $(RTL_DIR)/top.sv \
          $(RTL_DIR)/program_counter.sv \
          $(RTL_DIR)/salu.sv \
          $(RTL_DIR)/sdatamem.sv \
          $(RTL_DIR)/sdecode.sv \
          $(RTL_DIR)/sregfile.sv \
          $(RTL_DIR)/swbmux.sv \
          $(RTL_DIR)/instr_mem.sv \
          $(RTL_DIR)/shazard_detection.sv \
          $(RTL_DIR)/forwarding_unit.sv

# Target executable
TARGET = obj_dir/Vtop

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(CPP_SRCS) $(SV_SRCS)
	$(VERILATOR) $(VERILATOR_OPTS) $(CPP_SRCS) $(SV_SRCS) --top-module top

run: $(TARGET)
	$(TARGET)

clean:
	rm -rf obj_dir
	rm -f *.vcd
