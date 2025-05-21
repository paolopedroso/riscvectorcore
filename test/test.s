# test.s - Test program for RISC-V core
# Basic operations
addi x1, x0, 1       # x1 = 1
addi x2, x0, 2       # x2 = 2
add  x3, x1, x2      # x3 = 3
slli x4, x3, 2       # x4 = 12 (shift left)
andi x5, x4, 10      # x5 = 8 (bitwise AND)

# Store and load
sw   x3, 0(x0)       # Store x3 to address 0
lw   x6, 0(x0)       # Load from address 0 to x6

# Jump and link
jal  x7, label1      # Jump to label1, x7 = PC+4
addi x8, x0, 123     # Should be skipped
label1:
addi x9, x0, 42      # x9 = 42
