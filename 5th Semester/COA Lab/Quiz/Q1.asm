main:
	li $t0,1
print:
	move $a0,$t0
	li $v0,1
	syscall
	
	addi $t0,$t0,1
	ble $t0,5, print
	li $v0,10
	syscall
