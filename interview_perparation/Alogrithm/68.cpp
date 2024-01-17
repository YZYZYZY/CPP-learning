//文本左右对齐

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth){
    vector<string> ans;
    int right = 0, n = words.size();
    while(true){
        int left = right;
        int sumLen = 0;
        while(right<n && sumLen+words[right].length()+right-left<=maxWidth){
            sumLen += words[right].length();
            ++right;
        }
        if(right == n){
            string s;
            for(int i=left;i<right;++i){
                s += words[i];
                if(s.length()<maxWidth){
                    s += " ";
                }
            }
            while(s.length()<maxWidth){
                s += " ";
            }
            ans.push_back(s);
            return ans;
        }
        int numWords = right - left;
        int numSpaces = maxWidth - sumLen;
        if(numWords == 1){
            string s = words[left];
            while(numSpaces--){
                s += " ";
            }
            ans.push_back(s);
            continue;
        }
        int avgSpaces = numSpaces / (numWords - 1);
        int extraSpaces = numSpaces % (numWords - 1);
        string s1;
        for(int i=left;i<right-1;++i){
            s1 += words[i];
            if(s1.length()<maxWidth){
                for(int j=0;j<avgSpaces;++j){
                    s1 += " ";
                }
                if(extraSpaces>0){
                    s1 += " ";
                    --extraSpaces;
                }
            }
        }
        s1 += words[right-1];
        ans.push_back(s1);
    }
}

// 辅助函数，用于在单词间添加空格
string join(const vector<string>& words, int left, int right, int maxWidth, bool lastLine = false) {
    if (left == right) {
        return words[left] + string(maxWidth - words[left].length(), ' ');
    }

    int totalSpaces = maxWidth;
    for (int i = left; i <= right; i++) {
        totalSpaces -= words[i].length();
    }

    int spaces = lastLine ? 1 : totalSpaces / (right - left);
    int extraSpaces = lastLine ? 0 : totalSpaces % (right - left);

    string result = words[left];
    for (int i = left + 1; i <= right; i++) {
        result += string(spaces + (i - left <= extraSpaces ? 1 : 0), ' ') + words[i];
    }

    if (lastLine) {
        result += string(maxWidth - result.length(), ' ');
    }
    return result;
}

vector<string> fullJustify2(vector<string>& words, int maxWidth) {
    vector<string> result;
    int left = 0;

    while (left < words.size()) {
        int right = left;
        int sumLength = words[right++].length();

        while (right < words.size() && sumLength + 1 + words[right].length() <= maxWidth) {
            sumLength += 1 + words[right++].length();
        }

        result.push_back(join(words, left, right - 1, maxWidth, right == words.size()));
        left = right;
    }

    return result;
}