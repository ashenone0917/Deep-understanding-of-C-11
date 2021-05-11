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
    //这只是编译器的优化，由于x86架构是强顺序内存模型，所以不考虑cpu的强顺序内存和弱顺序内存模型的优化
    //memory_order_comsume只保证原子数据类型相同的读操作必须在本原子操作完成后，才能执行之后所有的读原子操作

    //为了保证a输出的值不为0，而又保证编译器有一定的优化就可以这么写
    a.store(t, memory_order_relaxed);
    b.store(2, memory_order_release);//本原子操作完成之前，所有写原子操作必须完成

}

void Observer(int) {
    while (b.load(memory_order_acquire) != 2) {//本原子操作完成后，才能执行之后所有的读原子操作
        cout << "a = " << a.load(memory_order_relaxed)<<endl;
    }
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
