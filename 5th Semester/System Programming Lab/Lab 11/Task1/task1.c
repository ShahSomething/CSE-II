#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int x=0;
void SigHandler()
{
    x=1;
}

void mywait()
{
    while(x==0);
}

int main()
{
    int ret = fork();
    if(ret==-1)
    {
        perror("Failed to create a child");
        return -1;
    }
    if(ret==0)
    {
        printf("Child: Hi\n");
    }else{
        struct sigaction act;
        act.sa_handler =SigHandler;
        if(sigaction(SIGCHLD,&act,NULL)==-1)
        {
            perror("Error using sigaction");
            return -1;
        }
        mywait();
        printf("Parent: After child's termination\n");
    }

}