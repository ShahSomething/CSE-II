clc
clear all
close all
f = 3;
fs = 20*f;     %Nyquist Criterion
t = 0:1/fs:1;
x = sin(2*pi*f*t);
subplot(2,1,1)
plot(t,x);
title('Analog');
subplot(2,1,2)
stem(t,x);
title('Digital');

    

