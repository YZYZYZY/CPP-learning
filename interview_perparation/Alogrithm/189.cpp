#include <iostream>
#include <vector>
#include <algorithm>

//翻转3次数组
void rotate(std::vector<int>& nums, int k) {
    k = k % nums.size(); // 处理 k 大于数组长度的情况
    std::reverse(nums.begin(), nums.end()); // 反转整个数组
    std::reverse(nums.begin(), nums.begin() + k); // 反转前 k 个元素
    std::reverse(nums.begin() + k, nums.end()); // 反转剩余元素
}

//将k个元素放到数组头部
void rotate2(std::vector<int>& nums, int k) {
    k = k % nums.size(); // 处理 k 大于数组长度的情况
    std::vector<int> temp(nums.end() - k, nums.end()); // 将后 k 个元素存到临时数组中
    nums.erase(nums.end() - k, nums.end()); // 删除后 k 个元素
    nums.insert(nums.begin(), temp.begin(), temp.end()); // 将临时数组插入到 nums 的头部
}
//循环k次，每次将数组最后一个元素放到数组头部
void rotate3(std::vector<int>& nums, int k) {
    k = k % nums.size(); // 处理 k 大于数组长度的情况
    for (int i = 0; i < k; ++i) {
        int temp = nums.back(); // 取出最后一个元素
        nums.pop_back(); // 删除最后一个元素
        nums.insert(nums.begin(), temp); // 将最后一个元素插入到数组头部
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
    // 输出结果
    for (int num : nums) {
        std::cout << num << " ";
    }
    system("pause");
    return 0;
}
