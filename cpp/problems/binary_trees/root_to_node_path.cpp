// Time Complexity - O(n)
// Space Complexity - O(h)

#include <vector>

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
        bool get_path(TreeNode *root, vector<int>& arr, int x) {
            if(!root) return false;

            arr.push_back(root->val);

            if(root->val == x) return true;

            if(get_path(root->left, arr, x) || get_path(root->right, arr, x)) return true;

            arr.pop_back();
            return false;
        }

    public:
        vector<int> root_to_node_path(TreeNode *root, int x) {
            vector<int> arr;
            if(root == nullptr) return arr;

            get_path(root, arr, x);
            return arr;
        }
};