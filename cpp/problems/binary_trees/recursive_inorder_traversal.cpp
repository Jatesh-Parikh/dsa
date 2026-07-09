// Time Complexity - O(n)
// Space Complexity - O(n)

// Inorder - Left, Root, Right 

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

void recursive_inorder(TreeNode *root) {
    if (root == nullptr) return;

    recursive_inorder(root->left);

    cout << root->val << endl;
    
    recursive_inorder(root->right);
}