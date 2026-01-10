#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
    int minimumDeleteSum(std::string s1, std::string s2) {
        int m = s1.size();
        int n = s2.size();
        std::vector dp(m + 1, std::vector<int>(n + 1, 0));
        int total = std::reduce(s1.begin(), s1.end(), 0) +
                    std::reduce(s2.begin(), s2.end(), 0);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[i + 1][j + 1] = s1[i] == s2[j]
                                       ? dp[i][j] + s1[i]
                                       : std::max(dp[i][j + 1], dp[i + 1][j]);

        return total - dp[m][n] * 2;
    }
};
