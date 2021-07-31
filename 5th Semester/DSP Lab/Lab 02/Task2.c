#include <stdio.h>

int main()
{
	int number;
	printf("Enter a number: ");
	scanf("%d",&number);
	printf(" %d\n",number);
	printf("Fibonacci Series: ");
	int a=0,b=1;
	printf(" %d %d ",a,b);
	int sum=a+b;
	while(sum<=number)
	{
		printf(" %d ",sum);
		a=b;
		b=sum;
		sum=a+b;
	}
	return 0;
}
