/* 
    Name: Shah Raza
    Assignment #1
    Question: 2
*/


#include <stdio.h>
#include <unistd.h>
//Defining the structure for PCB
typedef struct PCB{
    int ProcessTime;
    int Priority;
    int pt;
    int pid;
    int ppid;
    char *state;

}PCB;

PCB Process[5];
int count = 0;
//A function to Initialize the data members of PCB
void Initialize(int i,int pTime)
{
    Process[i].pid = 70+i+1;
    Process[i].ppid = 70;
    Process[i].state = "";
    Process[i].Priority = i;
    Process[i].pt = 0;
    Process[i].ProcessTime = pTime;
}
//This function helps us in simulating the PCB
void ProcessState(int i,int bTime){
    printf("PCB of Process %d\n",i+1);
    Process[i].state="Running\n";
    printf("Process ID: %d\n",Process[i].pid);
    printf("Parent Process ID: %d\n",Process[i].ppid);
    printf("Process State: %s\n",Process[i].state);
    printf("Process Time: %d\n",Process[i].ProcessTime);
    printf("Process Priority: %d\n",Process[i].Priority);
    Process[i].ProcessTime-=bTime;
    Process[i].pt++;
    if(Process[i].ProcessTime >0)
        printf("Remaining Time for Process %d : %d\n",i+1,Process[i].ProcessTime);
    else{
        printf("Process %d has been Finished in %d cycles\n",i+1,Process[i].pt);
        if(Process[i].ProcessTime<0){
            int temp=-1 * Process[i].ProcessTime;
            printf("Process %d Finished before %d sec\n\n",i+1,temp);
        }
        count++;
    }
}


int main()
{
    int bTime,np,pTime;
    printf("Enter the number of Processes: ");
    scanf("%d",&np);
    printf("Enter Burst Time in seconds: ");
    scanf("%d",&bTime);
    for(int i=0;i<np;i++){
        printf("Enter Process Time for Process %d: ",i+1);
        scanf("%d",&pTime);
        Initialize(i,pTime);
    }
    int i=0;
    while (count < np)
    {
        if(Process[i].ProcessTime>0)
            ProcessState(i,bTime);
        if(i==np-1)
            i=0;
        else
            i++;
    }
    return 0;
}