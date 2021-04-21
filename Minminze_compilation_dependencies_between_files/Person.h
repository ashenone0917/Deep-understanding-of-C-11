#pragma once
#include <string>
#include <memory>
//���ļ��ı��������ϵ�������
class PersonImpl;
class Date;
class Address;

class Person
{
public:
	Person(const std::string& name, const Date& birthday, 
		const Address& addr);
	void Print();
private:
	std::shared_ptr<PersonImpl> pImpl;
};

