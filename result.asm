.data
	string_2: .asciiz "Array elements"
string_5: .asciiz "Enter element to find:"
string_13: .asciiz "Found."
string_14: .asciiz "Not found."
string_17: .asciiz "Not found x2."

	nextline: .asciiz "\n"
.text	
.globl main
	
f: 
addiu $sp, $sp, -12

sw $ra, 0($sp)

sw $a0, 4($sp)
lw $t0, 4($sp)

li $t1, 1

add $t0, $t0, $t1

sw $t0, 8($sp)
while_0: 
lw $t0, 8($sp)

li $t1, 10

div $t0, $t1
mfhi $t0

li $t1, 0

seq $t0, $t0, $t1


beqz $t0, endWhile_1
lw $t0, 8($sp)

li $t1, 10

div $t0, $t1
mflo $t0
sw $t0, 8($sp)

j while_0
endWhile_1: 
lw $t0, 8($sp)

move $v0, $t0

lw $ra, 0($sp)

addiu $sp, $sp, 12
jr $ra
main: 
addiu $sp, $sp, -44

sw $ra, 0($sp)


la $a0, string_2
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall
li $t0, 0

li $t1, 4

sw $t0, 24($sp)
startFor_3: 
bge $t0, $t1, endFor_4
lw $t2, 24($sp)

li $t3, 1

add $t2, $t2, $t3

lw $t3, 24($sp)

li $a0, 4
mult $a0, $t3
mflo $t4
la $t5, 4($sp)
add $t4, $t4, $t5
lw $t2, 24($sp)

li $t3, 1

add $t2, $t2, $t3


sw $t2, 0($t4)
lw $t2, 24($sp)

li $a0, 4
mult $a0, $t2
mflo $t2
la $t3, 4($sp)
add $t2, $t3, $t2
lw $t2, 0($t2)

move $a0, $t2
li $v0, 1
syscall
la $a0, nextline
li $v0, 4
syscall
addi $t0, $t0, 1
sw $t0, 24($sp)
j startFor_3
endFor_4: 
li $t0, 0
sw $t0, 28($sp)

la $a0, string_5
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall
li $v0, 5
syscall
move $t0, $v0
sw $t0, 36($sp)
li $t0, 0

li $t1, 4

sw $t0, 32($sp)
startFor_6: 
bge $t0, $t1, endFor_7
if_8: 
lw $t2, 32($sp)

li $a0, 4
mult $a0, $t2
mflo $t2
la $t4, 4($sp)
add $t2, $t4, $t2
lw $t2, 0($t2)

lw $t5, 36($sp)

seq $t2, $t2, $t5


beqz $t2, endif_9
li $t2, 1
sw $t2, 28($sp)

j endif_9
endif_9: 
addi $t0, $t0, 1
sw $t0, 32($sp)
j startFor_6
endFor_7: 
if_10: 
lw $t0, 28($sp)

beqz $t0, else_11

la $a0, string_13
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall

j endif_12
else_11: 
la $a0, string_14
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall

endif_12: 
if_15: 
lw $t0, 28($sp)
slti $t0, $t0, 1

beqz $t0, endif_16

la $a0, string_17
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall

j endif_16
endif_16: 
li $t0, 20

move $a0, $t0
jal f
move $t0, $v0
sw $t0, 40($sp)
lw $t0, 40($sp)

move $a0, $t0
li $v0, 1
syscall
la $a0, nextline
li $v0, 4
syscall

lw $ra, 0($sp)

addiu $sp, $sp, 44
jr $ra
li $v0, 10
syscall

