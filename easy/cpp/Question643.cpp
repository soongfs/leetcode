#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i - k + 1 < 0) {
                continue;
            } else {
                ans = max(ans, sum);
                sum -= nums[i - k + 1];
            }
        }
        return 1. * ans / k;
    }
};

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    cout << Solution().findMaxAverage(nums, 4) << endl;
    return 0;
}