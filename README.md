# RISC-V Scalar Core Implementation

## Project Overview
This is a 32-bit RISC-V scalar processor core implemented in SystemVerilog, featuring a 5-stage pipeline design with comprehensive hazard detection and forwarding mechanisms.

## Current Architecture
### Pipeline Stages
- Instruction Fetch (IF)
- Instruction Decode (ID)
- Execute (EX)
- Memory (MEM)
- Write Back (WB)

### Key Modules
1. **Program Counter (`program_counter.sv`)**: 
   - Manages instruction address progression
   - Supports branch and jump instructions
   - Handles pipeline stalls

2. **Instruction Memory (`instr_mem.sv`)**: 
   - Word-addressable memory
   - Supports loading predefined instructions
   - Configurable memory size (default 1024 words)

3. **Decoder (`sdecode.sv`)**: 
   - Decodes RISC-V instructions
   - Generates control signals for pipeline stages
   - Supports various instruction types (R-type, I-type, S-type, B-type, U-type, J-type)

4. **Register File (`sregfile.sv`)**: 
   - 32 32-bit registers
   - Supports read and write operations
   - x0 hardwired to zero

5. **Arithmetic Logic Unit (`salu.sv`)**: 
   - Supports multiple operations:
     - Arithmetic: ADD, SUB
     - Logical: AND, OR, XOR
     - Shifts: SLL, SRL, SRA
     - Comparisons: SLT, SLTU
   - Generates zero, negative, and overflow flags

6. **Data Memory (`sdatamem.sv`)**: 
   - Byte-addressable memory
   - Supports byte, halfword, and word read/write operations

7. **Hazard Detection (`shazard_detection.sv`)**: 
   - Detects and handles load-use hazards
   - Stalls the pipeline when necessary

8. **Forwarding Unit (`forwarding_unit.sv`)**: 
   - Implements data forwarding to reduce pipeline stalls
   - Supports forwarding from MEM and WB stages

## Simulation and Testing
- Uses Verilator for SystemVerilog simulation
- Includes a comprehensive testbench (`tb_top.sv`)
- Generates VCD trace files for debugging
- Supports instruction tracing and pipeline state monitoring

## Test Program
The current test program demonstrates basic RISC-V instructions:
- Register initialization
- Arithmetic operations
- Logical operations
- Memory store and load
- Simple jump instruction

## Build and Run
### Prerequisites
- Verilator
- RISC-V GNU Toolchain
- Make

### Compilation and Simulation
```bash
# In the testbench directory
make clean
make
make run
```

## Current Limitations
- 32-bit RISC-V Integer (RV32I) instruction set
- Basic pipeline with simple hazard handling
- Limited memory and register file size

## Future Improvements
- Currently extending the design to support RISC-V vector extensions (RVV) for improved parallel processing capabilities, with planned implementation of custom vector register file and vector execution units
- Implement more advanced branch prediction
- Add support for RV32M extension (multiplication/division)
- Enhance hazard detection and forwarding
- Implement cache mechanisms

## Licensing
Apache 2.0 License
Copyright 2025 Paolo Pedroso

## Project Structure
```
.
├── core/               # RTL source files
│   ├── top.sv          # Top-level module
│   ├── program_counter.sv
│   ├── salu.sv
│   ├── sdatamem.sv
│   └── ...
├── tb/                 # Testbench and simulation files
│   ├── tb_top.sv
│   ├── sim_main.cpp
│   └── Makefile
└── tools/              # Utility scripts
    ├── bin2hex.py
    └── run_test.sh
```
