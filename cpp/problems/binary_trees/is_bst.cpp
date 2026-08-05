#include <climits>

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
        bool is_valid(TreeNode *root, int min_val, int max_val) {
            if (root == nullptr) return true;
            if (root->val >= max_val || root->val <= min_val) return false;
            return is_valid(root->left, min_val, root->val) && is_valid(root->right, root->val, max_val);
        }

    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        bool is_bst(TreeNode *root) {
            return is_valid(root, INT_MIN, INT_MAX);
        }
};