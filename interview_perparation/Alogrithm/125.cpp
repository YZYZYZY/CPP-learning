//验证回文串

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s)
{
    if (s.empty())//空字符串也是回文串,有很多个空字符也是回文串？
        return true;
    int i = 0, j = s.size() - 1;
    while (i < j)
    {   
        //如果不是字母或数字，跳过
        while (i < j && !isalnum(s[i]))//isalnum()判断是否为字母或数字
            i++;
        while (i < j && !isalnum(s[j]))
            j--;
        //如果不相等，返回false
        if (tolower(s[i]) != tolower(s[j]))//tolower()将大写字母转换为小写字母
            return false;
        i++;
        j--;
    }
    return true;
}


int main(){
    // Test code for isPalindrome function
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << isPalindrome("race a car") << endl;
    cout << isPalindrome("12321") << endl;
    cout << isPalindrome("hello") << endl;
    system("pause");
    return 0;
    

}


