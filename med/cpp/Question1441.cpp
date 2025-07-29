#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            if (target.size() > 0 && i == target[0]) {
                ans.push_back("Push");
                target.erase(target.begin());
            } else if (target.size() > 0 && i != target[0]) {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};

int main() {
    vector<int> target = {1, 3};
    for (string s : Solution().buildArray(target, 3)) {
        cout << s << endl;
    }
    return 0;
}
