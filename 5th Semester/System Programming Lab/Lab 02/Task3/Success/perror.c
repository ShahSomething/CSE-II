#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int ret = close(0);
	printf("Return value of close: %d\n",ret);
	if(ret==-1)
	{
		perror("Error Occured");
		printf("Error No: %d\n",errno);
	}
	else
	{
		perror("File Closed Successfully");
		printf("Error No: %d\n",errno);
	}

}


