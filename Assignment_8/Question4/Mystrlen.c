///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question4.c 
//  File name   : Mystrlen.c
//  Descreption : Making my own strlenX string
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////

#include<stdio.h>

int Mystrlen(const char *str)
{
    int iCount = 0;

    if(str == NULL)
    {
        return -1;
    }
    
   while(*str != '\0')
   {
        iCount++;
        str++;
   }

   return iCount;
}
