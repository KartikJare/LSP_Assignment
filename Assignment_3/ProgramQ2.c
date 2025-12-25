///////////////////////////////////////////////////////////
//
//  File name   : Assigment3Question2.c
//  Description : Check File Present in Directory
//                • Accept directory name and file name.
//                • Check whether that file exists in that directory.
//                • Print absolute matched path if found.
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<limits.h>
#include<stdlib.h>    

#define PATH_MAX 4096

int main()
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    char DirName[100];
    char FileName[100];
    char AbsPath[PATH_MAX];
    int iFound = 0;

    printf("Enter directory name : \n");
    scanf("%s", DirName);

    printf("Enter file name to search : \n");
    scanf("%s", FileName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory : %s\n", strerror(errno));
        return -1;
    }

    while((ptr = readdir(dp)) != NULL)
    {
        if(strcmp(ptr->d_name, FileName) == 0)
        {
            if(realpath(DirName, AbsPath) != NULL)
            {
                strcat(AbsPath, "/");
                strcat(AbsPath, FileName);
                printf("File found at path : %s\n", AbsPath);
            }
            else
            {
                printf("File found : %s/%s\n", DirName, FileName);
            }

            iFound = 1;
            break;
        }
    }

    if(iFound == 0)
    {
        printf("File not found in given directory\n");
    }

    closedir(dp);
    return 0;
}