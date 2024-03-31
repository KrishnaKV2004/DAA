#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quick_select(vector<int>& arr, int low, int high, int k)
{
    if (low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1)
        {
            return arr[pivotIndex];
        }
        else if (pivotIndex > k - 1)
        {
            return quick_select(arr, low, pivotIndex - 1, k);
        }
        else
        {
            return quick_select(arr, pivotIndex + 1, high, k);
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        cin >> k;
        
        int result = quick_select(arr, 0, n - 1, k);
        if (result != -1)
        {
            cout << result << endl;
        }
        else
        {
            cout << "not present" << endl;
        }
    }
    return 0;
}
