#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] * nums[left] <= nums[right] * nums[right]) {
                ret.push_back(nums[left] * nums[left]);
                left++;
            } else {
                ret.push_back(nums[right] * nums[right]);
                right--;
            }
        }
        ret.push_back(nums[left] * nums[left]);
        return ret;
    }
};