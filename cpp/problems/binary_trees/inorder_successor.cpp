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
        // Time Complexity - O(h)
        // Space Complexity - O(1)
        TreeNode *inorder_successor(TreeNode *root, TreeNode *p) {
            TreeNode *successor = nullptr;

            while (root) {
                if (root->val <= p->val) {
                    root = root->right;
                } else {
                    successor = root;
                    root = root->left;
                }
            }

            return successor;
        }

        // Time Complexity - O(h)
        // Space Complexity - O(1)
        TreeNode *inorder_predecessor(TreeNode *root, TreeNode *p) {
            TreeNode *predecessor = nullptr;

            while (root) {
                if (root->val >= p->val) {
                    root = root->left;
                } else {
                    predecessor = root;
                    root = root->right;
                }
            }

            return predecessor;
        }
};