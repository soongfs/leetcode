#include <bits/stdc++.h>
#include <ranges>

using namespace std;

class Solution {
public:
    int minRemoval(vector<int> &nums, int k) {
        ranges::sort(nums);
        int mx = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (1LL * nums[left] * k < nums[right]) {
                left++;
            }
            mx = max(mx, right - left + 1);
        }
        return nums.size() - mx;
    }
};
