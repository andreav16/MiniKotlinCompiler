.data
	string_0: .asciiz "resultado de suma"
string_1: .asciiz "resultado de resta"
string_2: .asciiz "resultado de multiplicacion"
string_3: .asciiz "resultado de division"
string_4: .asciiz "resultado de residuo"

	nextline: .asciiz "\n"
.text	
.globl main
	
main: 
addiu $sp, $sp, -16

sw $ra, 0($sp)

li.s $f0, 12.5
s.s $f0, 4($sp)
li.s $f0, 3.5
s.s $f0, 8($sp)
l.s $f0, 4($sp)

l.s $f1, 8($sp)

add.s $f2, $f0, $f1

s.s $f2, 12($sp)

la $a0, string_0
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall
l.s $f0, 12($sp)

mov.s $f12, $f0
li $v0, 2
syscall
la $a0, nextline
li $v0, 4
syscall
l.s $f0, 4($sp)

l.s $f1, 8($sp)

sub.s $f2, $f0, $f1

s.s $f2, 12($sp)

la $a0, string_1
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall
l.s $f0, 12($sp)

mov.s $f12, $f0
li $v0, 2
syscall
la $a0, nextline
li $v0, 4
syscall
l.s $f0, 4($sp)

l.s $f1, 8($sp)

mul.s $f2, $f0, $f1

s.s $f2, 12($sp)

la $a0, string_2
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall
l.s $f0, 12($sp)

mov.s $f12, $f0
li $v0, 2
syscall
la $a0, nextline
li $v0, 4
syscall
l.s $f0, 4($sp)

l.s $f1, 8($sp)

div.s $f2, $f0, $f1

s.s $f2, 12($sp)

la $a0, string_3
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall
l.s $f0, 12($sp)

mov.s $f12, $f0
li $v0, 2
syscall
la $a0, nextline
li $v0, 4
syscall
l.s $f0, 4($sp)

l.s $f1, 8($sp)

div.s $f15, $f0, $f1
mul.s $f16, $f15, $f1
sub.s $f2, $f0, $f16

s.s $f2, 12($sp)

la $a0, string_4
li $v0, 4
syscall
la $a0, nextline
li $v0, 4
syscall
l.s $f0, 12($sp)

mov.s $f12, $f0
li $v0, 2
syscall
la $a0, nextline
li $v0, 4
syscall

lw $ra, 0($sp)

addiu $sp, $sp, 16
jr $ra
li $v0, 10
syscall

