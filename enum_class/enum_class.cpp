// enum_class.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
enum class Number {ONE = 1,TOW,THREE};
enum class Type:char{General,Light,Medium};
enum class U :unsigned int {U1= 1,U2};
int main()
{
    std::cout << sizeof(Type::General) << std::endl;
    std::cout << sizeof(Number::ONE) << std::endl;
    std::cout << sizeof(U::U1) << std::endl;
    std::cout << "Hello World!\n";
}