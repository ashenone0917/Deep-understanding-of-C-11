// spin lock.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

std::atomic_flag lock = ATOMIC_FLAG_INIT;

void f(int n) {
    while (lock.test_and_set(std::memory_order_acquire))
        cout << "Wait from thread " <<n << endl;
    cout << "Thread " << n << " starts working" << endl;
}

void g(int n) {
    cout << "Thread " << n << " is going to start." << endl;
    lock.clear();
    cout << "Thread " << n << " starts working" << endl;
}

void Lock(atomic_flag& lock) { while (lock.test_and_set()); }
void UnLock(atomic_flag& lock) { lock.clear(); }

int main()
{
    lock.test_and_set();
    thread t1(f, 1);
    thread t2(g, 2);
    
    t1.join();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    t2.join();
    std::cout << "Hello World!\n";
}