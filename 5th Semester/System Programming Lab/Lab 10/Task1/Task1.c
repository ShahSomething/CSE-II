#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd[2];
    int ret = pipe(fd);
    if(ret==-1)
    {
        perror("Failed to create a pipe");
        return -1;
    }
    int x = fork();
    if(x==-1)
    {
        perror("Failed to create a child process");
        return -1;
    }
    if(x==0)
    {
        char buffer[100];
        printf("Child: Enter a message for parent.\n");
        fgets(buffer,200,stdin);
        write(fd[1],buffer,strlen(buffer));
    }else{
        wait(NULL);
        char buffer[200];
        read(fd[0],buffer,sizeof(buffer));
        printf("Parent Recieved: %s",buffer);
    }
}