///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question7.c
//  Descreption : A shared library that maintains a 
//                global variable inside the library.
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

#include<stdio.h>

int Value = 0;

void GobalValueIncrement()
{
    Value++;
}

void Display()
{
    printf("Golbal varaiable value : %d\n",Value);
}

void Reset()
{
    Value = 0;
}

// gcc -fPIC -shared -o libServerQ7.so ServerQ7.c