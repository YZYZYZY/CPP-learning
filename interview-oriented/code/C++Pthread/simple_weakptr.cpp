#include <iostream>
#include <memory>

class B; // 前置声明

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::weak_ptr<A> a_ptr; // 使用weak_ptr避免循环引用
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();

    a->b_ptr = b;
    b->a_ptr = a; // 不增加A的引用计数

    // 此时，尽管A和B互相引用，但其中一个使用了weak_ptr，
    // 因此当main结束时，它们都可以被正确销毁。
}
