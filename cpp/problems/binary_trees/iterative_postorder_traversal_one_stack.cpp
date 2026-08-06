// Time Complexity - O(n)
// Space Complexity - O(n)

// Postorder - Left, Right, Root 

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
        vector<int> iterative_postorder_traversal(TreeNode *root) {
            vector<int> postorder;
            if (root == nullptr) return postorder;

            stack<TreeNode *> st;
            TreeNode *curr = root;
            TreeNode *temp;

            while (curr != nullptr || !st.empty()) {
                if (curr != nullptr) {
                    st.push(curr);
                    curr = curr->left;
                } else {
                    temp = st.top()->right;
                    if (temp == nullptr) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);

                        while (!st.empty() && temp == st.top()->right) {
                            temp = st.top();
                            st.pop();
                            postorder.push_back(temp->val);
                        }
                    } else {
                        curr = temp;
                    }
                }
            }

            return postorder;
        }
};