#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int max = atoi(argv[1]);
	for(int i=1;i<argc;i++)
	{
		if(atoi(argv[i])>max)
			max=atoi(argv[i]);
	}
	return max;
}
