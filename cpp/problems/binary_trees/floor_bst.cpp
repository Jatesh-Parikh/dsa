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
        int find_floor(TreeNode *root, int key) {
            int floor = -1;

            while(root) {
                if (root->val == key) {
                    floor = root->val;
                    return floor;
                }

                if(root->val < key) {
                    floor = root->val;
                    root = root->right;
                } else {
                    root = root->left;
                }
            }

            return floor;
        }
};