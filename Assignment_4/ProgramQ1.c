///////////////////////////////////////////////////////////
//
//  File name   : Assigment4Question1.c
//  Descreption : File Copy Utility
//                Problem Statement:
//                Write a program that copies the contents of one file into another.
//  Author      : Kartik Ganesh Jare
//  Date        : 30/12/25
//  
///////////////////////////////////////////////////////////

/*
  Input:
     Source file name and destination file name as command-line arguments.
  Output:
     Destination file containing an exact copy of source file.
     • Handle file-not-found and permission errors.
     • Destination file should be created if not present..
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>

#define BUFFERSIZE 1024


int main(int argc, char *argv[])
{
    int fdSrc = 0,fdDest = 0;
    char Buffer[BUFFERSIZE];
    int iRet = 0;
    struct stat sobj;

    fdSrc = open(argv[1],O_RDONLY);
    if(fdSrc == -1)
    {
        printf("%s",strerror(errno));
        return -1;
    }

    fdDest = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0777,sobj.st_mode);
    if(fdDest == -1)
    {
        printf("%s",strerror(errno));
        return -1;
    } 

    while((iRet = read(fdSrc,Buffer,BUFFERSIZE)) > 0)
    {
        write(fdDest,Buffer,iRet);
    }

    if(iRet == -1)
    {
        printf("Error while reading source file\n");
    }
    else
    {
        printf("File copied successfully\n");
    }

    close(fdSrc);
    close(fdDest);    

    return 0;
}