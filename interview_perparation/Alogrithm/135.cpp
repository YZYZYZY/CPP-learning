//分发糖果

#include <iostream>
#include <vector>

using namespace std;

//这道题目的思路是，先从左往右遍历，然后再从右往左遍历，然后取两者的最大值
//时间复杂度O(n)
int candy(vector<int>& ratings){
    int n = ratings.size();
    vector<int> left(n);
    for(int i=0;i<n;i++){
        if(i > 0 && ratings[i] > ratings[i-1]){
            left[i] = left[i-1] + 1;//为什么是left[i-1] + 1，因为如果当前的ratings[i]比前一个ratings[i-1]大，那么就需要在前一个的基础上加1。不是简单的自己加一
        }else{
            left[i] = 1;
        }
    }
    int right = 0, ret = 0;
    for(int i=n-1;i>=0;i--){
        if(i < n-1 && ratings[i] > ratings[i+1]){
            right++;//为什么这个不是数组？因为这个right是用来记录当前的位置，而不是用来记录当前的值
        }else{
            right = 1;
        }
        ret += max(left[i], right);
    }
    return ret;
}

//有一个错误解发，但是我不知道为什么是错误的
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candys(n,1);
    for(int i = 1; i<n-1;i++){
        if(ratings[i] > ratings[i-1]){
            candys[i] = candys[i] + 1;
        }else if(ratings[i] < ratings[i-1]){
            candys[i-1] = candys[i-1] + 1;
        }
        if(ratings[i] > ratings[i+1]){
            candys[i] = candys[i] + 1;
        }else if(ratings[i] < ratings[i+1]){
            candys[i+1] = candys[i+1] + 1;
        }
    }
    //candys数组求和
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += candys[i];
    }
    return sum;
}


int main(){
    vector<int> ratings = {1,0,2};
    cout << candy(ratings) << endl;
    system("pause");
    return 0;
}