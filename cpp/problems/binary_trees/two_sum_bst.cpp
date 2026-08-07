#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class BSTIterator {
    private:
        stack<TreeNode *> st;
        bool before;

    public:
        BSTIterator(TreeNode *root, bool before): before(before) {
            push_all(root);
        }   
        
        bool has_next() {
            return !st.empty();
        }

        int next() {
            TreeNode *temp = st.top();
            st.pop();
            if (before) push_all(temp->left);
            else push_all(temp->right);
            return temp->val;
        }
    
    private:
        void push_all(TreeNode *node) {
            while (node) {
                st.push(node);
                if (before) node = node->right;
                else node = node->left;
            }
        }
};

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(h)
        bool two_sum_bst(TreeNode *root, int k) {
            if (!root) return false;

            BSTIterator maximum(root, true);
            BSTIterator minimum(root, false);

            int i = minimum.next();
            int j = maximum.next();

            while (i < j) {
                if (i + j == k) return true;
                else if (i + j < k) i = minimum.next();
                else j = maximum.next();
            }

            return false;
        }
};