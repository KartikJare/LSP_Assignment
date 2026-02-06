///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question1.c 
//  File name   : Client.c
//  Descreption : Main Fucntion
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include "perfect.h"
#include<stdbool.h>

int main()
{
    int No = 0;
    bool bRet = false;

    printf("Enter number : ");
    scanf("%d",&No);

    bRet = Perfect(No);

    if (bRet == true)
    {
        printf("Number is a perfect number\n");
        
    }
    else
    {
        printf("Number is a not perfect number\n");
    }

    return 0;
}