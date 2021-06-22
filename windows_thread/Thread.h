#pragma once
#include <Windows.h>
class Thread 
{
public:
enum ThreadType{
	ONCE_FALG,
	PERSISTENT,
	RECYCLE
};
public:
	Thread(ThreadType type = PERSISTENT,DWORD millis = 100);

	virtual ~Thread();

	bool Suspend();

	bool Wait();

	DWORD WaitTime(DWORD millis);

	bool Resume();
	
	bool isActive() const;

	void Terminate();

	DWORD GetThreadId() const;

	static void Sleep(DWORD millis);

	static void yield();

protected:
	virtual void Execute() = 0;

	bool isTerminating() const;

	virtual void OnTerminate();

private:
	static DWORD WINAPI threadProc(LPVOID pThread);

	static DWORD WINAPI threadProcCycle(LPVOID pThread);

	static DWORD WINAPI threadProcOnce(LPVOID pThread);

private:
	HANDLE m_hThread = NULL;

	DWORD m_dwThreadID = NULL;

	bool m_bAcctive = false;

	bool m_bTermianate = false;

	DWORD m_dwMillis = 0;
};

