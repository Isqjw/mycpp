#include "../head.h"

string longestPalindrome(string s)
{
    int maxIdx = 0;
    int maxLen = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        int j = i, k = i, len = 0;
        while (j - 1 >= 0 && s[j - 1] == s[i])
        {
            j--;
        }
        while (k + 1 < s.size() && s[k + 1] == s[i])
        {
            k++;
        }
        while (j >= 0 && k < s.size())
        {
            if (s[j] == s[k])
            {
                len = k - j + 1;
                if (len > maxLen)
                {
                    maxLen = len;
                    maxIdx = j;
                }
                j--;
                k++;
            }
            else
            {
                break;
            }
        }
    }

    return s.substr(maxIdx, maxLen);
}

int main()
{
    cout << longestPalindrome("babad") << endl;
    return 0;
}