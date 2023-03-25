.data
	string_0: .asciiz "hola"

	nextline: .asciiz "\n"
.text	
.globl main
	
main: 
addiu $sp, $sp, -8

sw $ra, 0($sp)

la $a0, 
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall

lw $ra, 0($sp)

addiu $sp, $sp, 8
jr $ra
li $v0, 10
syscall

