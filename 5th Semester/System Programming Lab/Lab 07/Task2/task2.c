#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	int x;
	for(int i=1;i<argc;i+=2)
	{
		x= fork();
		if(x==0)
		{
			int fd1 = open(argv[i],O_RDONLY);
			if(fd1==-1)
			{
				printf("Failed to open %s: %s\n", argv[i], strerror(errno));
				return -1;
			}
		
			int fd2 = open(argv[i+1],O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
			if(fd2==-1)
			{
				printf("Failed to open %s: %s\n", argv[i+1], strerror(errno));
				return -1;
			}
			int bytesread;
			char buffer[1024];
			do
			{
				bytesread = read(fd1,buffer,sizeof(buffer));
				if(bytesread==-1)
				{
					printf("Failed to read from %s: %s\n",argv[i],strerror(errno));
					return -1;
				}
				int byteswriten = write(fd2,buffer,bytesread);
				if(byteswriten==-1)
				{
					printf("Failed to Write to %s: %s\n", argv[i + 1], strerror(errno));
					return -1;
				}
			}while(bytesread!=0);
	
			int cfd1 = close(fd1);
			if(cfd1==-1)
			{
				printf("Failed to close %s: %s\n",argv[i],strerror(errno));
				return -1;
			}
			int cfd2 = close(fd2);
			if(cfd2==-1)
			{
				printf("Failed to close %s: %s\n",argv[i+1],strerror(errno));
				return -1;
			}
			break;
		}
	}
	if(x>0)
	{
		for(int i=1;i<argc/2;i++)
			wait(NULL);
	}
	return 0;
}

