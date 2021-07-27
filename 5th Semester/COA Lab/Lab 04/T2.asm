.data
	str: .asciiz"Enter A: "
	str1: .asciiz"Enter B: "
	str2: .asciiz"Multiples of A from A to A*B:\n"
	str3: .asciiz"\n"
.text

main:
	li $v0,4	#system call to print string
	la $a0,str	#address of string
	syscall		#syscall

	li $v0,5	#Take input from the user
	syscall		#syscall
	move $t0,$v0	#move to t0

	li $v0,4	#system call to print string
	la $a0,str1	#address of string
	syscall		#syscall

	li $v0,5	#Take input from the user
	syscall		#syscall
	move $t1,$v0	#move to t1

	li $v0,4	#system call to print string
	la $a0,str2	#address of string
	syscall		#syscall

	li $t2,1	#load 1 to t2
label:
	mul $t3,$t0,$t2		#multiply t0 and t2 and store the result in t3
	move $a0,$t3		#move t3 to a0
	li $v0,1		#system call to print int
	syscall			#syscall
	li $v0,4		#system call to print string
	la $a0,str3		#address of string
	syscall			#syscall
	addi $t2,$t2,1		#Increment t2 by 1
	ble $t2,$t1, label	#branch if t2 is less than or equal to t1
	li $v0,10		#Terminate the program
	syscall			#syscall

	
	

