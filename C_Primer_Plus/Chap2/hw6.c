#include <math.h>
#include <stdio.h>

int main(void)
{
    int toes;
    double ans;

    toes = 10;
    ans = pow(toes,2);
    printf("Original value is %d.\n", toes);
    printf("2 times is %d.\n", 2*toes);
    printf("Square is %f.\n", ans);
    return 0;
}