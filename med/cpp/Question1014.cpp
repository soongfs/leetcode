#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        int ans = 0, pre_max = values[0] + 0;
        for (int i = 1; i < values.size(); i++) {
            ans = max(ans, pre_max + values[i] - i);
            pre_max = max(pre_max, values[i] + i);
        }
        return ans;
    }
};