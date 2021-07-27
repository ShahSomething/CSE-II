.data
    str1: .asciiz"Enter a to print multiplication table of 2\n"
    str2: .asciiz"Enter b to print multiplication table of 3\n"
    str3: .asciiz"Enter c to print multiplication table of 4\n"
    str4: .asciiz"Choice: "
    str5: .asciiz" * "
    str6: .asciiz" = "
    str7: .asciiz"\n"
    str8: .asciiz"Wrong Choice\n"
.text

main:
    li $v0,4
    la $a0,str1
    syscall

    li $v0,4
    la $a0,str2
    syscall

    li $v0,4
    la $a0,str3
    syscall

    li $v0,4
    la $a0,str4
    syscall

    li $v0,12
    syscall
    move $t0,$v0

    li $t1,97
    li $t2,98
    li $t3,99

    li $t4,1
    li		$t6, 10		
    

    beq		$t0, $t1, Mult2	 
    beq		$t0, $t2, Mult3	
    beq		$t0, $t3, Mult4	
    j		Wrong			
    

    Mult2:
        target:
            li $v0,4
            la $a0,str7
            syscall

            li		$t1, 2		
            move 	$a0, $t1		
            li		$v0, 1		
            syscall

            li $v0,4
            la $a0,str5
            syscall

            move 	$a0, $t4		
            li		$v0, 1		
            syscall

            li $v0,4
            la $a0,str6
            syscall
            
	        mul $t5,$t1,$t4
	        move $a0,$t5
	        li $v0,1
	        syscall
	        addi $t4,$t4,1
	        ble $t4,$t6, target
            j		exit				
    Mult3:
        target2:
            li $v0,4
            la $a0,str7
            syscall

            li		$t1, 3		
            move 	$a0, $t1		
            li		$v0, 1		
            syscall

            li $v0,4
            la $a0,str5
            syscall

            move 	$a0, $t4		
            li		$v0, 1		
            syscall

            li $v0,4
            la $a0,str6
            syscall
            
	        mul $t5,$t1,$t4
	        move $a0,$t5
	        li $v0,1
	        syscall
	        addi $t4,$t4,1
	        ble $t4,$t6, target2
            j		exit				
    Mult4:
        target3:
            li $v0,4
            la $a0,str7
            syscall

            li		$t1, 4		
            move 	$a0, $t1		
            li		$v0, 1		
            syscall

            li $v0,4
            la $a0,str5
            syscall

            move 	$a0, $t4		 
            li		$v0, 1		
            syscall

            li $v0,4
            la $a0,str6
            syscall
            
	        mul $t5,$t1,$t4
	        move $a0,$t5
	        li $v0,1
	        syscall
	        addi $t4,$t4,1
	        ble $t4,$t6, target3
            j		exit				
    Wrong:
        li $v0,4
        la $a0,str8
        syscall
    exit:
        li		$v0, 10		
        syscall

    
    
    

