#include <stdio.h>

int main()
{
	int Array1[5];
	printf("Enter the first Array: ");
	int i;
	for(i=0;i<5;i++)
	{
			scanf("%d",&Array1[i]);
			printf(" %d ",Array1[i]);
	}
	int Array2[5];
	printf("\nEnter the Second Array: ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&Array2[i]);
		printf(" %d ",Array2[i]);
	}
	printf("\nSum: ");
	int Sum[5];
	for(i=0;i<5;i++)
		Sum[i]=Array1[i]+Array2[i];
	for(i=0;i<5;i++)
		printf(" %d ",Sum[i]);
	printf("\nDifference: ");
	int Diff[5];
	for(i=0;i<5;i++)
		Diff[i]=Array1[i]-Array2[i];
	for(i=0;i<5;i++)
		printf(" %d ",Diff[i]);
	return 0;
}
