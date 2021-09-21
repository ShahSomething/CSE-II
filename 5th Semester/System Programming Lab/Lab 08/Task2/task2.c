#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>

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
    struct stat buffer;
    while ((direntp = readdir(dirp))!=NULL)
    {
    	if(direntp->d_name[0]=='.')
    		continue;
        stat(direntp->d_name,&buffer);
        if(S_ISDIR(buffer.st_mode))
            printf("d\t");
        else
            printf("-\t");
        
        if(S_IRUSR&buffer.st_mode)
            printf("r");
        else
            printf("-");
        if(S_IWUSR&buffer.st_mode)
            printf("w");
        else
            printf("-");
        if(S_IXUSR&buffer.st_mode)
            printf("x");
        else
            printf("-");
        
        
        if(S_IRGRP&buffer.st_mode)
            printf("r");
        else
            printf("-");
        if(S_IWGRP&buffer.st_mode)
            printf("w");
        else
            printf("-");
        if(S_IXGRP&buffer.st_mode)
            printf("x");
        else
            printf("-");

        if(S_IROTH&buffer.st_mode)
            printf("r");
        else
            printf("-");
        if(S_IWOTH&buffer.st_mode)
            printf("w");
        else
            printf("-");
        if(S_IXOTH&buffer.st_mode)
            printf("x\t");
        else
            printf("-\t");

        printf("%ld\t",buffer.st_nlink);
        
        struct passwd *USR = getpwuid(buffer.st_uid);
        printf("%s   ",USR->pw_name);

        struct passwd *GRP = getpwuid(buffer.st_gid);
        printf("%s\t",GRP->pw_name);

        printf("%ld   ",buffer.st_size);
        char *time = ctime(&buffer.st_atime);
        int i;
        for(i=0;*(time+i)!='\n';i++);
        *(time+i) = '\0';
        printf("%s\t",time);
        printf("%s\n",direntp->d_name);
    }
    return 0;

}
