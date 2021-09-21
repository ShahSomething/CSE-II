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
    if(sigdelset(&set,SIGCHLD)==-1)
        perror("Failed to remove SIGCHLD from set");
    if(sigprocmask(SIG_SETMASK,&set,NULL)==-1)
        perror("Error using sigprocmask");
    pause();
}

int main()
{
    struct sigaction act;
    act.sa_handler = SigHandler;
    if(sigaction(SIGCHLD,&act,NULL)==-1){
        perror("Error using sigaction");
        return -1;
    }
    if(sigfillset(&set)==-1)
    {
        perror("Error using sigfillset");
        return -1;
    }
    if(sigprocmask(SIG_BLOCK,&set,NULL)==-1){
        perror("Error using sigprocmask");
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
