#include "test.h"
extern template void func<int>(int);
void test2() {
	func(4);
}