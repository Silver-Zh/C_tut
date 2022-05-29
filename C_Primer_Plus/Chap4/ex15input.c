//何时使用&
#include <stdio.h>
int main(void)
{
    int age;
    float assets;
    char pet[30];

    printf("Enter your age, assets, and favorite pet.\n");
    scanf("%d %f", &age, &assets);//使用&
    scanf("%s", pet);//字符数组不用&
    printf("%d $%.2f %s\n", age, assets, pet);

    return 0;
}