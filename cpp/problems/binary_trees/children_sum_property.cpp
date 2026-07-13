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
        void children_sum_property(TreeNode *root) {
            if (root == nullptr) return;
            int child = 0;

            if(root->left) child += root->left->val;
            if(root->right) child += root->right->val;

            if(child >= root->val) root->val = child;
            else {
                if(root->left) root->left->val = root->val;
                if(root->right) root->right->val = root->val;
            }

            children_sum_property(root->left);
            children_sum_property(root->right);

            int total = 0;
            if(root->left) total += root->left->val;
            if(root->right) total += root->right->val;
            if(root->left || root->right) root->val = total;
        }
};