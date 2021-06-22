#pragma once
#include "Thread.h"
#include <functional>
class ThreadEx : public Thread
{
public:
	using ThreadFunc = std::function<void()>;
	ThreadEx(ThreadFunc func, 
		Thread::ThreadType type = ThreadType::PERSISTENT, 
		DWORD millis = 100);
	ThreadEx(ThreadFunc func,
		ThreadFunc terminate_func, 
		Thread::ThreadType type = ThreadType::PERSISTENT, 
		DWORD millis = 100);
protected:
	virtual void Execute() override;
	virtual void OnTerminate() override;
private:
	ThreadFunc func_;
	ThreadFunc terminate_func_;
};

