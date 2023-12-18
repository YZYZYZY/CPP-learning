#include <iostream>
#include <csignal>
#include <unistd.h> // sleep?

//signum是信号的编号，可以是除了SIGKILL和SIGSTOP之外的任何信号
void signalHandler( int signum )
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    // cleanup and close up stuff here  
    // terminate program  
    exit(signum);  
}

int main ()
{
    // register signal SIGINT and signal handler  
    signal(SIGINT, signalHandler);  

    while(1){
        std::cout << "Going to sleep...." << std::endl;
        sleep(1);
    }
    return 0;
}