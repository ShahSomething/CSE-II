#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
	int ret = close(6);
	printf("Return value of close: %d\n",ret);
	if(ret==-1)
	{
		printf("Error Occured: %s\n",strerror(errno));
		printf("Error No: %d\n",errno);
	}
	else
	{
		printf("File closed Successfully.\n");
	}

}

