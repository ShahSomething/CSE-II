f0=4;
A=3;

t=-1:0.005:1;
x=A*sin(2*pi*f0*t);
stem(t,x,'*:');
xlabel('Time');
ylabel('Amplitude');
title('Sinusoid');
