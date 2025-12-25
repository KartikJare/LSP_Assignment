///////////////////////////////////////////////////////////
//
//  File name   : Assigment2Question4.c
//  Description : List Files with Type
//                • Accept directory name.
//                • Print each entry with its type: 
//                  Regular / Directory / Link / FIFO / Socket / Char / Block
//                • Use lstat() for accurate type.
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

int main()
{
    DIR *dp = NULL;
    char DirName[100];
    char Path[100];
    struct dirent *ptr = NULL;
    struct stat sobj;
    
    printf("Enter the directory name : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
    else
    {
        printf("Directory gets succesfully opened\n");
    }

    while((ptr = readdir(dp)) != NULL)
    {

        snprintf(Path, sizeof(Path), "%s/%s", DirName, ptr->d_name);

        if(lstat(Path, &sobj) == -1)
        {
            perror("lstat failed");
            return;
        }

        printf("File type is :");

        if(S_ISBLK(sobj.st_mode))
        {
            printf("Block Device\n");
        }
        else if(S_ISCHR(sobj.st_mode))
        {
            printf("Character Device\n");
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("Directory File\n");
        }
        else if(S_ISREG(sobj.st_mode))
        {
            printf("Regular file\n");
        }
        else if(S_ISSOCK(sobj.st_mode))
        {
            printf("Socket file\n");
        }
        else if(S_ISFIFO(sobj.st_mode))
        {
            printf("Pipe file\n");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("Symbolic link\n");
        }       
    }

    return 0;
}