clc
clear all
close all
%For M=5
M = 5;
b = (1/M)*ones(1,M);
a = 1;
figure;
zplane(b,a);
figure;
freqz(b,a);
%For M=8
M = 8;
b = (1/M)*ones(1,M);
figure;
zplane(b,a);
figure;
freqz(b,a);
