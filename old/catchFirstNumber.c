#include <stdio.h>
#include <math.h>

int main()
{
    int ch;
    //long long temp;
    long long num = 0;
    int overflow = 0;

    const int max_int = pow(2, sizeof(int) * 8) / 2 - 1;
    const int min_int = pow(2, sizeof(int) * 8) / 2 * (-1);

    printf("Type a string: \n");


    do {
        ch = getchar();

        if(ch >= '0' && ch <= '9')//如果有数字
        {
            num = num * 10 + (ch - '0');//ch本身的值并非个位数
            if (num > max_int || num < min_int)
            {
                overflow = 1;
                break;
            }
        }
        else//如果没有数字
        {
            if (num)//如果已有数字则中断
            {
                break;
            }
        }
    
    }
    while (ch != '\n');

    if (overflow)
    {
        printf("The number is beyond the limitation!\n");
    }
    else
    {
        if(!num)
        {
            printf("No number found!\n");
        }
        else
        {
            printf("The First number string is: %lld\n", num);
        }
    }
    
    return 0;
}