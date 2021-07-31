n=-10:10;
x=[zeros(1,10) ones(1,11)];
stem(n,x,'filled');
xlabel('Time');
ylabel('Amplitude');
title('Unit Step');
axis([-10 10 0 2]);