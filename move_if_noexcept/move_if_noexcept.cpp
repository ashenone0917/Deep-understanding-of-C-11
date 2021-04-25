// move_if_noexcept.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <utility>
using namespace std;

struct Maythrow {
    Maythrow() = default;
    Maythrow(const Maythrow&) {
        cout << "Maythrow copy constructor." << endl;
    }
    Maythrow(Maythrow&&) {
        cout << "Maythrow move constructor." << endl;
    }
};


struct Nothrow {
    Nothrow() = default;
    Nothrow(const Nothrow&) {
        cout << "Nothrow copy constructor." << endl;
    }
    Nothrow(Nothrow&&) noexcept { //移动构造最好不要抛出异常
        cout << "Nothrow move constructor." << endl;
    }
};
int main()
{
    Maythrow m;
    Nothrow n;
    Maythrow mt = std::move_if_noexcept(m); //Maythrow copy constructor.
    Nothrow nt = std::move_if_noexcept(n); //Nothrow move constructor.
    std::cout << "Hello World!\n";
}
