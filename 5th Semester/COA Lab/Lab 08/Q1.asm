.data
    str: .asciiz"Enter temperature in Celsius: "
    str1: .asciiz"\nTemperature in Fahrenhiet: "
.text

main:
    la $a0,str  #Load str to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,6    #Take floating point input
    syscall     #syscall
    mov.s $f2,$f0   #move input to f2

    li.s $f4,9.0    #f4 = 9.0
    li.s $f6,5.0    #f6 = 5.0
    li.s $f8,32.0   #f8 = 32.0

    mul.s $f10,$f2,$f4      #f10 = Celsius*9.0
    div.s $f10,$f10,$f6     #f10 = (Celsius*9.0)/5.0
    add.s $f10,$f10,$f8     #f10 = Celsius*9.0/5.0 +32.0

    mov.s $f12,$f10        #f12 = f10

    la $a0,str1 #Load str1 to a0
    li $v0,4    #Print str
    syscall     #syscall

    li $v0,2    #Print the result
    syscall     #syscall

    li $v0,10   #Terminate the Program
    syscall     #syscall
