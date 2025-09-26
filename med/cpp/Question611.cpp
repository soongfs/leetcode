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
        unordered_map<int, int> map;
        map[nums[0] + nums[1]]++;
        for (int i = 2; i < nums.size(); i++) {
                }
    }
};