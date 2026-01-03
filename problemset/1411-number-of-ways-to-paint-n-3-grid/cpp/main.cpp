#include <vector>

class Solution {
public:
    int numOfWays(int n) {
        constexpr int MOD = 1'000'000'007;
        std::vector<int> f(n + 1);
        f[0] = 3;
        f[1] = 12;
        for (int i = 2; i <= n; i++) {
            f[i] = (f[i - 1] * 5LL - f[i - 2] * 2LL) % MOD;
        }
        return (f[n] + MOD) % MOD;
    }
};
