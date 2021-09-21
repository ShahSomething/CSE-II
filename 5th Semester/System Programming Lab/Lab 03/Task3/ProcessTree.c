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
	}
	for(int i=0;i<atoi(argv[1]);i++)
		wait(NULL);
	printf("Pid: %d, Parent id: %d\n",getpid(),getppid());
	sleep(30);
}


