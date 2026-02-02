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

int Addition(int A,int B)
{
    int Ans = 0;
    Ans = A + B;
    return Ans;
}

// gcc -fPIC -shared -o libClient1.so Client1.c