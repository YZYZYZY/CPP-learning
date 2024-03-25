#include <iostream>
#include <vector>
#include <concepts>

// 定义一个概念，要求类型T必须支持加法操作
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>; // 加法操作返回的类型必须与操作数类型相同
};

// 定义一个函数模板，使用概念作为模板参数的约束
template <Addable T>
T sum(const std::vector<T>& vec) {
    T result = 0; // 初始化结果

    // 遍历容器并累加元素
    for (const T& element : vec) {
        result += element;
    }

    return result;
}

int main() {
    std::vector<int> intVec = {1, 2, 3, 4, 5};
    std::vector<double> doubleVec = {1.1, 2.2, 3.3, 4.4, 5.5};

    // 使用sum函数计算整数向量的总和
    std::cout << "Sum of integers: " << sum(intVec) << std::endl;

    // 使用sum函数计算浮点数向量的总和
    std::cout << "Sum of doubles: " << sum(doubleVec) << std::endl;

    return 0;
}
