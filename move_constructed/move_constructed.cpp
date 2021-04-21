// move_constructed.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
class MoveClass {
public:
    MoveClass() {
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
    return std::move(MoveClass());
}

MoveClass Test2() {
    return MoveClass();
}


int main()
{
    MoveClass result2 = std::move(Test1());
} 