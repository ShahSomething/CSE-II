#include <stdio.h>

int A[5] = {3,5,7,9,11};
int B[5] = {1,3,4,8,6};
int Add[5];
int Sub[5];

int main()
{
	int i;
	for(i=0;i<5;i++)
	{
		Add[i]=A[i]+B[i];
		Sub[i]=A[i]-B[i];
	
	}
	return 0;

}
