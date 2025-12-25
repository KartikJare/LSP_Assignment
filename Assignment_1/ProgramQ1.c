///////////////////////////////////////////////////////////
//
//  File name   : Assigment1Question1.c
//  Descreption : Open File
//                • Accept file name from user and open it using open().
//                • Print: success message + returned file descriptor.
//                • Handle errors using perror().
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    char fName[60];
    int fd = 0;

    printf("Enter the file name: \n");
    scanf(" %s",fName);

    fd = open(fName,O_RDONLY);

    if(fd == -1)
    {
        printf("%s",strerror(errno));
    }
    else
    {
        printf("File gets sucesfully open with fd : %d\n",fd);
    }

    return 0;
}