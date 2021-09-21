#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int x;
	for(int i=1;i<3;i++)
	{
		x=fork();
		if(x==0)
		{
			if(i==1)
			{
				strcpy(argv[0],"Task2a");
				execv(argv[0],argv);
			}else{
				strcpy(argv[0],"Task2b");
				execv(argv[0],argv);
			}
			break;
		}
	}

}
