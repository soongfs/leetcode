#include <stack>
#include <vector>

class Solution {
public:
    int trap(std::vector<int> &height) {
        int n = height.size();
        int ans = 0;
        std::stack<int> st;

        for (int i = 0; i < n; ++i) {
            int h = height[i];
            while (!st.empty() && height[st.top()] <= h) {
                int bottom_h = height[st.top()];
                st.pop();
                if (st.empty())
                    break;
                int left = st.top();
                int deepth = std::min(height[left], height[i]) - bottom_h;
                ans += deepth * (i - left - 1);
            }
            st.push(i);
        }
        return ans;
    }
};
