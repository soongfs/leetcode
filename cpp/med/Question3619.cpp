#include <bits/stdc++.h>

class Solution {
public:
    int countIslands(std::vector<std::vector<int>> &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](this auto &&dfs, int i, int j) -> int {
            if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || grid[i][j] == 0) {
                return 0;
            }
            int cnt = grid[i][j] % k;
            grid[i][j] = 0;
            cnt = (cnt + dfs(i - 1, j)) % k;
            cnt = (cnt + dfs(i + 1, j)) % k;
            cnt = (cnt + dfs(i, j - 1)) % k;
            cnt = (cnt + dfs(i, j + 1)) % k;
            return cnt;
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && dfs(i, j) % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
