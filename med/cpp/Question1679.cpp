#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(k - nums[i]) != m.end() && m[k - nums[i]] > 0) {
                m[k - nums[i]] -= 1;
                ans++;
            } else {
                m[nums[i]] += 1;
            }
        }
        return ans;
    }
};