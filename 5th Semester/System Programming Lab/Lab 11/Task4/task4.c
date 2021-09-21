#include <stdio.h>
#include <unistd.h>
#include <signal.h>

sigset_t set;
void SigHandler()
{
    //Does nothing but we need a signal handler for this task to work
    return;
}
void mywait()
{
    int signo;
    if(sigwait(&set,&signo)==-1)
    {
        perror("Error using sigwait");
    }
    printf("Signal number that caused sigwait to return: %d\n",signo);
}

int main()
{
    struct sigaction act;
    act.sa_handler = SigHandler;
    if(sigaction(SIGCHLD,&act,NULL)==-1)
    {
        perror("Error using sigaction");
        return -1;
    }
    if(sigemptyset(&set)==-1)
    {
        perror("Error using sigemptyset");
        return -1;
    }
    if(sigaddset(&set,SIGCHLD)==-1){
        perror("Failed to add SIGCHLD to set");
        return -1;
    }
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
        mywait();
        printf("Parent: After child's termination\n");
    }

}