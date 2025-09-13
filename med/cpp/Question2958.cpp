#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        int left = 0, ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            map[nums[right]]++;
            while (map[nums[right]] > k) {
                map[nums[left]]--;
                if (map[nums[left]] == 0) {
                    map.erase(nums[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
