// Time Complexity - O(n)
// Space Complexity - O()

#include <vector>
#include <unordered_map>

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
        TreeNode *build_tree(
            vector<int>& inorder, 
            int is, 
            int ie, 
            vector<int>& postorder, 
            int ps, 
            int pe, 
            unordered_map<int, int>& map
        ) {
            if(is > ie || ps > pe) return nullptr;

            TreeNode *root = new TreeNode(postorder[pe]);
            int inorder_root_index = map[root->val];
            int nums_left = inorder_root_index - is;

            root->left = build_tree(inorder, is, inorder_root_index - 1, postorder, ps, ps + nums_left - 1, map);
            root->right = build_tree(inorder, inorder_root_index + 1, ie, postorder, ps + nums_left, pe - 1, map);

            return root;
        }

    public:
        TreeNode *build_tree(vector<int>& inorder, vector<int>& postorder) {
            if(inorder.size() != postorder.size()) {
                return nullptr;
            }

            unordered_map<int, int> map;

            for (int i = 0; i < inorder.size(); i++) {
                map[inorder[i]] = i;
            }

            return build_tree(inorder, 0 , inorder.size() - 1, postorder, 0, postorder.size() - 1, map);
        }
}; 