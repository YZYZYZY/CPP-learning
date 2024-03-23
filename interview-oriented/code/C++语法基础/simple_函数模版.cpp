#include <iostream>

template <typename T>
T max(T x, T y) {
    return x > y ? x : y;
}

int main() {
    // 使用函数模板生成int类型的max函数
    std::cout << max(10, 5) << std::endl;  // 输出: 10
    
    // 使用函数模板生成double类型的max函数
    std::cout << max(10.5, 20.5) << std::endl;  // 输出: 20.5
    
    // 使用函数模板生成string类型的max函数
    std::cout << max(std::string("Apple"), std::string("Orange")) << std::endl;  // 输出: Orange
}
