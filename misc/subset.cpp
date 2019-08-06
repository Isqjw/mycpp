#include "../head.h"

void findSubSets(vector<int> &nums, vector<int> record, int idx, vector<vector<int>> &res)
{
    if (idx >= nums.size())
    {
        res.push_back(record);
        return;
    }

    //不放
    findSubSets(nums, record, idx + 1, res);
    //放
    record.push_back(nums[idx]);
    findSubSets(nums, record, idx + 1, res);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> record;

    findSubSets(nums, record, 0, res);

    return res;
}

vector<vector<int>> bsubsets(vector<int> &nums)
{
    vector<vector<int>> res;
    unsigned int value = pow(2, nums.size());
    for (int i = 0; i < value; ++i)
    {
        vector<int> tmp;
        unsigned int mask = (1 << (nums.size() - 1));
        for (int j = 0; j < nums.size(); ++j)
        {
            if (mask & i)
            {
                tmp.push_back(nums[j]);
            }
            mask >>= 1;
        }
        res.push_back(tmp);
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subset = bsubsets(nums);
    for (int i = 0; i < subset.size(); ++i)
    {
        for (int j = 0; j < subset[i].size(); ++j)
        {
            cout << subset[i][j] << ',';
        }
        cout << endl;
    }

    return 0;
}