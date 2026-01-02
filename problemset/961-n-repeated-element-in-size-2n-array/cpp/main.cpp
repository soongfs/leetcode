#include <unordered_set>
#include <vector>

class Solution {
public:
    int repeatedNTimes(std::vector<int> &nums) {
        std::unordered_set<int> seen;
        for (int x : nums)
            if (!seen.insert(x).second)
                return x;
        return -1;
    }
};
