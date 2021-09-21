#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>

void breadthfirst(char *name)
{
    DIR *dirp = opendir(name);
    if(dirp==NULL)
    {
        perror("Failed to open directory");
    }
    struct dirent *direntp; 
    struct stat buffer;
    char cwd[400];
    int retchd = chdir(name);
    if(retchd==-1)
    	perror("Failed to change directory");
    if(getcwd(cwd,sizeof(cwd))==NULL)
    	perror("Failed to get cwd");
    while((direntp=readdir(dirp))!=NULL)
    {
    	if(direntp->d_name[0]=='.')
    			continue;
    	printf("%s/%s\n",cwd,direntp->d_name);
    }
    rewinddir(dirp);
    while((direntp=readdir(dirp))!=NULL)
    {
    	if(direntp->d_name[0]=='.')
    			continue;
    	int ret = stat(direntp->d_name,&buffer);
    	if(ret==-1)
    		perror("Error using stat");
    	if(S_ISDIR(buffer.st_mode))
    	{
    		breadthfirst(direntp->d_name);
    		chdir("..");
    	}
    }
}

int main(int argc, char *argv[])
{
    breadthfirst(argv[1]);
    return 0;
}
