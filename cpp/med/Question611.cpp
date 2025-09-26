#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        if (nums.size() < 3) {
            return 0;
        }
        int ans = 0;
        sort(nums.begin(), nums.end());
        map<int, int> m;
        m[nums[0] + nums[1]]++;
        for (int i = 2; i < nums.size(); i++) {
            auto it = m.upper_bound(nums[i]);
            for (auto iter = it; iter != m.end(); iter++) {
                ans += iter->second;
            }
            for (int j = 0; j < i; j++) {
                m[nums[i] + nums[j]]++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 4};
    cout << sol.triangleNumber(nums) << endl;
    return 0;
}
