#include <stdio.h>

int main()
{
    char name[256];
    float cm, kg, in, lb;

    printf("Name: ");
    scanf("%s", &name);

    printf("height: ");
    scanf("%f", &cm);

    printf("weight: ");
    scanf("%f", &kg);

    in = cm / 2.54;
    lb = kg / 0.453;

    printf("height %.2f cm for %.2f in\n", cm, in);
    printf("weight %.2f kg for %.2f lb\n", kg, lb);

    return 0;
}