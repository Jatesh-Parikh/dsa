// Time Complexity - O(n)
// Space Complexity - O(n)

// Preorder - Root, Left, Right 

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

void recursive_preorder(TreeNode *root) {
    if (root == nullptr) return;
    
    cout << root->val << endl;
    
    recursive_preorder(root->left);
    recursive_preorder(root->right);
} 