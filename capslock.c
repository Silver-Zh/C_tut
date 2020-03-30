#include <stdio.h>

int main() {
    char i,o;
    char *w;

    printf("Print a letter: ");
    scanf("%c", &i);

    if (65 <= i && i <= 90)
    {
        o = i + 32;
        printf("%c\n", o);
    }
    else if (97 <= i && i <= 122)
    {
        o = i - 32;
        printf("%c\n", o);
    }
    else
    {
        w = "invalid";
        printf("%s\n", w);
    }

    return 0;
}