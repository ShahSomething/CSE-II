#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

//Signal Handler for SIGINT
void SigHandler()
{
    //Get the Parent Process id
    int ppid = getppid();
    //Kill the Parent
    kill(ppid,SIGKILL);
    printf("\nParent Process Killed\n");
    return;
}

int main()
{
    //Request a child Process to be created
    int ret = fork();
    if(ret==-1)
    {
        
        perror("Failed to create a child");
        return -1;
    }
    if(ret==0) //Child's Program
    {
        //Declaring a set
        sigset_t set;
        struct sigaction act;
        //Set the handler to SidHandler
        act.sa_handler = SigHandler;
        if(sigaction(SIGINT,&act,NULL)==-1){
            perror("Error using sigaction");
            return -1;
        }
        //Clear the garbage
        if(sigemptyset(&set)==-1)
        {
            perror("Error using sigemptyset");
            return -1;
        }
        //Add SIGUSR1 to the set
        if(sigaddset(&set,SIGUSR1)==-1)
        {
            perror("Error adding SIGUSR1 to set");
            return -1;
        }
        //Add SIGUSR2 to the set
        if(sigaddset(&set,SIGUSR2)==-1)
        {
            perror("Error adding SIGUSR2 to set");
            return -1;
        }

        printf("Child: If I receive SIGINT, I will kill my Parent Process(%d)\n",getppid());
        //Block SIGUSR1 and SIGUSR2 and wait for other signals
        sigsuspend(&set);
        
    }else{ //Parents Code
        printf("Parent: The line after wait would not be printed because I will be dead\n");
        wait(NULL);
        printf("Parent: After child's termination\n");
    }
}