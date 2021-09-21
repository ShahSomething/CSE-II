#include <stdio.h>
#include <sys/select.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("Sleeping for %s seconds and %s micro-seconds.....\n",argv[1],argv[2]);
	struct timeval timeout;
	timeout.tv_sec = atoi(argv[1]);
	timeout.tv_usec = atoi(argv[2]);
	int ret = select(1,NULL,NULL,NULL,&timeout);
	printf("Awake now!\n");
	return 0;
}
