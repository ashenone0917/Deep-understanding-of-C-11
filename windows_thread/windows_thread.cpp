// windows_thread.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <atomic>
#include "ThreadEx.h"
class ThreadTest {
public:
    ThreadTest() = default;
    void Execute() {
        thread_ = std::make_unique<ThreadEx>(
            std::bind(&ThreadTest::ThreadTemp, this, 1),
            std::bind(&ThreadTest::Terminate, this));
        if (thread_) {
            thread_->Resume();
        }
    }

    void Execute2() {
        thread_ = std::make_unique<ThreadEx>(
            std::bind(&ThreadTest::ThreadTemp2, this, 1),
            Thread::RECYCLE,1000);
        if (thread_) {
            thread_->Resume();
        }
    }

    void ThreadTemp(DWORD n) {
        while (acctive) {
            Sleep(1000);
            std::cout << n << std::endl;
        }   
    }

    void ThreadTemp2(DWORD n) {
       std::cout << n << std::endl;   
    }

    void Terminate() {
        acctive = false;
    }

    void Terminate2() {
        thread_->Terminate();
    }

private:
    std::shared_ptr<ThreadEx> thread_ = nullptr;
    std::atomic_bool acctive = true;
};
void funct() {

}
int main()
{
    std::shared_ptr<ThreadTest> test = nullptr;
    {
        std::shared_ptr<ThreadTest> test = std::make_shared<ThreadTest>();
        test->Execute2();
    }
    
    Sleep(10000);
    test->Terminate2();
    Sleep(1000);
    std::cout << "Hello World!\n";
    getchar();
}

