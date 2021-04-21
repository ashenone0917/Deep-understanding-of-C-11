// template_friend_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
template <typename T> class DefenderT {
public:
    friend T;
    void Defence(int x, int y) {};
    void Tackle(int x, int y) {};
private:
    int m_nPosX = 15;
    int m_nPosY = 0;
    int m_nSpeed = 2;
    int m_nStamina = 120;
};

template <typename T> class AttackerT {
public:
    friend T;
    void Move(int x, int y) {};
    void SpeedUp(float ratio) {};
private:
    int m_nPosX = 0;
    int m_nPosY = -30;
    int m_nSpeed = 3;
    int m_nStamina = 100;
};

using Defender = DefenderT<int>;
using Attacker = AttackerT<int>;

class Validator {
public:
    void Validate(int x, int y, DefenderTest& d) { };
    void Validate(int x, int y, AttackerTest& a) { };
};

using DefenderTest = DefenderT<Validator>;
using AttackerTest = AttackerT<Validator>;

struct Base {
    virtual void test(int n) {

    };
};

//derived classes内的名称会遮掩base classes内的名称
struct Derived : public Base {
    using Base::test;//如果没有这一句，那么Base的test会被Driverd的test所掩盖
    void test(double g) {

    };
};
int main()
{
    Derived dr;
    dr.test(10);//如果using Base::test，会调用void test(double g)
    dr.test(10.0);//如果using Base::test，会调用void test(double g)

    DefenderTest d;
    AttackerTest a;
    a.Move(15, 30);
    d.Defence(15, 30);
    a.SpeedUp(1.5f);
    d.Defence(15, 30);
    Validator v;
    v.Validate(7, 0, d);
    v.Validate(1, -10, a);
    return 0;
}
