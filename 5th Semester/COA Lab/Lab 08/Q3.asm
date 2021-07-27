.data
    str: .asciiz"Enter the first double floating point number: "
    str1: .asciiz"\nEnter the second double floating point number: "
    str2: .asciiz"\n1. Addition"
    str3: .asciiz"\n2. Subtraction"
    str4: .asciiz"\n3. Multiplication"
    str5: .asciiz"\n4. Division"
    str6: .asciiz"\nEnter your Choice: "
    str7: .asciiz"\nResult: "
    str8: .asciiz"\nInvalid Choice"
.text

main:
    la $a0,str  #Load str to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,7    #Take double floating point input
    syscall     #syscall
    mov.d $f2,$f0   #move input to f2

    la $a0,str1 #Load str1 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,7    #Take double floating point input
    syscall     #syscall
    mov.d $f4,$f0   #move input to f4

    la $a0,str2 #Load str2 to a0
    li $v0,4    #Print str
    syscall     #syscall

    la $a0,str3 #Load str3 to a0
    li $v0,4    #Print str
    syscall     #syscall

    la $a0,str4 #Load str4 to a0
    li $v0,4    #Print str
    syscall     #syscall

    la $a0,str5 #Load str5 to a0
    li $v0,4    #Print str
    syscall     #syscall

    la $a0,str6 #Load str6 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,5    #Take integer input
    syscall     #syscall
    move 	$t0, $v0		# Choice

    li $t1,1    #t1 = 1
    li $t2,2    #t2 = 2
    li $t3,3    #t3 = 3
    li $t4,4    #t4 = 4

    beq	$t0, $t1, Add   #Branch to Add if t0 == t1
    beq $t0, $t2, Sub   #Branch to Sub if t0 == t2
    beq $t0, $t3, Mul   #Branch to Mul if t0 == t3
    beq $t0, $t4, Div   #Branch to Div if t0 == t4
    j Invalid           #Jump to Invalid

Add:
    la $a0,str7 #Load str7 to a0
    li $v0,4    #Print str
    syscall     #syscall

    add.d $f12,$f2,$f4  #Add the two numbers
    li $v0,3    #Print the result
    syscall     #syscall

    j exit  #Jump to exit
Sub:
    la $a0,str7 #Load str7 to a0
    li $v0,4    #Print str
    syscall     #syscall

    sub.d $f12,$f2,$f4  #Subtract the two numbers
    li $v0,3    #Print the result
    syscall     #syscall

    j exit  #Jump to exit
Mul:
    la $a0,str7 #Load str7 to a0
    li $v0,4    #Print str
    syscall     #syscall

    mul.d $f12,$f2,$f4  #Multiply the two numbers
    li $v0,3    #Print the result
    syscall     #syscall

    j exit  #Jump to exit
Div:
    la $a0,str7 #Load str7 to a0
    li $v0,4    #Print str
    syscall     #syscall

    div.d $f12,$f2,$f4  #Divide the two numbers
    li $v0,3    #Print the result
    syscall     #syscall

    j exit  #Jump to exit
Invalid:
    la $a0,str8 #Load str8 to a0
    li $v0,4    #Print str
    syscall     #syscall
exit:
    li $v0,10   #Terminate the Program
    syscall     #syscall
    