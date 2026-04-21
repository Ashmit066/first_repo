#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string str;
    cout << "Enter a word: ";
    cin >> str;

    unordered_map<char, int> freq;

    // Step 1: Count frequency
    for(char c : str) {
        freq[c]++;
    }

    int first = 0, second = 0;

    // Step 2 & 3: Find highest and second highest frequency
    for(auto it : freq) {
        if(it.second > first) {
            second = first;
            first = it.second;
        } else if(it.second > second && it.second < first) {
            second = it.second;
        }
    }

    // Step 4: Print character(s) with second highest frequency
    cout << "Second highest occurring character(s): ";
    for(auto it : freq) {
        if(it.second == second) {
            cout << it.first << " ";
        }
    }

    return 0;
}