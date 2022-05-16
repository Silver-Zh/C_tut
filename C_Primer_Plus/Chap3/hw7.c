#include <stdio.h>
int main(void)
{
    float h;
    printf("Input height in inches: \n");
    scanf("%f",&h);
    printf("Height in centimeters is %f. \n",h*2.54);

    return 0;
}