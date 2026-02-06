///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question4.c 
//  File name   : Client.c
//  Descreption : Main function for own strlen
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////

#include<stdio.h>   

int Mystrlen(const char *str);

int main()
{
    char string[100];
    int iRet = 0;

    printf("Enter the string : ");
    fgets(string,sizeof(string),stdin);

    iRet = Mystrlen(string);

    printf("String lenght is : %d\n",iRet);

    return 0;
}