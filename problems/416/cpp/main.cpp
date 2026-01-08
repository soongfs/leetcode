#include <numeric>
#include <vector>

class Solution {
public:
    bool canPartition(std::vector<int> &nums) {
        int s = std::reduce(nums.begin(), nums.end());
        if (s % 2)
            return false;

        int n = nums.size();
        std::vector memo(n, std::vector<int>(s / 2 + 1, -1));

        auto dfs = [&](this auto &&dfs, int i, int j) -> bool {
            if (i < 0)
                return j == 0;

            int &res = memo[i][j];
            if (res != -1)
                return res;
            if (j < nums[i])
                return res = dfs(i - 1, j);
            return res = dfs(i - 1, j - nums[i]) || dfs(i - 1, j);
        };

        return dfs(n - 1, s / 2);
    }
};
