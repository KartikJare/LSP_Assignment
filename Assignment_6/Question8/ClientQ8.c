///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question8.c
//  Descreption : A C program to dynamically load a shared 
//                library that performs string operations
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

/*
• Count number of lowercase letters
• Count number of uppercase letters
• Count number of digits
*/
#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{   
    void *handle = NULL;
    char str[100];

    int(*fpLower)(char *);
    int(*fpUpper)(char *);
    int(*fpDigit)(char *);

    printf("Enter a string : ");
    scanf("%[^\n]",str);

    handle = dlopen("./libServerQ8.so",RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error : %s\n",dlerror());
        return -1;
    }

    fpLower = (int(*)(char*))dlsym(handle,"CountLower");
    fpUpper = (int(*)(char*))dlsym(handle,"CountUpper");
    fpDigit = (int(*)(char*))dlsym(handle,"CountDigit");

    if(dlerror() != NULL)
    {
        printf("Error : %s\n");
            dlclose(handle);
            return -1;
    }

    printf("Lowercase letters : %d\n", fpLower(str));
    printf("Uppercase letters : %d\n", fpUpper(str));
    printf("Digits            : %d\n", fpDigit(str));

    dlclose(handle);

    return 0;
}

// gcc ClientQ7.c -o ClientQ7 -ldl 


//    This use only when we call dlopen/dclose
// gcc ClientQ7.c -L. -lServerQ7 -o ClientQ7
// LD_LIBRARY_PATH=. ./ClientQ7
