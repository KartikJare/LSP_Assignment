///////////////////////////////////////////////////////////
//
//  File name   : Assigment2Question1.c
//  Descreption : 1) Read Whole File
//                • Accept file name and print full content on console.
//                • Use a buffer loop (read() until 0).
//                • Show total bytes read.
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024  

int main()
{
    char Fname[20] = {'\0'};
    int fd = 0, iRet = 0, iCnt = 0;
    char Buffer[BUFFER_SIZE] = {'\0'};

    printf("Enter the file name that you want to open :\n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
    }
    else
    {
        printf("File is successfully opened with fd: %d\n",fd);

        while((iRet = read(fd,Buffer,BUFFER_SIZE)) > 0)
        {
           write(1, Buffer, iRet);
        }
        
        close(fd);
    }

    return 0;
}