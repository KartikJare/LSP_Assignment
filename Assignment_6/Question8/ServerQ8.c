///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question8.c
//  Descreption : A C program to dynamically load a shared 
//                library that performs string operations
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

/*
• Count number of lowercase letters
• Count number of uppercase letters
• Count number of digits
*/

#include<stdio.h>

int CountLower(char *str)
{
    int iCnt = 0;

    while (*str != '\0')
    {  
        if((*str >= 'a') && (*str <= 'z'))
        {
            iCnt++;
        }
        str++;
    }
    return iCnt;
}

int CountUpper(char *str)
{
    int iCnt = 0;

    while (*str != '\0')
    {  
        if((*str >= 'A') && (*str <= 'Z'))
        {
            iCnt++;
        }
        str++;
    }
    return iCnt;
}

int CountDigit(char *str)
{
    int iCnt = 0;

    while (*str != '\0')
    {  
        if((*str >= '0') && (*str <= '9'))
        {
            iCnt++;
        }
        str++;
    }
    return iCnt;
}

// gcc -fPIC -shared -o libServerQ7.so ServerQ7.c