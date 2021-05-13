// aliga.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
//char 要求对齐到1字节
//int 要求对齐到4字节
//而整体要求对齐到最大的数据类型
//就变成了8字节大小
//对齐到4字节的意思是，要求数据必须放到一个能够整除4的地址上，这样在读写的性能上就会有优势
//每种类型都有自己需要的对齐大小，比如int就需要对齐4字节，double需要对齐8字节

//内存对齐的主要作用是：
//1.平台原因(移植原因)：不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出硬件异常。
//2.性能原因：经过内存对齐后，CPU的内存访问速度大大提升。
//CPU把内存当成是一块一块的，块的大小可以是2，4，8，16字节大小，因此CPU在读取内存时是一块一块进行读取的。块大小成为memory access granularity（粒度） 本人把它翻译为“内存读取粒度” 。
//假设CPU要读取一个int型4字节大小的数据到寄存器中，分两种情况讨论：
//1.数据从0字节开始
//2.数据从1字节开始
//再次假设内存读取粒度为4。其实就是数据总线有多少根
//当该数据是从0字节开始时，很CPU只需读取内存一次即可把这4字节的数据完全读取到寄存器中。
//当该数据是从1字节开始时，问题变的有些复杂，此时该int型数据不是位于内存读取边界上，这就是一类内存未对齐的数据。
//此时CPU先访问一次内存，读取0—3字节的数据进寄存器，并再次读取4—5字节的数据进寄存器，接着把0字节和6，7，8字节的数据剔除，
//最后合并1，2，3，4字节的数据进寄存器。对一个内存未对齐的数据进行了这么多额外的操作，大大降低了CPU性能。
//这还属于乐观情况了，上文提到内存对齐的作用之一为平台的移植原因，因为以上操作只有有部分CPU肯干，其他一部分CPU遇到未对齐边界就直接罢工了。
//好像有的cpu只会从偶数开始取数据，有的只会从奇数开始取数据？
struct HowManyBytes {
    char a;
    int b;
};

struct alignas(32) ColorVector { //对齐到32字节边界
    double r;
    double g;
    double b;
    double a;
};
int main()
{

    cout << "sizeof(HowManyBytes) = " << sizeof(HowManyBytes) << endl;
    cout << "HowManyBytes offset of char a = " << offsetof(HowManyBytes, a) << endl;
    cout << "HowManyBytes offset of int b = " << offsetof(HowManyBytes, b) << endl;
    cout << "alignof(HowManyBytes) = " << alignof(HowManyBytes) << endl;//HowManyBytes的对齐方式
    cout << "alignof(ColorVector) = " << alignof(ColorVector) << endl;//ColorVector的对齐方式
    //alignas可以接受类型作为参数
    alignas(double) char c;
    alignas(alignof(double)) char d;
} 