#include <vector>
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
        TreeNode *build(vector<int>& a, int& i, int ub) {
            if (i == a.size() || a[i] > ub) return nullptr;
            TreeNode *root = new TreeNode(a[i++]);
            root->left = build(a, i, root->val);
            root->right = build(a, i, ub);
            return root;
        }
        
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(h)
        TreeNode *bst_from_preorder(vector<int>& a) {
            int i = 0;
            return build(a, i, INT_MAX);
        }
};