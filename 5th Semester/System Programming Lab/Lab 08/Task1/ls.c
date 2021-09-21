#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
     DIR *dirp;
     if(argc==1)
     {
         dirp = opendir(".");
     }
     else if(argc==2)
     {
     	dirp = opendir(argv[1]);
     }
     else
     {
     	printf("Invalid number of Arguments");
         return -1;
     }
    if(dirp==NULL)
    {
        perror("Failed to open directory");
        return -1;
    }

    struct dirent *direntp; 
    while ((direntp= readdir(dirp))!=NULL)
    {
    	if(direntp->d_name[0]=='.')
    		continue;
        printf("%s \t",direntp->d_name);
    }
    printf("\n");
    return 0;

}
