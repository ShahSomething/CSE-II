clc
clear all
close all
fs = 1000;
N = 512;
t = (0:N-1)/fs;
x = sin(2*pi*100*t);
noise = 1+2*rand(size(t));
xN = x+noise;
xNk = fft(xN);
f = ((0:N-1)*fs)/N;
m = 4;
b = (1/m)*ones(1,m);
y = filter(b,1,xN);
yk = fft(y);
subplot(2,2,1)
plot(t,xN);
title('Noisy Signal');
subplot(2,2,2)
plot(f,abs(xNk));
title('Frequency Domain');
subplot(2,2,3)
plot(t,y);
title('Filtered Signal');
subplot(2,2,4)
plot(f,abs(yk));
title('Frequency Domain');