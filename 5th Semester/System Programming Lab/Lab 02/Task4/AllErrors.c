#include <stdio.h>
#include <string.h>

int main()
{
	for(int i=0;i<134;i++)
	{
		printf("Error No %d: %s\n",i,strerror(i));
	}

}
