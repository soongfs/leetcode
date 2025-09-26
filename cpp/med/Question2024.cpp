#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int cntT = 0, leftT = 0, ansT = 0;
        int cntF = 0, leftF = 0, ansF = 0;
        for (int right = 0; right < answerKey.length(); right++) {
            if (answerKey[right] == 'T') {
                cntT++;
            } else {
                cntF++;
            }

            while (cntT > k) {
                if (answerKey[leftT] == 'T') {
                    cntT--;
                }
                leftT++;
            }
            ansT = max(ansT, right - leftT + 1);

            while (cntF > k) {
                if (answerKey[leftF] == 'F') {
                    cntF--;
                }
                leftF++;
            }
            ansF = max(ansF, right - leftF + 1);
        }
        return max(ansT, ansF);
    }
};
