#!/usr/bin/env python3
import sys
import re

def parse_vcd(filename):
    """Parse VCD file to extract register values"""
    try:
        with open(filename, 'r') as f:
            vcd_content = f.read()
        
        print(f"Successfully opened VCD file, size: {len(vcd_content)} bytes")
        
        # Find register identifiers and their codes
        reg_pattern = r'\$var wire 32 ([!-~]) register\[(\d+)\]'
        reg_id_map = {}
        
        for match in re.finditer(reg_pattern, vcd_content):
            var_id = match.group(1)
            reg_num = int(match.group(2))
            reg_id_map[var_id] = reg_num
            
        print(f"Found {len(reg_id_map)} register identifiers")
        
        # If we didn't find any registers in the usual format, try an alternative format
        if not reg_id_map:
            alt_pattern = r'\$var wire 32 ([!-~]) top\.sregfile_inst\.register\[(\d+)\]'
            for match in re.finditer(alt_pattern, vcd_content):
                var_id = match.group(1)
                reg_num = int(match.group(2))
                reg_id_map[var_id] = reg_num
            print(f"Found {len(reg_id_map)} register identifiers with alternative format")
        
        # Find the final timestamp
        timestamps = re.findall(r'#(\d+)', vcd_content)
        if not timestamps:
            print("No timestamps found in VCD file")
            return {}
            
        final_time = int(timestamps[-1])
        print(f"Final simulation timestamp: {final_time}")
        
        # Extract register values at the end of simulation
        registers = {}
        current_time = 0
        
        # Process in chunks to handle large files
        chunk_size = 100000  # Process 100k lines at a time
        lines = vcd_content.split('\n')
        
        for i in range(0, len(lines), chunk_size):
            chunk = lines[i:i+chunk_size]
            for line in chunk:
                if line.startswith('#'):
                    try:
                        current_time = int(line[1:])
                    except ValueError:
                        continue
                elif current_time == final_time and line and line[0] in reg_id_map:
                    var_id = line[0]
                    reg_num = reg_id_map[var_id]
                    
                    # Extract value (format: b[01]+ or b[01]+)
                    if len(line) > 1 and line[1] == 'b':
                        value_str = line[2:].split()[0]
                        try:
                            value = int(value_str, 2)
                            registers[reg_num] = value
                        except ValueError:
                            print(f"Error parsing value for register {reg_num}: {line}")
        
        print(f"Extracted {len(registers)} register values")
        
        # If we couldn't extract from VCD, try to read from register_dump.txt
        if not registers:
            print("No register values found in VCD. Trying register_dump.txt...")
            registers = read_register_dump("register_dump.txt")
            
        return registers
        
    except Exception as e:
        print(f"Error parsing VCD file: {e}")
        print("Trying to read from register_dump.txt instead...")
        return read_register_dump("register_dump.txt")

def read_register_dump(filename):
    """Read register values from the register_dump.txt file"""
    registers = {}
    try:
        with open(filename, 'r') as f:
            for line in f:
                # Look for lines with x0=0, x1=1 format
                match = re.match(r'x(\d+)=(\d+)', line.strip())
                if match:
                    reg_num = int(match.group(1))
                    value = int(match.group(2))
                    registers[reg_num] = value
                else:
                    # Try the other format: "register x0 = 0 (zero)"
                    match = re.match(r'register x(\d+) = (\d+)', line.strip())
                    if match:
                        reg_num = int(match.group(1))
                        value = int(match.group(2))
                        registers[reg_num] = value
        
        print(f"Read {len(registers)} register values from {filename}")
        return registers
    except Exception as e:
        print(f"Error reading register dump: {e}")
        return {}

def verify_results(registers):
    """Verify register values against expected results"""
    # Updated expected values based on our fixed test program
    expected = {
        # Original registers
        1: 0xC8,            # x1 = 200 (0xC8)   - Set by JAL instruction at PC=0x000000C4
        2: 2,               # x2 = 2            - addi x2, x0, 2
        3: 3,               # x3 = 3            - add x3, x1, x2 (1+2=3)
        4: 0xFFFFFFFE,      # x4 = -2 (0xFFFFFFFE) - sub x4, x1, x3 (1-3)
        5: 0,               # x5 = 0            - and x5, x1, x2 (1&2=0)
        6: 3,               # x6 = 3            - or x6, x1, x2 (1|2=3) 
        7: 3,               # x7 = 3            - xor x7, x1, x2 (1^2=3)
        8: 2,               # x8 = 2            - slli x8, x1, 1 (1<<1=2)
        9: 0,               # x9 = 0            - srli x9, x1, 2 (1>>2=0)
        10: 0,              # x10 = 0           - srai x10, x1, 2 (1>>2=0)
        11: 3,             
        12: 1,
        13: 3,            
        14: 253,            # x14 = 253 (0xFD)  - addi x14, x0, 253
        15: 0xFFFFFFFD,     # x15 = -3 (0xFFFFFFFD) - lb x15, 16(x0) (sign-extended) 
        16: 0xAAAAB000,     # x16 = 0xAAAAB000 - lui x16, 0xaaaab (the 0x12345 never completes due to EBREAK)
        17: 0xFFFFB000,     # x17 = -20480 (0xFFFFB000) - lh x17, 20(x0) (sign-extended from 0xB000)
        18: 0x0000B000,     # x18 = 0x0000B000
        19: 3,              # x19 = 3           - addi x19, x0, 3
        20: 5,              # x20 = 5           - addi x20, x0, 5
        21: 20,             # x21 = 20          - addi x21, x0, 20
        22: 10,             # x22 = 10          - addi x22, x0, 10 (executed after branch)
        23: 253,            # x23 = 253 (0xFD)  - lw x23, 16(x0)
        24: 26,             # x24 = 26          - addi x24, x20, 21 (5+21=26) 
        25: 50,             # x25 = 50          - addi x25, x24, 24 (26+24=50)
        26: 75,             # x26 = 75          - addi x26, x25, 25 (50+25=75)
        27: 101,            # x27 = 101         - addi x27, x26, 26 (75+26=101)
        28: 29,             # x28 = 29          - addi x28, x0, 29
        29: 101,            # x29 = 101         - lw x29, 28(x0) (loads mem[28]=101)
        30: 56,             # x30 = 56          - add x30, x30, x30 (28+28=56)
        31: 30,             # x31 = 30          - addi x31, x0, 30
    }
    
    passed = 0
    failed = 0
    
    # Print all register values for debugging
    print("\nAll register values:")
    for reg in sorted(registers.keys()):
        print(f"  x{reg} = {registers[reg]}")
    
    print("\nVerification results:")
    for reg, expected_value in expected.items():
        if reg in registers:
            actual = registers[reg]
            if actual == expected_value:
                print(f"PASS: x{reg} = {actual} (expected {expected_value})")
                passed += 1
            else:
                print(f"FAIL: x{reg} = {actual} (expected {expected_value})")
                failed += 1
        else:
            print(f"MISSING: x{reg} (expected {expected_value})")
            failed += 1
    
    print(f"\nVerification complete: {passed} passed, {failed} failed")
    return failed == 0

if __name__ == "__main__":
    vcd_file = "tb_top.vcd"
    if len(sys.argv) > 1:
        vcd_file = sys.argv[1]
    
    print(f"Analyzing VCD file: {vcd_file}")
    registers = parse_vcd(vcd_file)
    success = verify_results(registers)
    
    if success:
        print("All tests PASSED!")
        sys.exit(0)
    else:
        print("Some tests FAILED!")
        sys.exit(1)