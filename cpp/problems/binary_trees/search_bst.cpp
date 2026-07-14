// Time Complexity - O(logn)
// Space Complexity - O(1)

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
        TreeNode *search(TreeNode *root, int val) {
            while (root != nullptr && root->val != val) {
                root = root->val > val ? root->left : root->right;
            }
            return root;
        }
};