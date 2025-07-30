#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        vector<bool> ans(queries.size());
        vector<int> pre(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i - 1] + (nums[i] % 2 == nums[i - 1] % 2);
        }
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = (pre[queries[i][0]] == pre[queries[i][1]]);
        }
        return ans;
    }
};