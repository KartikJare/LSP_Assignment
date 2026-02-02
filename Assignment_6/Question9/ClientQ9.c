///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question9.c
//  Descreption : A program to demonstrate the use of function 
//                pointers with dlsym().
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

/*
• Store addresses of multiple dynamically loaded functions in an array of function pointers.
• Invoke functions using this array.
• Display function addresses along with results.
*/
#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{   
    void *handle = NULL;

    int (*fp[3])(int , int);

    char *Arr[] = {"Add","Sub","Mul"};
    char *error = NULL;

    int i = 0; 
    int iRet = 0;

    handle = dlopen("./libServerQ9.so",RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : %s\n",dlerror());
        return -1;
    }

    for(i = 0;i < 3;i++)
    {

       fp[i] = (int(*)(int,int))dlsym(handle,Arr[i]);

       error = dlerror();

        if(error != NULL)
        {
            printf("%s\n",error);
            dlclose(handle);
            return -1;
        }
    }

    for(i = 0;i< 3;i++)
    {
        printf("Function Name :  %s\n",Arr[i]);
        printf("Address is : %p\n",fp[i]);

        iRet = fp[i](10,11);
        printf("Result is : %d\n",iRet);
    }

    dlclose(handle);

    return 0;
}

// gcc ClientQ7.c -o ClientQ7 -ldl 


//    This use only when we call dlopen/dclose
// gcc ClientQ7.c -L. -lServerQ7 -o ClientQ7
// LD_LIBRARY_PATH=. ./ClientQ7
