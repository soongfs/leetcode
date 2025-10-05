#include <vector>

class Solution {
public:
    long long mostPoints(std::vector<std::vector<int>> &questions) {
        int n = questions.size();
        std::vector<long long> memo(n, -1);

        auto dfs = [&](this auto &&dfs, int i) -> long long {
            if (i > n - 1)
                return 0;
            if (i == n - 1)
                return questions[n - 1][0];
            if (i == n - 2)
                return std::max(questions[n - 2][0], questions[n - 1][0]);
            if (memo[i] != -1)
                return memo[i];
            return memo[i] =
                       std::max(questions[i][0] + dfs(i + questions[i][1] + 1),
                                dfs(i + 1));
        };

        return dfs(0);
    }
};
