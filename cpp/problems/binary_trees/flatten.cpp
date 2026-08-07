#include <stack>

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
        TreeNode *prev = nullptr;

        void flatten(TreeNode *node) {
            if (node == nullptr) return;

            flatten(node->right);
            flatten(node->left);

            node->right = prev;
            node->left = nullptr;
            prev = node;
        }

    public:
        // Right, Left, Root
        // Time Complexity - O(n)
        // Space Complexity - O(h)
        void flatten_recursive(TreeNode *root) {
            prev = nullptr;
            flatten(root);
        }

        // Time Complexity - O(n)
        // Space Complexity - O(n)
        void flatten_iterative(TreeNode *root) {
            if (!root) return;
            stack<TreeNode *> st;
            st.push(root);

            while (!st.empty()) {
                TreeNode *curr = st.top();
                st.pop();

                if (curr->right) st.push(curr->right);
                if (curr->left) st.push(curr->left);

                if (!st.empty()) curr->right = st.top();
                curr->left = nullptr;
            }
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        void flatten_optimized(TreeNode *root) {
            if (!root) return;

            TreeNode *curr = root;

            while (curr) {
                if (curr->left) {
                    TreeNode *prev = curr->left;
                    
                    while (prev->right) {
                        prev = prev->right;
                    }

                    prev->right = curr->right;
                    curr->right = curr->left;
                    curr->left = nullptr;
                }
                curr = curr->right;
            }
        }
};