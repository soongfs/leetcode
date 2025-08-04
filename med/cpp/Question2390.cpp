#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string ret;
        for (auto ch : s) {
            if (ch == '*') {
                ret.pop_back();
            } else {
                ret.push_back(ch);
            }
        }
        return ret;
    }
};
