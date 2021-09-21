#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/select.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Fifo name not provided\n");
        return -1;
    }
    int fd,w,r,ret;
    if(mkfifo(argv[1],S_IRWXU)==-1)
    {
        if(errno!=EEXIST)
        {
            perror("Failed to create fifo\n");
            return -1;
        }
    }
    fd = open(argv[1],O_RDWR);
    if(fd==-1)
    {
        perror("Failed to open fifo\n");
        return -1;
    }
    char str[512];
    char str2[4] = ">> ";
    fd_set readset;
    sleep(4);
    while(1)
    {
        FD_ZERO(&readset);
        FD_SET(fd,&readset);
        FD_SET(STDIN_FILENO,&readset);
        ret = select(fd+1,&readset,NULL,NULL,NULL);
        if(ret==-1)
        {
            perror("Error Using Select");
            return -1;
        }
        if(FD_ISSET(STDIN_FILENO,&readset))
        {
            fprintf(stderr, ">> ");
            r = read(STDIN_FILENO,str,sizeof(str));
            w = write(fd,str,r);
            if(w==-1)
            {
                perror("Error while writing to fifo");
                return -1;
            }
            sleep(4);
            continue;
        }
        if(FD_ISSET(fd,&readset))
        {
            r = read(fd,str,sizeof(str));
            if(r==-1)
            {
                perror("Error while reading from fifo");
                return -1;
            }else if(r==0)
                continue;
            fprintf(stderr,"Recieved: %s\n",str);
        }
    }
}