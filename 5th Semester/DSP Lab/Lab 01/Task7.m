n=-10:10;
x=[zeros(1,11) ones(1,10)];
stem(n,x,'filled');
xlabel('Time');
ylabel('Amplitude');
title('Delayed Unit step');
axis([-10 10 0 2]);