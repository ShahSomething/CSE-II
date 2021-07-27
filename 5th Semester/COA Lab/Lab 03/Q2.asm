.data
	str: .asciiz"Enter the first number: "
	str1: .asciiz"Enter the second number: "
	str2: .asciiz"t0 is less than t1\n"
	str3: .asciiz"t0 is less than or equal to t1\n"
	str4: .asciiz"t0 is greater than t1\n"
	str5: .asciiz"t0 is greater than or equal to t1\n"
.text

main:
	li $v0,4	#system call code for printing string
	la $a0,str	#address of the string to print
	syscall		#print the string
	li $v0,5	#input first number
	syscall		#system call
	move $t0,$v0  	#move first number to t0

	li $v0,4	#system call code for printing string
	la $a0,str1	#address of the string to print
	syscall		#print the string
	li $v0,5	#input second number
	syscall		#system call
	move $t1,$v0	#move second number to t1

	blt $t0,$t1,Lab1	#check if t0 is less than t1
	j test2			#jump to test2
	
Lab1:
	li $v0,4	#system call code for printing string
	la $a0,str2	#address of the string to print
	syscall		#print the string
test2:
	ble $t0,$t1,Lab2	#check if t0 is less than or equal to t1
	j test3			#jump to test3
Lab2:
	li $v0,4	#system call code for printing string
	la $a0,str3	#address of the string to print
	syscall		#print the string
test3:
	bgt $t0,$t1,Lab3	#check if t0 is greater than t1
	j test4			#jump test4
Lab3:
	li $v0,4	#system call code for printing string
	la $a0,str4	#address of the string to print
	syscall		#print the string
test4:
	bge $t0,$t1,Lab4	#check if t0 is greater than or equal to t1
	j exit			#jump to exit
Lab4:
	li $v0,4	#system call code for printing string
	la $a0,str5	#address of the string to print
	syscall		#print the string
exit:
	li $v0,10	#Terminate the program
	syscall		#syscall

