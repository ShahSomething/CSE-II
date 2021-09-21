#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	int fd[4];
	for (int i = 0; i < argc-1; i+=2)
	{
		fd[i] = open(argv[i+1], O_RDONLY);
		if (fd[i] == -1)
		{
			printf("Failed to open %s: %s\n", argv[i+1], strerror(errno));
			return -1;
		}
		fd[i+1] = open(argv[i + 2], O_WRONLY | O_CREAT , S_IRWXU);
		if (fd[i+1] == -1)
		{
			printf("Failed to open %s: %s\n", argv[i+2], strerror(errno));
			return -1;
		}
	}
	char buffer[1024];
	int bytesRead;
	int bytesWritten;
	for (int i = 0; i < argc-1; i += 2)
	{
		do
		{
			bytesRead = read(fd[i],buffer,sizeof(buffer));
			if (bytesRead == -1)
			{
				printf("Failed to read from %s: %s\n",argv[i+1],strerror(errno));
				return -1;
			}
			bytesWritten = write(fd[i+1],buffer,bytesRead);
			if (bytesWritten == -1)
			{
				printf("Failed to Write to %s: %s\n", argv[i + 2], strerror(errno));
				return -1;
			}
		} while (bytesRead!=0);
	}
	for (int i = 0; i < argc-1; i++)
	{
		int ret = close(fd[i]);
		if (ret == -1)
			printf("Failed to close %s: %s\n",argv[i+1],strerror(errno));
	}
	return 0;
}

