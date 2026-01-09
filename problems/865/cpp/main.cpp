#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        int max_depth = -1;
        TreeNode *ans;

        auto dfs = [&](this auto &&dfs, TreeNode *node, int depth) {
            if (node == nullptr) {
                max_depth = std::max(max_depth, depth);
                return depth;
            }

            int left_max_depth = dfs(node->left, depth + 1);
            int right_max_depth = dfs(node->right, depth + 1);

            if (left_max_depth == right_max_depth &&
                left_max_depth == max_depth)
                ans = node;

            return std::max(left_max_depth, right_max_depth);
        };

        dfs(root, 0);
        return ans;
    }
};
