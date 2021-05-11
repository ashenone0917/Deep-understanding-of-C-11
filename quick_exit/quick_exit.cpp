// quick_exit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdlib>
using namespace std;
struct A { ~A() { cout << "Destruct A. " << endl; } };
void closeDevice() { cout << "device is closed" << endl; }
int main()
{
    A a;
    at_quick_exit(closeDevice);
    quick_exit(0);
    std::cout << "Hello World!\n";
}
