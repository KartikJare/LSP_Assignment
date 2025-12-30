///////////////////////////////////////////////////////////
//
//  File name   : Assigment2Question2.c
//  Descreption : Write String to File
//                • Accept file name and a string from user.
//                • Write string using write() (append mode by default).
//                • Print number of bytes written.
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    char Fname[20];
    int fd = 0, iRet = 0;
    char Buffer[100];

    printf("Enter the file name that you want to open :\n");
    scanf("%s",Fname);

    printf("Write the string to be writed in the file:\n");
    scanf(" %[^\n]", Buffer);

    fd = open(Fname,O_WRONLY | O_APPEND); 
    if(fd == -1)
    {
        printf("Unable to open the file\n");
    }
    else
    {
        printf("File is successfully opened with fd: %d\n",fd);

        iRet = write(fd,Buffer,strlen(Buffer));

        printf("%d bytes gets written sucessfully\n",iRet);

        close(fd);
    }

    return 0;
}
