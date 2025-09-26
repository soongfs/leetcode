#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for (char ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
        }
        return false;
    }
};
