// Time Complexity - O(n)
// Space Complexity - O(n)

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
        bool is_identical(TreeNode *p, TreeNode *q) {
            if (p == nullptr && q == nullptr) return true;

            if (p == nullptr || q == nullptr) return false;

            return (p->val == q->val) && is_identical(p->left, q->left) && is_identical(p->right, q->right);
        }
};