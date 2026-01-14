#include <algorithm>
#include <bitset>
// #include <numeric>
#include <vector>

class Solution {
public:
    // int maxTotalReward(std::vector<int> &rewardValues) {
    //     int n = rewardValues.size();
    //     std::sort(rewardValues.begin(), rewardValues.end());
    //     int max_j = std::reduce(rewardValues.begin(), rewardValues.end(), 0);
    //     std::vector dp(n, std::vector<int>(max_j + 1, -1));

    //     for (int j = 0; j < rewardValues[n - 1]; ++j)
    //         dp[n - 1][j] = j + rewardValues[n - 1];

    //     for (int j = rewardValues[n - 1]; j <= max_j; ++j)
    //         dp[n - 1][j] = j;

    //     for (int i = n - 2; i >= 0; --i) {
    //         for (int j = 0; j < rewardValues[i]; ++j)
    //             dp[i][j] =
    //                 std::max(dp[i + 1][j], dp[i + 1][j + rewardValues[i]]);

    //         for (int j = rewardValues[i]; j <= max_j; ++j)
    //             dp[i][j] = dp[i + 1][j];
    //     }

    //     return dp[0][0];
    // }

    int maxTotalReward(std::vector<int> &rewardValues) {
        std::ranges::sort(rewardValues);
        rewardValues.erase(std::ranges::unique(rewardValues).begin(),
                           rewardValues.end());

        std::bitset<100000> f{1};
        for (int v : rewardValues) {
            int shift = f.size() - v;
            f |= f << shift >> (shift - v);
        }

        for (int i = rewardValues.back() * 2 - 1;; --i) {
            if (f[i])
                return i;
        }
    }
};
