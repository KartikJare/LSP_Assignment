///////////////////////////////////////////////////////////
//
//  File name   : Assigment4Question3.c
//  Description : Copy a file using pread() and pwrite() without changing the file offset
//  Author      : Kartik Ganesh Jare
//  Date        : 30/12/25
//  
///////////////////////////////////////////////////////////

/*
    Input:
        Source and destination file names.
    Output:
        Copied file identical to source.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>

#define BUFFERSIZE 1024

int main()
{
    int fdSrc = 0, fdDest = 0;
    char SrcFile[100];
    char DestFile[100];
    char Buffer[BUFFERSIZE];
    long int liRead = 0;
    off_t offset = 0;


    printf("Enter source directory name : \n");
    scanf("%s", SrcFile);

    printf("Enter destination directory name : \n");
    scanf("%s", DestFile);
    
    fdSrc = open(SrcFile, O_RDONLY);
    if(fdSrc == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    fdDest = open(DestFile, O_WRONLY | O_CREAT | O_TRUNC,0777);
    if(fdDest == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while((liRead = pread(fdSrc, Buffer, BUFFERSIZE, offset)) > 0)
    {
        pwrite(fdDest, Buffer, liRead, offset);
        offset = offset + liRead;
    }

    if(liRead == -1)
    {
        printf("%s",strerror(errno));
    }
    else
    {
        printf("File copied successfully without changing file offset\n");
    }
    
    close(fdSrc);
    close(fdDest);

    return 0;
}