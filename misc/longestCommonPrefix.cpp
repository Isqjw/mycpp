#include "../head.h"

string longestCommonPrefix(vector<string> &strs)
{
    int i = 0, j = 0, len = -1;
    char c;
    while (i < strs.size())
    {
        string &s = strs[i];
        if (s.size() <= j)
        {
            break;
        }
        if (0 == i)
        {
            c = s[j];
        }
        else
        {
            if (c != s[j])
            {
                break;
            }
        }
        if (i == strs.size() - 1)
        {
            i = 0;
            j++;
            len++;
        }
        else
        {
            i++;
        }
    }

    if (-1 == len)
    {
        return "";
    }

    string res = strs[0].substr(0, len + 1);
    return res;
}

int main()
{
    vector<string> strs = {
    };
    cout << longestCommonPrefix(strs) << endl;

    return 0;
}