#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(-1 * nums[i]) != s.end()) {
                ans = max(ans, abs(nums[i]));
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1, 2, -3, 3};
    cout << Solution().findMaxK(nums) << endl;
}
