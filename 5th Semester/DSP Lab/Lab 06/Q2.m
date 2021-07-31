clc
clear all
close all
f = 3;
t = 0:1/50:1;
x = sin(2*pi*f*t);
comb = ones(1,51);
Digital = x.*comb;
subplot(3,1,1)
plot(t,x);
title('Analog');
subplot(3,1,2)
stem(t,comb);
title('Comb');
subplot(3,1,3)
stem(t,Digital)
title('Digital');