///////////////////////////////////////////////////////////
//
//  File name   : Assigment1Question4.c
//  Description : Display Complete File Information
//                • Accept file name and display file metadata using stat():
//                ◦ Size, inode, permissions, hard links, owner uid/gid, file type, last access/modify time.
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<time.h>

int main()
{
    char fName[60];
    
    struct stat sobj;

    printf("Enter the file name:\n");
    scanf("%s", fName);

    if(stat(fName,&sobj) == -1)
    {
        printf("%s",strerror(errno));
        return -1;
    }
    
    printf("Total Size : %ld\n",sobj.st_size);
    printf("Inode number : %ld\n",sobj.st_ino);
    printf("Block size : %lu\n",sobj.st_blksize);
    printf("HardLink count : %lu\n",sobj.st_nlink);
    
    printf("Owner UID : %u\n",sobj.st_uid);
    printf("Owner GID : %u\n",sobj.st_gid);

    printf("Last Access Time : %s",ctime(&sobj.st_atime));
    printf("Last Modify Time : %s",ctime(&sobj.st_mtime));

    printf("Permissions : ");                              //Need to ask sir
    printf( (sobj.st_mode & S_IRUSR) ? "r" : "-" );
    printf( (sobj.st_mode & S_IWUSR) ? "w" : "-" );
    printf( (sobj.st_mode & S_IXUSR) ? "x" : "-" );
    printf( (sobj.st_mode & S_IRGRP) ? "r" : "-" );
    printf( (sobj.st_mode & S_IWGRP) ? "w" : "-" );
    printf( (sobj.st_mode & S_IXGRP) ? "x" : "-" );
    printf( (sobj.st_mode & S_IROTH) ? "r" : "-" );
    printf( (sobj.st_mode & S_IWOTH) ? "w" : "-" );
    printf( (sobj.st_mode & S_IXOTH) ? "x" : "-" );
    printf("\n");

    printf("File type is :");

    if(S_ISBLK(sobj.st_mode))
    {
        printf("Block Device\n");
    }
    else if(S_ISCHR(sobj.st_mode))
    {
        printf("Character Device\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Directory File\n");
    }
    else if(S_ISREG(sobj.st_mode))
    {
        printf("Regular file\n");
    }
    else if(S_ISSOCK(sobj.st_mode))
    {
        printf("Socket file\n");
    }
    else if(S_ISFIFO(sobj.st_mode))
    {
        printf("Pipe file\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Symbolic link\n");
    }
    

    return 0;
}