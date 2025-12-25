///////////////////////////////////////////////////////////
//
//  File name   : Assigment1Question5.c
//  Description : Read N bytes from file
//                • Accept file name and number of bytes N
//                • Read exactly N bytes using read()
//                • If file contains less than N bytes,
//                  print only available bytes
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char fName[60];
    int fd = 0;
    int iRet = 0;
    int iSize = 0;
    char *Buffer = NULL;

    printf("Enter the file name:\n");
    scanf("%s", fName);

    printf("Enter number of bytes to read:\n");
    scanf("%d", &iSize);

    fd = open(fName, O_RDONLY);
    if(fd == -1)
    {
        printf("Error : %s\n", strerror(errno));
        return -1;
    }

    Buffer = (char *)malloc(sizeof(char) * iSize);
    if(Buffer == NULL)
    {
        printf("Memory allocation failed\n");
        close(fd);
        return -1;
    }

    iRet = read(fd, Buffer, iSize);
    if(iRet == -1)
    {
        printf("Read error : %s\n", strerror(errno));
        free(Buffer);
        close(fd);
        return -1;
    }

    write(1, Buffer, iRet);

    free(Buffer);
    close(fd);

    return 0;
}