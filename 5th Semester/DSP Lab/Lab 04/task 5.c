#include <stdio.h>

short A[5] = {4,2,6,5,8};
short Square[5];

int main()
{
	int i;
	for(i=0;i<5;i++)
		Square[i]=A[i]*A[i];
	return 0;

}
