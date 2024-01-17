//找出字符串中第一个匹配项的下标

#include <iostream>
#include <string>

using namespace std;

//还是双指针思路，一个指针指haystack(i)，一个指针指needle(j)，两个指针指向的字符相等时，同时+1，两个指针指向的字符不相同时，haystack指针加1，needle指针指向haystack指针；当needle的指针取余needle长度时，返回，i-j的位置
int strStr(string haystack, string needle){
    int n = haystack.size();
    int m = needle.size();
    if(m==0){
        return 0;
    }

    int pn = 0;
    while(pn<n-m+1){//这个条件是隐含条件
        while(pn<n-m+1 && haystack[pn]!=needle[0]){
            ++pn;
        }
        int curr_len = 0, pL = 0;
        while(pL<m && pn<n && haystack[pn]==needle[pL]){
            ++pn;
            ++pL;
            ++curr_len;
        }
        if(curr_len == m){
            return pn-m;
        }
        pn = pn - curr_len + 1;//确保匹配到了一个完整的needle之后，pn指针指向的位置
    }
    return -1;
}

int main(){
    string haystack = "hello";
    string needle = "ll";
    cout << strStr(haystack,needle) << endl;
    system("pause");
    return 0;
}