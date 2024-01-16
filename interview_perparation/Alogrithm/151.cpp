//翻转字符串中的单词

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//方法一：双指针法 首先要找到字符串中的全部单词（就用一个end和一个start指针），然后把单词全部存放在字符串数组中，之后直接翻转数组
string reverseWords(string s) {
    vector<string> strs;
    int start = 0, end = 0;
    while (end < s.size()) {
        while (end < s.size() && s[end] != ' ') {
            ++end;
        }
        strs.push_back(s.substr(start, end - start));

        while (end < s.size() && s[end] == ' ') {
            ++end;
        }
        start = end;
    }
    string res = "";
    for (int i = strs.size() - 1; i >= 0; --i) {
        res += strs[i];
        if (i > 0) {
            res += " ";
        }
    }
    return res;
}
//自己跟着思路复现
string reverseWords2(string s){
    vector<string> strs;
    int start = 0, end = 0;
    while(end < s.size()){
        while(end < s.size() && s[end] != ' '){//这里的条件判断是为了找到第一个单词的末尾
            ++end;
        }
        strs.push_back(s.substr(start,end-start));//第一个如果是空格，那么就会把空字符串放入数组中？
        while(end < s.size() && s[end] == ' '){//这里的条件判断是为了找到第二个单词的开头
            ++end;
        }
        start = end;
    }
     // 构建结果字符串
    string res = "";
    for (int i = strs.size() - 1; i >= 0; --i) {
        if (!strs[i].empty()) {
            res += strs[i];
            if (i > 0) res += " ";
        }
    }
    // 删除尾随空格
    if (!res.empty() && res.back() == ' ') {
        res.pop_back();
    }
    return res;
}


int main() {
    string s = "  hello world  ";
    cout << reverseWords2(s) << endl;
    system("pause");
    return 0;
}