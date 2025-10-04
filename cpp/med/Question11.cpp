#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int mx = height[0], mx_i = 0;
        int ans = 0;
        for (int i = 1; i < height.size(); i++) {
            ans = max(ans, (i - mx_i) * min(mx, height[i]));
            if (height[i] > mx) {
                mx = height[i];
                mx_i = i;
            }
        }
        return ans;
    }
};
