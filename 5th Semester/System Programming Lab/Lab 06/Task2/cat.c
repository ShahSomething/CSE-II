#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void ReadWrite(int fd1, int fd2)
{
	int bytesread;
	char buffer[100];
	do
	{
		bytesread = read(fd1,buffer,100);
		int byteswriten = write(fd2,buffer,bytesread);
	}while(bytesread!=0);
}

int main(int argc, char *argv[])
{
	if(argc>4 || (argc>1 && argc%2!=0))
	{
		printf("Invalid number of Arguments\n");
		return -1;
	}
	
	if(argc==1)
	{
		ReadWrite(0,1);
	}
	else if(argc==2)
	{
		int fd1 = open(argv[1],O_RDONLY);
		if(fd1==-1)
		{
			perror("Failed to open Source file");
			return -1;
		}
		
		ReadWrite(fd1,1);
	
		int cfd1 = close(fd1);
		if(cfd1==-1)
		{
			perror("Failed to close Source file");
			return -1;
		}
	}
	else
	{
		if(*argv[2]=='>')
		{
			int fd1 = open(argv[1],O_RDONLY);
			if(fd1==-1)
			{
				perror("Failed to open Source file");
				return -1;
			}
			
			int fd2 = open(argv[3],O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
			if(fd2==-1)
			{
				perror("Failed to open destination file");
				return -1;
			}
	
			ReadWrite(fd1,fd2);
	
			int cfd1 = close(fd1);
			if(cfd1==-1)
			{
				perror("Failed to close Source file");
				return -1;
			}
		}
		else
			printf("Unabale to recognize %s\n",argv[2]);
		
	}
	return 0;

}
