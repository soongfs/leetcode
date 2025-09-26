#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime,
                    vector<int> &endTime) {
        int max_s = 0, sum = 0;
        int n = startTime.size();
        for (int right = 0; right < n; right++) {
            sum += startTime[right] - (right == 0 ? 0 : endTime[right - 1]);
            if (right < k) {
                continue;
            }
            max_s = max(max_s, sum);
        }
    }
};