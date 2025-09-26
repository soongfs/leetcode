#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int ans = 0, k_thre = k * threshold, sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (i < k - 1) {
                continue;
            }
            if (sum >= k_thre) {
                ans++;
            }
            sum -= arr[i - k + 1];
        }
        return ans;
    }
};