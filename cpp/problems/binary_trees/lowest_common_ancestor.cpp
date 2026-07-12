// Time Complexity - O(n)
// Space Complexity - O(h)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
    public:
        TreeNode * lowest_common_ancestor(TreeNode *root, TreeNode *p, TreeNode *q) {
            if (root == nullptr || root == p || root == q) {
                return root;
            }

            TreeNode *left = lowest_common_ancestor(root->left, p, q);
            TreeNode *right = lowest_common_ancestor(root->right, p, q);

            if (left == nullptr) {
                return right;
            } else if (right == nullptr) {
                return left;
            } else {
                return root;
            }
        }
};