main:
li $t0,3 #load 3 in t0
li $t1,6 #load 6 in t1
li $t2,2 #load 2 in t2
add $t3,$t0,$t1 #addition of t1 and t0
add $t3,$t3,$t2 #addition of t3 and t2
li $v0,10
syscall