#include <algorithm>
#include <string>

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
    std::string getDirections(TreeNode *root, int startValue, int destValue) {
        std::string path;

        auto dfs = [&](this auto &&dfs, TreeNode *node, int target) -> bool {
            if (node == nullptr)
                return false;

            if (node->val == target)
                return true;

            path += 'L';
            if (dfs(node->left, target))
                return true;

            path.back() = 'R';
            if (dfs(node->right, target))
                return true;

            path.pop_back();
            return false;
        };

        dfs(root, startValue);
        std::string path_to_start = path;

        path.clear();
        dfs(root, destValue);
        std::string path_to_dest = std::move(path);

        int i = 0;
        while (i < std::min(path_to_start.size(), path_to_dest.size()) &&
               path_to_start[i] == path_to_dest[i])
            i++;

        return std::string(path_to_start.size() - i, 'U') +
               path_to_dest.substr(i);
    }
};
