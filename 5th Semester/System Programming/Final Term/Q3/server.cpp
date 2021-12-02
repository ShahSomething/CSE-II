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
#include <stdlib.h>
#include <signal.h>

#define MSGSZ     128

int h=0,runflag=1;
using namespace std;
typedef struct  {
   long mtype;
   char mtext[MSGSZ];
} message_buf;


class MessageQueue {
private :
   key_t key;     /* key to be passed to msgget() */ 
   int MsgFlg;   /* msgflg to be passed to msgget() */ 
   int MsQid;   /* return value from msgget() */ 
   char **reciever;
   int users;
   message_buf buf;
public :
   MessageQueue ( int id ){
      reciever=(char **)malloc(sizeof(char*)*50);
      users=0;
      this->key=id;
      this->MsgFlg=IPC_CREAT | 0666;
      if (( MsQid = msgget( key , MsgFlg )) == -1){
         perror("msgget: msgget failed");   
      }
      else{
         cout<<"Message Queue generated\n";
      }
   }
   void reAllocate(){
      reciever=(char**)realloc(reciever,50);
   }
   void removeUser(char *a){
      printf("%s\n",a);
      printf("removing FIFO_%s\n",a);
      char tem[15];
      sprintf(tem,"FIFO_%s",a);
      int er=unlink(tem);
      for(int i=0;i<users;i++){
         if(strcmp(reciever[i],a)==0){
            strcpy(reciever[i],"");
            for(int j=i;j<users-1;j++){
               strcpy(reciever[j],reciever[j+1]);
            }
            delete(reciever[users-1]);
            users--;
         }
      }
   }
   void removeAll(){
      char tem[15];
      for(int i=0;i<users;i++){
         sprintf(tem,"FIFO_%s",reciever[i]);
         printf("removing %s\n",tem);
         int er=unlink(tem);
         delete(reciever[i]);
      }
   }
   void recieveMessage(){
      int rtrn;
      if(runflag==0)
         exit(0);
      if (rtrn = msgrcv(this->MsQid,&buf, 180, 1, this->MsgFlg) == -1)
         perror("msgop: msgrcv failed");

      if(strncmp(buf.mtext,"login",5)==0){
         reciever[users]=(char*)malloc(sizeof(char*)*10);
         strcpy(reciever[users],buf.mtext+6);
         printf("%s connected\n",reciever[users]);
         users++;
         if(users>50)
            reAllocate();
      }
      else if(strncmp(buf.mtext,"logout",6)==0){
         removeUser(buf.mtext+7);
      }
      else{
         int r;
         int f;
         char filename[15];
         if(h==0){
            for(int i=0;i<users;i++){
               sprintf(filename,"FIFO_%s",reciever[i]);
               mkfifo(filename, 0666);
               strcpy(filename,"");   
            }
            mkfifo("FIFO_shah", 0666);
            h++;
         }
         for(int i=0;i<users;i++){ 
            sprintf(filename,"FIFO_%s",reciever[i]);
            while(1){
               f=open(filename,O_WRONLY);
               char tem[10];
               strcpy(tem,filename+5);
               if(strncmp(buf.mtext,tem,strlen(tem))==0)
                  break;
               r=write(f,buf.mtext,strlen(buf.mtext));
               if (r==0 || r==-1)
                  if(r==-1)
                     printf("failed\n");
               break;
            }
            strcpy(filename,""); 
            close(f);
         }  
      }
   }
   void setMessage( ){
      int r;
      int f;
      char filename[15];
      strcpy(buf.mtext,"$");
      for(int i=0;i<users;i++){ 
         sprintf(filename,"FIFO_%s",reciever[i]);
         while(1){
            f=open(filename,O_WRONLY);
            cout<<"i am while here\n";
            char tem[10];
            strcpy(tem,filename+5);
            printf("%s-\n",tem);
            r=write(f,buf.mtext,strlen(buf.mtext));
            if (r==0 || r==-1)
               if(r==-1)
                  printf("failed\n");
            break;
         }
         strcpy(filename,""); 
         close(f);
         cout<<"out\n"; 
      }  
   }
};

void *terminate(void *a){
   MessageQueue *m=(MessageQueue*)a;
   char ter[5];
   while(1){
      cin.getline(ter,5);
      if(strcmp(ter,"*")==0)
         break;
   }
   printf("treadpit\n");
   runflag=0;
   m->setMessage();
   m->removeAll();
   int error=pthread_kill(pthread_self(),SIGKILL);
}
int main(){
   pthread_t id;
   MessageQueue m( 123 ); 
   pthread_create(&id,NULL,terminate,(void*)&m);
   while(runflag){
     m.recieveMessage(); 
   }
   return 0;
}


