#include <stdio.h>

int main()
{
    int ch;

    printf("Type an English string: \n");

    while ((ch = getchar()) != '\n')
    {
        if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - 'A' + 'a';
            putchar(ch);
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
            putchar(ch);
        }
    }

    putchar('\n');
    return 0;
}