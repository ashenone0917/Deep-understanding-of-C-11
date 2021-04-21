#include "Person.h"
#include "PersonImpl.h"
#include "Address.h"
#include "Date.h"
Person::Person(const std::string& name, const Date& birthday, 
	const Address& addr)
{

}

void Person::Print() {
	pImpl->Print();
}
