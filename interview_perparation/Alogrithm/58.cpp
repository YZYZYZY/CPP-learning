//最后一个单词的长度

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    int end = s.length() - 1;
    //从后往前找到第一个不为空格的字符
    while (end >= 0 && s[end] == ' ') {
        --end;
    }
    if (end < 0) {
        return 0;
    }
    int start = end;//这里保证了最边界的情况，即最后一个单词的长度为整个字符串的长度
    //从后往前找到第一个为空格的字符
    while (start >= 0 && s[start] != ' ') {
        --start;
    }
    return end - start;
}

int main(){
    string s = "   fly me   to   the moon  ";
    cout << lengthOfLastWord(s) << endl;
    system("pause");
    return 0;
}