#include <iostream>
#include <fstream>

class RAIIFile {
private:
    std::fstream file;
public:
    RAIIFile(const std::string& filename) {
        file.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file.");
        }
    }

    ~RAIIFile() {
        if (file.is_open()) {
            file.close();
        }
    }

    // 禁止复制和赋值
    RAIIFile(const RAIIFile&) = delete;
    RAIIFile& operator=(const RAIIFile&) = delete;

    // 允许移动
    RAIIFile(RAIIFile&& other) noexcept : file(std::move(other.file)) {
    }

    RAIIFile& operator=(RAIIFile&& other) noexcept {
        if (this != &other) {
            file = std::move(other.file);
        }
        return *this;
    }

    // 其他成员函数...
};