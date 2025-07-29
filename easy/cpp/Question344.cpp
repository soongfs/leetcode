#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            s[left] ^= s[right] ^= s[left] ^= s[right];
            left++;
            right--;
        }
        return;
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution().reverseString(s);
    for (char ch : s) {
        cout << ch;
    }
    cout << endl;
    return 0;
}
