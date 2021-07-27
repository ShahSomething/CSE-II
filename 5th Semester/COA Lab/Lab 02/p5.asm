.data
str: .asciiz"Enter first number: "
str1: .asciiz"Enter second number: "
str2: .asciiz"And: "
str3: .asciiz"   Or: "
str4: .asciiz"   Xor: "
str5: .asciiz"   Nor: "
str6: .asciiz"   Andi: "
str7: .asciiz"   Ori: "
str8: .asciiz"   Xori: "
str9: .asciiz"   Shift left: "
str10: .asciiz"   Shift Right: "
str11: .asciiz"   Shift right arithm: "
str12: .asciiz"   Shift left by var: "
str13: .asciiz"   Shift right by var: "
str14: .asciiz"   Shift right arithm. by var: "
.text


main:
li $v0,4      #system call code for printing string
la $a0,str    #address of a string to print
syscall       #print the string
li $v0,5      #take the value from user
syscall
move $t0,$v0  #move the value to t0

li $v0,4      #system call code for printing string
la $a0,str1   #address of a string to print
syscall       #print the string
li $v0,5      #take the value from user
syscall
move $t1,$v0  #move the value to t1


li $v0,4      #system call code for printing string
la $a0,str2   #address of a string to print
syscall       #print the string

and $t2,$t0,$t1 #and of t0 and t1 stored in t2
move $a0,$t2    #move t2 to a0
li $v0,1        #output the value
syscall

li $v0,4      #system call code for printing string
la $a0,str3   #address of a string to print
syscall       #print the string

or $t2,$t0,$t1  #or of t0 and t1 stored in t2
move $a0,$t2    #move t2 to a0
li $v0,1        #output the value
syscall

li $v0,4     #system call code for printing string
la $a0,str4  #address of a string to print
syscall      #print the string

xor $t2,$t0,$t1  #xor of t0 and t1 stored in t2
move $a0,$t2     #move t2 to a0
li $v0,1         #output the value
syscall

li $v0,4     #system call code for printing string
la $a0,str5  #address of a string to print
syscall      #print the string

nor $t2,$t0,$t1  #nor of t0 and t1 stored in t2
move $a0,$t2     #move t2 to a0
li $v0,1         #output the value
syscall

li $v0,4     #system call code for printing string
la $a0,str6  #address of a string to print
syscall      #print the string

andi $t2,$t0,7  #andi of t0 and 7 stored in t2
move $a0,$t2    #move t2 to a0
li $v0,1        #output the value
syscall

li $v0,4      #system call code for printing string
la $a0,str7   #address of a string to print
syscall       #print the string

ori $t2,$t0,7  #ori of t0 and 7 stored in t2
move $a0,$t2   #move t2 to a0
li $v0,1       #output the value
syscall

li $v0,4      #system call code for printing string
la $a0,str8   #address of a string to print
syscall       #print the string

xori $t2,$t0,7  #xori of t0 and 7 stored in t2
move $a0,$t2    #move t2 to a0
li $v0,1        #output the value
syscall

li $v0,4      #system call code for printing string
la $a0,str9   #address of a string to print
syscall       #print the string

sll $t2,$t0,2  #sll of t0 and 2 stored in t2
move $a0,$t2   #move t2 to a0
li $v0,1       #output the value
syscall

li $v0,4       #system call code for printing string
la $a0,str10   #address of a string to print
syscall        #print the string

srl $t2,$t0,2  #srl of t0 and 2 stored in t2
move $a0,$t2   #move t2 to a0
li $v0,1       #output the value
syscall

li $v0,4       #system call code for printing string
la $a0,str11   #address of a string to print
syscall        #print the string

sra $t2,$t0,2  #sra of t0 and 2 stored in t2
move $a0,$t2   #move t2 to a0
li $v0,1       #output the value
syscall


li $v0,4       #system call code for printing string
la $a0,str12   #address of a string to print
syscall        #print the string

sllv $t2,$t0,$t1  #sllv of t0 and t1 stored in t2
move $a0,$t2      #move t2 to a0
li $v0,1          #output the value
syscall

li $v0,4       #system call code for printing string
la $a0,str13   #address of a string to print
syscall        #print the string

srlv $t2,$t0,$t1  #srlv of t0 and t1 stored in t2
move $a0,$t2      #move t2 to a0
li $v0,1          #output the value
syscall

li $v0,4       #system call code for printing string
la $a0,str14   #address of a string to print
syscall        #print the string

srav $t2,$t0,$t1  #srav of t0 and t1 stored in t2
move $a0,$t2      #move t2 to a0
li $v0,1          #output the value
syscall


li $v0,10       #exit program
syscall
