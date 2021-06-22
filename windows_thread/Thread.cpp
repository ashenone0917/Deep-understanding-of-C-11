#include "Thread.h"

Thread::Thread(ThreadType type,DWORD millis)
    :m_dwMillis(millis) {
    switch (type)
    {
    case ThreadType::ONCE_FALG:
        m_hThread = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threadProcOnce,
            (LPVOID)this, CREATE_SUSPENDED, (LPDWORD)&m_dwThreadID);
        break;
    case ThreadType::PERSISTENT:
        m_hThread = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threadProc,
            (LPVOID)this, CREATE_SUSPENDED, (LPDWORD)&m_dwThreadID);
        break;
    case ThreadType::RECYCLE:
        m_hThread = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threadProcCycle,
            (LPVOID)this, CREATE_SUSPENDED, (LPDWORD)&m_dwThreadID);
        break;
    default:
        break;
    }
}

Thread::~Thread() {
    if (m_hThread != NULL) {
        ::CloseHandle(m_hThread);
    }
}

bool Thread::Suspend() {
    if (m_hThread != NULL) {
        m_bAcctive = (::SuspendThread(m_hThread) == -1);
    }
    return !m_bAcctive;
}

bool Thread::Wait() {
    if (m_hThread != NULL) {
        return (::WaitForSingleObject(m_hThread, INFINITE) != WAIT_FAILED);
    }
    return true;
}

DWORD Thread::WaitTime(DWORD millis) {
    if (m_hThread != NULL) {
        return ::WaitForSingleObject(m_hThread, millis);
    }
    return WAIT_FAILED;
}

bool Thread::Resume() {
    if (m_hThread != NULL) {
        m_bAcctive = (::ResumeThread(m_hThread) != -1);
    }
    return m_bAcctive;
}

bool Thread::isActive() const {
    return m_bAcctive;
}

void Thread::Terminate() {
    m_bTermianate = true;
    OnTerminate();
}

bool Thread::isTerminating() const {
    return m_bTermianate;
}

void Thread::OnTerminate(){

}

DWORD Thread::GetThreadId() const {
    return m_dwThreadID;
}

void Thread::Sleep(DWORD millis) {
    ::Sleep(millis);
}

void Thread::yield() {
    SwitchToThread();
}

DWORD WINAPI Thread::threadProc(LPVOID pThread) {
    Thread* _this = (Thread*)pThread;
    _this->Execute();
    _this->m_bAcctive = false;
    _this->m_bTermianate = true;
    return 0;
}

DWORD WINAPI Thread::threadProcCycle(LPVOID pThread) {
    Thread* _this = (Thread*)pThread;
    while (!_this->m_bTermianate) {
        _this->Execute();
        Sleep(_this->m_dwMillis);
    }
    _this->m_bAcctive = false;
    _this->m_bTermianate = true;
    return 0;
}

DWORD WINAPI Thread::threadProcOnce(LPVOID pThread) {
    Thread* _this = (Thread*)pThread;
    _this->Execute();
    return 0;
}
