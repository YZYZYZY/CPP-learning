#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {4, 1, 3, 5, 2};

    // 使用 std::sort 对 nums 进行排序
    std::sort(nums.begin(), nums.end());

    // 输出排序后的数组
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
