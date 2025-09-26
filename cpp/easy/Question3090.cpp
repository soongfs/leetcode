#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int, int> map;
        int max_len = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            while (map[s[right]] == 2) {
                map[s[left]]--;
                left++;
            }
            map[s[right]]++;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
