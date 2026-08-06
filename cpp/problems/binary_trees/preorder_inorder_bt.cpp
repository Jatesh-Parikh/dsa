// Time Complexity - O(n)
// Space Complexity - O(n)

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
            vector<int>& pre_order, 
            int pre_start, 
            int pre_end,
            vector<int>& in_order,
            int in_start,
            int in_end,
            unordered_map <int, int>& map  
        ) {
            if (pre_start > pre_end || in_start > in_end) return nullptr;

            TreeNode *root = new TreeNode(pre_order[pre_start]);

            int inorder_root_index = map[root->val];
            int nums_left = inorder_root_index - in_start;

            root->left = build_tree(
                            pre_order, 
                            pre_start + 1, 
                            pre_start + nums_left, 
                            in_order, 
                            in_start, 
                            inorder_root_index - 1, 
                            map
                        );
            root->right = build_tree(
                            pre_order, 
                            pre_start + nums_left + 1, 
                            pre_end, 
                            in_order, 
                            inorder_root_index + 1, 
                            in_end, 
                            map
                        );
            
            return root;
        }
    
    public:
        TreeNode *build_tree(vector<int>& pre_order, vector<int>& in_order) {
            unordered_map<int, int> map;

            for (int i = 0; i < in_order.size(); i++) {
                map[in_order[i]] = i;
            }

            TreeNode *root = build_tree(pre_order, 0, pre_order.size() - 1, in_order, 0, in_order.size() - 1, map);

            return root;
        }
};