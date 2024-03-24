#include <future>
#include <iostream>

int compute() {
    // 执行一些计算
    return 42;
}

int main() {
    // 启动异步任务
    std::future<int> result = std::async(compute);

    // 在这里可以执行其他操作...

    // 获取异步操作的结果
    std::cout << "The answer is " << result.get() << std::endl;

    return 0;
}
