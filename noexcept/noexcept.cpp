#include <iostream>
void Throw() { throw 1; };
void NoBlockThrow() { Throw(); };
void BlockThrow() noexcept { Throw(); }; //noexcept(���ʽ)�����ʽ����Ϊtrueʱ�����������׳��쳣
//Ĭ��ֻ��noexceptʱΪnoexcept(true)
int main()
{

}