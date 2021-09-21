#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>

int i=0;
void depthfirst(char *name)
{
    i++;
    DIR *dirp = opendir(name);
    if(dirp==NULL)
    {
        perror("Failed to open directory");
    }
    struct dirent *direntp; 
    struct stat buffer;
    int retchd = chdir(name);
    if(retchd==-1)
    	perror("Failed to change directory");
    while((direntp=readdir(dirp))!=NULL)
    {
    	if(direntp->d_name[0]=='.')
    			continue;
    	for(int j=0;j<i;j++)
    		printf("    ");
    	printf("%s\n",direntp->d_name);
    	int ret = stat(direntp->d_name,&buffer);
    	if(ret==-1)
    		perror("Error using stat");
    	if(S_ISDIR(buffer.st_mode))
    	{
    		depthfirst(direntp->d_name);
    		chdir("..");
    		i--;
    	}
    }
}

int main(int argc, char *argv[])
{
    printf("%s\n",argv[1]);
    depthfirst(argv[1]);
    return 0;
}
