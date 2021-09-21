#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int x;
	for (int i=0;i<atoi(argv[1]);i++)
	{
		x= fork();
		
		if(x>0)
		{
			printf("Pid: %d,  Parent id: %d,  Child id: %d, i: %d\n",getpid(),getppid(),x,i);
			break;
		}
	}
	for(int i=0;i<atoi(argv[1]);i++)
		wait(NULL);
	sleep(15);

}
