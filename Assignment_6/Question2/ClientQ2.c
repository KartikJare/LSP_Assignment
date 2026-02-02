///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question2.c
//  Descreption : To demonstrate runtime dynamic linking in Linux
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

/*
Your program should:
• Load a shared library using dlopen()
• Fetch function addresses using dlsym()
• Handle errors using dlerror()
• Release the library using dlclose()
*/

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;

    int (*fp)(int , int);

    int iRet = 0;

    // To load the shared Library
    handle = dlopen("./libServerQ2.so",RTLD_LAZY);
    
    // if dlopen fail
    if(handle == NULL)
    {
        printf("Error : %s\n",dlerror());
        return -1;
    }

    printf("Library gets loaded succesfully\n");

    // To Fetch function address
    fp = (int(*)(int,int))dlsym(handle,"Addition");
    
    // if dlsym fail
    if(fp == NULL)
    {
        printf("Unable to get address of function\n");
        dlclose(handle);

        return -1;
    }

    // Call the Function
    iRet = fp(11,10);

    printf("Addition is : %d\n",iRet);

    // To Fetch function address
    
    fp = (int(*)(int,int))dlsym(handle,"Substraction");

    // if dlsym fail
    if(fp == NULL)                                             
    {
        printf("Unable to get address of function\n");
        dlclose(handle);

        return -1;
    }

    // Call the Function
    iRet = fp(11,10);

    printf("Substraction is : %d\n",iRet);
   
    // Close the shared library
    dlclose(handle);

    return 0;
}

// gcc Server1.c -o Server1 -ldl