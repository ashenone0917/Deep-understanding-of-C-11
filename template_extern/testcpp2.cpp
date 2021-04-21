#include "test.h"
template void func<int>(int);//显示实例化函数模板，其他地方extern外部调用，可以防止实例化出多份代码再由编译器去重
//可以减少编译器的工作量，减少编译时间，降低模板展开编译器的开销
void test1() {
	func(3);
}