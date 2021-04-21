// construct_delegate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <deque>
#include <list>
#include <vector>
using namespace std;

class Info
{
public:
    Info() :Info(1) {
    };

    Info(int i) :Info(i, 1.0, '1') {

    };

private:
    Info(int i, double j, char k) 
        :m_nI(i),m_fJ(j),m_cK(k){
        Init();
    }

    void Init() {

    };
private:
    int m_nI = 0;
    double m_fJ = 0.0;
    char m_cK = '0';
};

//模板委托构造函数
template <typename  T>
class TDConstructed {
public:
    using value_type = T;
public:
    TDConstructed(vector<value_type>& v)
        :TDConstructed(v.begin(), v.end()) { //TDConstructed参数会被推导为vector<value_type>::iterator

    };

    TDConstructed(deque<value_type>& d)
        :TDConstructed(d.begin(), d.end()) { //TDConstructed参数会被推导为deque<value_type>::iterator

    };
private:
    template<typename T> 
    TDConstructed(T first, T last)
        :l(first, last) {
        
    }

    list<value_type> l;
};

//委托构造函数捕捉异常
class DCExcept {
public:
    DCExcept(double d)
        try : DCExcept(1, d) {
            cout << "Run the body!" << endl;
        }
        catch (...) {
            cout << "catch exception!" << endl;
        }
private:
    DCExcept(int type_, double data_)
        :type(type_), data(data_) {
        cout << "going to throw" << std::endl;
        throw 0;
    };
private:
    int type{};
    double data{};
};

int main()
{
    vector<int> v = { 1,2,3 };
    TDConstructed<int> t(v);

    deque<int> d = { 1,2,3 };
    TDConstructed<int> t_(v);

    DCExcept dce(1.0);
    std::cout << "Hello World!\n";
}
