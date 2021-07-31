n=-10:10;
x=[zeros(1,10) 1 zeros(1,10)];
stem(n,x,'filled');
xlabel('Time');
ylabel('Amplitude');
title('Unit Impulse');
axis([-10 10 0 2]);