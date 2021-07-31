clc
clear all
close all
f = 15;
fs = 1000;
t = 0:1/fs:1;
noise = 1+2*rand(size(t));
signal = sin(2*pi*f*t);
x = signal+noise;
subplot(2,1,1);
plot(t,x);
title('Noisy Signal');
m=5
b = (1/m)*ones(1,m);
y = filter(b,1,x);
subplot(2,1,2)
plot(t,y);
title("Filtered Signal");

 
