#include <climits>
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

class NodeValue {
    public:
        int min_val;
        int max_val;
        int max_size;

        NodeValue(int min_val, int max_val, int max_size): min_val(min_val), max_val(max_val), max_size(max_size) {}
};

class Solution {
    private:
        NodeValue largest_bst_subtree(TreeNode *root) {
            if (!root) return NodeValue(INT_MAX, INT_MIN, 0);

            auto left = largest_bst_subtree(root->left);
            auto right = largest_bst_subtree(root->right);

            if (left.max_val < root->val && root->val < right.min_val) { // valid bst
                return NodeValue(min(left.min_val, root->val), max(root->val, right.max_val), 1 + left.max_size + right.max_size);
            }

            return NodeValue(INT_MIN, INT_MAX, max(left.max_size, right.max_size));
        }

    public:
        // Time Complexity - O(n)
        // Space Complexity - O(h)
        int largest_bst(TreeNode *root) {
            return largest_bst_subtree(root).max_size;
        }
};