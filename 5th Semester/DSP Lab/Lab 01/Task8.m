n=1:10;
stem(n,n-1,'filled');
xlabel('Time');
ylabel('Amplitude');
title('Delayed Ramp Function');
axis([-10 10 -1 11]);