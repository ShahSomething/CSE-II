clc
clear all
close all
f = 1000;
fs = 10*f;
t = 0:1/fs:1;
x = sin(2*pi*f*t);
stem(t,x);
axis([0 0.02 -2 2]);
title('Sampled Signal');