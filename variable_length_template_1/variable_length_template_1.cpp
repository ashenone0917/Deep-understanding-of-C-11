// variable_length_template_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdexcept>
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

void Printf(const char* s) {
    while (*s) {
        if (*s == '%' && *++s != '%') {
            throw std::runtime_error("invalid format: missing arguments");
        }
        std::cout << *s++;
    }
}

template<typename T,typename... Args>
void Printf(const char* s, T value, Args... args) {
    while (*s) {
        if (*s == '%' && *++s != '%') {
            std::cout << value;
            return Printf(++s, args...);
        }
        std::cout << *s++;
    }
    throw std::runtime_error("extra arguments provided to Printf");
}

int main()
{

    std::cout << Test::val << std::endl;
    std::cout << Multiply<2, 3, 4, 5, 6>::val << std::endl;
    std::cout << Multiply<22, 33, 44, 55, 66>::val << std::endl;
    Printf("hello %s\n", std::string(" world"));
}