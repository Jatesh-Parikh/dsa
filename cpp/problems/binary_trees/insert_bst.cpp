// Time Complexity - O(log n)
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
        TreeNode *insert(TreeNode *root, int value) {
            if (root == nullptr) return new TreeNode(value);

            TreeNode *curr = root;

            while (root) {
                if (curr->val <= value) {
                    if(curr->right) curr = curr->right;
                    else {
                        curr->right = new TreeNode(value);
                        break;
                    }
                } else {
                    if (curr->left) curr = curr->left;
                    else {
                        curr->left = new TreeNode(value);
                        break;
                    }
                }
            }

            return root;
        }
};