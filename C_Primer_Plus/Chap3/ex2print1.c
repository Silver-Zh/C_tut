//printf的一些特性
#include <stdio.h>
int main(void)
{
    int ten = 10;
    int two = 2;

    printf("Doing it right: ");
    printf("%d minus %d is %d\n", ten, 2, ten - two);
    printf("Doing iit wrong: ");
    printf("%d minus %d is %d\n", ten);//missing 2 parameters

    return 0;
}