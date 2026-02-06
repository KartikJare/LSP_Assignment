///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question1.c 
//  File name   : helper.c  
//  Descreption : Helper function for perfect number logic
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////

#include "helper.h"

int SumOfFactors(int No)
{
    int i = 0;
    int iSum = 0;

    for(i = 1;i <= No / 2;i++)
    {
        if(No % i == 0)
        {
            iSum = iSum + i;
        }
    }
    return iSum;
}