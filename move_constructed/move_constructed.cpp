
#include <iostream>
class MoveClass {
public:
    MoveClass() {
        std::cout << "construct" << std::endl;
        m_nX = new int(10);
    }

    MoveClass(const MoveClass& move_) {
        std::cout << "copy construct" << std::endl;
        m_nX = new int(*move_.m_nX);
    }

    MoveClass(MoveClass&& move_) noexcept {
        std::cout << "move construct" << std::endl;
        m_nX = move_.m_nX;
        move_.m_nX = NULL;
    }

    ~MoveClass() {
        if (m_nX) {
            std::cout << "move desstruct not null" << std::endl;
            delete m_nX;
            m_nX = NULL;
        }
        else {
            std::cout << "move desstruct is null" << std::endl;
        }
    }

private:
    int* m_nX = NULL;
};

MoveClass Test1() {
    MoveClass test;
    return std::move(test);
}

MoveClass Test2() {
    return MoveClass();
}


int main()
{
    {
        MoveClass && result1 = Test1();
    }
    MoveClass result1 = Test1();//一次移动构造,rvo and nrvo
    MoveClass result2 = Test2();//rvo and nrvo，优化到直接构造
    std::cout << "-----------------------" << std::endl;
    MoveClass result3 = std::move(Test1());//两次移动构造
} 