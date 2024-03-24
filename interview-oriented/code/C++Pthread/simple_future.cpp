#include <future>
#include <iostream>
#include <thread>

void compute(std::promise<int>&& prom) {
    int result = 42; // 假设这是一些复杂计算的结果
    prom.set_value(result); // 设置promise的值，与future关联
}

int main() {
    std::promise<int> prom; // 创建promise对象
    std::future<int> fut = prom.get_future(); // 获取与promise关联的future

    std::thread t(compute, std::move(prom)); // 将promise移动到新线程

    // 在主线程中等待异步操作完成并获取结果
    int result = fut.get();
    std::cout << "Result: " << result << std::endl;

    t.join(); // 等待线程完成
    return 0;
}
