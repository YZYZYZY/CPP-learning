//122. 买卖股票的最佳时机 II
#include <iostream>
#include <vector>

using namespace std;

//为什么贪心算法可以得到最优解？
int maxprofit(vector<int>& prices){
    int maxprofit = 0;
    for(int i=1;i<prices.size();i++){
        if(prices[i] > prices[i-1]){
            maxprofit += prices[i] - prices[i-1];
        }
    }
    return maxprofit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxprofit(prices) << endl;
    system("pause");
    return 0;
}