//H指数
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//排序，从大到小排序之后，那么每个下标就对应发的论文篇数，一直到下标大于这个下标的元素，那就是停止了，返回这个元素
int hIdex(vector<int>& citations){
    sort(citations.begin(),citations.end(),greater<int>());
    int h = 0;
    for(int i=0;i<citations.size();i++){
        if(i+1 <= citations[i]){
            h=i+1;
        }else{
            break;
        }
    }
    return h;

}

//第二种方法，计数排序
//计数排序，统计每个引用次数的论文数量，然后从大到小遍历，直到引用次数大于等于当前的引用次数，那么就是h指数
int hIndex(vector<int>& citations){
    int n = citations.size();
    vector<int> papers(n+1,0);
    for(int c:citations){
        papers[min(n,c)]++;
    }
    int k = n;
    for(int s=papers[n];k>s;s+=papers[k]){
        k--;
    }
    return k;
}

int main(){
    vector<int> citations = {3,0,6,1,5};
    cout<<hIdex(citations)<<endl;
    system("pause");
    return 0;
}