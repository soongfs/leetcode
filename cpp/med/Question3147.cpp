#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
    // 思路错误
    // int maximumEnergy(std::vector<int> &energy, int k) {
    //     int n = energy.size();
    //     std::vector<int> memo(n, -1001);
    //     auto dfs = [&](this auto &&dfs, int i) -> int {
    //         if (i > n - 1)
    //             return 0;
    //         if (i == n - 1)
    //             return energy[n - 1];
    //         if (memo[i] != -1001)
    //             return memo[i];
    //         return memo[i] = std::max(dfs(i + k) + energy[i], dfs(i + 1));
    //     };
    //     return dfs(0);
    // }

    // 枚举起点
    // int maximumEnergy(std::vector<int> &energy, int k) {
    //     int n = energy.size();
    //     std::vector<int> memo(n, 0);
    //     for (int i = 0; i < k; ++i) {
    //         for (int j = i; j < n; j += k) {
    //             memo[i] += energy[j];
    //         }
    //     }
    //     for (int i = k; i < n; ++i) {
    //         memo[i] = memo[i - k] - energy[i - k];
    //     }
    //     return *std::max_element(memo.begin(), memo.end());
    // }

    // 枚举终点
    int maximumEnergy(std::vector<int> &energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        for (int i = n - k; i < n; ++i) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                ans = std::max(ans, sum);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> energy({5, 2, -10, -5, 1});
    int k = 3;
    std::cout << sol.maximumEnergy(energy, k) << std::endl;
    return 0;
}
