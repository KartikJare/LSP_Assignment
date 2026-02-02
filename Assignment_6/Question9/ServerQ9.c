///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question9.c
//  Descreption : A program to demonstrate the use of function 
//                pointers with dlsym().
//  Author      : Kartik Ganesh Jare
//  Date        : 29/1/26
//  
///////////////////////////////////////////////////////////

int Add(int A,int B)
{
    int Ans = 0;

    Ans = A + B;

    return Ans;
}

int Sub(int A,int B)
{
    int Ans = 0;

    Ans = A - B;

    return Ans;
}

int Mul(int A,int B)
{
    int Ans = 0;

    Ans = A * B;

    return Ans;
}




// gcc -fPIC -shared -o libServerQ7.so ServerQ7.c