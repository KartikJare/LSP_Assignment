///////////////////////////////////////////////////////////
//
//  File name   : Assigment4Question1.c
//  Descreption : Copy File Contents (source → destination)
//                • Accept source_file and dest_file.
//                • Create destination if not exists (O_CREAT | O_TRUNC).
//                • Copy using buffered read()/write() loop.
//                • Preserve permissions (optional bonus using stat() + chmod()).
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>

#define BUFFERSIZE 1024


int main()
{
    int fdSrc = 0,fdDest = 0;
    char SrcFile [100];
    char DestFile [100];
    char Buffer[BUFFERSIZE];
    int iRet = 0;
    struct stat sobj;

    printf("Enter source file name : \n");
    scanf("%s",SrcFile);

    printf("Enter destination file name : \n");
    scanf("%s",DestFile);

    fdSrc = open(SrcFile,O_RDONLY);
    if(fdSrc == -1)
    {
        printf("%s",strerror(errno));
        return -1;
    }

    fdDest = open(DestFile,O_WRONLY | O_CREAT | O_TRUNC,0777,sobj.st_mode);
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
