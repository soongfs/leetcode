#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int max_len = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main() {
    string s = "abcabcbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}
