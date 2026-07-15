// Time Complexity - O(h)
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
    private:
        TreeNode *helper(TreeNode *root) {
            if (root->left == nullptr) {
                return root->right;
            }

            if (root->right == nullptr) {
                return root->left;
            }

            TreeNode *right_child = root->right;
            TreeNode *last_right_child = find_last_right(root->left);
            last_right_child->right = right_child;
            return root->left;
        }

        TreeNode *find_last_right(TreeNode *root) {
            if (root->right == nullptr) {
                return root;
            }

            return find_last_right(root->right);
        }

    public:
        TreeNode *delete_node(TreeNode *root, int key) {
            if (root == nullptr) return nullptr;

            if(root->val == key) return helper(root);

            TreeNode *dummy = root;

            while (root != nullptr) {
                if (root->val > key) {
                    if (root->left != nullptr && root->left->val == key) {
                        root->left = helper(root->left);
                        break;
                    } else {
                        root = root->left;
                    }
                } else {
                    if (root->right != nullptr && root->right->val == key) {
                        root->right = helper(root->right);
                        break;
                    } else {
                        root = root->right;
                    }
                }
            }

            return dummy;
        }
};