#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 递归
    // int rob(vector<int> &nums) {
    //     int n = nums.size();
    //     vector<int> memo(n, -1);
    //     auto dfs = [&](this auto &&dfs, int i) -> int {
    //         if (i < 0)
    //             return 0;
    //         if (memo[i] != -1)
    //             return memo[i];
    //         return memo[i] = max(dfs(i - 1), dfs(i - 2) + nums[i]);
    //     };
    //     return dfs(n - 1);
    // }

    // 递推
    // int rob(vector<int> &nums) {
    //     int n = nums.size();
    //     if (n == 1) {
    //         return nums[0];
    //     }
    //     vector<int> f(n);
    //     f[0] = nums[0];
    //     f[1] = max(nums[0], nums[1]);
    //     for (int i = 2; i < n; i++) {
    //         f[i] = max(f[i - 1], f[i - 2] + nums[i]);
    //     }
    //     return f[n - 1];
    // }

    // 优化空间
    int rob(vector<int> &nums) {
        int f0 = 0, f1 = 0;
        for (int x : nums) {
            int new_f = max(f1, f0 + x);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};
