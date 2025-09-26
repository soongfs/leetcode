#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        int cnt = 1;
        while (n > 1) {
            ret.push_back(cnt);
            ret.push_back(-cnt);
            cnt++;
            n -= 2;
        }
        if (n == 0) {
            return ret;
        } else {
            ret.push_back(0);
            return ret;
        }
    }
};