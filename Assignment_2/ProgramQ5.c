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

int main()
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    struct stat sobj;
    char DirName[100];
    char LargeFile[100];
    char FileName[300];
    int iRet = 0;
    long int iMax = 0;
    
    printf("Enter the directory name : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while((ptr = readdir(dp)))
    {
        snprintf(FileName,sizeof(FileName),"%s/%s",DirName, ptr->d_name); //ask to sir
        
        iRet = stat(FileName,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > iMax)
            {
                iMax = sobj.st_size;
                strcpy(LargeFile, ptr->d_name);
            }
        }
    }
   
    if(iMax == 0)
    {
        printf("No regular files found in directory\n");
    }
    else
    {
        printf("Largest File Name : %s\n",LargeFile);
        printf("Largest File Size : %ld bytes\n",iMax);
    }

    return 0;
}
