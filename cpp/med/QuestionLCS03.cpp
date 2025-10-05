#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int largestArea(std::vector<std::string> &grid) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](this auto &&dfs, int i, int j, char tar) -> int {
            /**
             * [FIXME]
             * 会导致提前返回
             */
            if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || grid[i][j] == '0') {
                return -1;
            }
            if (grid[i][j] != tar) {
                return 0;
            }
            int cnt = 1;
            grid[i][j] = '6';
            int tmp;
            if ((tmp = dfs(i - 1, j, tar)) == -1)
                return -1;
            else
                cnt += tmp;
            if ((tmp = dfs(i + 1, j, tar)) == -1)
                return -1;
            else
                cnt += tmp;
            if ((tmp = dfs(i, j - 1, tar)) == -1)
                return -1;
            else
                cnt += tmp;
            if ((tmp = dfs(i, j + 1, tar)) == -1)
                return -1;
            else
                cnt += tmp;
            return cnt;
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '0' && grid[i][j] != '6') {
                    int tmp = dfs(i, j, grid[i][j]);
                    if (tmp != -1)
                        ans = std::max(ans, tmp);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> grid = {"110", "231", "221"};
    std::cout << sol.largestArea(grid) << std::endl;
    return 0;
}
