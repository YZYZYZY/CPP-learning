#include <iostream>
#include <pthread.h>

#define NUM_THREADS 5

void *say_hello(void* args){
    std::cout << "Hello Runoob!" << std::endl;
    return 0;
}

int main(){
    //定义线程的 id 变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];
    for(int i=0;i < NUM_THREADS; ++i){
        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if(ret != 0){
            std::cout << "pthread_create error: error_code=" << ret << std::endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没执行完
    system("pause");
    return 0;
}