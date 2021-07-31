n=-10:10;
x=(n+abs(n))/2;
x1=[zeros(1,10) ones(1,11)];
mul=x.*x1;
stem(n,mul,'filled');
xlabel('Time');
ylabel('Amplitude');
title('Multiplication of Unit step and Ramp Function');
axis([-10 10 0 10]);