#include <algorithm>
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
        TreeNode *prev;
        TreeNode *first;
        TreeNode *middle;
        TreeNode *last;

        void inorder(TreeNode *root) {
            if (!root) return;

            inorder(root->left);

            if (prev && (root->val < prev->val)) {
                if (first == nullptr) {
                    first = prev;
                    middle = root;
                } else {
                    last = root;
                }
            }

            prev = root;
            inorder(root->right);
        }

    public:
        // Time Complexity - O(n)
        // Space Complexity - O(h)
        void recover_bst(TreeNode *root) {
            first = middle = last = nullptr;
            prev = nullptr;
            inorder(root);
            if (first && last) swap(first->val, last->val);
            else if (first && middle) swap(first->val, middle->val);
        }
};