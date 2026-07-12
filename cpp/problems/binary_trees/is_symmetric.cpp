// Time Complexity - O(n)
// Space Complexity - O(h)

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
        bool is_symmetric_helper(TreeNode * left, TreeNode *right) {
            if(left == nullptr || right == nullptr) {
                return left == right;
            }

            if (left->val != right->val) return false;

            return is_symmetric_helper(left->left, right->right) && is_symmetric_helper(left->right, right->left);
        }   
    
    public:
        bool is_symmetric(TreeNode *root) {
            return root == nullptr || is_symmetric_helper(root->left, root->right);
        }    
};
