//read a number and print ASCII char
#include <stdio.h>
int main(void)
{
    int a;
    char ch;
    printf("Input a ASCII number: \n");
    scanf("%d",&a);
    ch=a;
    printf("The corresponding ASCII character is \"%c\".", ch);
    return 0;
}