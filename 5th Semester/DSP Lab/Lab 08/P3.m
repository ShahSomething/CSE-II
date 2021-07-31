clc
clear all
close all
b = [0.1 0.2 0.1];
a = 1;
TransferF = filt(b,a)
fvtool(b,a);