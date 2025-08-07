#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> ret(n, -1);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i < (2 * k + 1) - 1) {
                continue;
            }
            ret[i - k] = sum / (2 * k + 1);
            sum -= nums[i - (2 * k + 1) + 1];
        }
        return ret;
    }
};