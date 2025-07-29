#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/**
 * 方法一：双层遍历
 */
// class Solution {
//    public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };

/**
 * 方法二：枚举右维护左+哈希表
 */
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                return {map[target - nums[i]], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    for (int x : Solution().twoSum(nums, 9)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
