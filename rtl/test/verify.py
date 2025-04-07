#!/usr/bin/env python3
import sys

def verify_registers(actual_file, expected_file):
    # Read actual register values
    actual = {}
    with open(actual_file, 'r') as f:
        for line in f:
            if '=' in line:
                parts = line.strip().split('=')
                if len(parts) == 2:
                    reg, value = parts
                    actual[reg.strip()] = int(value.strip())
    
    # Read expected register values
    expected = {}
    with open(expected_file, 'r') as f:
        for line in f:
            if '=' in line:
                parts = line.strip().split('=')
                if len(parts) == 2:
                    reg, value = parts
                    expected[reg.strip()] = int(value.strip())
    
    # Compare values
    success = True
    for reg, expected_value in expected.items():
        if reg in actual:
            actual_value = actual[reg]
            if actual_value != expected_value:
                print(f"ERROR: {reg} expected {expected_value}, got {actual_value}")
                success = False
        else:
            print(f"ERROR: {reg} not found in register dump")
            success = False
    
    return success

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: verify.py actual_registers.txt expected_registers.txt")
        sys.exit(1)
    
    actual_file = sys.argv[1]
    expected_file = sys.argv[2]
    
    success = verify_registers(actual_file, expected_file)
    
    if success:
        print("Verification successful! All registers match expected values.")
        sys.exit(0)
    else:
        print("Verification failed! Some registers do not match expected values.")
        sys.exit(1)
        