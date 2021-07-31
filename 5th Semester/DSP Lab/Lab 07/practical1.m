clc
clear all
close all
f1 = 10;
f2 = 200;
fs = 8000;
t = 0:1/fs:0.3;
noise = 1+2*rand(size(t));
x1 = sin(2*pi*f1*t);
x2 = sin(2*pi*f2*t);
x = (x1+x2)+noise;
subplot(4,2,[1,2]);
plot(t,x);
title('Original Signal');
i=3;
for m=5:10
    b = (1/m)*ones(1,m);
    y = filter(b,1,x);
    subplot(4,2,i)
    plot(t,y);
    title(['M = ',num2str(m)]);
    i=i+1;
end
 
