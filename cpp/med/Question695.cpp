#include <bits/stdc++.h>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](this auto &&dfs, int i, int j) -> int {
            if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || grid[i][j] != 1) {
                return 0;
            }
            int cnt = 1;
            grid[i][j] = 2;
            cnt += dfs(i - 1, j);
            cnt += dfs(i + 1, j);
            cnt += dfs(i, j - 1);
            cnt += dfs(i, j + 1);
            return cnt;
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = std::max(ans, dfs(i, j));
                }
            }
        }
        return ans;
    }
};
