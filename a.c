#include <stdio.h>

int main()
{
    int ch;
    int num = 0;

    printf("Type a string: \n");


    do {
        ch = getchar();

        if(ch >= '0' && ch <= '9')//如果有数字
        {
            num = num * 10 + (ch - '0');//ch本身的值并非个位数
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

    printf("The First number string is: %d\n", num);
    return 0;
}