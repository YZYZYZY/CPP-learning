//多数元素
#include <iostream>
#include <vector>
#include <algorithm>

int majorityElement(std::vector<int>& nums){
    int count = 0;
    int candidate = 0;

    for(int num:nums){
        if(count == 0 ){
            candidate = num;
        }
        count += (num == candidate ? 1 : -1);
    }
    return candidate;
}

int majorityElement_sort(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

int main(){
    std::vector<int> nums = {2,2,1,1,1,2,2};
    int res = majorityElement_sort(nums);
    std::cout << res << std::endl;
    system("pause");
    return 0;
}