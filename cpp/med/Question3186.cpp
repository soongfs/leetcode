#include <bits/stdc++.h>
#include <vector>

using namespace std;

/**
 * [FIXME]
 * 各种写法爆内存
 */
class Solution {
public:
    long long maximumTotalDamage(vector<int> &power) {
        long long mx = ranges::max(power);

        vector<int> y(mx + 1, 0);
        for (int x : power)
            y[x] += x;

        if (mx == 1)
            return y[1];
        if (mx == 2)
            return max(y[1], y[2]);

        // 递归爆内存
        // vector<long long> memo(mx + 1, -1);
        // auto dfs = [&](this auto &&dfs, long long i) -> long long {
        //     if (i < 0)
        //         return 0;
        //     if (i == 0)
        //         return y[0];
        //     if (memo[i] != -1)
        //         return memo[i];
        //     return memo[i] = max(dfs(i - 1), dfs(i - 3) + y[i]);
        // };

        // 递推也爆了
        // vector<long long> f(mx + 1);
        // f[0] = 0;
        // f[1] = y[1];
        // f[2] = max(y[1], y[2]);
        // for (int i = 3; i <= mx; i++) {
        //     f[i] = max(f[i - 1], f[i - 3] + y[i]);
        // }

        int f0 = 0, f1 = y[1], f2 = max(y[1], y[2]);
        for (int x : power) {
            int new_f = max(f2, f0 + x);
            f0 = f1;
            f1 = f2;
            f2 = new_f;
        }

        // return dfs(mx);
        // return f[mx];
        return f2;
    }
};
