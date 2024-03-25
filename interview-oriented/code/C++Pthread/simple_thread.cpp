#include <iostream>
#include <thread>

// 线程任务
void threadFunction(int x) {
    std::cout << "Inside Thread :: ID = " << std::this_thread::get_id() << ":: Value = " << x << std::endl;
}

int main() {
    int x = 9;
    std::cout << "Inside Main Thread :: ID = " << std::this_thread::get_id() << std::endl;

    // 创建线程
    std::thread th(threadFunction, x);

    // 等待线程完成任务
    th.join();

    std::cout << "Exit of Main Thread" << std::endl;
    return 0;
}
