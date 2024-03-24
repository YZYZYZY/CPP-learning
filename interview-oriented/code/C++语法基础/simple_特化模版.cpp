#include <iostream>
#include <string>

// 通用模板
template<typename T>
void print(const T& value) {
    std::cout << "General template: " << value << std::endl;
}

// 特化模板，针对int类型
template<>
void print<int>(const int& value) {
    std::cout << "Specialized template for int: " << value << std::endl;
}

// 特化模板，针对std::string类型
template<>
void print<std::string>(const std::string& value) {
    std::cout << "Specialized template for std::string: " << value << std::endl;
}

int main() {
    print(42);           // 将调用int的特化版本
    print(std::string("Hello")); // 将调用std::string的特化版本
    print(3.14);         // 将调用通用模板
    return 0;
}
