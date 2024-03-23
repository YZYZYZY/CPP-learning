#include <iostream>
#include <thread>

void threadFunction() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(threadFunction); // 创建并启动线程
    t.join(); // 等待线程结束
    return 0;
}