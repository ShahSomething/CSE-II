#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd[2];
    int ret = pipe(fd);
    char buffer[100];
    if(ret==-1)
    {
        perror("Failed to create a pipe");
        return -1;
    }
    for(int i=0;i<3;i++)
    {
        int x = fork();
        if(x==-1)
        {
            perror("Failed to create a child process");
            return -1;
        }
        if(x>0)
        {
            printf("\nEnter a message for Child %d:",i+1);
            fgets(buffer,sizeof(buffer),stdin);
            write(fd[1],buffer,strlen(buffer));
            wait(NULL);
        }else{
            read(fd[0],buffer,sizeof(buffer));
            printf("Child %d Received: %s",i+1,buffer);
            break;
        }
    }
    
}