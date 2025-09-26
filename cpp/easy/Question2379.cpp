#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = 0x3f3f3f3f, cnt = 0;
        for (int i = 0; i < blocks.length(); i++) {
            if (blocks[i] == 'W') {
                cnt++;
            }
            if (i < k - 1) {
                continue;
            }
            ans = min(ans, cnt);
            if (blocks[i - k + 1] == 'W') {
                cnt--;
            }
        }
        return ans;
    }
};