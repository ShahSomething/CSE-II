.data
	CV: .asciiz"########################### CV ###############################\n"
	Name: .asciiz"Name: "
	FatherName: .asciiz"Father Name: "
	Education: .asciiz"Education: "
	Experience: .asciiz"Experience: "
	End: .asciiz"#############################################################"
	input1: .space 15
	input2: .space 15
	input3: .space 15
	input4: .space 15
	str1: .asciiz"Enter your Name: "
	str2: .asciiz"Enter your Father Name: "
	str3: .asciiz"Enter your Education: "
	str4: .asciiz"Enter your Experience: "
.text

main:

	li $v0,4	#system call to print string
	la $a0,str1	#address of string
	syscall		#syscall

	#Take string as an input
	li $v0,8	
	la $a0,input1
	li $a1,15
	syscall

	li $v0,4	#system call to print string
	la $a0,str2	#address of string
	syscall		#syscall

	#Take string as an input
	li $v0,8
	la $a0,input2
	li $a1,15
	syscall

	li $v0,4	#system call to print string
	la $a0,str3	#address of string
	syscall		#syscall


	#Take string as an input
	li $v0,8
	la $a0,input3
	li $a1,15
	syscall

	li $v0,4	#system call to print string
	la $a0,str4	#address of string
	syscall		#syscall

	#Take string as an input
	li $v0,8
	la $a0,input4
	li $a1,15
	syscall

	li $v0,4	#system call to print string
	la $a0,CV	#address of string
	syscall		#syscall

	li $v0,4	#system call to print string
	la $a0,Name	#address of string
	syscall		#syscall
	li $v0,4	#system call to print string
	la $a0,input1	#address of string
	syscall		#syscall

	li $v0,4		#system call to print string
	la $a0,FatherName	#address of string
	syscall			#syscall
	li $v0,4		#system call to print string
	la $a0,input2		#address of string
	syscall			#syscall

	li $v0,4		#system call to print string
	la $a0,Education	#address of string
	syscall			#syscall
	li $v0,4	#system call to print string
	la $a0,input3	#address of string
	syscall		#syscall

	li $v0,4		#system call to print string
	la $a0,Experience	#address of string
	syscall			#syscall
	li $v0,4	#system call to print string
	la $a0,input4	#address of string
	syscall		#syscall

	li $v0,4	#system call to print string
	la $a0,End	#address of string
	syscall		#syscall

	li $v0,10	#Terminate the Program
	syscall		#syscall
