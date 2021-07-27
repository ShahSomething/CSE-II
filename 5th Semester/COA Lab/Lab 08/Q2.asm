.data
    str: .asciiz"---------------  GPA Calculator ----------------"
    str1: .asciiz"\nEnter your GPA in suject 1: "
    str2: .asciiz"\nCredit Hours: "
    str3: .asciiz"\nEnter your GPA in suject 2: "
    str4: .asciiz"\nEnter your GPA in suject 3: "
    str5: .asciiz"\nEnter your GPA in suject 4: "
    str6: .asciiz"\nYour GPA is: "
.text

main:
    la $a0,str  #Load str to a0
    li $v0,4    #Print str
    syscall     #syscall

    la $a0,str1 #Load str1 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,6    #Take floating point input
    syscall     #syscall
    mov.s $f2,$f0   #GPA of sub1

    la $a0,str2 #Load str2 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,6    #Take floating point input
    syscall     #syscall
    mov.s 	$f1, $f0	# CH of sub1

    la $a0,str3 #Load str3 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,6    #Take floating point input
    syscall     #syscall
    mov.s $f4,$f0   #GPA of sub2

    la $a0,str2 #Load str2 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,6    #Take floating point input
    syscall     #syscall
    mov.s 	$f3, $f0	# CH of sub2

    la $a0,str4 #Load str4 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,6    #Take floating point input
    syscall     #syscall
    mov.s $f6,$f0   #GPA of sub3

    la $a0,str2 #Load str2 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,6    #Take floating point input
    syscall     #syscall
    mov.s 	$f5, $f0	# CH of sub3

    la $a0,str5 #Load str5 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,6    #Take floating point input
    syscall     #syscall
    mov.s $f8,$f0   #GPA of sub4

    la $a0,str2 #Load str2 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,6    #Take floating point input
    syscall     #syscall
    mov.s 	$f7, $f0	# CH of sub4

    add.s $f9,$f1,$f3
    add.s $f9,$f9,$f5
    add.s $f9,$f9,$f7     #Total Credit hours (denom)

    mul.s $f12,$f2,$f1
    li.s $f10,0.0
    add.s $f10,$f10,$f12    #f10=GPA1*CH1

    mul.s $f12,$f4,$f3
    add.s $f10,$f10,$f12

    mul.s $f12,$f6,$f5
    add.s $f10,$f10,$f12

    mul.s $f12,$f8,$f7
    add.s $f10,$f10,$f12    #Nom

    div.s $f12,$f10,$f9     #Result

    la $a0,str6 #Load str6 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,2    #Print the result
    syscall     #syscall

    li $v0,10   #Terminate the Program
    syscall     #syscall