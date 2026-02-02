///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question2.c 
//  File name   : Client.c
//  Descreption : Main Fucntion
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////

#include<stdio.h>

int Addition(int A,int B);
int Substraction(int A,int B);

int main()
{
    int Value1 = 0,Value2 = 0;

    printf("Enter frist number : ");
    scanf("%d",&Value1);

    printf("Enter second number : ");
    scanf("%d",&Value2);

    printf("Addition is : %d\n",Addition(Value1,Value2));
    printf("Substraction is : %d\n",Substraction(Value1,Value2));

    return 0;
}
