#include <stdio.h>

int main()
{
	int number,bit,i;
	printf("Enter a decimal number: ");
	scanf("%d",&number);
	printf("%d\n",number);
	printf("Binary representation of %d: ",number);
	for(i=31;i>=0;i--)
	{
		bit = number>>i;
		if(bit&1)
			printf("1");
		else
			printf("0");
	}
	return 0;
}
