//参数错误的情况
#include <stdio.h>
int main(void)
{
    int n = 4;
    int m = 5;
    float f = 7.0f;
    float g = 8.0f;

    printf("%d\n", n, m);//too few parameters
    printf("%d %d %d \n", n);//too many parameters
    printf("%d %d\n", f, g);//wrong types

    return 0;
}