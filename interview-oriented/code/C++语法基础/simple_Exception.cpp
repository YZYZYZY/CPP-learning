#include <iostream>
#include <stdexcept> // 标准异常库

int main() {
    try {
        // 可能抛出异常的代码
        throw std::runtime_error("发生错误！");
    } catch (const std::runtime_error& e) {
        // 处理特定类型的异常
        std::cout << "捕获到异常: " << e.what() << std::endl;
    } catch (...) {
        // 捕获所有类型的异常
        std::cout << "捕获到未知异常" << std::endl;
    }

    return 0;
}
