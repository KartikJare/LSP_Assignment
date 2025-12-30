///////////////////////////////////////////////////////////
//
//  File name   : Assigment1Question4.c
//  Description : Delete All Empty Regular Files
//                • Accept directory name.
//                • Delete files with size = 0 bytes (regular files only).
//                • Print names deleted + total deleted count.
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

int main()
{
    DIR *dp = NULL;
    struct dirent * ptr = NULL;
    struct stat sobj;
    char DirName[100];
    char Path[100];
    int DeleCount = 0;

    printf("Enter directory name : \n");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("%s",strerror(errno));
        return;
    }
    
    return 0;
}