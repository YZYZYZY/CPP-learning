#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
int data = 0;

void worker_thread() {
    // 等待直至 main() 发送数据
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; }); // 只有当 ready == true 时才会继续执行

    // 等待后，我们占有锁。
    std::cout << "Worker thread is processing data\n";
    data += 2; // 模拟数据处理
    std::cout << "Worker thread is processing data\n";
    // 发送数据回 main()
    ready = false;
    cv.notify_one();
}

int main() {
    std::thread worker(worker_thread);

    data = 1; // 设置数据
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true; // 设置标志位为 true
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one(); // 通知一个等待的线程

    // 等待工作线程完成处理
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !ready; });
    }
    std::cout << "Back in main(), data = " << data << '\n';

    worker.join();
    return 0;
}
