#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                ans += m[nums[i]];
            }
            m[nums[i]] += 1;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << Solution().numIdenticalPairs(nums) << endl;
    return 0;
}
