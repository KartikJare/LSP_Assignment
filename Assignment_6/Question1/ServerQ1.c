///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question1.c
//  Descreption : create a shared library (.so) that contains two functions:
//                • Addition(int, int)
//                • Substraction(int, int)
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

int Substraction(int A,int B)
{
    int Ans = 0;
    Ans = A -B;
    return Ans;
}

// gcc -fPIC -shared -o libClient1.so Client1.c