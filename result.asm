.data
	
	nextline: .asciiz "\n"
.text	
.globl main
	
main: 
addiu $sp, $sp, -16

sw $ra, 0($sp)

li $t0, 10
sw $t0, 4($sp)
li $t0, 5
sw $t0, 8($sp)
if_0: 
lw $t0, 4($sp)

lw $t1, 8($sp)

sgt $t0, $t0, $t1


beqz $t0, endif_1
lw $t0, 8($sp)

move $v0, $t0

j endif_1
endif_1: 
lw $t0, 12($sp)

move $a0, $t0
li $v0, 1
syscall
la $a0, nextline
li $v0, 4
syscall

lw $ra, 0($sp)

addiu $sp, $sp, 16
jr $ra
li $v0, 10
syscall

