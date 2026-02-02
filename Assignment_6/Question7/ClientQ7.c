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

void GobalValueIncrement();
void Display();
void Reset();

int main()
{   
    Display();

    GobalValueIncrement();
    GobalValueIncrement();
    Display();

    Reset();
    Display();

    return 0;
}

// gcc ClientQ7.c -o ClientQ7 -ldl 
//    This use only when we call dlopen/dclose
// gcc ClientQ7.c -L. -lServerQ7 -o ClientQ7
// LD_LIBRARY_PATH=. ./ClientQ7
