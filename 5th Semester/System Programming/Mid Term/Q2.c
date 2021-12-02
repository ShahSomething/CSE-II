#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc,char *argv[])
{
	if(argc<2)
	{
		printf("Arguments not Provided\n");
		return -1;
	}
	int Words[argc-1];
	for(int i=0;i<argc-1;i++)
		Words[i]=0;
	for(int i=1;i<argc;i++)
	{
		int fd = open(argv[i],O_RDONLY);
		int bytesread;
		char *buffer;
		do
		{
			bytesread = read(fd,&buffer,1);
			if(bytesread==-1)
			{
				perror("Error Occured while reading");
				return -1;
			}
			if(buffer==" ")
				Words[i-1]++;
		}while(bytesread!=0);
	}
		int fd2 = open("result",O_WRONLY|O_CREAT);
		write(fd2,Words);
	}
	
	printf("%s: %d words\n", Files[minindex],Words[minindex]);
	printf("Max words are in %s\n",Files[argc-1]);

}
