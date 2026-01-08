#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int> &nums) {
        int dp = nums[0];
        int mx = dp;
        for (int i = 1; i < nums.size(); ++i) {
            dp = dp > 0 ? dp + nums[i] : nums[i];
            mx = std::max(mx, dp);
        }

        return mx;
    }
};
