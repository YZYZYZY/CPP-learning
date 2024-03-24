#include <iostream>

class MyClass {
public:
    int value = 42;
    void demo() {
        // 值捕获
        auto lambda_val = [=]() { std::cout << "Value capture: " << value << std::endl; };
        lambda_val();

        // 引用捕获
        auto lambda_ref = [&]() { std::cout << "Reference capture before: " << value << std::endl;
                                  value = 100;  // 修改外部变量的值
                                };
        lambda_ref();
        std::cout << "Value after reference capture: " << value << std::endl;

        // 捕获this
        auto lambda_this = [this]() { std::cout << "This capture: " << this->value << std::endl; };
        lambda_this();
    }
};

int main() {
    MyClass obj;
    obj.demo();
    return 0;
}
