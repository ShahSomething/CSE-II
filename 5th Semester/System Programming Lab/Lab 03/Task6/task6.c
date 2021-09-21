#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
	int Array[50];
	for(int i=0;i<50;i++)
	{
		Array[i]=i;
	}
	int x;
	int sum[10]={0},total=0,stat;
	int a=0,b=5;
	for (int i=0;i<10;i++)
	{
		x= fork();
		if(x==0)
		{
			for(int j=a;j<b;j++)
			{
				sum[i]+=Array[j];
			}
			printf("Pid: %d, Parent id: %d, Sum returned: %d\n",getpid(),getppid(),sum[i]);
			return sum[i];
			break;
		}
		else if(x>0)
		{
			sleep(1);
			a+=5;
			b+=5;
			wait(&stat);
			total+=WEXITSTATUS(stat);
		}
	}
	if(x>0)
	{
		sleep(1);						
		printf("Total Sum: %d\n",total);
	}
}

