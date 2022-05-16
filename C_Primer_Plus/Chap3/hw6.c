#include <stdio.h>
int main(void)
{
    float w;
    float n;
    printf("Input weight of water: \n");
    scanf("%f",&w);
    n=w*950/3E-23;
    printf("Estimate number of water molecules are %f", n);

    return 0;
}