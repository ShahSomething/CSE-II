main:
li  $v0,5 #input value from user
syscall
move $t0,$v0
li  $v0,5 #input value from user
syscall
move $t1,$v0
li  $v0,5 #input value from user
syscall
move $t2,$v0
li  $v0,5 #input value from user
syscall
move $t3,$v0
add $t4,$t0,$t1 #addition of t0 and t1
add $t4,$t4,$t3 #addition of t4 and t3
sub $t5,$t4,$t2 #subtraction of t4 and t2
move $a0,$t5
li $v0,1
syscall
li $v0,10
syscall