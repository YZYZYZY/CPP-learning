#include <iostream>
#include <thread>
#include <vector>

thread_local int tlsVar = 0; // 定义一个线程局部存储变量

void threadFunc(int num) {
    tlsVar = num; // 每个线程设置tlsVar为不同的值
    std::cout << "Thread " << num << " tlsVar = " << tlsVar << std::endl;
}

int main() {
    std::vector<std::thread> threads;

    // 创建并启动3个线程
    for (int i = 1; i <= 3; ++i) {
        threads.push_back(std::thread(threadFunc, i));
    }

    // 等待所有线程完成
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
