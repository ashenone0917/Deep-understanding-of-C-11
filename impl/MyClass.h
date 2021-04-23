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
    //ʹ��unique_ptr�����C2027��ʹ����δ��������ͣ����Ǵ���deleter
    //���黹��ֱ��ʹ��shared_ptr

    //template <class _Dx2>
    //using _Unique_ptr_enable_default_t =
    //    enable_if_t<conjunction_v<negation<is_pointer<_Dx2>>, is_default_constructible<_Dx2>>, int>;

    //// CLASS TEMPLATE unique_ptr SCALAR
    //template <class _Ty, class _Dx /* = default_delete<_Ty> */>
    //class unique_ptr { // non-copyable pointer to an object
    //public:
    //    using pointer = typename _Get_deleter_pointer_type<_Ty, remove_reference_t<_Dx>>::type;//unique_ptr�޷�ʹ�ú���һ���йأ���Ҫָ��deleter������
    //    using element_type = _Ty;
    //    using deleter_type = _Dx;
};

