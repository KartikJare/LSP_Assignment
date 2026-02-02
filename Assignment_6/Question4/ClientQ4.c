///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question4.c
//  Descreption : a program to demonstrate what happens when:
//                • A valid shared library is loaded
//                • An invalid or missing function name is passed to dlsym()
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;

    int (*fp)(int , int);

    char *error = NULL;

    int iRet = 0;

    // To load the shared Library
    handle = dlopen("./libServerQ4.so",RTLD_LAZY);
    
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
    error = dlerror();
    if(error != NULL)
    {
        printf("%s\n",error);
        dlclose(handle);

        return -1;
    }

    // Call the Function
    iRet = fp(11,10);

    printf("Addition is : %d\n",iRet);

    // To Fetch function address
    
    fp = (int(*)(int,int))dlsym(handle,"Substraction");

    // if dlsym fail
    error = dlerror();
    if(error != NULL)                                             
    {
        printf("%s\n",error);
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