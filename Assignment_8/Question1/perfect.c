///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question1.c 
//  File name   : perfect.c
//  Descreption : Helper function for perfect number logic
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////

#include "helper.h"
#include "perfect.h"
#include<stdbool.h>

bool Perfect(int No)
{
    int iSum = 0;

    iSum = SumOfFactors(No);

    if(iSum == No)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    return 0;

}