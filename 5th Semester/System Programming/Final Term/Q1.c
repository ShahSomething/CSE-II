#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

//This function tells if a number is Non Prime or not
int IsNonPrime(int num)
{
	int count = 0;
	for(int i=1;i<num;i++)
		if(num%i==0)
			count++;
	if(count>1)
		return 1;
	return 0;
}
//This function prints all the non prime factors of the number passed to it
void PrintNonPrimeFactor(int pid)
{
	for(int f=1;f<=pid;f++)
		if((pid%f)==0)
			if(IsNonPrime(f))
				{
					printf("%d ",f);
				}
	printf("\n");
}
int main(int argc, char *argv[])
{
	int x,count=0;
	//A loop for creating a process fan of 10 child processes
	for (int i=0;i<10;i++)
	{
		//Request to create a child
		x= fork();
		if(x==-1)
		{
			perror("Failed to create Child Process");
			return -1;
		}
		
		if(x==0)
		{
			//Get the parent Process id to calculate its Non Prime factors
			int ppid =getppid();
			for(int f=1;f<=ppid;f++)
				if((ppid%f)==0)
					if(IsNonPrime(f))
					{
						count++;
					}
			printf("Pid: %d, PPid: %d, Number of Non-Prime factors of %d= %d\n",getpid(),ppid,ppid,count);
			break;
		}
	}
	if(x>0)
	{
		//Wait for all the child processes to terminate
		for(int i=0;i<10;i++)
		{
			wait(NULL);
		}
		printf("Parent: Non prime factors %d: ",getpid());
		PrintNonPrimeFactor(getpid());
	}
}
