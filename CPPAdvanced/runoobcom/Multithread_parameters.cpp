#include <iostream>
#include <pthread.h>
#include <cstdlib>

#define NUM_THREADS 5

struct thread_data{
    int thread_id;
    char *message;
};

void *PrintHello(void *threading){
    struct thread_data *my_data;
    my_data = (struct thread_data *) threading;
    std::cout << "Thread ID: " << my_data->thread_id;
    std::cout << " Message: " << my_data->message << std::endl;
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;

    for(i=0; i < NUM_THREADS; ++i){
        std::cout << "main(): creating thread, " << i << std::endl;
        td[i].thread_id = i;
        td[i].message = (char *)"This is message";
        //接收的这个参数(void *)&td[i]，是一个指向thread_data结构体的指针，这个结构体是在主线程中定义的，所以在主线程中分配内存，子线程中使用
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
        if(rc){
            std::cout << "Error: unable to create thread, " << rc << std::endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}