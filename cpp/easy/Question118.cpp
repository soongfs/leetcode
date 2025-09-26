#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; i++) {
            // length=i+1
            ret[i].resize(i + 1, 1);
            // i=0不进入循环
            for (int j = 1; j < i; j++) {
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
        return ret;
    }
};
