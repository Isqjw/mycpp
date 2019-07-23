#include "../head.h"

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];
    int idx = start + 1;
    for (int i = idx; i <= end; ++i)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }
    swap(arr[start], arr[idx - 1]);
    return idx - 1;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end || start < 0 || end >= arr.size())
    {
        return;
    }

    int idx = partition(arr, start, end);
    quickSort(arr, start, idx - 1);
    quickSort(arr, idx + 1, end);
}

int main()
{
    vector<int> arr = {6, 5, 4, 1, 2, 3, 7, 9, 8, 10};
    quickSort(arr, 0, arr.size() - 1);

    for (auto iter = arr.begin(); iter != arr.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}