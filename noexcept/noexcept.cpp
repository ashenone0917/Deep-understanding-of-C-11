#include <iostream>
void Throw() { throw 1; };
void NoBlockThrow() { Throw(); };
void BlockThrow() noexcept { Throw(); }; //noexcept(表达式)，表达式返回为true时，表明不会抛出异常
//默认只有noexcept时为noexcept(true)
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
		std::cout << "throw except"  << std::endl; //NoBlockThrow内没有catch，抛到了main函数的catch
	}

	try {
		BlockThrow();
	}
	catch (...) {		std::cout << "throw except" << std::endl;//noexcept默认，说明函数不会抛出异常，但实际上却抛出了异常，会导致调用std::terminate结束进程
	}

	return 0;
}