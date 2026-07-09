// Time Complexity - O(n)
// Space Complexity - O(n)

// Inorder - Left, Root, Right 

#include <vector>
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

class Solution {
    public:
        vector<int> iterative_inorder_traversal(TreeNode *root) {
            vector<int> inorder;
            stack <TreeNode *> st;
            TreeNode *node = root;

            while (true) {
                if (node != nullptr) {
                    st.push(node);
                    node = node->left;
                } else {
                    if (st.empty()) break;
                    node = st.top();
                    st.pop();

                    inorder.push_back(node->val);
                    node = node->right;
                }
            }

            return inorder;
        }
};