#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec; // 创建一个int类型的vector

    // 添加元素
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // 遍历vector
    std::cout << "Vector elements: ";
    for(int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 插入元素到第二个位置
    vec.insert(vec.begin() + 1, 15);

    // 删除第三个元素
    vec.erase(vec.begin() + 2);

    // 使用迭代器遍历vector
    std::cout << "Vector after insertion and deletion: ";
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
