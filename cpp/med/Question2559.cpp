#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
        vector<int> ans(queries.size());
        vector<int> pre(words.size() + 1);

        for (int i = 0; i < words.size(); i++) {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1])) {
                pre[i + 1] = pre[i] + 1;
            } else {
                pre[i + 1] = pre[i];
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            ans[i] = pre[queries[i][1] + 1] - pre[queries[i][0]];
        }

        return ans;
    }

    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};