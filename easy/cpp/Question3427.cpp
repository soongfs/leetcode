#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums) {
        int ans = 0;
        vector<int> pre;
        pre.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            pre[i + 1] = pre[i] + nums[i];
            ans += pre[i + 1] - pre[max(0, i - nums[i])];
        }
        return ans;
    }
};