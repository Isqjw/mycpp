#include "../head.h"

using namespace std;

/*
**单词拆分
**当满足以下两个条件，即说明以当前字符结尾的字符串是可以被拆分的
**1.p指向的位置的状态是1（说明0到p的字符串是可以完全拆分的），且s[p+1:i]在字典里面
**2.p指向的位置的状态是字符串的开头，且s[p+1:i]在字典里面
 */
bool wordBreak(const string &s, const vector<string> &wordDict)
{
    int maxLen = 0;

    //方便查找
    set<string> dict;
    for (auto val : wordDict)
    {
        maxLen = val.size() > maxLen ? val.size() : maxLen;
        dict.insert(val);
    }

    //动态规划
    vector<int> fn = vector<int>(s.size(), 0);
    for (int i = 0; i < s.size(); ++i)
    {
        int p = i;
        while (p >= 0 && i - p <= maxLen)
        {
            if ((0 == p && dict.find(s.substr(p, i + 1 - p)) != dict.end()) || (1 == fn[p] && dict.find(s.substr(p + 1, i - p)) != dict.end()))
            {
                fn[i] = 1;
            }
            p--;
        }
    }

    return fn.back();
}

int main()
{
    vector<string> test;
    test.push_back("apple");
    test.push_back("pen");

    cout << wordBreak("applepenapple", test) << endl;

    return 0;
}