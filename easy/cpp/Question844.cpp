#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    string build(string str) {
        string ret;
        for (char ch : str) {
            if (ch != '#') {
                ret.push_back(ch);
            } else if (!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    }
};

int main() {
    cout << Solution().backspaceCompare("a#c", "b") << endl;
    return 0;
}
