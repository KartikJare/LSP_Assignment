///////////////////////////////////////////////////////////
//
//  File name   : Assigment1Question2.c
//  Descreption : Open File in Given Mode
//                • Accept file name and mode (R, W, RW, A) from user.
//                • Convert mode to flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND | O_CREAT).
//                • Open file accordingly and display fd.
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include <unistd.h>

int main()
{
    char fName[60];
    char mode[10];
    int fd = 0,flags = 0;

    printf("Enter the file name: \n");
    scanf(" %s",fName);
 
    printf("Enter the mode R/W/RW/A : \n");
    scanf("%s",mode);

    if(strcmp(mode,"R") == 0)
    {
        flags = O_RDONLY;
    }
    else if(strcmp(mode,"W") == 0)
    {
        flags = O_WRONLY | O_CREAT;
    }
    else if(strcmp(mode,"RW") == 0)
    {
        flags = O_RDWR | O_CREAT;
    }
    else if(strcmp(mode,"A") == 0)
    {
        flags = O_APPEND | O_WRONLY | O_CREAT;
    }
    else
    {
        printf("Ivalid mode\n");
        return -1;
    }

    fd = open(fName,flags,0777);
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

// New call strcmp to compares the two strings.