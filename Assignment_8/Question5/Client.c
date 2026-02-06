///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question5.c 
//  File name   : Client.c
//  Descreption : Main File to call Mystring and Mymath
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////


#include<stdio.h>  
#include "Mystring.h"
#include "Mymath.h" 

int main()
{
    int choice;
    int No1,No2;
    char str1[50],str2[50],ch;
    
    while (choice != 0)
    {
        printf("\n1. String Length");
        printf("\n2. String Copy");
        printf("\n3. String Compare");
        printf("\n4. String Reverse");
        printf("\n5. Power");
        printf("\n6. Square Root");
        printf("\n7. GCD & LCM");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter string: ");
                scanf("%s", str1);
                printf("Length: %d\n", strlenX(str1));
                break;

            case 2:
                printf("Enter source: ");
                scanf("%s", str1);
                StrcpyX(str2, str1);
                printf("Copied string: %s\n", str2);
                break;

            case 3:
                printf("Enter string1: ");
                scanf("%s", str1);
                printf("Enter string2: ");
                scanf("%s", str2);
                printf("Result: %d\n", StrcmpX(str1, str2));
                break;

            case 4:
                printf("Enter string: ");
                scanf("%s", str1);
                strrevX(str1);
                printf("Reversed: %s\n", str1);
                break;

            case 5:
                printf("Enter base & exponent: ");
                scanf("%d %d", &No1, &No2);
                printf("Power: %.2lf\n", powX(No1, No2));
                break;

            case 6:
                printf("Enter number: ");
                scanf("%d", &No1);
                printf("Sqrt: %.3lf\n", SqrtX(No1));
                break;

            case 7:
                printf("Enter two numbers: ");
                scanf("%d %d", &No1, &No2);
                printf("GCD: %d\n", GCDX(No1, No2));
                printf("LCM: %d\n", LCMX(No2, No2));
                break;
        }
        
    }
    
    return 0;
}