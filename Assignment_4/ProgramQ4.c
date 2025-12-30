///////////////////////////////////////////////////////////
//
//  File name   : Assigment4Question4.c
//  Description : Merge multiple input files into a single output file
//  Author      : Kartik Ganesh Jare
//  Date        : 30/12/25
//  
///////////////////////////////////////////////////////////

/*
    Input:
        output_file file1 file2 file3 ...
    Output:
        Combined file content in order.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    int fdSrc = 0, fdDest = 0;
    char Buffer[BUFFERSIZE];
    int iRet = 0;
    int iCnt = 0;

    fdDest = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fdDest == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    for(iCnt = 2; iCnt < argc; iCnt++) // 2 is use cuz of agrv[2]
    {
        fdSrc = open(argv[iCnt],O_RDONLY);
        if(fdSrc == -1)
        {
            printf("%s\n",strerror(errno));
            return -1;
        }

        while((iRet = read(fdSrc,Buffer,BUFFERSIZE)) > 0)
        {
            write(fdDest, Buffer, iRet);
        }
    }

    printf("Files merged successfully into %s\n", argv[1]);

    close(fdDest);
    close(fdSrc);

    return 0;
}