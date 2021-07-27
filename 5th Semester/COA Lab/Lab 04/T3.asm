.data
	str: .asciiz"Enter a Number: "
.text

main:

	li $v0,4	#system call to print string
	la $a0,str	#address of string
	syscall		#syscall

	li $v0,5	#Take input from the user
	syscall		#syscall

	move $t0,$v0	#move input to t0

	sll $t1,$t0,2	#shift left t0 by 2 and store in t1
	sll $t2,$t0,4	#shift left t0 by 4 and store in t2

	add $t3,$t1,$t2	#add t1 to t2 and store in t3

	move $a0,$t3	#move t3 to a0

	li $v0,1	#system call to print int
	syscall		#syscall

	li $v0,10	#Terminate the program
	syscall		#syscall