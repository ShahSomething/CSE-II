#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fret= fork();
	if(fret==-1)
	{
		printf("Return value: %d\n",fret);
		printf("Error Occured: %s\n",strerror(errno));
		printf("Error No: %d\n",errno);
	}
	else if(fret==0)
	{
		exit(0);
	}
	else if(fret >0)
	{
		int ret = wait(NULL);
		if(ret==-1)
		{
			printf("Return value: %d\n",ret);
			printf("Error Occured: %s\n",strerror(errno));
		  	printf("Error No: %d\n",errno);
			
		}
		else
		{
			printf("Return value: %d\n",ret);
			printf("Operation Successful: %s\n",strerror(errno));
			printf("Error No: %d\n",errno);
		}
		
	}


}

