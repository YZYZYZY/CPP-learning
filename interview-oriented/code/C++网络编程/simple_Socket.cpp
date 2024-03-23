#include <iostream>
#include <sys/socket.h> //for socket(), connect(), send(), recv() functions
#include <netinet/in.h> //for sockaddr_in structure
#include <unistd.h> // for read() and write() close() functions
#include <cstring>  //for strlen() function

int main(){
    int sockfd;
    struct sockaddr_in serverAddr;

    //创建socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        std::cerr << "Error in connection.\n";
        exit(1);
    }
    std::cout << "Server socket created.\n";

    //设置地址
    memset(&serverAddr, '\0', sizeof(serverAddr));

    //指定服务器地址
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //连接服务器
    if(connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
        std::cerr << "Error in connection.\n";
        exit(1);
    }
    std::cout << "Connected to server.\n";

    //发送数据
    const char* msg = "Hello server!";
    write(sockfd, msg, strlen(msg));

    //接收数据
    char buffer[1024] = {0};
    read(sockfd, buffer, sizeof(buffer));
    std::cout << "Server: " << buffer << std::endl;

    //关闭socket
    close(sockfd);

    return 0;

}