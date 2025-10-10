#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                                long long success) {
        int n = spells.size(), m = potions.size();
        ranges::sort(potions);
        for (int &sp : spells) {
            auto it = lower_bound(potions.begin(), potions.end(),
                                  (success + sp - 1) / sp);
            sp = (m - (it - potions.begin()));
        }
        return spells;
    }
};
