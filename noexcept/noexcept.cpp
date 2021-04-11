#include <iostream>
void Throw() { throw 1; };
void NoBlockThrow() { Throw(); };
void BlockThrow() noexcept { Throw(); }; //noexcept(���ʽ)�����ʽ����Ϊtrueʱ�����������׳��쳣
//Ĭ��ֻ��noexceptʱΪnoexcept(true)
int main()
{
	try {
		Throw();
	}
	catch (int & n) {
		std::cout << "throw except=" << n <<std::endl;
	}

	try {
		NoBlockThrow();
	}
	catch (...) {
		std::cout << "throw except"  << std::endl; //NoBlockThrow��û��catch���׵���main������catch
	}

	try {
		BlockThrow();
	}
	catch (...) {		std::cout << "throw except" << std::endl;//noexceptĬ�ϣ�˵�����������׳��쳣����ʵ����ȴ�׳����쳣���ᵼ�µ���std::terminate��������
	}

	return 0;
}