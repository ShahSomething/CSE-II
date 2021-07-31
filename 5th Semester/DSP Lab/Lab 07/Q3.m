clc
clear all
close all
f1 = 10;
f2 = 20;
f3 = 30;
fs = 1000;
n = 0:1/fs:0.30;
bx = [2.2403 2.4908 2.2403];
by = [1 0.4 0.75];
h = impz(bx,by);
x1 = sin(2*pi*f1*n);
x2 = sin(2*pi*f2*n);
x3 = sin(2*pi*f3*n);
x = x1+x2+x3;
y1 = conv(x,h);
subplot(2,1,1)
stem(y1);
title('Convolution of sum of S1, S2, S3');

yx1 = conv(x1,h);
yx2 = conv(x2,h);
yx3 = conv(x3,h);
y2 = yx1+yx2+yx3;
subplot(2,1,2)
stem(y2);
title('Sum of Convolutions of S1, S2 and S3');

