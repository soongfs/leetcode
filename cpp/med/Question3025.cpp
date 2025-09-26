#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>> &points) {
        ranges::sort(points, {}, [](auto &p) { return pair(p[0], -p[1]); });
        int ans = 0, n = points.size();
        for (int i = 0; i < n; i++) {
            int max_y = INT_MIN;
            for (int j = i + 1; j < n && max_y < points[i][1]; j++) {
                if (points[j][1] <= points[i][1] && points[j][1] > max_y) {
                    ans++;
                    max_y = points[j][1];
                }
            }
        }
        return ans;
    }
};