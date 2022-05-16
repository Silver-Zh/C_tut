# C Primer Plus

[toc]

## Chap 2 概述

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

## Chap 3 数据和C

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

#### int类型

声明和赋值int：

```c
int erns;
int hogs, cows, goats;

cows = 112;
```

初始化int可以通过赋值变量或者直接在声明中完成：

```c
int hogs = 21;
int cos = 32, goats = 14;
int dogs, cats =94; /*valid but terrible*/
```

最后一行中仅初始化了cats，没有初始化dogs。但容易误认为两个都被初始化了，因此最好避免把初始化和未初始化的变量放在同一条声明中。

<img src="https://raw.githubusercontent.com/qihaozhuo/imgBed/main/PicGo/202201091823930.png" alt="image-20220109182348830" style="zoom:67%;" />

打印时用%d指定打印整数的位置。

其他整数类型：

+ short int，有符号类型。
+ long int，有符号类型。
+ long long int或long long，有符号类型。
+ unsigned int或unsigned只用于非负值的场合，16位unsigned int取值范围0~65535，而非-32756~32767。
+ C90添加了unsigned  long int、unsigned long、unsigned int、unsigned short。
+ C99添加了unsigned long long int和unsigned long long。
+ 任何有符号类型前添加signed可以强调使用有符号。short、short int、signed short、signed short int都表示同一种类型。

现在PC上常见的设置为long long占64位，long占32位，short占16位，int占16位或32位。

对于常数，当超出int范围时编译器会将其视为long int，如果超出long范围，则视为unsigned long，再超出则视为long long或者unsigned long long。如果要将一个较小的常量作为long类型，可以在值得末尾加l或者L，比如7L，后缀l比较有误解性，L更好。类似地，020L和0x10L将八进制和十六进制作为long储存。同样地，5ull、10LLU、6LLU或9Ull。

打印整数类型时，%u表示unsigned，%l表示long类型。x和o前面可以用l前缀，%lx表示以十六进制打印long类型整数，%lo表示以八进制打印long。

#### char类型

通过编码，用特定的整数表示特定的字符。标准ASCII码的范围是0~127，只需要7位二进制数。通常char类型定义为8位的存储单元，容纳ASCII绰绰有余，扩展ASCII码也在8位表示范围之内。一般而言，C语言会保证char类型足够大以存储实现C语言的系统的基本字符集。

声明赋值和初始化char：

```c
char response;
char itable, latan;
char grade = 'A';/*correct*/

grade = 'T';/*正确赋值*/
grade = T;/*T是一个变量*/
grade = "T";/*"T"是一个字符串*/
```

 `char grade = 65` 在ASCII是和`char grade = 'A'` 等同的，但前者并不是很好的选择，因为移植到非ASCII编码时会出现问题，因此最好使用字符常量而不是数字代码值给char赋值。奇怪的是，C语言将字符常量视为int类型而非char类型。例如，在int为32位、char为8位的ASCII系统中，`char grade = 'B';` B对应的数值66本来储存在32位的存储单元中，现在却可以储存在8位的存储单元中（grade）。在这种情况下，可以定义一个字符常量'FATE'，即把4个独立的8位ASCII码储存在一个32位存储单元中，如果把这样的字符常量赋给char类型变量grade，只有最后8位有效。因此，grade的值是'E'。

打印时用%c指定打印char的位置。

非打印字符：

单引号只适用于字符、数字和标点符号，部分ASCII是无法直接打印出来的。例如一些代表行为的字符，如退格、换行、终端响铃或蜂鸣。C语言提供了3种方法表示。

1. 使用ASCII码，蜂鸣字符的ASCII值是7。`char beep = 7`

2. 使用转义序列。把转义序列赋给字符变量时必须用单引号将其括起来。`char nerf = '\n'`

   | 转义序列 | 含义                                                 |
   | -------- | ---------------------------------------------------- |
   | \a       | 警报（ANSI C）                                       |
   | \b       | 退格                                                 |
   | \f       | 换页                                                 |
   | \n       | 换行                                                 |
   | \r       | 回车                                                 |
   | \t       | 水平制表符                                           |
   | \v       | 垂直制表符                                           |
   | \\\      | 反斜杠（\）                                          |
   | \\'      | 单引号                                               |
   | \\"      | 双引号                                               |
   | \?       | 问号                                                 |
   | \0oo     | 八进制值（oo必须是有效的八进制数，每个o都是0~7）     |
   | \xhh     | 十六进制值（hh必须是有效的十六进制数，每个h都是0~f） |

   要打印Gramps sez, "a \ is a blackslash."

   `printf("Gramps sez, \"a \\ is a blackslash.\"\n")`

3. 使用十六进制形式表示字符常量，即用反斜杠后面跟一个x或者X再加上1~3位十六进制数。例如，Ctrl+P字符的ASCII十六进制码时10（相当于十进制的16），可表示为'\x10'或'\X10'。

   | 类型               | 十六进制 | 八进制  | 十进制 |
   | ------------------ | -------- | ------- | ------ |
   | char               | \0x41    | \0101   | N.A.   |
   | int                | 0x41     | 0101    | 65     |
   | unsigned int       | 0x41u    | 0101u   | 65u    |
   | long               | 0x41L    | 0101L   | 65L    |
   | unsigned long      | 0x41UL   | 0101UL  | 65UL   |
   | long long          | 0x41LL   | 0101LL  | 65LL   |
   | unsigned long long | 0x41ULL  | 0101ULL | 65ULL  |

char有符号还是无符号取决于编译器，因此可以用signed char和unsigned char规避歧义。这在用char处理小整数时很有用。

#### _Bool类型

C99添加了_Bool类型用于表示布尔值，即逻辑值true和false。因为C语言用1表示true，0表示false，所以\_Bool类型实际上也是一种整数类型。但原则上仅占用1位存储空间。

#### 可移植类型/精确宽度整数类型

stdint.h和inttypes.h

#### 浮点数类型

C语言中浮点数类型有float、double和long double，代表单精度、双精度和更高精度。它们与FORTRAN和Pascal中的real类型一致。

声明浮点数：

```c
float noah, jonah;
double trouble;
float planck = 6.63e-34;
long double gnp;
```

浮点型常量：-1.56E+12	2.87e-3	3.14159	.2	4e16	.8E-5	100.

但不要在浮点型常量中间加空格。

默认情况下，编译器假定浮点型常量是double类型的精度。假设some是float类型的变量，`some = 4.0 * 2.0; ` 通常4.0和2.0被储存为64位的double类型，使用双精度进行乘法运算，然后将乘积再截断成float类型。这样做虽然精度更高，但会减慢程序的运行速度。

在浮点数后边加上f或F的口追可以覆盖默认设置，如2.3f和9.11E9F。使用l或L后缀使其成为long double类型，如54.3l和4.32L。同样，更建议用L后缀。

C99添加了十六进制表示浮点型常量的格式，在十六进制数前加上0x或0X的十六进制前缀，用p和P分别代替e和E，用2的幂代替10的幂。如0xa.1fp10，十六进制a等于十进制10，.lf是1/16加上15/256（十六进制f等于十进制5），p10是$2^{10}$即1024。0xa.lfp10表示的值是(10+1/16+15/256)x1024，即十进制10364.0。

用%f打印十进制计数法的float和double型，用%e打印指数计数法的浮点数。如果系统支持十六进制的浮点数，可以用a和A分别代替e和E。打印long double时使用%Lf、%Le或%La。

#### 浮点数的上溢和下溢

浮点数上溢时在过去是未定义的，但现在C语言规定，会给变量赋一个表示无穷大的特定值，`printf`时显示该值为`inf` 或`infinity`，或者具有无穷含义的其他内容。

浮点数以指数和尾数部分储存。假设一个浮点数类型能用全部精度表示的最小数字，将其除以2。通常，这个操作会减小指数部分，但是在假设的情况中，指数已经是最小值了。所以计算机只好把尾数部分的位向右移，空出第1个二进制位，并丢弃最后一个二进制位，虽然得到了结果，但是在计算过程中损失了原末尾有效位上的数字。这种情况就叫下溢。C语言把损失了类型全精度的浮点值为低于正常的（subnormal）浮点值。因此，把最小的正浮点数除以2将得到一个低于正常的值。如果除以一个非常大的值，会导致所有的位都为0。现在，C库已提供了用于检查计算是否会产生低于正常值的函数。

还有另一个特殊的浮点值`NaN`（not a number的缩写）。例如给asin()函数传递一个值，该函数将返回一个角度，该角度的正弦就是传入函数的值。但是正弦值不能大于1，因此如果传入的参数大于1，该函数的行为是未定义的。此时该函数将返回`NaN`值，`print`将其显示为`nan`、`NaN`或其他类似的内容。

#### 复数和虚数类型

C99支持复数类型和虚数类型，但有所保留。C11标准把整个复数软件包都作为可选项。C语言有三种复数类型：

+ float_Complex
+ double_Complex
+ long double_Complex

例如，float_Complex应包括两个float类型的值，分别表示实部和虚部。类似地，C语言的三种虚数类型：

+ float_Imaginary
+ double_Imaginary
+ long double_Imaginary

C语言标准没有直接采用complex作为类型关键字而是使用\_Complex，通过添加一个头文件，在该头文件中把complex定义为\_Complex。这是考虑到直接换用complex会导致很多人的已有代码失效。

#### 其他类型

C语言没有字符串类型，但也能很好地处理字符串。C语言还有一些从基本类型衍生出来的其他类型，包括数组、指针、结构和联合。

#### 小结

+ 基本数据类型由11个关键字组成：int、long、short、unsigned、cahr、float、double、signed、\_Bool、\_Complex、\_Imaginary
+ 有符号整型可用于表示正整数和负整数：
  + int：系统给定的基本整数类型，C语言规定int类型不小于16位。
  + short/short int：最大的short类型整数小于或等于最大的int类型整数。C语言规定short类型至少占16位。
  + long/long int：该类型可表示的整数大于或等于最大的int类型整数，C语言规定long类型至少占32位。
  + long long/long long int：该类型可表示的整数大于或等于最大的long类型整数，long long类型至少占64位。
  + 一般而言，long类型占用内存比short类型大，int类型的宽度要么和long相同，要么和short相同。
+ 无符号整型只能用于表示零和正整数，因此无符号整型可表示的正整数比有符号整型大。在整型类型前加上关键字unsigned声明其为无符号整型：unsigned int、unsigned long、unsigned short。单独的unsigned相当于unsigned int。
+ 可打印出来的符号都是字符。根据定义， cahr类型表示一个字符要占用1字节内存。需要时可以在char前边加上关键字signed或unsigned来指明具体使用类型。
+ 布尔值类型\_Bool表示true和false。C语言用1表示true，0表示false。是无符号int类型。
+ 实浮点类型可以表示正浮点数和负浮点数：
  + float：系统的基本浮点类型，可精确表示至少6位有效数字。
  + double：储存浮点数的范围更大，能表示比float更多的有效数字，至少10位。
  + long double：储存范围更大。
+ 复数和虚数浮点数：float_Complex、double_Complex、long double_Complex、float_Imaginary、double_Imaginary、long double_Imaginary
+ 声明简单变量：
  + 类型说明符 变量名：int erest; 
  + 多个说明符 变量名：unsigned short cash;
  + 同时声明相同类型的多个变量，用逗号分隔变量名：char ch, init, ans;
  + 声明的同时初始化变量：float mass =  6.0E24;

## Chap 4 字符串和格式化输入/输出

### 字符串













