///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question5.c 
//  File name   : MyMath.c
//  Descreption : Making my own #include<math.h>
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////

#include "Mymath.h"

double powX(double base,int No)
{
    int result = 0;
    int i = 0;

    for (i = 1;i<base;i++)
    {   result = i;
        result*=No * No;
    }
    return result;
}

double SqrtX(double base)
{
    int Ans = 0;

    Ans = base * base;

    return Ans;
}

//int AbsX(int)

int MaxX(int No1,int No2)
{
    return (No1 > No2);
}

int MinX(int No1,int No2)
{
    return (No1 < No2);
}

int FactorialX(int No)
{
    int iCnt = 0;

    for(iCnt = 1; iCnt < No; iCnt++)
    {
        if((No % iCnt) == 0)
        {
            return iCnt;
        }
    }
}

int GCDX(int No1,int No2)
{
    int temp;

    while (No2 != 0)
    {
        temp = No1 % No2;
        No1 = No2;
        No2 = temp;    
    }
    return No1;
}

int LCMX(int No1,int No2)
{
    return (No1 * No2) / GCDX(No1,No2);
}