#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
	int ret = wait(NULL);
	printf("Return Value: %d\n",ret);
	if(ret==-1)
	{
		perror("Error Occured");
		printf("Error No: %d \n",errno);
	}

}
