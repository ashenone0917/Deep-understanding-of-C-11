// trans_constructor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
template <typename T>
class Ptr {
public:
    using value = T;
    Ptr(value* ptr)
        :ptr_(ptr) {
    }

    operator bool() const {
        if (ptr_ == nullptr) {
            return false;
        }
        else {
            return true;
        }
    }

    ~Ptr() {
        if (ptr_ != nullptr) {
            delete ptr_;
            ptr_ = nullptr;
        }
    }
private:
    value* ptr_ = nullptr;
};
int main()
{
    Ptr<int> ptr(new int(5));
    if (ptr) {
        std::cout << "ptr not null\n";
    }
    
}
