// variable_length_template_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
template <typename... Elements> class mytuple;
template <typename Head,typename... Tail>
class mytuple<Head, Tail...> : private mytuple<Tail...> {
    Head head;
};
template<> class mytuple<> {};

template <long... nums> struct Multiply;

template <long first,long... last>
struct Multiply<first, last...> {
    static const long val = first * Multiply<last...>::val;
};

template <>
struct Multiply<> {
    static const long val = 1;
};

struct Test {
    static const long val = 10;
};

#include <future>

int main()
{

    std::cout << Test::val << std::endl;
    std::cout << Multiply<2, 3, 4, 5, 6>::val << std::endl;
    std::cout << Multiply<22, 33, 44, 55, 66>::val << std::endl;
}