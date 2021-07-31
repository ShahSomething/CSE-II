clc
clear all
close all
b = 0.5;
a = [1 -2 1];
TransferF = filt(b,a)
fvtool(b,a);
