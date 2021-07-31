n=-10:10;
x=[zeros(1,11) 1 zeros(1,9)];
stem(n,x,'filled');
xlabel('Time');
ylabel('Amplitude');
title('Delayed Unit Impulse');
axis([-10 10 0 2]);