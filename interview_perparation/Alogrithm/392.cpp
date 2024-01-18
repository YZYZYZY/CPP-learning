//判断子序列

#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(string s, string t)
{
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            j++;
    }
    return i == s.size();
}

int main()
{
    // Test code for isSubsequence function
    cout << isSubsequence("abc", "ahbgdc") << endl;
    cout << isSubsequence("axc", "ahbgdc") << endl;
    system("pause");
    return 0;
}