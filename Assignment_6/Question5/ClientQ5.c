///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question5.c
//  Descreption : Difference between RTLD_LAZY and RTLD_NOW 
//                flags used with dlopen().
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

/*
    A program that loads the same shared library twice:
    • Once using RTLD_LAZY
    • Once using RTLD_NOW
*/
#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;

    int (*fp)(int , int);

    char *error = NULL;

    int iRet = 0;

    printf("Using RTLD_LAZY\n");

    handle = dlopen("./libServerQ5.so",RTLD_LAZY);
    
    if(handle == NULL)
    {
        printf("Error : %s\n",dlerror());
        return -1;
    }

    printf("Library gets loaded Using RTLD_LAZY\n");

    fp = (int(*)(int,int))dlsym(handle,"Addition");
    
    error = dlerror();
    if(error != NULL)
    {
        printf("%s\n",error);
        dlclose(handle);

        return -1;
    }

    iRet = fp(11,10);

    printf("Addition is : %d\n",iRet);
    
    printf("-------------------------\n");
    
    printf("Using RTLD_NOW\n");

    handle = dlopen("./libServerQ5.so",RTLD_NOW);

    if(handle == NULL)
    {
        printf("Error : %s\n",dlerror());
        return -1;
    }

    printf("Library gets loaded Using RTLD_NOW\n");
    
    fp = (int(*)(int,int))dlsym(handle,"Substraction");

    error = dlerror();
    if(error != NULL)                                             
    {
        printf("%s\n",error);
        dlclose(handle);

        return -1;
    }

    iRet = fp(11,10);

    printf("Substraction is : %d\n",iRet);

    dlclose(handle);

    return 0;
}

// gcc Server1.c -o Server1 -ldl