// initializer_list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
enum class Gender{boy, girl};
class People {
public:
    People(initializer_list<pair<string, Gender>> l) {
        for (auto& it : l) {
            data.emplace_back(it);
        }
    }
private:
    std::vector<pair<string, Gender>> data;
};
int main()
{
    People p = { {"string1",Gender::boy},{"string2",Gender::girl} };
    std::cout << "Hello World!\n";
}
