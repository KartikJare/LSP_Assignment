///////////////////////////////////////////////////////////
//
//  File name   : Assigment4Question5.c
//  Description : Display the contents of a file in reverse order.
//  Author      : Kartik Ganesh Jare
//  Date        : 30/12/25
//  
///////////////////////////////////////////////////////////

/*
    Input:
        File name.
    Output:
        File content printed in reverse.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
    int fd = 0,FileSize = 0,iCnt = 0;
    char FileName[100];
    char ch;

    printf("Enter file name : \n");
    scanf("%s", FileName);

    fd = open(FileName, O_RDONLY);
    if(fd == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    FileSize = lseek(fd, 0, SEEK_END);

    for(iCnt = FileSize - 1; iCnt >= 0;iCnt--)
    {
        lseek(fd,iCnt,SEEK_SET);
        read(fd,&ch,1);
        write(1,&ch,1);  
    }

    printf("\n");

    close(fd);

    return 0;
}