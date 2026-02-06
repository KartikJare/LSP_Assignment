///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question3.c 
//  File name   : Client.c
//  Descreption : Main function
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////

#include<stdio.h>   

void Display(char *str);

int main()
{
    char string[100];

    printf("Enter the string : ");
    fgets(string,sizeof(string),stdin);

    Display(string);

    return 0;
}