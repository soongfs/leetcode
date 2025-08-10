#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int max_s = 0, sum = 0;
        for (int right = 0; right < customers.size(); right++) {
            if (grumpy[right] == 1) {
                sum += customers[right];
            }
            if (right < minutes - 1) {
                continue;
            }
            max_s = max(max_s, sum);
            if (grumpy[right - minutes + 1] == 1) {
                sum -= customers[right - minutes + 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                ans += customers[i];
            }
        }
        return ans + max_s;
    }
};