#include <bits/stdc++.h>

// using namespace std;

class Solution {
public:
    int deleteAndEarn(std::vector<int> &nums) {
        int mx = std::ranges::max(nums);
        std::vector<int> y(mx + 1);
        for (int x : nums) {
            y[x] += x;
        }

        std::vector<int> memo(mx + 1, -1);
        auto dfs = [&](this auto &&dfs, int i) {
            if (i < 0)
                return 0;
            if (i == 0)
                return y[0];
            if (memo[i] != -1)
                return memo[i];
            return memo[i] = std::max(dfs(i - 1), dfs(i - 2) + y[i]);
        };

        return dfs(mx);
    }
};
