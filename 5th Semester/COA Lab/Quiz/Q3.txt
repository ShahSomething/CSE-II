.data
	str: .asciiz" * "
	str1: .asciiz" = "
	str2: .asciiz"Enter a positive integer: "
	str3: .asciiz"\n"
.text

main:

	li $v0,4
	la $a0,str2
	syscall

	li $v0,5
	syscall
	move $t0,$v0
	
	li $t1,1
label:
	move $a0,$t0
	li $v0,1
	syscall

	li $v0,4
	la $a0,str
	syscall
	
	move $a0,$t1
	li $v0,1
	syscall

	li $v0,4
	la $a0,str1
	syscall

	mul $t2,$t0,$t1
	move $a0,$t2
	li $v0,1
	syscall

	li $v0,4
	la $a0,str3
	syscall

	addi $t1,$t1,1

	ble $t1,10,label

	li $v0,10
	syscall

	
	
