#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // int numWaterBottles(int numBottles, int numExchange) {
    //     int ans = 0;
    //     int numVoid = 0;
    //     while (numBottles > 0) {
    //         numVoid += numBottles;
    //         ans += numBottles;
    //         numBottles = 0;
    //         numBottles += numVoid / numExchange;
    //         numVoid -= (numVoid / numExchange) * numExchange;
    //     }
    //     return ans;
    // }

    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        while (numBottles >= numExchange) {
            ans += numExchange;
            numBottles -= numExchange - 1;
        }
        return ans + numBottles;
    }
};
