#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int prod=1;
	for(int i=1;i<argc;i++)
	{
		prod*=atoi(argv[i]);
	}
	printf("Total Product: %d\n",prod);
}

