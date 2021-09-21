#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	int ret = wait(NULL);
	printf("Return Value: %d\n",ret);
	if(ret==-1)
	{
		printf("Error Occured: %s\n", strerror(errno));
		printf("Error No: %d\n", errno);
	}
}


