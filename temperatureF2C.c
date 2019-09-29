#include <stdio.h>

int main()
{
    float F,C;

    printf("Fahrenheit: ");
    scanf("%f", &F);

    C = (F - 32) * 5 / 9;

    printf("Celsius: %.2f\n", C);

    return 0;
}