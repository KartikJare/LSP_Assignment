///////////////////////////////////////////////////////////
//
//  File name   : Assigment2Question5.c
//  Description : Find Largest File in Directory
//                • Accept directory name.
//                • Find and print:
//                ◦ largest file name
//                ◦ its size in bytes
//                • Consider only regular files (ignore directories).
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
        
    }

    return 0;
}