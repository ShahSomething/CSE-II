fs = 1000;
N = 1000;
t = (0:N-1)/fs;
x1 = sin(2*pi*10*t);
x2 = sin(2*pi*20*t);
x3 = sin(2*pi*50*t);
x = x1+x2+x3;
noise = 1+2*rand(size(t));
xN = x+noise;
xk = fft(x);
xNk = fft(xN);
f = ((0:N-1)*fs)/N;
subplot(3,2,1)
plot(t,x);
title('Time Domain Signal');
subplot(3,2,2)
plot(f,abs(xk));
title('Frequency Domain of the signal');
subplot(3,2,3)
plot(t,xN);
title('Noisy Signal Time Domain');
subplot(3,2,4)
plot(f,abs(xNk));
title('Frequency Domain of Noisy Signal');
y = filter(Num,1,xN);
yk = fft(y);
subplot(3,2,5)
plot(t,y);
title('Filtered (Time domain)');
subplot(3,2,6)
plot(f,abs(yk));
title('Filtered (Frequency domain)');
