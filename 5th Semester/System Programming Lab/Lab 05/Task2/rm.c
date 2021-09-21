#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("Required arguments not Provided\n");
		return -1;
	}
		
	int ret = unlink(argv[1]);
	if(ret==-1)
	{
		perror("Failed to remove file");
	}
	return 0;
}
