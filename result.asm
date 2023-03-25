.data
	string_0: .asciiz "hola"
string_1: .asciiz "adios"

	nextline: .asciiz "\n"
.text	
.globl main
	
main: 
addiu $sp, $sp, -12

sw $ra, 0($sp)

la $t0, string_0
sw $t0, 4($sp)

lw $a0, 4($sp)
syscall
la $a0, nextline
li $v0, 4
syscall

la $a0, string_1
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall
li $t0, 55

move $a0, $t0
li $v0, 1
syscall
la $a0, nextline
li $v0, 4
syscall
li.s $f0, 223.322
s.s $f0, 8($sp)
l.s $f0, 8($sp)

mov.s $f12, $f0
li $v0, 2
syscall
la $a0, nextline
li $v0, 4
syscall

lw $ra, 0($sp)

addiu $sp, $sp, 12
jr $ra
main2: 
addiu $sp, $sp, -4

sw $ra, 0($sp)


lw $ra, 0($sp)

addiu $sp, $sp, 4
jr $ra
li $v0, 10
syscall

