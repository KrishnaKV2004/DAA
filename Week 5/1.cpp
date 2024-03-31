#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

pair<char, int> max_occurrences(const string& str) {
    unordered_map<char, int> freq_map;
    for(char c : str) {
        freq_map[c]++;
    }

    char max_char = '\0';
    int max_count = 0;
    bool duplicates_present = false;

    for(const auto& entry : freq_map) {
        if(entry.second > max_count) {
            max_count = entry.second;
            max_char = entry.first;
            duplicates_present = false;
        } else if (entry.second == max_count) {
            duplicates_present = true;
        }
    }

    if(max_count == 1 || duplicates_present) {
        return make_pair('\0', -1);
    }

    return make_pair(max_char, max_count);
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // ignore newline character

    while(T--) {
        int n;
        string str;
        cin >> n;
        cin.ignore(); // ignore newline character
        getline(cin, str);

        pair<char, int> result = max_occurrences(str);
        if(result.first == '\0') {
            cout << "No Duplicates Present" << endl;
        } else {
            cout << result.first << " " << result.second << endl;
        }
    }
    return 0;
}