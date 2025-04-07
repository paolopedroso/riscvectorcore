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
        1: 1,    # x1 = 1
        2: 2,    # x2 = 2
        3: 3,    # x3 = 3
        4: 12,   # x4 = 12
        5: 8,    # x5 = 8
        6: 3,    # x6 = 3
        7: 48,   # x7 = 48
        8: 1,    # x8 = 1
        9: 42,   # x9 = 42
        10: 3,   # x10 = 3
        11: 2,   # x11 = 2
        12: 4,   # x12 = 4
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