#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{       int val, pid;

         for(int i=1;i<=2;i++)
        {  
                pid=fork();
                if(pid==0)
                {
                if(i==1)
               {
                   execlp("cp", "cp", "-r","/home/shahsomething/","new",NULL);
                }
                break;
         }
      }
}
