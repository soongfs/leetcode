#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int j = 0, sum = 0, ans = 0x3f3f3f3f;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                ans = min(ans, i - j + 1);
                sum -= nums[j++];
            }
        }
        return ans == 0x3f3f3f3f ? 0 : ans;
    }
};

int main() {
    Solution sol;
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}
