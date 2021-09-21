#include <stdio.h>
#include <sys/select.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("Invalid Number of Arguments\n");
		return -1;
	}
	int fd[argc-1];
	for(int i=0;i<argc-1;i++)
	{
		fd[i] = open(argv[i+1],O_RDONLY);
		if(fd[i]==-1)
		{
			printf("Failed to open %s: %s",argv[i+1],strerror(errno));
			return -1;
		}
	}
	fd_set readSet;
	FD_ZERO(&readSet);
	for(int i=0;i<argc-1;i++)
	{
		FD_SET(fd[i],&readSet);
	}
	int maxFD = fd[0];
	for(int i=0;i<argc-1;i++)
	{
		if(fd[i]>maxFD)
			maxFD = fd[i];
	}
	struct timeval timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 42;
	int nfds = select(maxFD+1,&readSet,NULL,NULL,&timeout);
	if(nfds==-1)
	{
		perror("An error Occured with select function\n");
		return -1;
	}
	if(nfds==0)
	{
		printf("Timeout\n");
		return -1;
	}
	printf("Number of files ready: %d\n",nfds);
	for(int i=0;i<argc-1;i++)
	{
		if(FD_ISSET(fd[i],&readSet))
			printf("%s is ready\n",argv[i+1]);
		else
			printf("%s is not ready\n",argv[i+1]);
	}
	return 0;
}
