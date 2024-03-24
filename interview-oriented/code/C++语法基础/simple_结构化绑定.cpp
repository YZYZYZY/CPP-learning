#include <tuple>
#include <map>
#include <string>
#include <iostream>

int main() {
    // 使用结构化绑定解包std::tuple
    std::tuple<int, double, std::string> myTuple{1, 2.3, "example"};
    auto [x, y, z] = myTuple;
    std::cout << x << ", " << y << ", " << z << std::endl;

    // 使用结构化绑定遍历std::map
    std::map<std::string, int> myMap{{"one", 1}, {"two", 2}};
    for (const auto& [key, value] : myMap) {
        std::cout << key << ": " << value << std::endl;
    }

    // 使用结构化绑定解包数组
    int myArray[] = {1, 2, 3};
    auto [a, b, c] = myArray;
    std::cout << a << ", " << b << ", " << c << std::endl;
}
