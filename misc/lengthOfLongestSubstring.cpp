#include "../head.h"

/*
**无重复字符的最长子串
**滑动窗口
 */
int lengthOfLongestSubstring(string s)
{
    map<char, int> sMap;
    int maxLen = 0;
    for (int i = 0, j = 0; j < s.size(); ++j)
    {
        auto iter = sMap.find(s[j]);
        if (sMap.end() != iter)
        {
            i = max(iter->second + 1, i);
            iter->second = j;
        }
        sMap.insert(make_pair(s[j], j));
        maxLen = max(maxLen, j - i + 1);
    }
    return maxLen;
}

int main()
{
    cout << lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}