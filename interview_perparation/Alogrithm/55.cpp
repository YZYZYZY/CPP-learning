//55.跳跃游戏
#include <iostream>
#include <vector>

using namespace std;

//贪心算法
bool canJump(vector<int>& nums){
    int n = nums.size();
    int rightmost = 0;
    for(int i=0;i<n;i++){
        if(i <= rightmost){
            rightmost = max(rightmost,i+nums[i]);
            if(rightmost >= n-1){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums) << endl;
    system("pause");
    return 0;
}