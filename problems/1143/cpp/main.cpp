#include <string>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.size();
        int n = text2.size();
        std::vector dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[i + 1][j + 1] = text1[i] == text2[j]
                                       ? dp[i][j] + 1
                                       : std::max(dp[i][j + 1], dp[i + 1][j]);

        return dp[m][n];
    }
};
