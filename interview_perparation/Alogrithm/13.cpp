//罗马数组转整数

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    //首先建立一个哈希表来映射符号和值，然后我们从左往右遍历字符串，如果当前字符代表的值不小于其右边，就加上该值；否则就减去该值。
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50}, 
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        int value = symbolValues[s[i]];
        if (i < n - 1 && value < symbolValues[s[i + 1]]) {
            ans -= value;
        } else {
            ans += value;
        }
    }
    return ans;
}

int main(){
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    system("pause");
    return 0;
}
