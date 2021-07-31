n=-10:10;
x=(n+abs(n))/2;
x1=[zeros(1,10) ones(1,11)];
diff=x1-x;
stem(n,diff,'filled');
xlabel('Time');
ylabel('Amplitude');
title('Difference of Unit step and Ramp Function');
axis([-10 10 -11 2]);