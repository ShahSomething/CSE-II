#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int ret = close(7);
	printf("Return value of close: %d\n",ret);
	if(ret==-1)
	{
		perror("Error Occured");
		printf("Error No: %d\n",errno);
	}
	else
	{
		printf("File closed Successfully.\n");
	}

}


