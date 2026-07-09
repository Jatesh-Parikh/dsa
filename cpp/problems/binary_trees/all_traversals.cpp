// Time Complexity - O(n)
// Space Complexity - O(n)

// Preorder - Root, Left, Right
// Inorder - Left, Root, Right
// Postorder - Left, Right, Root

#include <vector>
#include <stack>
#include <tuple>

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
    public:
    tuple<vector<int>, vector<int>, vector<int>> all_traversals(TreeNode *root) {
        vector<int> preorder, inorder, postorder;

        if(root == nullptr) return {{}, {}, {}};

        stack<pair<TreeNode *, int>> st;
        st.push({ root, 1 });

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            if (it.second == 1) { // Preorder
                preorder.push_back(it.first->val);
                it.second++;
                st.push(it);

                if(it.first->left != nullptr) st.push({ it.first->left, 1 });
            } else if (it.second == 2) { // Inorder
                inorder.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->right != nullptr) st.push({ it.first->right, 1});
            } else { // Postorder
                postorder.push_back(it.first->val);
            }
        }

        return {preorder, inorder, postorder};
    }
};
