#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if two elements exist whose sum is equal to the given key
bool hasSumPair(const vector<int>& arr, int key) {
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Sort the array

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == key) {
            cout << arr[left] << " " << arr[right] << endl;
            return true;
        } else if (currentSum < key) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int key;
        cin >> key;

        if (!hasSumPair(arr, key)) {
            cout << "No Such Elements Exist" << endl;
        }
    }

    return 0;
}