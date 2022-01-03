#include <stdio.h>

int main(){
    int count = 0;

    printf("Type an English string: \n");

    while (getchar() != '\n')
    {
        count = count + 1;
    }

    printf("Total letters = %d\n", count);

    return 0;
}