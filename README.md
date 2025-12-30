# RISC-V Scalar / Vector Core Implementation

A 32-bit RISC-V processor core with 5-stage pipeline and comprehensive hazard handling, implemented in SystemVerilog.

## Current Architecture

### Pipeline Stages
- Instruction Fetch (IF)
- Instruction Decode (ID)
- Execute (EX)
- Memory (MEM)
- Write Back (WB)

### Key Features
- Complete RV32IV base integer instruction support
- 5-stage pipeline with data forwarding and hazard detection
- Load/store memory operations with byte, halfword, and word support
- Branch and jump instructions with pipeline flushing
- Comprehensive debug features and simulation support

## Getting Started

### Prerequisites
- WSL2
- Git Bash (optional)
- Verilator (tested with version 4.2+)
- GNU Make
- Python 3.6+
- C++ compiler with C++11 support
- dos2unix

**For writing your own assembly code**
- riscv64-unknown-elf-as
- riscv64-unknown-elf-ld
- riscv64-unknown-elf-objcopy

**Install with:**
```wsl
sudo apt-get install gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf
```

### Building and Running

1. **Clone the repository:**
   ```wsl
   git clone https://github.com/paolopedroso/riscvectorcore.git
   cd riscvectorcore
   ```

2. **Run Simulation:**
   ```wsl
   cd sim
   dos2unix sim_top.sh
   ./sim_top.sh
   ```

   ```
   make clean
   ``` 
   
3. **Analyze results:**
   ```wsl
   cd sim
   python3 analyze_vcd.py
   ```

## Debugging

1. **Analyze register values:**
   ```wsl
   python3 analyze_vcd.py
   ```
   This will compare actual register values against expected results.


## Running Your Own Assembly Program
Use the necessary commands
```wsl
sudo apt-get install gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf

dos2unix compile_riscv.sh
```
1. Create a `.s` assembly file
2. Run `./compile_riscv.sh <name of assembly file>.s`
3. Then `./sim_top.sh`

Examine the `simulation_output.log` for results.

## Licensing

Apache 2.0 License  
Copyright 2025 Paolo Pedroso

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/your-feature`
3. Make your changes and commit them: `git commit -m 'Add your feature'`
4. Push to the branch: `git push origin feature/your-feature`
5. Submit a pull request
