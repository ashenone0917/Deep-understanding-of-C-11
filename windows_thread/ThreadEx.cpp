#include "ThreadEx.h"

ThreadEx::ThreadEx(ThreadFunc func, 
	Thread::ThreadType type,
	DWORD millis)
	: Thread(type,millis) {
	func_ = func;
}

ThreadEx::ThreadEx(ThreadFunc func, 
	ThreadFunc terminate_func, 
	Thread::ThreadType type,
	DWORD millis)
	: Thread(type, millis) {
	func_ = func;
	terminate_func_ = terminate_func;
}

void ThreadEx::Execute() {
	if(func_) func_();
}

void ThreadEx::OnTerminate() {
	if(terminate_func_) terminate_func_();
}
