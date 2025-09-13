#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int y = accumulate(nums.begin(), nums.end(), 0) - x;
        if (y < 0)
            return -1;
        int j = 0, cnt = 0, ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            cnt += nums[i];
            while (cnt > y)
                cnt -= nums[j++];
            if (cnt == y)
                ans = max(ans, i - j + 1);
        }
        if (ans == -1)
            return ans;
        return nums.size() - ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1};
    int x = 3;
    int result = sol.minOperations(nums, x);
    cout << "Result: " << result << endl;
    return 0;
}
