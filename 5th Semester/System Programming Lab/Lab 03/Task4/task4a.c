#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int x;
	for (int i=0;i<atoi(argv[1]);i++)
	{
		x= fork();
		
		if(x==-1)
		{
			perror("Error Occured");
			return 0;
		}
		
		if(x>0)
		{
			printf("\nPid: %d,  Parent id: %d,  Child id: %d, i: %d",getpid(),getppid(),x,i);
			break;
		}
	}
}

