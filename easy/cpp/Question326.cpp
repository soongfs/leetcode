#include <bits/stdc++.h>
#include <type_traits>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        } else if (1162261467 % n == 0) {
            return true;
        } else {
            return false;
        }
    }
};
