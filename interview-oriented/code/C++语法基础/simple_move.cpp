#include <iostream>
#include <utility> // 包含 std::move()

class MyResource {
public:
    MyResource() {
        std::cout << "Resource acquired" << std::endl;
    }
    ~MyResource() {
        std::cout << "Resource released" << std::endl;
    }
    // 移动构造函数
    MyResource(MyResource&& other) noexcept {
        std::cout << "Move constructor called" << std::endl;
    }
    // 移动赋值运算符
    MyResource& operator=(MyResource&& other) noexcept {
        std::cout << "Move assignment operator called" << std::endl;
        return *this;
    }
};

int main() {
    MyResource res1; // 创建一个对象，分配资源
    MyResource res2(std::move(res1)); // 使用移动构造函数将资源从res1移动到res2
    MyResource res3;
    res3 = std::move(res2); // 使用移动赋值运算符将资源从res2移动到res3
    return 0;
}
