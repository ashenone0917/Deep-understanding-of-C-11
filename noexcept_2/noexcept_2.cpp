// noexcept_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
struct A {
    ~A() { throw 1; } //析构函数默认为noexcept(true)，所以会调用std::terminate
};

struct B {
    ~B() noexcept(false) {
        throw 1;
    }
};

struct C {
    B b;
};
 
void FuncA() {
    A a;
}

void FuncB() {
    B b;
}

void FuncC() {
    C c;
}

int main()
{
    try {
        FuncB();
    }
    catch (...) {
        std::cout << "catch FuncB" << std::endl;
   }

    try {
        FuncC();
    }
    catch (...) {
        std::cout << "catch FuncC" << std::endl;
    }

    try {
        FuncA();//terminate 
    }
    catch (...) {
        std::cout << "catch FuncA" << std::endl;
    }
}
