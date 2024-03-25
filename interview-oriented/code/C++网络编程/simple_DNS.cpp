#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

std::string resolve_dns(const std::string& hostname) {
    try {
        boost::asio::io_context io_context;
        udp::resolver resolver(io_context);
        udp::resolver::results_type endpoints = resolver.resolve(udp::v4(), hostname, "domain");
        for (auto iter = endpoints.begin(); iter != endpoints.end(); ++iter) {
            std::cout << "Resolved IP address: " << iter->endpoint().address().to_string() << std::endl;
        }
        return endpoints.begin()->endpoint().address().to_string();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return "";
    }
}

int main() {
    std::string hostname = "www.example.com"; // 要解析的主机名
    std::string ip_address = resolve_dns(hostname);
    if (!ip_address.empty()) {
        std::cout << "IP address of " << hostname << ": " << ip_address << std::endl;
    } else {
        std::cerr << "Failed to resolve DNS for " << hostname << std::endl;
    }
    return 0;
}
