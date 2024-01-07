#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();

    int k = 2; // k 指向非重复元素应该插入的位置
    for (int i = 2; i < nums.size(); ++i) {
        if (nums[i] != nums[k - 2]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main() {
    std::vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3}; // 示例数组
    int len = removeDuplicates(nums);

    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < len; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\nNew length of array: " << len << std::endl;
    system("pause");
    return 0;
}
