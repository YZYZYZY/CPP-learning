//跳跃游戏 II
#include <iostream>
#include <vector>

using namespace std;
//贪心算法
int canjump(vector<int>& nums){
    int n = nums.size();
    int rightmost = 0;
    int end = 0;
    int step = 0;
    for(int i=0;i<n-1;i++){
        if(i <= rightmost){
            //这个逻辑就已经是最优解了？
            rightmost = max(rightmost,i+nums[i]);
            if(i == end){
                end = rightmost;
                step++;
            }
        }
    }
    return step;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << canjump(nums) << endl;
    system("pause");
    return 0;
}