.data
	string_0: .asciiz "Talk is cheap. "
string_1: .asciiz "Show me the code. "
string_2: .asciiz "- Linus Torvalds"

	nextline: .asciiz "\n"
.text	
.globl main
	
main: 
addiu $sp, $sp, -20

sw $ra, 0($sp)

la $t0, string_0
sw $t0, 4($sp)
la $t0, string_1
sw $t0, 8($sp)
la $t0, string_2
sw $t0, 12($sp)
lw $t0, 4($sp)

lw $t1, 8($sp)

move $a0, $t0
addi $a0, $a0, 15
move $a1, $t1
concat_loop_3: 
lb $t2, ($a1) 
sb $t2, ($a0) 
addi $a0, $a0, 1 
addi $a1, $a1, 1 
bnez $t2, concat_loop_3


lw $t1, 12($sp)

move $a0, $t0
addi $a0, $a0, 33
move $a1, $t1
concat_loop_4: 
lb $t2, ($a1) 
sb $t2, ($a0) 
addi $a0, $a0, 1 
addi $a1, $a1, 1 
bnez $t2, concat_loop_4

move $t1, $t0
sw $t1, 16($sp)
lw $t0, 16($sp)

move $a0, $t0
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall

lw $ra, 0($sp)

addiu $sp, $sp, 20
jr $ra
li $v0, 10
syscall

