#include <climits>
#include <vector>

class Solution {
public:
    int maxDotProduct(std::vector<int> &nums1, std::vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        std::vector memo(n, std::vector<int>(m, INT_MAX));

        auto dfs = [&](this auto &&dfs, int i, int j) -> int {
            if (i < 0 || j < 0)
                return INT_MIN;

            int &res = memo[i][j];
            if (res != INT_MAX)
                return res;

            res = std::max(dfs(i - 1, j - 1), 0) + nums1[i] * nums2[j];
            res = std::max(res, dfs(i - 1, j));
            res = std::max(res, dfs(i, j - 1));

            return res;
        };

        return dfs(n - 1, m - 1);
    }
};
