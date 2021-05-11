// lambda.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int girls = 3, boys = 4;
    auto child = [](int x, int y) {return x + y; };
    typedef int (*allChild)(int x, int y);
    typedef int (*oneChild)(int x);

    allChild p = child; //允许lambda函数直接转为函数指针，可以转成function类
    oneChild q = chile; //失败

    decltype(child) allPeople = child;
    decltype(child) totalPeople = p; //失败，函数指针无法转为lambda


    std::cout << "Hello World!\n";
}
