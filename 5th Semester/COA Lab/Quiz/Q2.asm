.data
	str: .asciiz "Enter a positive integer: "
	str1: .asciiz "\nSum = "
.text

main:

	li $v0,4
	la $a0,str
	syscall

	li $v0,5
	syscall
	move $t0,$v0

	li $t1,0
	li $t2,1

label:
	add $t1,$t1,$t2
	addi $t2,$t2,1

	ble $t2,$t0, label

	li $v0,4
	la $a0,str1
	syscall

	move $a0,$t1
	li $v0,1
	syscall

	li $v0,10
	syscall

