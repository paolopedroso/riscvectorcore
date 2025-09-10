# Forwarding Test Program

# Initialize base values
li x1, 10           # x1 = 10
li x2, 20           # x2 = 20
li x3, 5            # x3 = 5

# TEST 1: EX-to-EX Forwarding (back-to-back ALU instructions)
add x4, x1, x2      # x4 = x1 + x2 = 30
add x5, x4, x3      # x5 = x4 + x3 = 35 (needs x4 from previous instruction)
sub x6, x5, x1      # x6 = x5 - x1 = 25 (needs x5 from previous instruction)

# TEST 2: MEM-to-EX Forwarding (load followed by ALU)
li x7, 0x1000       # Base address
sw x1, 0(x7)        # Store x1 to memory
lw x8, 0(x7)        # Load from memory to x8
add x9, x8, x2      # x9 = x8 + x2 (needs x8 from load instruction)

# TEST 3: Multiple forwarding paths
add x10, x1, x2     # x10 = 30
sub x11, x10, x3    # x11 = 25 (EX-to-EX forwarding)
add x12, x10, x11   # x12 = 55 (both operands need forwarding)

# TEST 4: Load-use hazard (requires stall + forwarding)
li x13, 0x1004      # Different address
sw x2, 0(x13)       # Store x2 to memory
lw x14, 0(x13)      # Load to x14
add x15, x14, x1    # Immediate use of loaded data (load-use hazard)

# TEST 5: Chain of dependencies
add x16, x1, x2     # x16 = 30
sll x17, x16, 1     # x17 = x16 << 1 = 60 (shift left by 1)
and x18, x17, x1    # x18 = x17 & x1 = 8 (bitwise AND)
or  x19, x18, x3    # x19 = x18 | x3 = 13 (bitwise OR)

# TEST 6: Branch with dependency
add x20, x1, x3     # x20 = 15
beq x20, x20, equal # Branch if equal (should take branch)
addi x21, x0, 999   # Should not execute
equal:
addi x21, x0, 777   # Should execute (fixed: added label)

# TEST 7: Store with forwarded data
add x22, x1, x2     # x22 = 30
li x23, 0x1008      # Store address
sw x22, 0(x23)      # Store forwarded data to memory

# TEST 8: RAW hazard with immediate instructions
addi x24, x1, 100   # x24 = 110
andi x25, x24, 0xFF # x25 = x24 & 0xFF = 110 (needs forwarding)
ori  x26, x25, 0x10 # x26 = x25 | 0x10 = 126

# TEST 9: Complex forwarding scenario
add  x27, x1, x2    # x27 = 30
sub  x28, x27, x3   # x28 = 25 (EX-to-EX)
sw   x28, 4(x7)     # Store x28 (MEM stage gets forwarded data)
lw   x29, 4(x7)     # Load back
add  x30, x29, x27  # x30 = 55 (MEM-to-EX forwarding)

# TEST 10: No forwarding needed (separated instructions)
add x31, x1, x2     # x31 = 30
nop                 # No operation
nop                 # No operation  
add x1, x31, x3     # x1 = 35 (no forwarding needed due to distance)

# End program
end:
ebreak              # Environment break (stops simulation)