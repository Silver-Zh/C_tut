#include <stdio.h>
int main(void)
{
    int y2s=3.156e7;
    int a;
    printf("Input your age: \n");
    scanf("%d",&a);
    printf("Corresponding seconds are %d", a*y2s);

    return 0;
}