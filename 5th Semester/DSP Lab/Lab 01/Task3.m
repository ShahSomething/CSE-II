n=-10:10;
x=(n+abs(n))/2;
stem(n,x,'filled');
xlabel('Time');
ylabel('Amplitude');
title('Ramp Function');
axis([-10 10 -1 11]);