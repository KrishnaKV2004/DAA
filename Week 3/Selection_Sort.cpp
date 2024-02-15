#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[idx])
                idx = j;
        }
        if (idx != i) 
        {
            swap(arr[idx],arr[i]);
            swaps++;
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nNumber of comparisons: " << comparisons << "\n";
    cout << "Number of swaps: " << swaps << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        selectionSort(arr, n);
    }
    return 0;
}