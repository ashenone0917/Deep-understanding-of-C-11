// forward.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
void RunCode(int&& m) {
    cout << "rvalue ref" << endl;
}

void RunCode(int& m) {
    cout << "lvalue ref" << endl;
}

void RunCode(const int&& m) {
    cout << "const rvalue ref" << endl;
}

void RunCode(const int& m) {
    cout << "const lvalue ref" << endl;
}

template <typename T>
void PerfectForward(T&& t) {
    RunCode(forward<T>(t));
}
int main()
{
    int a;
    int b;
    const int c = 1;
    const int d = 1;
    PerfectForward(a); //lvalue ref
    PerfectForward(move(b));//rvalue ref
    PerfectForward(c);//const lvalue ref
    PerfectForward(move(d));//const rvalue ref
    std::cout << "Hello World!\n";
}
