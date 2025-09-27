#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        unordered_map<int, long long> m;
        long long ans = 0;
        for (int i = low; i <= high; i++) {
            ans += f(i, zero, one, m);
            ans %= 1000000007;
        }
        return ans;
    }

    int f(int x, int zero, int one, unordered_map<int, long long> &m) {
        if (x == 0)
            return 1;
        if (x < 0)
            return 0;
        if (m.find(x) != m.end())
            return m[x];
        m[x] = f(x - zero, zero, one, m) % 1000000007 +
               f(x - one, zero, one, m) % 1000000007;
        return m[x];
    }
};
