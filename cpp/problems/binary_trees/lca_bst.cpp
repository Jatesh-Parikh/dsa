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
        // Space Complexity - O(h)
        TreeNode *lca_bst(TreeNode *root, TreeNode *p, TreeNode *q) {
            if (root == nullptr) return root;
            int curr = root->val;

            if (curr < p->val && curr < q->val) return lca_bst(root->right, p, q);
            if (curr > p->val && curr > q->val) return lca_bst(root->left, p, q);

            return root;
        }
};