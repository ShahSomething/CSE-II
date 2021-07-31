clc
clear all
close all
fs = 4000;
N = 512;
t = (0:N-1)/fs;
x1 = sin(2*pi*400*t);
x2 = sin(2*pi*850*t);
x = x1+x2;
xk = fft(x);
f = ((0:N-1)*fs)/N;
subplot(2,1,1)
plot(t,x);
title('Time Domain Signal');
subplot(2,1,2)
plot(f,abs(xk));
title('Frequency Domain(N=512)');