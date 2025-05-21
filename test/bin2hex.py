#!/usr/bin/env python3
import sys
import binascii

def bin2hex(binary_file, output_file):
    with open(binary_file, 'rb') as f:
        binary_data = f.read()
    
    with open(output_file, 'w') as f:
        f.write("// Generated from assembly file\n")
        f.write("initial begin\n")
        f.write("    for (int i = 0; i < MEM_SIZE; i++) begin\n")
        f.write("        imem[i] = 32'h0;\n")
        f.write("    end\n\n")
        
        for i in range(0, len(binary_data), 4):
            if i+3 < len(binary_data):
                # RISC-V is little-endian, so we need to reverse the bytes
                instr = binary_data[i] | (binary_data[i+1] << 8) | (binary_data[i+2] << 16) | (binary_data[i+3] << 24)
                f.write(f"    imem[{i//4}] = 32'h{instr:08x};  // Instruction at address {i//4}\n")
        
        f.write("end\n")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: bin2hex.py input.bin output.sv")
        sys.exit(1)
    
    bin2hex(sys.argv[1], sys.argv[2])
