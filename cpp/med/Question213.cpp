#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // int rob(vector<int> &nums) {
    //     int n = nums.size();

    //     if (n == 1)
    //         return nums[0];

    //     vector<int> memo0(n, -1);
    //     vector<int> memo1(n, -1);

    //     // [0,n-2]
    //     auto dfs0 = [&](this auto &&dfs0, int i) {
    //         if (i < 0)
    //             return 0;
    //         if (memo0[i] != -1)
    //             return memo0[i];
    //         return memo0[i] = max(dfs0(i - 1), dfs0(i - 2) + nums[i]);
    //     };

    //     // [1,n-1]
    //     auto dfs1 = [&](this auto &&dfs1, int i) {
    //         if (i < 1)
    //             return 0;
    //         if (memo1[i] != -1)
    //             return memo1[i];
    //         return memo1[i] = max(dfs1(i - 1), dfs1(i - 2) + nums[i]);
    //     };

    //     return max(dfs0(n - 2), dfs1(n - 1));
    // }

    // int rob(vector<int> &nums) {
    //     int n = nums.size();

    //     if (n == 1)
    //         return nums[0];
    //     if (n == 2)
    //         return max(nums[0], nums[1]);

    //     vector<int> f0(n), f1(n);
    //     f0[0] = nums[0];
    //     f0[1] = max(nums[0], nums[1]);
    //     f1[1] = nums[1];
    //     f1[2] = max(nums[1], nums[2]);

    //     for (int i = 2; i <= n - 2; i++) {
    //         f0[i] = max(f0[i - 1], f0[i - 2] + nums[i]);
    //     }
    //     for (int i = 3; i <= n - 1; i++) {
    //         f1[i] = max(f1[i - 1], f1[i - 2] + nums[i]);
    //     }

    //     return max(f0[n - 2], f1[n - 1]);
    // }

    int rob(vector<int> &nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int fir = nums[0], sec = max(nums[0], nums[1]);
        int f0 = 0, f1 = 0;

        for (int i = 2; i <= n - 2; i++) {
            int thi = max(sec, fir + nums[i]);
            fir = sec;
            sec = thi;
        }
        f0 = sec;

        fir = nums[1];
        sec = max(nums[1], nums[2]);
        for (int i = 3; i <= n - 1; i++) {
            int thi = max(sec, fir + nums[i]);
            fir = sec;
            sec = thi;
        }
        f1 = sec;

        return max(f0, f1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 2};
    cout << sol.rob(nums) << endl;
    return 0;
}
