#include <iostream>
#include <vector>

// 函数：移除排序数组中的重复项
int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int k = 1; // k 是非重复元素应该插入的下一个位置
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            ++k;
        }
    }
    return k;
}

int main() {
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 5, 5, 6};
    int len = removeDuplicates(nums);
    std::cout << len << std::endl;
    for (int i = 0; i < len; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}