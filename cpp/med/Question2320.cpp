#include <bits/stdc++.h>

using namespace std;

const int MOD = 10'0000'0007;

class Solution {
public:
    int countHousePlacements(int n) {
        vector<int> memo(n + 1, -1);

        auto dfs = [&](this auto &&dfs, int i) -> int {
            if (i == 0)
                return 1;
            if (i == 1)
                return 2;
            if (memo[i] != -1)
                return memo[i];
            return memo[i] = (dfs(i - 1) + dfs(i - 2)) % MOD;
        };

        long long tmp = dfs(n);
        return tmp * tmp % MOD;
    }
};
