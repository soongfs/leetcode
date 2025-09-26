#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int max_len = 0, left = 0;
        bool flag = false;
        for (int right = 0; right < nums.size(); right++) {
            if (flag && nums[right] == 0) {
                while (flag) {
                    if (nums[left] == 0) {
                        left++;
                        break;
                    }
                    left++;
                }
            } else if (nums[right] == 0) {
                flag = true;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};
