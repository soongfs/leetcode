#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        istringstream iss(text);
        string word;
        int ans = 0;
        while (iss >> word) {
            if (ranges::all_of(word, [&](char c) {
                    return brokenLetters.find(c) == string::npos;
                })) {
                ans++;
            }
        }
        return ans;
    }
};
