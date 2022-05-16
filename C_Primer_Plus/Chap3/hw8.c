#include <stdio.h>
int main(void)
{
    float cup;
    printf("Input cup: \n");
    scanf("%f",&cup);
    printf("Pint: %f\n",cup/2);
    printf("Ounce: %f\n",cup*8);
    printf("Big Cup: %f\n",cup*16);
    printf("Teaspoon: %f\n",cup*48);

    return 0;
}