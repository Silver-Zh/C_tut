#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    double result;

    printf("Input an interger");
    scanf("%d", &i);

    result = pow(i, 5);
    printf("result %.2f\n", result);

    return 0;
}