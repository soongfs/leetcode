#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        int cnt[26] = {};
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        int ans = 0;
        ans += max({cnt['a' - 'a'], cnt['e' - 'a'], cnt['i' - 'a'],
                    cnt['o' - 'a'], cnt['u' - 'a']});
        int m = 0;
        for (int i = 0; i < 26; i++) {
            if (i != 'a' - 'a' && i != 'e' - 'a' && i != 'i' - 'a' &&
                i != 'o' - 'a' && i != 'u' - 'a') {
                m = max(m, cnt[i]);
            }
        }
        ans += m;
        return ans;
    }
};
