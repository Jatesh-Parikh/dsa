// Time Complexity - O(n)
// Space Complexity - O(h)

#include <climits>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {} 
};

class Solution {
    private:
        int max_depth_sum(TreeNode *root, int& maximum) {
            if (root == nullptr) return 0;

            int left_max = max(0, max_depth_sum(root->left, maximum));
            int right_max = max(0, max_depth_sum(root->right, maximum));

            maximum = max(maximum, root->val +  left_max + right_max);

            return root->val + max(left_max, right_max);
        }
    
    public:
        int max_path_sum(TreeNode *root) {
            int maximum = INT_MIN;
            max_depth_sum(root, maximum);
            return maximum;
        }
};