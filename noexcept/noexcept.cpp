#include <iostream>
void Throw() { throw 1; };
void NoBlockThrow() { Throw(); };
void BlockThrow() noexcept { Throw(); }; //noexcept(表达式)，表达式返回为true时，表明不会抛出异常
//默认只有noexcept时为noexcept(true)
int main()
{

}