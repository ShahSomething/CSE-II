clc
clear all
close all
fs = 4000;
N = 800;
t = (0:N-1)/fs;
x = sin(2*pi*900*t);
xk = fft(x);
f = ((0:N-1)*fs)/N;
y = ifft(xk);
subplot(3,1,1)
plot(t,x);
title('Original Signal');
subplot(3,1,2)
plot(f,abs(xk));
title('Frequency Domain');
subplot(3,1,3)
plot(t,y);
title('IFFT');