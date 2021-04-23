// iterate_move.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
using u_list = std::list<std::unique_ptr<int>>;
u_list tl;
u_list test1() {
    tl.push_back(std::make_unique<int>(10));
    return std::move(tl);
}

u_list test2() {
    return test1(); //返回右值，自动调用移动构造给临时变量，不排除rvo
}
int main()
{
    auto temp = test2();
    (*temp.front()) = 100;
    std::cout << "Hello World!\n";
}
