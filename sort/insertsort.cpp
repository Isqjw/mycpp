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

int main()
{
    vector<int> arr = {6, 5, 4, 15, 2, 3, 7, 9, 8, 10};
    insertSort(arr, 0, 1);

    for (auto iter = arr.begin(); iter != arr.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}