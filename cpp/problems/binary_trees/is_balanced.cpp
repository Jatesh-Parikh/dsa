// Time Complexity - O(n)
// Space Complexity - O(h)

#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
    private:
        int max_depth(TreeNode *root) {
            if (root == nullptr) return 0;

            int left_height = max_depth(root->left);
            if (left_height == -1) return -1;

            int right_height = max_depth(root->right);
            if (right_height == -1) return -1;

            if(abs(left_height - right_height) > 1) return -1;

            return 1 + max(left_height, right_height);
        }

    public:
        bool is_balanced(TreeNode *root) {
            return max_depth(root) != -1;
        }
};