clc
clear all
close all
f = 3;
t = 0:1/1000:1;
x = sin(2*pi*f*t);
noise = 1+(7-1)*rand(1,1001);
NoisySignal = x+noise;
save Sinosoid x
save NoisySin NoisySignal