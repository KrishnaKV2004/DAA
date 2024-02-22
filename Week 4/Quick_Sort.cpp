#include <iostream>

using namespace std;

int comparisons = 0; 
int swaps = 0; 

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++)
    {
        comparisons++; 
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            swaps++; 
        }
    }
    
    swap(arr[i + 1], arr[high]);
    swaps++; 
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    cout << "\nNumber Of Elements ? --> ";
    cin >> n;

    int arr[n];

    cout << "\nEnter Elements -->\n\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i+1 << " --> ";
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    
    cout << "\nSorted Array -->\n\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    
    cout << endl;
    
    cout << "\nNumber Of Comparisons --> " << comparisons << endl;
    cout << "number Of Swaps --> " << swaps << endl;
    
    return 0;
}