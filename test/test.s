# Complete test program for RISC-V processor
# Exercises all major instruction types and pipeline hazards

#========== Basic ALU and Immediate Operations ==========
# Basic register setup
addi x1, x0, 1       # x1 = 1
addi x2, x0, 2       # x2 = 2
addi x3, x0, 4       # x3 = 4
addi x4, x0, 8       # x4 = 8

# Test arithmetic operations
add  x3, x1, x2      # x3 = 1 + 2 = 3 (tests forwarding)
sub  x4, x1, x3      # x4 = 1 - 3 = -2 (tests forwarding)

# Test logical operations
and  x5, x1, x2      # x5 = 1 & 2 = 0
or   x6, x1, x2      # x6 = 1 | 2 = 3
xor  x7, x1, x2      # x7 = 1 ^ 2 = 3

# Test shifts
slli x8, x1, 1       # x8 = 1 << 1 = 2
srli x9, x1, 2       # x9 = 1 >> 2 = 0
srai x10, x1, 2      # x10 = 1 >> 2 = 0 (arithmetic)

#========== Memory Operations with Data Hazards ==========
# Store operations - test immediate forwarding
sw   x3, 0(x0)       # mem[0] = 3
sw   x4, 4(x0)       # mem[4] = -2

# Load operations - test load-use hazard
lw   x11, 0(x0)      # x11 = mem[0] = 3
addi x11, x11, 0     # NOP-like to test load-use hazard

# Load-Add forwarding test
lw   x12, 4(x0)      # x12 = mem[4] = -2
add  x12, x11, x12   # x12 = 3 + (-2) = 1

# Complex store/load sequence with back-to-back dependencies
sw   x12, 8(x0)      # mem[8] = 1
lw   x13, 8(x0)      # x13 = mem[8] = 1
add  x13, x2, x13    # x13 = 2 + 1 = 3
sw   x13, 12(x0)     # mem[12] = 3

#========== Different Memory Access Sizes ==========
# Byte operations
addi x14, x0, 253    # x14 = 253 (0xFD)
sw   x14, 16(x0)     # mem[16] = 253
lb   x15, 16(x0)     # x15 = mem[16](byte) = -3 (sign extended)
lbu  x16, 16(x0)     # x16 = mem[16](byte) = 253 (zero extended)

# Halfword operations
lui  x16, 0xaaaab    # Upper 20 bits to make big value
sw   x16, 20(x0)     # mem[20] = big value
lh   x17, 20(x0)     # x17 = mem[20](halfword) = sign extended
lhu  x18, 20(x0)     # x18 = mem[20](halfword) = zero extended

#========== Test Branches ==========
# Branch test setup
addi x19, x0, 3      # x19 = 3
addi x20, x0, 5      # x20 = 5

# Test branch equal (not taken)
beq  x19, x20, beq_target  # Skip if x19 == x20 (should not branch)

# Continue with normal execution
addi x21, x0, 20     # x21 = 20 (only executed if branch not taken)

# Test branch not equal (taken)
bne  x19, x20, bne_target  # Branch if x19 != x20 (should branch)
addi x22, x0, -1     # x22 = -1 (should be skipped)

bne_target:
addi x22, x0, 10     # x22 = 10 (only executed if branch taken)

# Test load after branch
lw   x23, 16(x0)     # x23 = mem[16] = 253

beq_target:          # Target for the beq branch (not reached in normal execution)

#========== Test Complex Forwarding Cases ==========
# Multiple consecutive data hazards
addi x24, x20, 21    # x24 = 5 + 21 = 26
addi x25, x24, 24    # x25 = 26 + 24 = 50
addi x26, x25, 25    # x26 = 50 + 25 = 75
addi x27, x26, 26    # x27 = 75 + 26 = 101

# Store-load-store sequence
sw   x27, 28(x0)     # mem[28] = 101
lw   x29, 28(x0)     # x29 = mem[28] = 101
addi x28, x0, 29     # x28 = 29
sw   x28, 30(x0)     # mem[30] = 29

# Read from register being written
addi x30, x0, 28     # x30 = 28
addi x31, x0, 30     # x31 = 30
add  x30, x30, x30   # x30 = 28 + 28 = 56

#========== Final test and terminate ==========
# Test jump and link
jal  x1, jal_target  # Jump to jal_target, x1 = PC+4

# Instructions that should be skipped
addi x0, x0, 0       # NOP (should be skipped)
addi x0, x0, 0       # NOP (should be skipped)
addi x0, x0, 0       # NOP (should be skipped)
addi x0, x0, 0       # NOP (should be skipped)
addi x0, x0, 0       # NOP (should be skipped)

jal_target:
jalr x0, 0(x1)       # Return to where x1 points, don't update x1

# Final test - executed after return
lui  x16, 0x12345    # Final register update test

# Terminate with EBREAK
ebreak               # End simulation
