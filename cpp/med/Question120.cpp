#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int dep = triangle.size();
        vector<vector<int>> f = triangle;
        for (int i = dep - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[i][j] = triangle[i][j] + min(f[i + 1][j], f[i + 1][j + 1]);
            }
        }
        return f[0][0];
    }
};
