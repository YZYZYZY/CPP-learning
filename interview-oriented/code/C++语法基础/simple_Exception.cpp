#include <iostream>
#include <stdexcept>

void process_data(int value) {
    if (value < 0) {
        throw std::invalid_argument("Invalid value: must be non-negative");
    }

    // 模拟处理数据的过程
    std::cout << "Processing data with value: " << value << std::endl;
}

int main() {
    try {
        // 尝试处理数据，可能会抛出异常
        process_data(-10);
    } catch (const std::invalid_argument& e) {
        // 捕获特定类型的异常并处理
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
