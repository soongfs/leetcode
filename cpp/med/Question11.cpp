#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int ans = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            height[i] < height[j] ? i++ : j--;
        }
        return ans;
    }
};
