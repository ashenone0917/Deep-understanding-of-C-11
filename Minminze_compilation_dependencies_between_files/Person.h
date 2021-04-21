#pragma once
#include <string>
#include <memory>
//将文件的编译依存关系降至最低
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

