#include <stdio.h>

int A[6] = {1,2,3,4,5,6};
int B[6] = {2,4,6,8,10,12};
int dot_product[6];

int main()
{
	int i;
	for(i=0;i<6;i++)
		dot_product[i]=A[i]*B[i];
	
	return 0;

}
