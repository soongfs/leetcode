#include <bits/stdc++.h>

using namespace std;

// LC的时间复杂度分析结果是O(2^N)，怎么算的？
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        return f(target, nums, m);
    }

    int f(int n, vector<int> &nums, unordered_map<int, int> &m) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (m.find(n) != m.end())
            return m[n];
        int ans = 0;
        for (int x : nums) {
            ans += f(n - x, nums, m);
        }
        m[n] = ans;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1, 3};
    cout << sol.combinationSum4(nums, 35);
    return 0;
}
