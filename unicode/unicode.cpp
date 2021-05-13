// unicode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//char16_t 用于存储UTF-16编码的Unicode数据
//char32_t 用于存储UTF-8编码的Unicode数据

int main()
{
    auto utf8_str = u8"123456";
    auto utf16_str = u"123456";
    auto utf32_str = U"123456";

    std::cout << "Hello World!\n";
}
