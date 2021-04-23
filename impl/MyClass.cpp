#include "MyClass.h"
#include "MyClassImpl.h"
MyClass::MyClass() 
	:m_pImpl(std::make_shared<MyClassImpl>()){
	//:m_pImpl(new MyClassImpl){
	std::cout << "MyClass constructed" << std::endl;
}

MyClass::~MyClass() {
	std::cout << "MyClass des constructed" << std::endl;
}

void MyClass::Run() {
	m_pImpl->Run();
}

void MyClass::Result() {
	m_pImpl->Result();
}

void MyClass::SetResult(int n) {
	m_pImpl->SetResult(n);
}


