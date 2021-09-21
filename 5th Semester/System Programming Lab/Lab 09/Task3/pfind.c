#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <string.h>

int found=0;

void pfind(char *dir, char *file)
{
    DIR *dirp = opendir(dir);
    if(dirp==NULL)
    {
        perror("Failed to open directory");
    }
    struct dirent *direntp; 
    struct stat buffer;
    if(chdir(dir)==-1){
    	perror("Unable to change directory");
    }
    char cwd[400];
    while((direntp=readdir(dirp))!=NULL)
    {
    	int ret = stat(direntp->d_name,&buffer);
    	if(ret==-1)
    	{
    		perror("Stat Function Error");
    	}
    	if(direntp->d_name[0]=='.')
    		continue;
    	if(strcmp(direntp->d_name,file)==0)
    	{
    		if(getcwd(cwd,sizeof(cwd))==NULL)
    			perror("Failed to get cwd");
    		printf("File location: %s\n",cwd);
    		found=1;
    	}
    	if(S_ISDIR(buffer.st_mode))
    	{
    		pfind(direntp->d_name,file);
    		chdir("..");
    	}	
    }
}

int main(int argc, char *argv[])
{
	pfind(argv[1],argv[2]);
	if(!found)
		printf("File not found\n");
	return 0;
}

