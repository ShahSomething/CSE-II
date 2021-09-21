#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void Factors(int val)
{
	for(int i=1;i<val;i++)
	{
		if(val%i==0)
			printf(" %d ",i);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int x;
	for (int i=1;i<argc;i++)
	{
		x= fork();
		if(x==0)
		{
			printf("Pid: %d, Parent id: %d\nFactors of %d: ",getpid(),getppid(),atoi(argv[i]));
			Factors(atoi(argv[i]));
			break;
		}
			
	}
	for(int i=0;i<atoi(argv[1]);i++)
		wait(NULL);
}

