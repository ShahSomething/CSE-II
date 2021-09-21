#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int value;
	int x;
	for(int i=1;i<3;i++)
	{
		x=fork();
		if(x==0)
		{
			if(i==1)
			{
				strcpy(argv[0],"./min");
				printf("Min:\n");
				execv(argv[0],argv);
				perror("Failed to execute min\n");
			}else {
				strcpy(argv[0],"./max");
				printf("Max:\n");
				execv(argv[0],argv);
				perror("Failed to execute max\n");
			}
			break;
		}
	}
	for(int i=0;i<2;i++)
	{
			int Pid = wait(&value);
			printf("Pid: %d, Status: %d\n",Pid,WEXITSTATUS(value));
	}
}



