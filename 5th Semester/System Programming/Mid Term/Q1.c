#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int PrimeNumber(int number)
{
	int count=0;
	for(int i=2;i<=number;i++)
	{
		if(number%i==0)
			count++;
	}
	if(count==1)
		return 1;
	else
		return 0;
}

int main()
{
	int x;
	int Rnum1;
	int Rnum2;
	for (int i=0;i<32;i++)
	{
		x= fork();
		if(x==-1)
		{
			perror("Error Occured");
			return -1;
		}
		if(x>0)
		{
			srand(time(0)+i);
			
			do
			{
				Rnum1 = (rand()%(1000-1+1)+1);
			}while(!PrimeNumber(Rnum1));
			
			do
			{
				Rnum2 = (rand()%(1000-1+1)+1);
			}while(!PrimeNumber(Rnum2));
			printf("Pid: %d,  Parent id: %d,  Child id: %d, PrimeNumbers: %d, %d\n",getpid(),getppid(),x,Rnum1,Rnum2);
			break;
		}
	}
	wait(NULL);
}
