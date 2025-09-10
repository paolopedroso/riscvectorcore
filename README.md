# RISC-V Scalar Core Implementation (IN DEVELOPMENT)

A 32-bit RISC-V processor core with 5-stage pipeline and comprehensive hazard handling, implemented in SystemVerilog.

## Current Architecture

### Pipeline Stages
- Instruction Fetch (IF)
- Instruction Decode (ID)
- Execute (EX)
- Memory (MEM)
- Write Back (WB)

### Key Features
- Complete RV32I base integer instruction support
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

2. **Run all tests:**
   ```wsl
   cd sim
   dos2unix sim_top.sh
   ./sim_top.sh
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

`make clean` to remove generated files.

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

## Known Issues and Solutions

### Load/Store Instructions

The processor may experience issues with **load and store** instructions. Common problems include:

~~1. **Data Memory Endianness**: RISC-V uses little-endian byte ordering, which requires proper handling during loads and stores.~~
   ~~- Solution: The sdatamem.sv module has been updated with explicit byte ordering for little-endian memory access, with separate code paths for byte, halfword, and word operations.~~ FIXED

2. **Forwarding for Store Instructions**: Store instructions need special forwarding logic to capture recently calculated values.
   - ~~Note: There's a special case handling for register x3 in the test program that may need adjustment for other programs.~~

3. **Hazard Detection**: Load-use hazards require pipeline stalls to ensure data consistency.


### Register Value Verification

If you encounter incorrect register values after running the test program:

1. Check the `register_dump.txt` file to see actual register values
2. Compare against expected values using `python3 analyze_vcd.py`
3. Use waveform viewer on `tb_top.vcd` to trace specific instructions
4. Look for endianness-related issues that might cause misinterpretation of values

## Future Improvements

- **Vector extensions support**
- **Enchancing Assembly Programming Enviroment**
- Support for RV32M extension (multiplication/division)
- Enhanced branch prediction
- Cache implementation
- Memory management unit (MMU)

## Licensing

Apache 2.0 License  
Copyright 2025 Paolo Pedroso

---

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/your-feature`
3. Make your changes and commit them: `git commit -m 'Add your feature'`
4. Push to the branch: `git push origin feature/your-feature`
5. Submit a pull request

## Troubleshooting

### Common Issues

1. **Simulation gets stuck in infinite loop**  
   Check the program counter module bounds checking and loop detection logic. The top.sv module includes a mechanism to detect when the PC doesn't change for multiple cycles, indicating a potential infinite loop.
   - **Solution: Ensure to add EBREAK at end of program.**

2. **Incorrect register values after load/store operations**  
   Verify the little-endian handling in sdatamem.sv and ensure the forwarding paths are working properly for store operations. The memory layout in RISC-V (little-endian) requires careful byte ordering during reads and writes.

3. **Pipeline hazards causing incorrect execution**  
   Ensure the shazard_detection module is properly stalling the pipeline for load-use hazards, and that the forwarding_unit is correctly identifying all forwarding paths.

## Need Additional Testing
- BLT
- BGE
- BLTU, BGEU
- SLT/SLTI
- AUIPC

For detailed debugging, examine `simulation_output.log` and `debug_log.txt` files after running a test. The register_dump.txt file contains the final register values, which can be compared against expected results.

Contact: paoloapedroso@gmail.com