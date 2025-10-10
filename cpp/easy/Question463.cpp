#include <bits/stdc++.h>f

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
#define IN(x, y) (0 <= (x) && (x) < m && 0 <= (y) && (y) < n)

        auto dfs = [&](this auto &&dfs, int x, int y) -> int {
            if (!IN(x, y) || grid[x][y] != 1) {
                return 0;
            }
            grid[x][y] = 2;
            int cnt = 0;
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (!IN(nx, ny) || grid[nx][ny] == 0) {
                    ++cnt;
                }
            }
            for (int dir = 0; dir < 4; ++dir) {
                cnt += dfs(x + dx[dir], y + dy[dir]);
            }
            return cnt;
        };

        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == 1) {
                    return dfs(x, y);
                }
            }
        }
        return -1;
    }
};
