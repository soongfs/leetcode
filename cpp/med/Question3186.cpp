#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int> &power) {
        long long mx = ranges::max(power);
        vector<int> y(mx + 1, 0);
        for (int x : power)
            y[x] = x;

        vector<long long> memo(mx + 1, -1);
        auto dfs = [&](this auto &&dfs, long long i) -> long long {
            if (i < 0)
                return 0;
            if (i == 0)
                return y[0];
            if (memo[i] != -1)
                return memo[i];
            return memo[i] = max(dfs(i - 1), dfs(i - 3) + y[i]);
        };

        return dfs(mx);
    }
};
