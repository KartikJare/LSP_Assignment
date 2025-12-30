///////////////////////////////////////////////////////////
//
//  File name   : Assigment2Question3.c
//  Description : List All Files From Directory
//                • Accept directory name.
//                • Use opendir() / readdir() to print only names (skip . and ..).
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

int main()
{
    DIR *dp = NULL;
    char DirName[100];
    struct dirent *ptr = NULL;
    
    printf("Enter the directory name : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while((ptr = readdir(dp)) != NULL)
    {
        if((strcmp(ptr->d_name, ".")!= 0) && (strcmp(ptr->d_name,"..")!= 0))
        {
            printf("%s\n",ptr->d_name);
        }   
    }

    return 0;
}
