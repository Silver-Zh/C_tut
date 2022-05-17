/*十进制转八进制、十六进制*/
#include <stdio.h>
int main(void)
{
    int x = 100;

    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x , x , x);/*add 0 or 0x*/

    return 0;
}
