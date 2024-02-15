#include <bits/stdc++.h>
using namespace std;

bool duplicate(int arr[], int n) 
{
    int c=0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
           
            if (arr[i]==arr[j])
               c++;
        }
        if (c==0) 
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int main()
{
    int n;
    bool check;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    check = duplicate(arr, n);
    
    if (check == false)
    {
        cout<<"no"<<endl;
    }
    else
    {
        cout<<"yes"<<endl;
    }
    return 0;
}