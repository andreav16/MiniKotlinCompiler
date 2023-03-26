.data
	
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
addiu $sp, $sp, -28

sw $ra, 0($sp)

li $t0, 0

li $t1, 4

sw $t0, 24($sp)
startFor_2: 
bgt $t0, $t1, endFor_3
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
j startFor_2
endFor_3: 

lw $ra, 0($sp)

addiu $sp, $sp, 28
jr $ra
li $v0, 10
syscall

