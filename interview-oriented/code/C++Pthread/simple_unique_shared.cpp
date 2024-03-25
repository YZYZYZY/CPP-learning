#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructor called" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructor called" << std::endl;
    }
    void display() {
        std::cout << "Hello from MyClass" << std::endl;
    }
};

void uniquePtrExample() {
    // 使用std::unique_ptr管理动态分配的内存
    std::unique_ptr<MyClass> ptr1(new MyClass());
    ptr1->display();

    // 使用std::make_unique进行内存分配，更加安全和方便
    std::unique_ptr<MyClass> ptr2 = std::make_unique<MyClass>();
    ptr2->display();

    // 尝试拷贝或赋值会导致编译错误，因为std::unique_ptr不支持拷贝和赋值操作
    // std::unique_ptr<MyClass> ptr3 = ptr1; // 错误

    // std::move可以将所有权从一个std::unique_ptr转移给另一个
    std::unique_ptr<MyClass> ptr3 = std::move(ptr1);
    if (ptr1 == nullptr) {
        std::cout << "ptr1 is nullptr after move" << std::endl;
    }
}

void sharedPtrExample() {
    // 使用std::shared_ptr共享所有权
    std::shared_ptr<MyClass> ptr1(new MyClass());
    ptr1->display();

    // 多个std::shared_ptr可以指向相同的对象
    std::shared_ptr<MyClass> ptr2 = ptr1;
    ptr2->display();

    // 使用std::make_shared进行内存分配
    std::shared_ptr<MyClass> ptr3 = std::make_shared<MyClass>();
    ptr3->display();

    // 当所有std::shared_ptr都不再指向对象时，对象会被销毁
}

int main() {
    std::cout << "----- Unique Pointer Example -----" << std::endl;
    uniquePtrExample();

    std::cout << "\n----- Shared Pointer Example -----" << std::endl;
    sharedPtrExample();

    return 0;
}
