#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int x;
	for(int i=1;i<argc;i++)
	{
		x=fork();
		if(x==0)
		{
			printf("Pid: %d,  Executing: %s\n",getpid(),argv[i]);
			execlp(argv[i],argv[i],NULL);
			break;
		}
	}

}


