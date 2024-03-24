#include <boost/asio.hpp>
#include <iostream>

int main() {
    boost::asio::ip::address ipv4Address = boost::asio::ip::make_address("192.168.1.1");
    boost::asio::ip::address ipv6Address = boost::asio::ip::make_address("fe80::1");

    std::cout << "IPv4 Address: " << ipv4Address.to_string() << std::endl;
    std::cout << "IPv6 Address: " << ipv6Address.to_string() << std::endl;

    boost::asio::ip::tcp::endpoint endpoint(ipv4Address, 80); // IPv4地址和端口号80
    std::cout << "Endpoint: " << endpoint << std::endl;

    return 0;
}
