#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	if(argc<3)
	{
		printf("Required Arguments not Provided\n");
		return -1;
	}	
	int fd1 = open(argv[1],O_RDONLY);
	if(fd1==-1)
	{
		perror("Failed to open Source file");
		return -1;
	}
		
	int fd2 = open(argv[2],O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	if(fd2==-1)
	{
		perror("Failed to open destination file");
		return -1;
	}
	
	int bytesread;
	char buffer[100];
	do
	{
		bytesread = read(fd1,buffer,100);
		if(bytesread==-1)
		{
			perror("Error Occured while reading");
			return -1;
		}
		int byteswriten = write(fd2,buffer,bytesread);
		if(byteswriten==-1)
		{
			perror("Error Occured while writing");
			return -1;
		}
	}while(bytesread!=0);
	
	int cfd1 = close(fd1);
	if(cfd1==-1)
	{
		perror("Failed to close Source file");
		return -1;
	}
	int cfd2 = close(fd2);
	if(cfd2==-1)
	{
		perror("Failed to close destination file");
		return -1;
	}
	return 0;
}
