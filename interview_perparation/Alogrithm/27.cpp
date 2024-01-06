#include <iostream>
#include <vector>

using namespace std;

//两个下标，这个是从前面考虑，将不等于val的数放到前面，返回前面的长度
int removeElement(vector<int>& nums, int val){
    int i = 0;
    for(int j=0;j<nums.size();j++){
        if(nums[j] != val){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

//两个下标，这个是从后面考虑，将val放到后面，返回前面的长度
int removeElement2(vector<int>& nums, int val){
    int i = 0;
    int n = nums.size();
    while(i<n){
        if(nums[i] == val){
            nums[i] = nums[n-1];
            n--;
        }else{
            i++;
        }
    }
    return i;
}

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int len = removeElement(nums, val);
    cout << len << endl;
    for(int i=0;i<len;i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}