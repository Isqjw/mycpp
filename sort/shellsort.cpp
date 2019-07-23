#include "../head.h"

void insertSort(vector<int> &arr, int start, int gap)
{
    for (int i = gap + start; i < arr.size(); i++)
    {
        for (int j = i; j - gap >= 0; j = j - gap)
        {
            if (arr[j] < arr[j - gap])
            {
                swap(arr[j], arr[j - gap]);
            }
        }
    }
}

void shellSort(vector<int> &arr)
{
    int gap = arr.size() / 2;
    while (gap > 0)
    {
        for (int i = 0; i < arr.size() - gap; ++i)
        {
            insertSort(arr, i, gap);
        }
        gap /= 2;
    }
}

int main()
{
    vector<int> arr = {6, 5, 4, 15, 2, 3, 7, 9, 8, 10};
    // vector<int> arr = {};
    // for (int i = 0; i < 10; ++i)
    // {
    //     arr.push_back(rand());
    // }
    shellSort(arr);

    for (auto iter = arr.begin(); iter != arr.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}