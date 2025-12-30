///////////////////////////////////////////////////////////
//
//  File name   : Assigment3Question3.c
//  Description : Move All Files (Dir → Dir)
//                • Accept source dir and destination dir.
//                • Move all regular files
//                • Use rename() if possible
//                • Else copy + delete
//                • Print count of moved files
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
#include<dirent.h>

#define BUFSIZE 1024

int main()
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    struct stat sobj;
    char SrcDir[100];
    char DestDir[100];
    char SrcPath[300];
    char DestPath[300];
    char Buffer[BUFSIZE];
    int SrcFD = 0, DestFD = 0,iRet = 0, iCount = 0;

    printf("Enter source directory name : \n");
    scanf("%s", SrcDir);

    printf("Enter destination directory name : \n");
    scanf("%s", DestDir);

    dp = opendir(SrcDir);
    if(dp == NULL)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    while((ptr = readdir(dp)))
    {
        snprintf(SrcPath,sizeof(SrcPath), "%s/%s", SrcDir, ptr->d_name);
        snprintf(DestPath,sizeof(DestPath), "%s/%s", DestDir, ptr->d_name);

        iRet = stat(SrcPath,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(rename(SrcPath,DestPath) == 0)
            {
                iCount++;
            }
            else
            {
                SrcFD = open(SrcPath, O_RDONLY);
                if(SrcFD == -1)
                {
                    printf("%s",strerror(errno));
                }

                DestFD = open(DestPath, O_WRONLY | O_CREAT | O_TRUNC,0777);
                if(DestFD == -1)
                {
                    printf("%s",strerror(errno));
                }

                while((iRet = read(SrcFD,Buffer,sizeof(Buffer))) > 0)
                {
                    write(DestFD,Buffer,iRet);
                }

                iCount++;
            }
        }
    }

    printf("Total files moved : %d\n",iCount);

    close(SrcFD);
    close(DestFD);
    closedir(dp);
    unlink(SrcPath);
    
    return 0;
}
