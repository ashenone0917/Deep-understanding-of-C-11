// impl.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "MyClass.h"
int main()
{
    MyClass temp;
    temp.Run();
    temp.Result();
    temp.SetResult(10);
    temp.Result();
    std::cout << "Hello World!\n";
}
