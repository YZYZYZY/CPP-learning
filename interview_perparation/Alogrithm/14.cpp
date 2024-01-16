//最长公共前缀
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//方法一：横向扫描:就是同时遍历每个单词，有相同的计数器就加一，没有就清零。直到一个单词到结尾
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    int count = strs.size();//单词的个数
    int length = strs[0].size();//第一个单词的长度
    for (int i = 0; i < length; ++i) {
        char c = strs[0][i];//第一个单词的第i个字符
        for (int j = 1; j < count; ++j) {
            if (i == strs[j].size() || strs[j][i] != c) {//如果第j个单词的长度小于i或者第j个单词的第i个字符不等于第一个单词的第i个字符
                return strs[0].substr(0, i); //这个条件判断通常用于在遍历字符串数组时，检查每个字符串的相应位置的字符是否都相同。如果已经遍历完了某个字符串，或者某个字符串的相应位置的字符不等于预期的字符，那么就满足这个条件判断。
            }
        }
    }
    return strs[0];
}
//自己跟着思路复现
string longestCommonPrefixs2(vector<string>& strs){
    if(strs.empty()){
        return "";
    }
    int count = strs.size();
    int length = strs[0].size();
    for(int i=0;i<length;++i){ //循环的条件就是第一个单词的长度
        char c = strs[0][i];
        for(int j=0;j<count;j++){
            if(i==strs[j].size() || strs[j][i]!=c){//这个条件只能想到一个，没有想到整个字符串的长度小于i的情况
                return strs[0].substr(0,i);//这里同时也满足返回空字符串的条件
            }
        }
    }
    return strs[0];
}



int main(){
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs) << endl;
    system("pause");
    return 0;
}