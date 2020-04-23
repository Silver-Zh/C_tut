#include <stdio.h>

int main(){
    int count = 0;
    int ch;

    printf("Type an English string: \n");

    while ((ch = getchar()) != '\n')
    {
        if(ch >= 'A' && ch <= 'Z')
        {
            count = count + 1;  
        }
        
    }

    printf("Total capital letters = %d\n", count);

    return 0;
}