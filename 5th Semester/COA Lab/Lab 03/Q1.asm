.data
	str: .asciiz"Enter the first number: "
	str1: .asciiz"Enter the second number: "
	str2: .asciiz"Enter the third number: "
	str3: .asciiz"Enter the fourth number: "
	str4: .asciiz"The Greatest number is: "
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


	li $v0,4	#system call code for printing string
	la $a0,str2	#address of the string to print
	syscall		#print the string
	li $v0,5	#input third number
	syscall		#system call
	move $t2,$v0	#move third number to t1

	li $v0,4	#system call code for printing string
	la $a0,str3	#address of the string to print
	syscall		#print the string
	li $v0,5	#input fourth number
	syscall		#system call
	move $t3,$v0	#move fourth number to t1

	li $v0,4	#system call code for printing string
	la $a0,str4	#address of the string to print
	syscall		#print the string

	bgt $t0,$t1, t0GTt1	#check if t0 is greater than t1
	move $t4,$t1		#move t1 to t4
	j test2			#jump to test2
t0GTt1:
	move $t4,$t0	#move t0 to t4
test2:
	bgt $t2,$t4, t2GTt4	#check if t2 is greater than t4
	j test3			#jump to test3

t2GTt4:
	move $t4,$t2	#move t2 to t4
test3:
	bgt $t3,$t4, t3GTt4	#check if t3 is greater than t4
	j exit			#jump to exit
t3GTt4:
	move $t4,$t3	#move t3 to t4
exit:
	li $v0,1	#system call code to print int
	move $a0,$t4	#move t4 to a0
	syscall		#print value in a0
	li $v0,10	#Terminate the program
	syscall		#syscall


	
	


	