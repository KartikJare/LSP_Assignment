///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question6.c
//  Descreption : To demonstrate dynamic library search path 
//                resolution in Linux.
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

#include<stdio.h>

void Display();

int main()
{
    Display();

    return 0;
}

/*
    1] gcc -fPIC -shared -o libMyLibraryQ6.so MyLibraryQ6.c.
    3] whoami -> to know the user name 
    4] mkdir /home/kartik-ganesh-jare/Mylibs
    5] mv libMyLibraryQ6.so /home/kartik-ganesh-jare/Mylibs -> to move the so to the location
    6] gcc ClientQ6.c -L/home/kartik-ganesh-jare/Mylibs -lMyLibraryQ6 -o Client -> -L is used only at compile time, not runtime.
            lmylibrary → linker searches for libmylibrary.so
    7] Without the LD_LIBRARY_PATH we get error
    8] export LD_LIBRARY_PATH=//home/kartik-ganesh-jare/Mylibs -> LD_LIBRARY_PATH temporarily adds /home/user/mylibs to the runtime search path
    9] ./Client -> code will give the output
*/