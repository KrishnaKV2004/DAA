#include <iostream>

using namespace std;

int comparisions = 0;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int inversions = 0;
    int i = left, j = mid, k = left;
    
    while ((i <= mid - 1) && (j <= right))
    {
        comparisions ++;

        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inversions += mid - i;
        }
    }
    
    while (i <= mid - 1)
        temp[k++] = arr[i++];
        
    while (j <= right)
        temp[k++] = arr[j++];
        
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
        
    return inversions;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int inversions = 0;

    if (right > left)
    {
        int mid = (right + left) / 2;
        
        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);
        
        inversions += merge(arr, temp, left, mid + 1, right);
    }
    return inversions;
}

int main()
{
    int n;
    cout << "\nElements In Array ? --> ";
    cin >> n;
    
    int arr[n];
    cout << "\nEnter Elements -->\n\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i+1 << " --> ";
        cin >> arr[i];
    }
    
    int temp[n];
    int inversions = mergeSort(arr, temp, 0, n - 1);

    cout << "\nSorted Array -->\n\n";

    for (int i=0; i<n; i++)
    {
        cout << arr[i] << "\t";
    }
    
    cout << "\n\nNumber Of Cmparisions --> " << comparisions << endl;
    cout << "Number Of Inversions --> " << inversions << endl;
    
    return 0;
}