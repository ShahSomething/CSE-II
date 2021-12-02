/*
    Name: Shah Raza
    Assignment #1
    Question: 1
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

/* This Program will search every directory and its sub-directories
Starting from /home and will list every hardlink available on the system */ 

void BreadthFirst(char *name)
{
    //Pointer to the direntory being opened
    DIR *dirp = opendir(name);
    //Error checking for directory opening
    if(dirp==NULL)
    {
        perror("Failed to Open directory");
    }
    //Directory Entry Structure
    struct dirent *direntp;
    //Stat structure will be used to store information about each directory entry
    struct stat buffer;
    //Changing our working directory
    int retchd = chdir(name);
    //Errror checking for chdir
    if(retchd==-1)
        perror("Failed to change directory");
    //This loop will run till we go through all the entries in the directory
    while((direntp = readdir(dirp))!=NULL)
    {
        //We will skip the '.' and '..' directories
        if(direntp->d_name[0]=='.')
            continue;
        //Getting the information about directory entry
        int ret = stat(direntp->d_name,&buffer);
        //Error checking for stat
        if(ret==-1)
            perror("Error Using Stat");
        /*
            This is the part where we check if a file is hardlink or not.
            If the number of links to a file is greater than 1 then that file
            is a hardlink.But the problem is that a directory may also have no of links 
            greater than 1 and when C language dereferences a soft link, its number of links
            may also be greater than 1. So in order to get the correct result, we will check for
            the following condition: 
            If the entry is Not a Directory AND its number of links are greater than 1
            AND it is also NOT a Soft link then it is a Hard link. 
        */
        if(!(S_ISDIR(buffer.st_mode)) && (buffer.st_nlink > 1) && (direntp->d_type!=DT_LNK))
        {
            printf("%s: %ld (inode no)\n",direntp->d_name,buffer.st_ino);
        }
    }
    //Since we are using Breadth first algorithm so we need to rewind our directory
    rewinddir(dirp);
    //This loop will run till we go through all the entries in the directory
    while((direntp = readdir(dirp))!=NULL)
    {
        //We will skip the '.' and '..' directories
        if(direntp->d_name[0]=='.')
            continue;
         //Getting the information about directory entry
        int ret = stat(direntp->d_name,&buffer);
        //Error checking for stat
        if(ret==-1)
            perror("Error Using Stat");
        //If the entry is a directory, we will go through it in breadth first order
        if(S_ISDIR(buffer.st_mode))
        {
            BreadthFirst(direntp->d_name);
            chdir("..");
        }
    }
    //Close the directory
    closedir(dirp);
}

int main(int argc, char *argv[])
{
    printf("All the Hardlinks in the system: \n");
    BreadthFirst("/home");
    return 0;
}
