// Time Complexity - O(n)
// Space Complexity - O(n)

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
    private:
        bool is_leaf(TreeNode *root) {
            return root->left == nullptr && root->right == nullptr;
        }

        void add_left_boundary(TreeNode *root, vector<int>& res) {
            TreeNode *curr = root->left;

            while(curr) {
                if(!is_leaf(curr)) res.push_back(curr->val);

                if(curr->left) curr = curr->left;
                else curr = curr->right;
            }
        }

        void add_leaves(TreeNode *root, vector<int>& res) { // Preorder Traversal - Root, Left, Right
            if (is_leaf(root)) {
                res.push_back(root->val);
                return;
            }

            if (root->left) add_leaves(root->left, res);
            if (root->right) add_leaves(root->right, res);
        }

        void add_right_boundary(TreeNode *root, vector<int>& res) {
            TreeNode *curr = root->right;
            vector<int> temp;

            while (curr) {
                if (!is_leaf(curr)) temp.push_back(curr->val);
                if(curr->right) curr = curr->right;
                else curr = curr->left; 
            }

            for (int i = temp.size() - 1; i >= 0; i--) {
                res.push_back(temp[i]);
            }
        }
    
    public:
        vector<int> boundary_traversal(TreeNode *root) {
            vector<int> res;
            if(root == nullptr) return res;

            if(!is_leaf(root)) res.push_back(root->val);

            add_left_boundary(root, res);
            add_leaves(root, res);
            add_right_boundary(root, res);

            return res;
        }
};