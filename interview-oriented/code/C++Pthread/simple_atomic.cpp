#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> count(0); // 原子变量

void increment() {
    for (int i = 0; i < 1000; ++i) {
        count++; // 原子递增
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final count is " << count << std::endl;

    return 0;
}
