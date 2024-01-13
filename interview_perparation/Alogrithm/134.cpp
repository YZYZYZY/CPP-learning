//加油站 这道题有点儿没有理解到

#include <iostream>
#include <vector>

using namespace std;

//其实对于每一步来说只需要判断当前加油站的油，减去到下一站的油，+下一站的油，大于需要去下下一站的油,注意是环形。但是这样的话时间复杂度是O(n^2)
int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
    int n = gas.size();
    //对于每一个加油站，都尝试作为起点
    for(int i = 0; i < n; i++){
        int j = i;//这个j是用来记录当前的位置，是我完全没有想到的一层逻辑
        int remain = gas[i];
        //如果当前剩余的油可以到达下一站，那么就继续更新剩余的油，直到环形回到起点
        while(remain - cost[j] >=0){
            remain = remain - cost[j] + gas[(j+1)%n];
            j = (j+1)%n;
            if(j == i){
                return i;
            }
        }
    }
    return -1;
}

//优化的方法，时间复杂度为O(n)
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost){
    int n = gas.size();
    int i = 0;
    while(i < n){
        int sumOfGas = 0, sumOfCost = 0;
        int cnt = 0;//记录当前的加油站的个数
        while(cnt < n){
            int j = (i + cnt) % n;//这里的j是用来记录当前的位置
            sumOfGas += gas[j];
            sumOfCost += cost[j];
            if(sumOfCost > sumOfGas){
                break;
            }
            cnt++;
        }
        if(cnt == n){
            return i;
        }else{
            i = i + cnt + 1;//为什么不是i = i + 1，因为如果是i = i + 1的话，那么就会出现重复的情况，比如[1,2,3,4,5]和[3,4,5,1,2]，因为这两个数组的结果都是3，但是实际上第一个数组的结果是0，第二个数组的结果是3
        }
    }
    return -1;
}

//优化的方法，时间复杂度为O(n)
int canCompleteCircuit3(std::vector<int>& gas, std::vector<int>& cost) {
    int totalTank = 0;
    int currTank = 0;
    int startingStation = 0;
    for (int i = 0; i < gas.size(); i++) {
        totalTank += gas[i] - cost[i];
        currTank += gas[i] - cost[i];
        // 如果在这个站点油箱油量变为负，无法到达下一个站点
        // 那么从下一个站点重新开始，并将当前油箱油量重置为零
        if (currTank < 0) {
            startingStation = i + 1;
            currTank = 0;
        }
    }
    // 检查是否能够环绕一圈
    return totalTank >= 0 ? startingStation : -1;
}

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << canCompleteCircuit(gas, cost) << endl;
    cout << canCompleteCircuit2(gas, cost) << endl;
    cout << canCompleteCircuit3(gas, cost) << endl;
    system("pause");
    return 0;
}