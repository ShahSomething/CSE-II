main:
li  $v0,5 #input value from user
syscall
move $t0,$v0
li  $v0,5 #input value from user
syscall
move $t1,$v0
add $t2,$t0,$t1
li $v0,10
syscall
