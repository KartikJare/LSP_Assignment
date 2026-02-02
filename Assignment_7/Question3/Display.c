///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question3.c 
//  File name   : Display.c
//  Descreption : Display string
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////

#include<stdio.h>

void Display(char *str)
{
    int iCount = 0;
    char *temp = str;    // to keep the original string
    
   while(*temp != '\0')
   {
        iCount++;
        temp++;
   }

    printf("String is : %s\n",str);
    printf("Count in string are : %d\n",iCount);
}
