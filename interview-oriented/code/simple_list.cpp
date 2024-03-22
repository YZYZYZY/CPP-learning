#include <iostream>
#include <list>

int main() {
    std::list<int> lst; // 创建一个int类型的list

    // 添加元素
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    // 遍历list
    std::cout << "List elements: ";
    for(int i : lst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 在list中插入元素，先获取一个指向第一个元素的迭代器
    auto it = lst.begin();
    ++it; // 移动到第二个元素
    lst.insert(it, 15); // 在第二个元素前插入15

    // 删除第三个元素，迭代器已经在第二个元素，所以只需要再移动一次
    ++it;
    lst.erase(it);

    // 使用迭代器再次遍历list
    std::cout << "List after insertion and deletion: ";
    for(auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
