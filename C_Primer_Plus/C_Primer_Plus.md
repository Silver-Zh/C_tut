# C Primer Plus

[toc]

## Chap 2

C程序解剖：

<img src="https://raw.githubusercontent.com/qihaozhuo/imgBed/main/PicGo/202201030404141.png" alt="image-20220103040437826" style="zoom:67%;" />

`int main(void)` C程序一定从`main()` 函数开始执行，`int` 是函数返回类型，`void` 表示没有传入参数。

### 变量命名

+ 对于C99和C11，允许63个字符长度
+ 小写字母、大写字母、数字和下划线
+ 区分大小写
+ 第一个字符必须是字符或下划线，不能是数字

关键字和保留标识符：

| C11      |          |          |                |
| :------- | -------- | -------- | -------------- |
| auto     | extern   | short    | while          |
| break    | float    | signed   | \_Alignas      |
| case     | for      | sizeof   | \_Alignof      |
| char     | goto     | static   | \_Atomic       |
| const    | if       | struct   | \_Bool         |
| continue | inline   | switch   | _Complex       |
| default  | int      | typedef  | \_Generic      |
| do       | long     | union    | \_Imaginary    |
| double   | register | unsigned | \_Noreturrn    |
| else     | restrict | void     | _Static_assert |
| enum     | return   | volatile | \_Thread_local |

关键字使用不当时编译器会视为语法错误。

### 自定义函数

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

## Chap 3

### 数据类型

数据类型关键字：

| K&R      | C90    | C99         |
| -------- | ------ | ----------- |
| int      | signed | \_Bool      |
| long     | void   | \_Complex   |
| short    |        | \_Imaginary |
| unsigned |        |             |
| char     |        |             |
| float    |        |             |
| double   |        |             |

在C语言中，int表示基本整数类型。long, short，unsigned 和C90新增的signed用于提供基本整数类型的变式，例如unsigned short int和long long int。char关键字用于指定字母和其他字符（如#、\$、%和*），另外char类型也可以表示较小的整数。float double和1ong double表示带小数点的浮点数。\_Boo1类型表示布尔值（true或false），\_Complex和 \_Imaginary分别表示复数和虚数。

+ 位bit，可以储存0或1。位是计算机内存的基本构建块。
+ 字节byte，一般1byte = 8bit。$2^8=256$，因此通过二进制编码可以表示0~255的整数或一组字符。
+ 字word是设计计算机时给定的自然存储单位，

根据计算机的存储方式可以分为整数类型和浮点数类型。

#### 整数

没有小数部分，用二进制数字存储整数。整数7用二进制写成111，用8bit存储时需要将前5位设成0。

<img src="https://raw.githubusercontent.com/qihaozhuo/imgBed/main/PicGo/202201080210695.png" alt="image-20220108021046620" style="zoom:67%;" />

#### 浮点数

在一个值后添加小数点就使其成为浮点数，所以7是整数，7.00是浮点数。在十进制下，$7.0=0.7E1$，0.7是小数部分，1是指数部分。计算机内部使用二进制和2的幂进行储存，而不是10的幂。

<img src="https://raw.githubusercontent.com/qihaozhuo/imgBed/main/PicGo/202201080216335.png" alt="image-20220108021613286" style="zoom:67%;" />

+ 整数没有小数部分，浮点数有。
+ 浮点数可以表示的范围更大。
+ 对于一些算术运算比如两个很大的数加减，浮点数损失更多精度。
+ 在任何区间内都存在无穷多实数因此计算机的浮点数并不能表示区间内所有的值，浮点数通常只是实际值的近似值。7.0可能被存储位浮点值6.99999。
+ 在过去，浮点运算慢于整数运算，现在CPU中包含了浮点处理器，缩小了差距。

