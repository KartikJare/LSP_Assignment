///////////////////////////////////////////////////////////
//
//  File name   : Assigment6Question10.c
//  Descreption : Design and implement a mini dynamic library 
//                inspection tool.
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

// gcc -fPIC -shared -o libServerQ7.so ServerQ7.c