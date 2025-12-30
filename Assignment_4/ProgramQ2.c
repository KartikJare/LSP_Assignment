///////////////////////////////////////////////////////////
//
//  File name   : Assigment4Question2.c
//  Description : File Copy with Offset
//                Copy a file starting from a given byte offset of the source file.
//  Author      : Kartik Ganesh Jare
//  Date        : 30/12/25
//  
///////////////////////////////////////////////////////////

/*
   Input:
     source_file destination_file offset
   Output:
     Partial file copied starting from offset
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>

#define BUFFERSIZE 1024

int main()
{
    int fdSrc = 0, fdDest = 0;
    char SrcFile[100];
    char DestFile[100];
    char Buffer[BUFFERSIZE];
    int iRet = 0;
    long int offset = 0;
    struct stat sobj;

    printf("Enter source file name : \n");
    scanf("%s",SrcFile);

    printf("Enter destination file name : \n");
    scanf("%s",DestFile);

    printf("Enter offset in bytes : \n");
    scanf("%ld",&offset);

    fdSrc = open(SrcFile, O_RDONLY);
    if(fdSrc == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    iRet = stat(SrcFile, &sobj);
    
    if(offset >= sobj.st_size)
    {
        printf("Offset is beyond file size\n");
        close(fdSrc);
        return -1;
    }

    if(lseek(fdSrc, offset, SEEK_SET) == -1)
    {
        printf("lseek failed : %s\n", strerror(errno));
        close(fdSrc);
        return -1;
    }

    fdDest = open(DestFile, O_WRONLY | O_CREAT | O_TRUNC, sobj.st_mode);
    if(fdDest == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while((iRet = read(fdSrc, Buffer, BUFFERSIZE)) > 0)
    {
        iRet = write(fdDest, Buffer, iRet);
    }

    if(iRet == -1)
    {
        printf("Read error\n");
    }
    else
    {
        printf("File copied successfully from offset %ld\n", offset);
    }

    close(fdSrc);
    close(fdDest);

    return 0;
}

/*
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    int fdSrc = 0, fdDest = 0;
    char Buffer[BUFFERSIZE];
    int iRet = 0;
    long int offSet = 0;
    struct stat sobj;

    offSet = atoi(argv[3]);

    fdSrc = open(argv[1], O_RDONLY);
    if(fdSrc == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    stat(argv[1], &sobj);

    if(offSet >= sobj.st_size)
    {
        printf("Offset beyond file size\n");
        return -1;
    }

    lseek(fdSrc, offSet, SEEK_SET);

    fdDest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, sobj.st_mode);
    if(fdDest == -1)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    while((iRet = read(fdSrc, Buffer, BUFFERSIZE)) > 0)
    {
        write(fdDest, Buffer, iRet);
    }

    printf("File copied successfully from offset %ld\n", offSet);

    close(fdSrc);
    close(fdDest);

    return 0;
}
*/