#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int window = cardPoints.size() - k, sum = 0, ans = 0x3f3f3f3f;
        if (window == 0) {
            return reduce(cardPoints.begin(), cardPoints.end());
        }
        for (int right = 0; right < cardPoints.size(); right++) {
            sum += cardPoints[right];
            if (right < window - 1) {
                continue;
            }
            ans = min(ans, sum);
            sum -= cardPoints[right - window + 1];
        }
        return reduce(cardPoints.begin(), cardPoints.end()) - ans;
    }
};