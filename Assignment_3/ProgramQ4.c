///////////////////////////////////////////////////////////
//
//  File name   : Assigment4Question4.c
//  Description : Delete All Empty Regular Files
//                • Accept directory name.
//                • Delete files with size = 0 bytes (regular files only).
//                • Print names deleted + total deleted count.
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

int main()
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    struct stat sobj;
    char DirName[100];
    char Path[300];
    int DeleteCount = 0,iRet = 0;

    printf("Enter directory name : \n");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while((ptr = readdir(dp)))
    {
        iRet = stat(Path,&sobj);

        if(S_ISREG(sobj.st_mode) && sobj.st_size == 0)
        {
            if(unlink(Path) == 0)
            {
                printf("Deleted empty file : %s\n",ptr->d_name);
                DeleteCount++;
            }
            else
            {
                printf("%s\n",strerror(errno));
            }
        }
    }

    printf("Total empty files deleted : %d\n",DeleteCount);

    closedir(dp);

    return 0;
}
