///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question3.c
//  Descreption : Create a shared library that contains arithmetic
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

/*
• Addition
• Substraction
• Multiplication
• Division
*/

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    void *handle = NULL;

    int (*fp)(int , int);

    char * error = NULL;

    int iRet = 0;

    int Value1 = 0,Value2 = 0;

    int Choice = 0;  

    // To load the shared Library
    handle = dlopen("./libServerQ3.so",RTLD_LAZY);
    
    // if dlopen fail
    if(handle == NULL)
    {
        printf("Error : %s\n",dlerror());
        return -1;
    }

    printf("Library gets loaded succesfully\n");
    
    printf("\n1. Addition");
    printf("\n2. Substraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\nEnter your choice: ");
    scanf("%d", &Choice);

    printf("Enter Frist Number: ");
    scanf("%d",&Value1);

    printf("Enter Second Number: ");
    scanf("%d",&Value2);

    if(Choice == 1)
    {
        fp = (int(*)(int,int))dlsym(handle,"Addition");
    }
    else if(Choice == 2)
    {
        fp = (int(*)(int,int))dlsym(handle,"Substraction");
    }
    else if(Choice == 3)
    {
        fp = (int(*)(int,int))dlsym(handle,"Multiplication");
    }
    else if(Choice == 4)
    {
        fp = (int(*)(int,int))dlsym(handle,"Division");
    }
    else
    {
        printf("Invalid Input\n");
        dlclose(handle);
        return -1;
    }

    // if dlsym fail
    error = dlerror();
    if(error != NULL)                                             
    {
        printf("Unable to get address of function\n");
        printf("%s",error);
        dlclose(handle);

        return -1;
    }

    iRet = fp(Value1,Value2);

    printf("Result is : %d\n",iRet);
   
    // Close the shared library
    dlclose(handle);

    return 0;
}

// gcc Server1.c -o Server1 -ldl