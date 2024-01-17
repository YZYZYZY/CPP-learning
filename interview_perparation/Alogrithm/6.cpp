//Z字形变换 这道题没有搞懂，思路都没有搞懂

#include <iostream>
#include <string>


using namespace std;

string convert(string s, int numRows){
    if(numRows == 1 || s.length() < numRows){
        return s;
    }
    string res;
    int n = s.length();
    int cycleLen = 2 * numRows - 2;
    for(int i=0;i<numRows;++i){
        for(int j=0;j+i<n;j+=cycleLen){
            res += s[j+i];
            if(i!=0 && i!=numRows-1 && j+cycleLen-i<n){
                res += s[j+cycleLen-i];
            }
        }
    }
    return res;
}