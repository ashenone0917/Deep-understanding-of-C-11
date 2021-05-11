// lambda_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int val;

    //默认情况下lambd为const函数
    //编译失败，在const的lambda修改常量
    auto const_val_lambda = [=]() {val = 3; };

    //非const的lambda，可以修改常量数据
    auto mutable_val_lambda = [=]()mutable {val = 3; };

    //依然是const的lambda，不过没有改动引用本身，只改变引用的值
    auto const_ref_lambda = [&]() {val = 3; }; 

    //依然是const的lambda，通过参数传递引用本身
    auto const_param_lambda = [&](int v) {v = 3; };
    const_param_lambda(val);

}
