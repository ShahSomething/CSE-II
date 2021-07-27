main:
li $t0,6 #load 6 in t0
li $t1,8 #load 8 in t1
li $t2,21 #load 21 in t2
li $t3,30 #load 30 in t3
add $t4,$t0,$t1 #addition of t0 and t1
add $t4,$t4,$t3 #addition of t4 and t3
sub $t5,$t4,$t2 #subtraction of t4 and t2
li $v0,10
syscall