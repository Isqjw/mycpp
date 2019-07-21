#include "../head.h"

int maxArea(vector<int> &height)
{
    int area = 0;
    int i = 0;
    int j = height.size() - 1;

    while (i < j)
    {
        if (height[i] < height[j])
        {
            area = max(area, height[i] * (j - i));
            i++;
        }
        else
        {
            area = max(area, height[j] * (j - i));
            j--;
        }
    }

    return area;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;

    return 0;
}