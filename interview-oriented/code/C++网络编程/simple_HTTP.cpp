#include <iostream>
#include <string>
#include <sstream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string get_http_response(const std::string& url) {
    try {
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve(url, "http");
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        // 构造HTTP GET请求
        std::ostringstream request_stream;
        request_stream << "GET / HTTP/1.1\r\n";
        request_stream << "Host: " << url << "\r\n";
        request_stream << "Connection: close\r\n\r\n";
        std::string request = request_stream.str();

        // 发送请求
        boost::asio::write(socket, boost::asio::buffer(request));

        // 读取并打印响应
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");
        std::ostringstream response_stream;
        response_stream << &response;
        return response_stream.str();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return "";
    }
}

int main() {
    std::string url = "www.example.com"; // 你要访问的URL
    std::string response = get_http_response(url);
    std::cout << "Response:\n" << response << std::endl;
    return 0;
}
