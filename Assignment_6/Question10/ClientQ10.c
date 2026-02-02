///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question10.c
//  Descreption : Design and implement a mini dynamic library 
//                inspection tool.
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

/*
The program should:
• Accept shared library path and symbol name as command-line arguments
• Load the library using dlopen()
• Check whether the given symbol exists using dlsym()
• Display symbol address if found
• Display appropriate error message otherwise
*/

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{   
    void *handle = NULL;
    void *fp = NULL;
    char *error = NULL;

    handle = dlopen(argv[1],RTLD_LAZY);
    if(handle == NULL)
    {
        printf("%s\n",dlerror());
        return -1;
    }

    fp = dlsym(handle,argv[2]);

    error = dlerror();
    if(error != NULL)
    {
        printf("Symbol not found :%s\n",argv[2]);
        printf("%s\n",error);
        dlclose(handle);
        return -1;
    }

    printf("Symbol Found : %s\n",argv[2]);
    printf("Symbol Address: %p\n",fp);

    dlclose(handle);

    return 0;
}

// gcc ClientQ7.c -o ClientQ7 -ldl 


//    This use only when we call dlopen/dclose
// gcc ClientQ7.c -L. -lServerQ7 -o ClientQ7
// LD_LIBRARY_PATH=. ./ClientQ7
