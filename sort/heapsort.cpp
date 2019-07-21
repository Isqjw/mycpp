#include "../head.h"

void swap(vector<int> &arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapAdjuest(vector<int> &arr, int pos, int len)
{
    int left = pos * 2;
    int right = pos * 2 + 1;
    int largest = pos;

    if (left < len && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < len && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest == pos)
    {
        return;
    }

    swap(arr, largest, pos);

    heapAdjuest(arr, largest, len);
}

void heapBuild(vector<int> &arr)
{
    for (int i = arr.size() / 2; i >= 0; --i)
    {
        heapAdjuest(arr, i, arr.size());
    }
}

void heapSort(vector<int> &arr)
{
    heapBuild(arr);

    for (int i = arr.size() - 1; i > 0; --i)
    {
        swap(arr, 0, i);
        heapAdjuest(arr, 0, i);
    }
}

int main()
{
    vector<int> arr = {6, 5, 4, 1, 2, 3, 7, 9, 8, 10};
    heapSort(arr);

    for (auto iter = arr.begin(); iter != arr.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}