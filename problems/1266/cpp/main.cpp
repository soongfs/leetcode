#include <algorithm>
#include <vector>

class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>> &points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n - 1; ++i) {
            int dx = points[i][0] - points[i + 1][0] >= 0
                         ? points[i][0] - points[i + 1][0]
                         : points[i + 1][0] - points[i][0];
            int dy = points[i][1] - points[i + 1][1] >= 0
                         ? points[i][1] - points[i + 1][1]
                         : points[i + 1][1] - points[i][1];
            ans += std::max(dx, dy);
        }

        return ans;
    }
};
