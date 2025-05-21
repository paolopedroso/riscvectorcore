# 
# Enhanced Testbench Makefile
# 
# @copyright 2025 Paolo Pedroso <paoloapedroso@gmail.com>
# 
# @license Apache 2.0
# 

# Paths
RTL_DIR = ../core
SIM_DIR = .

# Verilator configuration
VERILATOR = verilator
VERILATOR_OPTS = --cc --exe --build -j 0 -Wall -Wno-fatal
VERILATOR_OPTS += --trace  # Generate VCD trace
VERILATOR_OPTS += --trace-max-array 1024  # Limit array size in trace
VERILATOR_OPTS += --trace-max-width 256   # Limit signal width in trace
VERILATOR_OPTS += -I$(RTL_DIR)  # Include path for RTL files
VERILATOR_OPTS += -DSIMULATION  # Define SIMULATION for conditional code
VERILATOR_OPTS += --trace-depth 99  # Increased trace depth
VERILATOR_OPTS += --assert  # Enable assertions
VERILATOR_OPTS += --timing
VERILATOR_DEFINES += -DENDIAN_DEBUG

# C++ sources (in SIM_DIR)
CPP_SRCS = $(SIM_DIR)/sim_main.cpp

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

# Analysis tools
PYTHON = python3
ANALYZER = analyze_vcd.py

lint:
	@echo "Linting SystemVerilog Files..."
	$(VERILATOR) --lint-only -Wall -Wno-lint -I$(RTL_DIR) $(SV_SRCS) --top-module top

.PHONY: all clean run analyze lint report debug docs

all: $(TARGET)

$(TARGET): $(CPP_SRCS) $(SV_SRCS)
	@echo "Building simulation with Verilator..."
	$(VERILATOR) $(VERILATOR_OPTS) $(CPP_SRCS) $(SV_SRCS) --top-module top

run: $(TARGET)
	@echo "Running simulation..."
	$(TARGET)

analyze: run
	@echo "Analyzing simulation results..."
	$(PYTHON) $(ANALYZER) tb_top.vcd

clean:
	@echo "Cleaning build artifacts..."
	rm -rf obj_dir
	rm -f *.vcd
	rm -f register_dump.txt
	rm -f memory_dump.txt
	rm -f debug_log.txt
	rm -f instruction_trace.txt
	rm -f *.log
	rm -f temp/*
	rmdir temp


# Generate HTML report from simulation
report: run
	@echo "Generating HTML report..."
	$(PYTHON) generate_report.py

# More verbose run with debug output
debug: $(TARGET)
	@echo "Running simulation with debug output..."
	$(TARGET) | tee simulation_output.log

# Auto-generate documentation from source
docs:
	@echo "Generating documentation..."
	mkdir -p docs
	verilator --xml-only $(SV_SRCS)
	python3 verilator_xml_to_doc.py
