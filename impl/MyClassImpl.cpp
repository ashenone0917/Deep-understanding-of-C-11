#include "MyClassImpl.h"
#include <iostream>
MyClassImpl::MyClassImpl() {
	std::cout << "MyClassImpl constructed" << std::endl;
}

MyClassImpl::~MyClassImpl() {
	std::cout << "MyClassImpl des constructed" << std::endl;
}

void MyClassImpl::Run() {
	std::cout << "run" << std::endl;
}

void MyClassImpl::Result() {
	std::cout << "Result=" <<m_nResult<< std::endl;
}

void MyClassImpl::SetResult(int n) {
	m_nResult = n;
}
