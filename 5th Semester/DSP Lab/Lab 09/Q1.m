clc
clear all
close all
fs = 1000;
N = 512;
t = (0:N-1)/fs;
x1 = sin(2*pi*200*t);
x2 = sin(2*pi*300*t);
x = x1+x2;
noise = 1+2*rand(size(t));
xN = x+noise;
xk = fft(x);
xNk = fft(xN);
f = ((0:N-1)*fs)/N;
y1 = ifft(xk);
y2 = ifft(xNk);
subplot(2,2,1)
plot(t,y1);
title('Time Domain Signal');
subplot(2,2,2)
plot(f,abs(xk));
title('Frequency Domain of the signal');
subplot(2,2,3)
plot(t,y2);
title('Noisy Signal Time Domain');
subplot(2,2,4)
plot(f,abs(xNk));
title('Frequency Domain of Noisy Signal');