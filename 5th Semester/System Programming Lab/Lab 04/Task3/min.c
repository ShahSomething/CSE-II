#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int min = atoi(argv[1]);
	for(int i=1;i<argc;i++)
	{
		if(atoi(argv[i])<min)
			min=atoi(argv[i]);
	}
	return min;
}
