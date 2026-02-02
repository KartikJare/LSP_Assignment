///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question3.c
//  Descreption : Create a shared library that contains arithmetic
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

int Multiplication(int A,int B)
{
    int Ans = 0;
    Ans = A * B;
    return Ans;
}

int Division(int A,int B)
{
    int Ans = 0;
    Ans = A / B;
    if(Ans == 0)
    {
        return -1;
    }
    return Ans;
}

// gcc -fPIC -shared -o libClient1.so Client1.c