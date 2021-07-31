n=-10:10;
x=(n+abs(n))/2;
x1=[zeros(1,10) ones(1,11)];
div=x1./x;
stem(n,div,'filled');
xlabel('Time');
ylabel('Amplitude');
title('Division of Unit step and Ramp Function');
axis([-10 10 0 2]);