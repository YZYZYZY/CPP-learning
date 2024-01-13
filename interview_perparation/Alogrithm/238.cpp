//除自身以外数组的乘积
#include <iostream>
#include <vector>

using namespace std;

//使用两个数组，分别存储当前元素左边的乘积和右边的乘积
vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> answer(n,1);
    //从左往右遍历，计算当前元素左边的乘积
    //要注意某些初始化的值
    for(int i=1;i<n;i++){
        answer[i] = answer[i-1] * nums[i-1];
    }
    //从右往左遍历，计算当前元素右边的乘积
    int right = 1;
    for(int i=n-1;i>=0;i--){
        answer[i] *= right;
        right *= nums[i];
    }
    return answer;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> answer = productExceptSelf(nums);
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}