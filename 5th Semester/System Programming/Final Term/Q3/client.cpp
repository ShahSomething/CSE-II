#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

using namespace std;

#define MSGSZ     180

/*
 * Declare the message structure.
 */
char filename[50];
typedef struct  {
    long    mtype;
    char    mtext[MSGSZ];
} message_buf;

void *ftn(void *a){
    int r;
    char buff[500];

    while(1){
        int i=0;
        int f=open(filename,O_RDONLY);
        r=read(f,buff,500);
        strcpy(buff+r,"");
        if(strcmp(buff,"$")==0){
            printf("%s\n",buff);
            break;
        }
        printf("%s\n",buff); 
    }
    int error=pthread_kill(pthread_self(),SIGKILL);
}

class client{
private:
    int msqid;
    int msgflg;
    key_t key;
    message_buf sbuf;
    size_t buf_length;
    char name[10];   
public:
    client(){
        msgflg = IPC_CREAT | 0666;
        key=123;
        if ((msqid = msgget(key, msgflg )) < 0) {
            perror("msgget");  
        }
        else 
            fprintf(stderr,"msgget: msgget succeeded: msqid = %d\n", msqid);
    }

    void sendLoginReq(){
 
        cout<<"Enter a username:\n";
        cin.getline(name,10);
        sprintf(sbuf.mtext, "login:%s",name);
        buf_length = strlen(sbuf.mtext) + 1 ;
        sbuf.mtype = 1;
        buf_length = strlen(sbuf.mtext) + 1 ;
        this->createFifo();
        if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
            perror("msgsnd");
        }
        else 
            printf("login request sent\n");
    }
    void sendMessage(char *a){
        sbuf.mtype = 1;   
        sprintf(sbuf.mtext, "%s:%s",name,a);
     
        buf_length = strlen(sbuf.mtext) + 1 ;
        if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
            perror("msgsnd");
        }
        else 
            printf("Message Sent\n");
    }
    void logOut(){
        sbuf.mtype = 1;   
        sprintf(sbuf.mtext,"logout:%s",name);
        buf_length = strlen(sbuf.mtext) + 1 ;
        if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
            perror("msgsnd");
        }
        else 
        printf("Logout requrest sent\n");
        int error=pthread_kill(pthread_self(),SIGKILL);
    }
    void createFifo(){
        int f;

        sprintf(filename,"FIFO_%s",name);
        mkfifo(filename, 0666);
        printf("%s created\n",filename);
        pthread_t id;
        pthread_create(&id,NULL,ftn,(void*)NULL); 
    }
};

int main()
{   
    char msg[180];
    client c;
    c.sendLoginReq();
    cout<<">";
    while(1){
    cin.getline(msg,100);
      if(strcmp(msg,"$")==0){
        
         c.logOut();
         break;
      }
      else{
         c.sendMessage(msg); 
      }  
    } 
  return 0;
}
 
