///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question2.c
//  Descreption : To demonstrate runtime dynamic linking in Linux
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