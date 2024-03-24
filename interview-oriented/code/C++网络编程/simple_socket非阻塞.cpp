#include <fcntl.h> // For O_NONBLOCK
#include <sys/socket.h>

int sockfd = socket(AF_INET, SOCK_STREAM, 0);

// 获取套接字当前的标志
int flags = fcntl(sockfd, F_GETFL, 0);
if (flags == -1) {
    // 处理错误
}

// 设置套接字为非阻塞模式
if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
    // 处理错误
}
