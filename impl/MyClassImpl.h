#pragma once
class MyClassImpl
{
public:
	MyClassImpl();
	~MyClassImpl();
	void Run();
	void Result();
	void SetResult(int n);
private:
	int m_nResult = 0;
};

