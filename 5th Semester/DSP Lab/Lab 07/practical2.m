clc
clear all
close all
f1 = 10;
f2 = 20;
fs = 1000;
n = 0:1/fs:0.30;
bx = [2.2403 2.4908 2.2403];
by = [1 0.4 0.75];
h = impz(bx,by);
x1 = sin(2*pi*f1*n);
x2 = sin(2*pi*f2*n);
x = x1+x2;
y1 = conv(x,h);
subplot(3,2,1)
stem(n,x1);
title('Signal 1');
subplot(3,2,3)
stem(n,x2);
title('Signal 2');
subplot(3,2,5)
stem(y1);
title('Convolution of S1 and S2');

yx1 = conv(x1,h);
yx2 = conv(x2,h);
y2 = yx1+yx2;
subplot(3,2,2)
stem(yx1);
title('Convolution of Signal 1');
subplot(3,2,4)
stem(yx2);
title('Convolution of Signal 2');
subplot(3,2,6)
stem(y2);
title('Sum of Convolutions of S1 and S2');

