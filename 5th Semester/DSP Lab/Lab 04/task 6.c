#include <stdio.h>

void Binary(char ch)
{

	int i;
	for(i=7;i>=0;i--)
	{
		if(ch&(1<<i))
			printf("1");
		else
			printf("0");
	
	}
}

int main()
{
	int a=3;
	printf("Number: %d\n",a);
	printf("Binary: ");
	Binary((char)a);
	printf("\nReverse Binary: ");
	int i;
	char temp,rev=0;
	for(i=0;i<8;i++)
	{
		temp=((char)a&(1<<i))>>i;
		temp=temp<<(7-i);
		rev=(rev|temp);
	
	}
	Binary(rev);
	return 0;

}
