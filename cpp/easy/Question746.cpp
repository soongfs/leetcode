#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> f = cost;
        int n = cost.size();
        // 这里有歧义，爬到n-1不算完成，仍然需要支付费用
        f[n - 1] = cost[n - 1];
        f[n - 2] = cost[n - 2];
        for (int i = n - 3; i >= 0; i--) {
            f[i] = cost[i] + min(f[i + 1], f[i + 2]);
        }
        return min(f[0], f[1]);
    }
};