clc
clear all
close all
fs = 4000;
N = 512;
t = (0:N-1)/fs;
x = sin(2*pi*400*t);
xk = fft(x,N);
f = ((0:N-1)*fs)/N;
subplot(3,1,1)
plot(t,x);
title('Time Domain Signal');
subplot(3,1,2)
plot(f,abs(xk));
title('Frequency Domain(N=512)');
y  = fftshift(xk);
f = ((-N/2:(N-1)/2)*fs)/N;
subplot(3,1,3)
plot(f,abs(y));
title('Range: -pi to pi');