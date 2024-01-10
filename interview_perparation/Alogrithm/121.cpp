//买卖股票的最佳时机
#include <iostream>
#include <vector>

using namespace std;

//从后往前遍历，记录最大值，然后计算差值，取最大值
//时间复杂度O(n^2) 超出时间限制
int maxProfit(vector<int>& prices){
    int maxprice = 0;
    int n = prices.size() - 1;
    for(int i=n;i>=0;i--){
        for(int j=0;j<i;j++){
            if(prices[i] - prices[j] > maxprice){
                maxprice = prices[i] - prices[j];
            }
        }
    }
    return maxprice;
}

//一次遍历，记录最小值，然后计算差值，取最大值
//时间复杂度O(n)
int maxProfit2(vector<int>& prices){
    int minprice = INT_MAX;
    int maxprofit = 0;
    for(int i=0;i<prices.size();i++){
        if(prices[i] < minprice){
            minprice = prices[i];
        }else if(prices[i] - minprice > maxprofit){
            maxprofit = prices[i] - minprice;
        }
    }
    return maxprofit;
}


int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
    system("pause");
    return 0;
}