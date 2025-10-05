#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> pondSizes(std::vector<std::vector<int>> &land) {
        int m = land.size(), n = land[0].size();
        auto dfs = [&](this auto &&dfs, int i, int j) -> int {
            if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || land[i][j] != 0) {
                return 0;
            }
            land[i][j] = 1;
            int cnt = 1;
            cnt += dfs(i - 1, j);
            cnt += dfs(i + 1, j);
            cnt += dfs(i, j - 1);
            cnt += dfs(i, j + 1);
            cnt += dfs(i - 1, j - 1);
            cnt += dfs(i - 1, j + 1);
            cnt += dfs(i + 1, j - 1);
            cnt += dfs(i + 1, j + 1);
            return cnt;
        };
        std::vector<int> ret;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0) {
                    ret.push_back(dfs(i, j));
                }
            }
        }
        std::ranges::sort(ret);
        return ret;
    }
};
