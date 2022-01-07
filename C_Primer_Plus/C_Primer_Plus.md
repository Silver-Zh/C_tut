# C Primer Plus

[toc]

## 第二章

C程序解剖：

![image-20220103040437826](https://raw.githubusercontent.com/qihaozhuo/imgBed/main/PicGo/202201030404141.png)

`int main(void)` C程序一定从`main()` 函数开始执行，`int` 是函数返回类型，`void` 表示没有传入参数。

变量命名：

+ 对于C99和C11，允许63个字符长度
+ 小写字母、大写字母、数字和下划线
+ 区分大小写
+ 第一个字符必须是字符或下划线，不能是数字

自定义函数：

```C
//*two_func.c -- 一个文件中包含两个函数 */
#include <stdio.h>
void butler(void); /*ANSI/ISO C函数原型 */
int main(void)
{
    printf("I will summon the butler function.\n");
    butler();
    printf("Yes. Bring me some tea and writeable DVDs.\n");
    
    return 0;
}
void butler(void) /*函数定义开始*/
{
    printf("You rang, sir?\n");
}
```

`butler()` 函数出现了三次。第一次函数原型（prototype），告知编译器；第二次函数调用（function call）；第三次函数定义（function definition）。`void butler(void)` 第一个void表明函数没有返回值，第二个void表面函数不带参数。C语言中，函数也可以调用另一个函数。

## 第三章

