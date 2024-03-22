#include <iostream>
#include <map>
#include <string>

int main() {
    // 创建map
    std::map<std::string, int> ageMap;

    // 添加元素
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap.insert(std::make_pair("Charlie", 20));

    // 访问元素
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;

    // 遍历map
    for(const auto& pair : ageMap) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    // 删除元素
    ageMap.erase("Bob");

    // 检查元素是否存在
    if(ageMap.find("Bob") == ageMap.end()) {
        std::cout << "Bob not found." << std::endl;
    }

    return 0;
}
