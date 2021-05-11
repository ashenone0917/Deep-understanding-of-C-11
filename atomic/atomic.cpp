// atomic.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <atomic>
#include <thread>

using namespace std;
atomic_int a{ 0 };
atomic_int b{ 0 };

int ValueSet(int) {
    int t = 1;
    //a = t;原子类型会禁止编译器对其赋值的重排优化，而memory_order_relaxed则会让其可以进行重排优化
    //b = 2;如果a,b的执行顺序不影响结果的话，可以使用memory_order_relaxed让编译器更好的优化代码
    //memory_order_seq_cst表示全部存取的按顺序执行，atomic类型的默认值
    //这只是编译器的优化，由于x86架构是强内存模型，所以不考虑cpu的强内存和弱内存模型的优化

    a.store(t, memory_order_relaxed); 
    b.store(2, memory_order_relaxed);

}

void Observer(int) {
    cout << "a = " << a << " b = " << b << endl;    
}

int main()
{
    thread t1(ValueSet, 0);
    thread t2(Observer, 0);

    t1.join();
    t2.join();
    cout << "Got a = " << a << " b = " << b;
    return 0;
}
