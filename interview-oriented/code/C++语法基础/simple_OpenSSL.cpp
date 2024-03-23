#include <openssl/ssl.h>
#include <openssl/err.h>

void initializeSSL() {
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

int main() {
    initializeSSL();
    
    const SSL_METHOD* method = TLS_server_method(); // 或 TLS_client_method();
    SSL_CTX* ctx = SSL_CTX_new(method);
    
    // 加载证书和私钥
    SSL_CTX_use_certificate_file(ctx, "server.crt", SSL_FILETYPE_PEM);
    SSL_CTX_use_PrivateKey_file(ctx, "server.key", SSL_FILETYPE_PEM);
    
    // 假设TCP连接已经建立，sockfd是底层套接字
    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    
    // 握手
    if (SSL_accept(ssl) <= 0) { // 服务端使用SSL_accept，客户端使用SSL_connect
        ERR_print_errors_fp(stderr);
    }
    
    // 发送和接收数据
    SSL_write(ssl, "hello", 5);
    
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    cleanup_openssl(); // 清理OpenSSL
}
