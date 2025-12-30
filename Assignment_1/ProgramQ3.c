
///////////////////////////////////////////////////////////
//
//  File name   : Assigment1Question3.c
//  Description : Check File Access Permission
//                • Accept file name and mode (read/write/execute)
//                • Use access() to check permission
//                • Print Accessible / Not Accessible with reason
//  Author      : Kartik Ganesh Jare
//  Date        : 22/12/25
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
    char fName[60];
    char mode[10];
    int iRet = 0, flags = 0;

    printf("Enter the file name:\n");
    scanf("%s", fName);

    printf("Enter the mode read/write/execute:\n");
    scanf("%s", mode);

    if(strcmp(mode,"read") == 0)
    {
        flags = R_OK;
    }
    else if(strcmp(mode,"write") == 0)
    {
        flags = W_OK;
    }
    else if(strcmp(mode,"execute") == 0)
    {
        flags = X_OK;
    }
    else
    {
        printf("Invalid mode\n");
        return -1;
    }

    iRet = access(fName,flags);
    if(iRet == 0)
    {
        printf("File is Accessible\n");
    }
    else
    {
        printf("File is Not Accessible\n");
        printf("%s\n",strerror(errno));
    }

    return 0;
}

//R_OK → read
//W_OK → write
//X_OK → execute
//F_OK → existence check
