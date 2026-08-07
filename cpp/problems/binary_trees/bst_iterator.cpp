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
    
    public:
        // Time Complexity - O(h)
        BSTIterator(TreeNode *root) {
            push_all(root);
        }

        // Time Complexity - O(1)
        bool has_next() {
            return !st.empty();
        }

        // Time Complexity - Amortized O(1)
        int next() {
            TreeNode *temp = st.top();
            st.pop();
            push_all(temp->right);
            return temp->val;
        }
    
    private:
        void push_all(TreeNode *node) {
            while (node) {
                st.push(node);
                node = node->left;
            }
        }
};