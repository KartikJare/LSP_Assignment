///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question5.c
//  Descreption : Difference between RTLD_LAZY and RTLD_NOW 
//                flags used with dlopen().
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
    Ans = A - B;
    return Ans;
}

// gcc -fPIC -shared -o libClient1.so Client1.c