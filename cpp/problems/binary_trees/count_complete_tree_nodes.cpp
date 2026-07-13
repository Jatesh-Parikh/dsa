// Time Complexity - O(log n ^ 2)
// Space Complexity - O(log n)

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
        int left_height(TreeNode *node) {
            int height = 0;

            while(node) {
                height++;
                node = node->left;
            }

            return height;
        }

        int right_height(TreeNode *node) {
            int height = 0;

            while(node) {
                height++;
                node = node->right;
            }

            return height;
        }

    public:
        int count_nodes(TreeNode *root) {
            if (root == nullptr) return 0;

            int lh = left_height(root);
            int rh = right_height(root);

            if(lh == rh) return (1 << lh) - 1;

            return 1 + count_nodes(root->left) + count_nodes(root->right);
        }
};