#include <stdio.h>
#include "helper.h"

int main()
{
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    int result = add(x, y);

    printf("Sum = %d\n", result);

    return 0;
}