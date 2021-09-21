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
	if(argc!=3)
	{
		printf("Invalid Number of Arguments\n");
		return -1;
	}
	int fd1 = open(argv[1],O_RDONLY);
	if(fd1==-1)
	{
		printf("Failed to open %s: %s\n",argv[1],strerror(errno));
		return -1;
	}
		
	int fd2 = open(argv[2],O_RDONLY);
	if(fd2==-1)
	{
		printf("Failed to open %s: %s\n",argv[2],strerror(errno));
		return -1;
	}
	fd_set readSet;
	FD_ZERO(&readSet);
	FD_SET(fd1,&readSet);
	FD_SET(fd2,&readSet);
	int maxFD = (fd1>fd2)?fd1:fd2;
	struct timeval timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 73;
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
	if(FD_ISSET(fd1,&readSet))
		printf("%s is ready\n",argv[1]);
	else
		printf("%s is not ready\n",argv[1]);
	if(FD_ISSET(fd2,&readSet))
		printf("%s is ready\n",argv[2]);
	else
		printf("%s is not ready\n",argv[2]);
		
	return 0;

}
