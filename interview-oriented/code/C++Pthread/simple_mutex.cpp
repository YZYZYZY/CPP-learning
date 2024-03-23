#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // 声明全局互斥锁
int shared_data = 0; // 共享数据

void increment_shared_data() {
    std::lock_guard<std::mutex> guard(mtx); // 自动加锁
    ++shared_data; // 安全地访问共享数据
    std::cout << "Data incremented to " << shared_data << std::endl;
    // 自动解锁，无需显式调用unlock
}

int main() {
    std::thread t1(increment_shared_data);
    std::thread t2(increment_shared_data);

    t1.join();
    t2.join();

    return 0;
}