.data
	string_2: .asciiz "Hello"

	nextline: .asciiz "\n"
.text	
.globl main
	
main: 
addiu $sp, $sp, -36

sw $ra, 0($sp)

li $t0, 2
sw $t0, 4($sp)
while_0: 
lw $t0, 4($sp)

li $t1, 0

sgt $t0, $t0, $t1


beqz $t0, endWhile_1
lw $t0, 4($sp)

li $t1, 1

sub $t0, $t0, $t1

sw $t0, 4($sp)

la $a0, string_2
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall

j while_0
endWhile_1: 
li $t0, 1
sw $t0, 8($sp)
li $t0, 3
sw $t0, 12($sp)
while_3: 
lw $t0, 8($sp)

bc1f endWhile_4
li $t0, 0
sw $t0, 8($sp)
li $t0, 0

lw $t1, 12($sp)

li $t2, 1

sub $t1, $t1, $t2


sw $t0, 28($sp)
startFor_5: 
bgt $t0, $t1, endFor_6
if_7: 
lw $t2, 28($sp)

li $a0, 4
mult $a0, $t2
mflo $t2
la $t3, 16($sp)
add $t2, $t3, $t2
lw $t2, 0($t2)

lw $t4, 28($sp)

li $t5, 1

add $t4, $t4, $t5


li $a0, 4
mult $a0, $t4
mflo $t4
la $t5, 16($sp)
add $t4, $t5, $t4
lw $t4, 0($t4)

sgt $t2, $t2, $t4


beqz $t2, endif_8
lw $t2, 28($sp)

li $a0, 4
mult $a0, $t2
mflo $t2
la $t4, 16($sp)
add $t2, $t4, $t2
lw $t2, 0($t2)
sw $t2, 32($sp)
lw $t2, 28($sp)

li $t6, 1

add $t2, $t2, $t6


li $a0, 4
mult $a0, $t2
mflo $t2
la $t6, 16($sp)
add $t2, $t6, $t2
lw $t2, 0($t2)
lw $t7, 28($sp)

li $a0, 4
mult $a0, $t7
mflo $t8
la $t9, 16($sp)
add $t8, $t8, $t9
lw $t2, 28($sp)

li $t6, 1

add $t2, $t2, $t6


li $a0, 4
mult $a0, $t2
mflo $t2
la $t6, 16($sp)
add $t2, $t6, $t2
lw $t2, 0($t2)

sw $t2, 0($t8)
lw $t2, 32($sp)
lw $t7, 28($sp)

li $t8, 1

add $t7, $t7, $t8


li $a0, 4
mult $a0, $t7
mflo $t8
la $t9, 16($sp)
add $t8, $t8, $t9
lw $t2, 32($sp)

sw $t2, 0($t8)
li $t2, 1
sw $t2, 8($sp)

j endif_8
endif_8: 
addi $t0, $t0, 1
sw $t0, 28($sp)
j startFor_5
endFor_6: 

j while_3
endWhile_4: 

lw $ra, 0($sp)

addiu $sp, $sp, 36
jr $ra
li $v0, 10
syscall

