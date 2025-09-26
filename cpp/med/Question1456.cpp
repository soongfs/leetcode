#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            // right=i
            // right-left+1=k
            // left=i-k+1
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                cnt++;
            }
            if (i < k - 1) {
                continue;
            }
            ans = max(ans, cnt);
            char out = s[i - k + 1];
            if (out == 'a' || out == 'e' || out == 'i' || out == 'o' ||
                out == 'u') {
                cnt--;
            }
        }
        return ans;
    }
};