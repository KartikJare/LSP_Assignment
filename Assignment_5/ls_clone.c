///////////////////////////////////////////////////////////
//
//  File name   : Assigment5Question1.c
//  Descreption : Create a program ls_clone.c that takes one directory path and prints:
//                • Entry name
//                • Type (file/dir/link/other)
//                • Size (bytes)
//                • Permissions in rwxr-xr-x format
//                • Last modified time
//                • Skip . and ...
//                • Build full path using snprintf(dir + "/" + name).
//  Author      : Kartik Ganesh Jare
//  Date        : 30/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<time.h>

int main()
{

    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    struct stat sobj;
    char DirName[100];
    char Path[100];
    int iRet = 0;

    printf("Enter Directory name : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("%s",strerror(errno));
        return -1;
    }  

    while(ptr = readdir(dp))
    {
        if((strcmp(ptr->d_name,".") == 0) || (strcmp(ptr->d_name,"..") == 0))
        {
            continue;
        }

        snprintf(Path,sizeof(Path),"%s/%s",DirName,ptr->d_name);

        iRet = stat(Path,&sobj);

        printf("File Name : %s\n",ptr->d_name);

        printf("File type is :");

        if(S_ISREG(sobj.st_mode))
        {
            printf("File\n");
        }   
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("Dir\n");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("Link\n");
        }    
        else
        {
            printf("Other\n");
        }    

        printf("File Size : %ld\n", sobj.st_size);

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

        printf("%s\n",ctime(&sobj.st_mtime));
    }
    
    closedir(dp);

    return 0 ;
}