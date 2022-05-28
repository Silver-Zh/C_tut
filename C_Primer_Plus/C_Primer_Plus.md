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

#### 转换说明

+ %d打印整数int。
+ %ld打印long整数。
+ %lx以十六进制打印long整数。
+ %lo以八进制打印long整数。
+ %hd十进制打印short整数。
+ %ho八进制打印short整数。
+ %lu打印unsigned long。
+ %lld和%llu分别表示有符号和无符号。
+ %c打印char字符，%d打印char类型变量会输出对应整数值。
+ %f十进制打印float和double浮点数。
+ %e打印指数计数法的浮点数。
+ 如果系统支持十六进制浮点数，可以用a和A分别代替e和E。
+ %Lf，%Le或%La打印long double浮点数。

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

C语言没有专门用于储存字符串的变量类型，字符串都被储存再char类型的数组中。

![image-20220516131509584](https://raw.githubusercontent.com/qihaozhuo/imgBed/main/PicGo/image-20220516131509584.png)

图中数组末尾的字符\\0是空字符null character，C语言用其标记字符串的结束。空字符不是数字0，而是一个非打印字符，ASCII码值是0。C语言中字符串一定以空字符结束，这意味着数组的容量必须至少比待存储字符串中的字符数多1。

通过声明`char name[40]`创建了一个包含40个元素的数组，每个元素储存一个char类型的值。

````C
//使用不同类型的字符串
#include <stdio.h>
#define PRAISSE "You are an extraordinary being."
int main(void)
{
    char name[40];

    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISSE);
}
````

%s用于打印字符串，无需亲自把空字符\0放进字符串末尾，scanf在读取输入时已经完成了这项工作，也无需在define字符串常量时在末尾添加。**注意**scanf在遇到第一个空格、制表符或换行符时就会停止读取输入。

### strlen()函数

````c
//如果编译器不识别%zd，尝试换成%u或者%lu
#include <stdio.h>
#include <string.h>
#define PRAISE "You are an extraordinary being."
int main(void)
{
    char name[40];

    printf("What's your name? ");
    scanf("%s",name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %zd letters occupies %zd memory cells.\n", strlen(name), sizeof name);
    printf("The phrase of praise has %zd letters ", strlen(PRAISE));
    printf("and occupies %zd memory cells.\n", sizeof PRAISE);

    return 0;
}
````

如果使用ANSI C之前的编译器必须移除``#include <string.h>``，string.h头文件包含多个与字符串相关的函数原型，包括strlen()。一些ANSI之前的UNIX系统使用strings.h代替string,h，也包含了一些字符串函数的声明。

一般而言，C把函数库中相关的函数归为一类，并为每类韩叔叔提供一个头文件，例如printf()和scanf()都隶属标准输入和输出函数，使用stdio.h头文件。

sizeof运算符报告，name数组有40个存储单元，但是只有前一部分单元用来存储输入，所以strlen()的结果不一定是40。strlen()并未计入末尾的空字符。

对于PRAISE，strlen()得出的也是字符串中的字符数，包含空格和标点符号。sizeof则将空字符也计算在内。C99和C11专门为sizeof运算符的返回类型添加了%zd转换说明，这对于strlen()同样适用。对于早期的C，就还需要知道sizeof和strlen()返回的实际类型，通常是unsigned或者unsigned long。

另外还需要注意，sizeof后圆括号的使用取决于对象，对象是类型时圆括号必不可少，比如sizeof(char)以及sizeof(float)。对于特定的变量，可有可无，比如sizeof name，但建议任何情况下都使用圆括号。

### 常量和C预处理器

创建符号常量的方法之一就是声明一个变量并赋值，但程序可能会无意间改变它的值。C语言提供了一个更好的方案，C预处理器，``#define TAXRATE 0.015``。编译程序时，程序中所有的TAXRATE都会被替换成0.015，这一过程被成为编译时替换compile-time substitution。通常这样定义的常量也称为明示常量manifest constant。注意其中并没有=符号。末尾也不用加分号。用全大写表示符号常量是C语言一贯的传统，提高程序可读性。另外还有一种不常用的命名约定，即在名称前带c\_或k\_前缀来表示常量，如c\_level或k\_level。符号常量的命名规则与变量相同，可以使用大小写字母、数字和下划线字符，首字符不能为数字。

![image-20220517164104243](https://raw.githubusercontent.com/qihaozhuo/imgBed/main/PicGo/image-20220517164104243.png)

``#define``指令还可以定义字符和字符串常量，前者使用单引号，后者使用双引号：

+ ``#define BEEP '\a'``
+ ``#define TEA 'T'``
+ ``#define ESC '\033'``
+ ``#define OOPS "Now you have done it!"``

**注意**符号常量名后面的内容被用来替换符号常量，不要犯以下错误：

``#define TOES = 20``

这样的话替换TOES的会是=20，而不是20。

#### const限定符

C90标准新增了const关键字，用于限定一个变量为只读，注意const是**变量**而不是常量。

````c
const int MONTHS = 12;//MONTHS在程序中不可更改，值为12
````

这使得MONTHS成为只读值，也就是说可以在计算中使用MONTHS，可以打印MONTHS，但是不能更改MONTHS的值。const使用起来比#define更灵活，第12章将更多讨论const。

#### 明示常量

头文件limits.h和float.h分别提供了与整数类型和浮点类型**大小限制**相关的详细信息，每个头文件都定义了一系列供实现使用的明示常量。例如limits.h头文件包含一下代码：

````c
#define INT_MAX +32767
#define INT_MIN -32768
````

这些明示常量代表int类型克表示的最大值和最小值，如果系统使用32位的int，该头文件会为这些明示常量提供不同的值。如果在程序中包含limits.h头文件，就可编写以下代码：

````c
printf("Maximum int value on this system = %d\n", INT_MAX);
````

如果系统使用4字节的int，limits.h头文件就会提供符合4字节int的INT_MAX和INT_MIN。

limits.h中的一些明示常量：

| 明示常量   | 含义                           |
| ---------- | ------------------------------ |
| CHAR_BIT   | char类型的位数                 |
| CHAR_MAX   | char类型的最大值               |
| CHAR_MIN   | char类型的最小值               |
| SCHAR_MAX  | signed char类型的最大值        |
| SCHAR_MIN  | signed char类型的最小值        |
| UCHAR_MAX  | unsigned char类型的最大值      |
| SHRT_MAX   | short类型的最大值              |
| SHRT_MIN   | short类型的最小值              |
| USHRT_MAX  | unsigned short类型的最大值     |
| INT_MAX    | int类型的最大值                |
| INT_MIN    | int类型的最小值                |
| UINT_MAX   | unsigned int类型的最大值       |
| LONG_MAX   | long类型的最大值               |
| LONG_MIN   | long类型的最小值               |
| ULONG_MAX  | unsigned long类型的最大值      |
| LLONG_MAX  | long long类型的最大值          |
| LLONG_MIN  | long long类型的最小值          |
| ULLONG_MAX | unsigned long long类型的最大值 |

float.h中的一些明示常量，将FLT分别替换成DBL和LDBL就可分别表示double和long double类型对应的明示常量：

| 明示常量       | 含义                                              |
| -------------- | ------------------------------------------------- |
| FLT_MANT_DIG   | float类型的尾数位数                               |
| FLT_DIG        | float类型的最少有效数字位数（十进制）             |
| FLT_MIN_10_EXP | 带全部有效数字的float类型的最小负指数（以10为底） |
| FLT_MAX_10_EXP | float类型的最大正指数（以10为底）                 |
| FLT_MIN        | 保留全部精度的float类型最小正数                   |
| FLT_MAX        | float类型的最大正数                               |
| FLT_EPSILON    | 1.00和比1.00大的最小float类型值之间的差值         |

### printf()和scanf()

printf()和scanf()属于输入/输出函数，I/O函数。这些函数曾经并不是C语言定义的一部分，C90和C99标准规定了这些函数的标准版本。printf()是输出函数，scanf()是输入函数，但工作原理几乎相同，两个函数都是用格式字符串和参数列表。

#### printf()函数

请求printf()函数打印数据的指令要与待打印数据的类型相匹配，即**转换说明**conversion specification，它们制定了如何把数据转换成可显示的形式。ANSI C标准为printf()提供的转换说明：

| 转换说明 | 输出                                                         |
| -------- | ------------------------------------------------------------ |
| %a       | 浮点数、十六进制数和p计数法（C99/C11）                       |
| %A       | 浮点数、十六进制数和p计数法（C99/C11）                       |
| %c       | 单个字符                                                     |
| %d       | 有符号十进制书                                               |
| %e       | 浮点数，e计数法                                              |
| %E       | 浮点数，e计数法                                              |
| %f       | 浮点数，十进制计数法                                         |
| %g       | 根据值的不同，自动选择%f或%e。%e用于指数小于-4或这大于等于精度时 |
| %G       | 根据值的不同，自动选择%f或%E。%E用于指数小于-4或这大于等于精度时 |
| %i       | 有符号十进制整数，与%d相同                                   |
| %o       | 无符号八进制整数                                             |
| %p       | 指针                                                         |
| %s       | 字符串                                                       |
| %u       | 无符号十进制整数                                             |
| %x       | 无符号十六进制整数，使用十六进制数0f                         |
| %X       | 无符号十六进制整数，使用十六进制数0F                         |
| %%       | 打印一个百分号                                               |

在%和转换字符之间插入修饰符可修饰基本的转换说明，如果要插入多个字符，其书写顺序应与下表所列出的顺序相同。不是所有的组合都可行。部分修饰符是C99新增。

| printf()的修饰符 | 含义                                                         |
| ---------------- | ------------------------------------------------------------ |
| 标记             | 后表中描述了5种标记（-、+、空格、#和0），可以不使用标记或使用多个标记。示例："%-10d" |
| 数字             | 最小字段宽度。如果该字段不能容纳待打印的数字或字符串，系统会使用更宽的字段。示例："%4d" |
| .数字            | 精度。对于%e、%E和%f转换，表示小数点右边数字的位数；对于%g和%G转换，表示有效数字最大位数；对于%s转换，表示待打印字符的最大数量；对于整型转换，表示待打印数字的最小位数。如有必要，使用前导0来达到这个位数。只使用.表示其后跟随一个0，所以%f和号%.0f相同。示例："%5.2f"打印一个浮点数，字段宽度为5字符，其中小数点后有两位数字。 |
| h                | 和整型转换说明一起使用，表示short int或unsigned short int类型的值。示例："%hu"、"%hx"、"%6.4hd" |
| hh               | 和整型转换说明一起使用，表示signed char或unsigned char类型的值。示例："%hhu"、"%hhx"、"%6,4hhd" |
| j                | 和整型转换说明一起使用，表示intmax_t或uintmax_t类型的值。这些类型定义在stdint.h中。示例："%jd"、"%8jx" |
| l                | 和整型转换说明一起使用，表示long int或unsigned long int类型的值。示例："%1d"、"%81u" |
| ll               | 和整型转换说明一起使用，表示long long int或unsigned longlong int类型的值（C99) 。示例："%11d"、"%811u" |
| L                | 和浮点转换说明一起使用，表示long double类型的值。示例："%Ld"、"%10.4Le" |
| t                | 和整型转换说明一起使用，表示ptrdiff_t类型的值。ptrdiff_t是两个指针差值的类型（C99) 。示例："%td"、"%12ti" |
| z                | 和整型转换说明一起使用，表示s1zet类型的值。size t是sizeof返回的类型（C99) 。示例："%zd"、"%12zd" |

sizeof运算符以字节为单位返回类型或值的大小。这应该是某种形式的整数，但是标准只规定 了该值是无符号整数.在不同的实现中，它可以是unsigned int、unsigned long甚至是unsigned long long。因此，如果要用printf()函数显示sizeof表达式，根据不同系统，可能使用%u、%lu 或%llu。这意味着要查找你当前系统的用法，如果把程序移植到不同的系统还要进行修改。鉴于此， C提供了可移植性更好的类型。首先，stddef.h头文件（在包含stdio.h头文件时已包含其中）把 size_t定义成系统使用sizeof返回的类型，这被称为底层类型underlying type。其次，printf() 使用z修饰符表示打印相应的类型。同样，C还定义了ptrdiff_t类型和t修饰符来表示系统使用 的两个地址差值的底层有符号整数类型。

对于浮点类型，有用于double和long double类型的转换说明，却没有float类型的。这是因为在K&RC中，表达式或参数中的float类型值会被自动转换成double类型。一般而言，ANSI C不会把float自动转换成double。然而，为保护大量假设f1oat类型的参数被自动转换成double 的现有程序，printf()函数中所有float类型的参数（对未使用显式原型的所有C函数都有效）仍自动转换成double类型。因此，无论是K&RC还是ANSI C,都没有显示f1oat类型值专用的转换说明。

| printf()中的标记 | 含义                                                         |
| ---------------- | ------------------------------------------------------------ |
| -                | 待打印项左对齐。即，从字段的左侧开始打印该项项。示例："%-20s" |
| +                | 有符号值若为正，则在值前面显示加号：若为负，则在值前面显示减号。示例："%+6.2f" |
| 空格             | 有符号值若为正，则在值前面显示前导空格（不显示任何符号）；若为负，则在值前面显示减号。+标记覆盖一个空格。示例："%6.2f |
| #                | 把结果转换为另一种形式。如果是%o格式，则以0开始；知果是%x或%X格式，则以0x或0X开始；对于所有的浮点格式，#保证了即使后面没有任何数字，也打印一个小数点字符。对于%g和%G格式，#防止结果后面的0被删除。示例："%#o"、"%#8.0f"、"%+#10.3e" |
| 0                | 对于数值格式，用前导0代替空格填充字段宽度。对于整数格式，如果出现-标记或指定精度，则忽略该标记。 |

不同数据类型的实例代码见GitHub。

#### 转换说明的意义 

转换说明把以二进制格式储存在计算机中的值转换成一系列字符（字符串）以便于显示。例如，数字76在计算机内部的存储格式是二进制数01001100。%d转换说明将 其转换成字符7和6，并显示为76；%x转换说明把相同的值01001100转换成十六进制记数法4c；%c 转换说明把01001100转换成字符L。转换conversion可能会让人误认为原始值被转替换成转换后的值。实际上，转换说明是翻译说明，%d的意思是把给定的值翻译成十进制整数文本并打印出来。

##### 转换不匹配

之前已经强调过转换说明应与待打印值得类型相匹配。通常会有多种选择。例如，如果要打印一个int类型的值，可以使用%d、%x或%o。这些转换说明都可用于打印int类型的值，其区别在于它们的表示形式不同。类似地，打印double类型的值时，可使用%f、%e或%g。转换说明不匹配时就会出现不正确的输出，见示例程序。

````c
//一些不匹配的整型转换
#include <stdio.h>
#define PAGES 336
#define WORDS 65618
int main(void)
{
    short num = PAGES;
    short mnum = -PAGES;
    printf("num as short and unsigned short: %hd %hu\n", num, num);
    printf("-num as short and unsigned short: %hd %hu\n", mnum, mnum);
    printf("num as int and char: %d %c\n", num, num);
    printf("WORDS as int, short, and char: %d %hd %c\n", WORDS, WORDS, WORDS);

    return 0;
}
````

输出如下：

````c
num as short and unsigned short: 336 336
-num as short and unsigned short: -336 65200
num as int and char: 336 P
WORDS as int, short, and char: 65618 82 R
````

输出的第1行，num变量对应的转换说明%hd和%hu输出的结果都是336，这没有任何问题。

然而，第2行mnum变量对应的转换说明%u（无符号）输出的结果却为65200，并非期望的336。这是由于有符号short int类型的值在我们的参考系统中的表示方式所致。首先，short int的大小是2字节；其次，系统使用二进制补码来表示有符号整数。这种方法，数字0-32767代表它们本身，而数字32768~ 65535则表示负数。其中，65535表示-1,65534表示-2，以此类推。因此-336表示为65200（即65536-336）。所以被解释成有符号int时，65200代表-336；而被解释成无符号int时，65200则代表65200。一定要谨慎！一个数字可以被解释成两个不同的值。尽管并非所有的系统都使用这种方法来表示负整数，但要注意一点：别期望用号u转换说明能把数字和符号分开。

第3行演示了如果把一个大于255的值转换成字符会发生什么情况。在我们的系统中，short int是2字节，char是1字节。当printf()使用%c打印336时，它只会查看储存336的2字节中的后1字节。这种截断（见下图）相当于用一个整数除以256，只保留其余数。在这种情况下，余数是80，对应的ASCII值是字符P。用专业术语来说，该数字被解释成“以256为模”（modulo256），即该数字除以256后取其余数。

![image-20220528135741485](https://raw.githubusercontent.com/qihaozhuo/imgBed/main/PicGo/image-20220528135741485.png)

最后，我们在该系统中打印比short int类型最大整数（32767）更大的整数（65618）。这次，计算机也进行了求模运算。在本系统中，应把数字65618储存为4字节的int类型值。用%hd转换说明打印时， printf()只使用最后2个字节。这相当于65618除以65536的余数。这里，余数是82。鉴于负数的储存方法，如果余数在32767~65536范围内会被打印成负数。对于整数大小不同的系统，相应的处理行为类似，但是产生的值可能不同。

若是混淆整数型和浮点型，输出会更奇怪。

````c
//不匹配的浮点型转换
#include <stdio.h>
int main(void)
{
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 = 2000000000;
    long n4 = 1234567890;

    printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
    printf("%ld %ld\n", n3, n4);
    printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);

    return 0;
}
````

因系统而异，输出如下：

````
3.0e+00 3.0e+00 0.0e+00 1.4e-309
2000000000 1234567890
0 1074266112 0 1074266112
````



#### scanf()函数
