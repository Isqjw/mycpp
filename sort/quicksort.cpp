#include "../head.h"

int main()
{
    vector<int> arr = {6, 5, 4, 1, 2, 3, 7, 9, 8, 10};
    sortHeap(arr);

    for (auto iter = arr.begin(); iter != arr.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}