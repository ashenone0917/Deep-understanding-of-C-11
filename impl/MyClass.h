#pragma once
#include <memory>
#include <iostream>
//class state_deleter {  // a deleter class with state
//    int count_;
//public:
//    state_deleter() : count_(0) {}
//    template <class T>
//    void operator()(T* p) {
//        std::cout << "[deleted #" << ++count_ << "]\n";
//        delete p;
//    }
//};

class MyClassImpl;
class MyClass
{
public:
	MyClass();
    ~MyClass();
	void Run();
	void Result();
	void SetResult(int n);
private:
	std::shared_ptr<MyClassImpl> m_pImpl;
	//std::unique_ptr<MyClassImpl, state_deleter> m_pImpl;
    //使用unique_ptr会出现C2027，使用了未定义的类型，除非传入deleter
    //建议还是直接使用shared_ptr

    //template <class _Dx2>
    //using _Unique_ptr_enable_default_t =
    //    enable_if_t<conjunction_v<negation<is_pointer<_Dx2>>, is_default_constructible<_Dx2>>, int>;

    //// CLASS TEMPLATE unique_ptr SCALAR
    //template <class _Ty, class _Dx /* = default_delete<_Ty> */>
    //class unique_ptr { // non-copyable pointer to an object
    //public:
    //    using pointer = typename _Get_deleter_pointer_type<_Ty, remove_reference_t<_Dx>>::type;//unique_ptr无法使用和这一段有关，需要指导deleter的类型
    //    using element_type = _Ty;
    //    using deleter_type = _Dx;
};

