#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int cnt = 0, sum = 0, target = threshold * k;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (i < k - 1) {
                continue;
            }
            if (sum >= target) {
                cnt++;
            }
            sum -= arr[i - k + 1];
        }
        return cnt;
    }
};