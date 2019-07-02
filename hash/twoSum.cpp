#include "../head.h"

using namespace std;

/*
**两数之和
**可用unorder_map优化以下代码
 */
void myInsert(map<int, int> &m, int val)
{
    auto iter = m.find(val);
    if (m.end() == iter)
    {
        m.insert(make_pair(val, 1));
    }
    else
    {
        iter->second++;
    }
}

void myErase(map<int, int> &m, int val)
{
    auto iter = m.find(val);
    if (m.end() != iter)
    {
        iter->second--;
    }
    // if (0 >= iter->second)
    // {
    //     m.erase(iter);
    // }
}

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> nmap;
    for (auto val : nums)
    {
        myInsert(nmap, val);
    }
    vector<int> idxs = vector<int>(2, -1);

    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];
        auto siter = nmap.find(num);
        if (nmap.end() != siter && siter->second > 0)
        {
            myErase(nmap, num);
            auto diter = nmap.find(target - num);
            if (nmap.end() != diter && diter->second > 0)
            {
                idxs[0] = i;
                for (int j = 0; j < nums.size(); ++j)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    if (nums[j] == target - num)
                    {
                        idxs[1] = j;
                        return idxs;
                    }
                }
            }
            else
            {
                myInsert(nmap, num);
            }
        }
    }

    return idxs;
}

int main()
{
    vector<int> nums{2, 7, 11, 15};
    vector<int> result = twoSum(nums, 9);

    for_each(result.begin(), result.end(), [](const int &val) -> void {
        cout << val << endl;
    });

    return 0;
}
