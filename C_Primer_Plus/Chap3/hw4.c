#include <stdio.h>
int main(void)
{
    float a;
    printf("Input a float number: \n");
    scanf("%f",&a);
    printf("Decimal is %f\n",a);
    printf("Exponential is %e\n",a);
    printf("No16 is %p\n",a);

    return 0;
}