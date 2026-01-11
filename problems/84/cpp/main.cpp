#include <stack>
#include <vector>

class Solution {
public:
    int largestRectangleArea(std::vector<int> &heights) {
        int n = heights.size();
        std::vector<int> left(n, -1);
        std::stack<int> st;
        for (int i = 0; i < n; ++i) {
            int h = heights[i];
            while (!st.empty() && heights[st.top()] >= h)
                st.pop();

            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }

        std::vector<int> right(n, n);
        st = std::stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            int h = heights[i];
            while (!st.empty() && heights[st.top()] >= h) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};
