#include <stdio.h>
#include "math.h"

int main()
{
    int a = 10, b = 5;

    printf("Add = %d\n", add(a, b));
    printf("Sub = %d\n", sub(a, b));
    printf("Mul = %d\n", mul(a, b));
    printf("Div = %d\n", divide(a, b));

    return 0;
}